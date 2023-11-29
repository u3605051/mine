#ifndef MECHANICS_H
#define MECHANICS_H


void leaderboard();
struct Board {
    int column; //the number of columns of the customized board
    int row; //the number of rows of the customized board
    int numberOfFlags; //the number of flags left to use
    int numberOfMines; //the number of mines on the board
    int xLocation; //expresses the xLocation of the player on the board
    int yLocation; //expresses the yLocation of the player on the board
    char **mineBoard; //Dynamically created 2-d array which represents a board filled with randomly scattered mines
    char **playerBoard; //Dynamically created 2-d array which presents a board which reflects the player's input
    int currentScore; //counts the current score of the player

    void setBoardSize();
    void setBoard();
    void placeMines();
    void delDynamic();
    void printBoard();
    char getPlayerInput(bool IsFirstTimePlaying);
    void uncover(int x, int y);
    void flagging();
    void endGame();
    void leaderboard();
    bool checkEndGame();

};

#endif
