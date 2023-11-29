#include "display.h"
#include "mechanics.h"
#include <iostream>
using namespace std;


//run the main game
void runGame() {
    Board b;
    b.setBoardSize();
    b.setBoard();
    b.xLocation = 3;
    b.yLocation = 3;
    b.currentScore = 3000;
    b.numberOfFlags = 0;
    char input;
    bool determine; 

    // first input
    do {
        input = b.getPlayerInput(true);
    } while (input != 'o');

    // set the board using the first input, and reveal.
    b.placeMines();
    b.uncover(b.xLocation, b.yLocation);

    // running the rest of the game.
    do {
        input = b.getPlayerInput(false);
        determine = b.checkEndGame();
    } while (input != 'm' && determine==false);

    //ending displays
    system("clear");
    displayEnding(b.currentScore);
    b.endGame();

    //deletes memory
    b.delDynamic();
}


int main() {
    displayBanner();
    mainMenu();

    int firstinput;
    cin >> firstinput;

    while (firstinput != 1 && firstinput != 2) {
        cout << "Please enter the number again: ";
        cin >> firstinput;
    }

    if(firstinput == 1){
        runGame();
    } else if (firstinput == 2) {
        system("clear");
        displayBanner();
        leaderboard();
        cout << "\n\nPlease input 's' if you want to start the game. Else, the program will end.\n\n"
                "Input: ";

        char input;
        cin >> input;
        if (input == 's' || input == 'S') {
            runGame();
        }
    }

    return 0;
}
