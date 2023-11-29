#include "display.h"
#include "mechanics.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "score.h"
#define reset "\033[1;0m"
#define blueBackground "\033[104m"
using namespace std;


//takes player input for row and column
void Board::setBoardSize() {
    system("clear");
    displayBanner();
    cout << "Customize your Minesweeper board for a personalized experience! \n";
    cout << "Enter a number between 8-16 for the row : ";
    cin >> row;
    cout << "Enter a number between 8-30 for the column : ";
    cin >> column;
    
    while ( row<8 || row>16)
    {
        cout << "Please enter the row again : ";
        cin >> row;
    }
    
    while ( column<8 || column >30 )
    {
        cout << "Please enter the column again : ";
        cin >> column;
    }
}


//generates a board with from the player input dynamically
void Board::setBoard() {
    mineBoard = new char*[row];
    for(int i=0; i<row; i++) {
        mineBoard[i] = new char[column];
    }
    
    // make player board
    playerBoard = new char*[row];
    for(int i=0; i<row; i++) {
        playerBoard[i] = new char[column];
    }
    
    for(int i=0; i<row; i++)
    {
        for(int j = 0; j < column; ++j) {
            playerBoard[i][j] = ' ';
            mineBoard[i][j] = '.';
        }
    }
}


//randomly places the mines on the board, except for the 3x3 grid surrounding the player's first reveal.
void Board::placeMines()
{
    mineBoard[yLocation][xLocation]='H';    //player's first reveal
    
    numberOfMines = (row*column) * 0.2;     //20% of the board are mines
    numberOfFlags = numberOfMines;
    
    int rnd_r, rnd_c;   // random input for row and column
    
    srand(time(NULL));
    for (int i=0; i<numberOfMines; i++)
    {
        rnd_r = rand() % row;
        rnd_c = rand() % column;
        
        while (rnd_r>=yLocation-1 && rnd_r<=yLocation+1 && rnd_c>=xLocation-1 && rnd_c<=xLocation+1) {
            rnd_r = rand() % row;
            rnd_c = rand() % column;
        }
        
        if (mineBoard[rnd_r][rnd_c] == 'B')
        {
            i--; continue;
        }
        else
            mineBoard[rnd_r][rnd_c] = 'B';
    }
}


// destroys the dynamically created 2-d array objects
void Board::delDynamic()
{
    for(int i=0; i<row; i++)
        delete[] mineBoard[i];
    delete[] mineBoard;
    
    mineBoard = nullptr;
}
     

//prints the board for the player
void Board::printBoard() {
    system("clear");
    displayBanner();
    
    string corners[9] = {"┌", "┬", "┐", "├", "┼", "┤", "└", "┴", "┘"};
    int l = 0;

    for (int i = 0; i < row; ++i) {
        if (i != 0) {
            l = 3;
        }

        cout << corners[l] << "─────";

        for (int j = 1; j < column; ++j) {
            cout << corners[l+1] << "─────";
        }

        cout << corners[l+2] << '\n';

        for (int j = 0; j < column; ++j) {
            if (i == yLocation && j == xLocation){
                cout << "│  " << blueBackground << playerBoard[i][j] << reset << "  ";
                continue;
            }
            cout << "│  " << playerBoard[i][j] << "  ";
        }
        cout << "│" << '\n';
    }

    cout << corners[6] << "─────";
    for (int j = 1; j < column; ++j) {
            cout << corners[7] << "─────";
        }
    cout << corners[8];
    cout << "\n";
    displayControls();
    displayFlags(currentScore, numberOfFlags);

    cout << "Your input: ";
}


//gets the player input and processes the command
char Board::getPlayerInput(bool IsFirstTimePlaying) {
    char playerInput;
    
    printBoard();
    
    bool validInput = false;
    do {
        cin >> playerInput;

        switch (playerInput) {
        case 's':
        case 'S':
            if (yLocation + 1 < row) {
                ++yLocation;
                validInput = true;
            }
            break;

        case 'a':
        case 'A':
            if (xLocation - 1 >= 0) {
                --xLocation;
                validInput = true;
            }
            break;

        case 'w':
        case 'W':
            if (yLocation - 1 >= 0) {
                --yLocation;
                validInput = true;
            }
            break;

        case 'd':
        case 'D':
            if (xLocation + 1 < column) {
                ++xLocation;
                validInput = true;
            }
            break;

        case 'o':
        case 'O':
            if (IsFirstTimePlaying == true) {
                return 'o';
            }
            uncover(xLocation, yLocation);
            validInput = true;
            break;

        case 'p':
        case 'P':
            if (IsFirstTimePlaying == true) {
                break;
            }
            flagging();
            validInput = true;
            break;

        case 'm':
        case 'M':
            validInput = true;
            return 'm';

        default:
            break;
        }
        
        if (!validInput) {
            printBoard();
            cout << "invalid input. please enter again.\n";
        }

    } while (!validInput);

    return '.';

}


//uncovers the mine underneath, or generates the number of surrounding mines
void Board::uncover(int x, int y) {
    if (mineBoard[y][x] == 'B') {
        currentScore -= 200;
        playerBoard[y][x] = '@';
        return;
    }
    
    playerBoard[y][x] = '.';
    int surroundingMineCount = 48;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {

            if (i == 0 && j == 0) {
                continue;
            }

            int neighborX = x + i;
            int neighborY = y + j;

            bool cellOutOfRange = (neighborX < 0 || neighborX >= column || neighborY < 0 || neighborY >= row);
            if (cellOutOfRange) {
                continue;
            }

            if (mineBoard[neighborY][neighborX] == 'B') {
                surroundingMineCount++;
            }
        }
    }

    if (surroundingMineCount != 48) {
        playerBoard[y][x] = char(surroundingMineCount);
        currentScore += 20;
        return;
    }

    // recursively uncover the neighboring cells if surroundingMineCount is 0.
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {

            if (i == 0 && j == 0) {
                continue;
            }

            int neighborX = x + i;
            int neighborY = y + j;

            bool cellOutOfRange = (neighborX < 0 || neighborX >= column || neighborY < 0 || neighborY >= row);
            if (cellOutOfRange) {
                continue;
            }

            if (playerBoard[neighborY][neighborX] == '.') {
                continue;
            }

            uncover(neighborX, neighborY);
        }
    }
}


//flags where the player's cursor is located
void Board::flagging() {
    if (playerBoard[yLocation][xLocation] == 'F') {
        playerBoard[yLocation][xLocation] = ' ';
        numberOfFlags += 1;
        currentScore -= 50;
        return;
    }

    playerBoard[yLocation][xLocation] = 'F';
    numberOfFlags -= 1;
    
    if (mineBoard[yLocation][xLocation] == 'B') {
        currentScore += 50;
    } else {
        currentScore -= 100;
    }
}


//at the end of the game, get the player's name to save the final score to the leaderboard
void Board::endGame(){
    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;

    // Update the scoreboard with the current score
    updateScoreboard(playerName, currentScore);

    // Display the scoreboard
    vector<Score> scoreboard;
    loadScoreboard(scoreboard);
}


//displays the leaderboard
void leaderboard() {
    vector<Score> scoreboard;
    loadScoreboard(scoreboard);

    if (scoreboard.empty()) {
        cout << "No previously saved scores." << endl;
        return;
    }

    // Sort the scoreboard
    sortScores(scoreboard);

    // Print the sorted scoreboard
   
    printScoreboard(scoreboard);
}


//checks if all the cells are revealed, and ends the game if so
bool Board::checkEndGame()
{
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<column; j++)
        {
            if (playerBoard[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}
