#include "display.h"
#include "mechanics.h"
#include <iostream>
using namespace std;

//displays the banner "minesweeper"
void displayBanner() {
    cout << "███╗░░░███╗██╗███╗░░██╗███████╗░██████╗░██╗░░░░░░░██╗███████╗███████╗██████╗░███████╗██████╗░\n"
            "████╗░████║██║████╗░██║██╔════╝██╔════╝░██║░░██╗░░██║██╔════╝██╔════╝██╔══██╗██╔════╝██╔══██╗\n"
            "██╔████╔██║██║██╔██╗██║█████╗░░╚█████╗░░╚██╗████╗██╔╝█████╗░░█████╗░░██████╔╝█████╗░░██████╔╝\n"
            "██║╚██╔╝██║██║██║╚████║██╔══╝░░░╚═══██╗░░████╔═████║░██╔══╝░░██╔══╝░░██╔═══╝░██╔══╝░░██╔══██╗\n"
            "██║░╚═╝░██║██║██║░╚███║███████╗██████╔╝░░╚██╔╝░╚██╔╝░███████╗███████╗██║░░░░░███████╗██║░░██║\n"
            "╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚══════╝╚═════╝░░░░╚═╝░░░╚═╝░░╚══════╝╚══════╝╚═╝░░░░░╚══════╝╚═╝░░╚═╝\n\n";
    
}


//displays the main menu of the game
void mainMenu() {
    cout << "\n\n\n"
            "█▀█ █▀█ █▀▀ █▀ █▀   ▄█   ▀█▀ █▀█   █▀ ▀█▀ ▄▀█ █▀█ ▀█▀\n"
            "█▀▀ █▀▄ ██▄ ▄█ ▄█   ░█   ░█░ █▄█   ▄█ ░█░ █▀█ █▀▄ ░█░\n"
            "\n"
            "█▀█ █▀█ █▀▀ █▀ █▀   ▀█   ▀█▀ █▀█   █▀ █▀▀ █▀▀   █░░ █▀▀ ▄▀█ █▀▄ █▀▀ █▀█ █▄▄ █▀█ ▄▀█ █▀█ █▀▄\n"
            "█▀▀ █▀▄ ██▄ ▄█ ▄█   █▄   ░█░ █▄█   ▄█ ██▄ ██▄   █▄▄ ██▄ █▀█ █▄▀ ██▄ █▀▄ █▄█ █▄█ █▀█ █▀▄ █▄▀\n";

}


//displays instructions to play the game
void displayControls() {
    cout << "\n"
            "┌───────────────────────────────────────────────────────────────────────────┐\n"
            "│ press W or A or S or D and press Enter for each move                      │\n"
            "│ if you put in multiple characters, only the first one will be considered  │\n"
            "│ press O and press Enter for uncovering the tile                           │\n"
            "│ press P and press Enter for flagging the tile                             │\n"
            "│ press M to end the game                                                   │\n"
            "│ @ means you uncovered a Mine                                              │\n"
            "│ if you uncover a Mine you will LOSE 100 points                            │\n"
            "│ FLAG all Mines to WIN!!                                                   │\n"
            "└───────────────────────────────────────────────────────────────────────────┘\n"
            "\n";
}


//displays the current score and number of flags left
void displayFlags(int currentScore, int numberOfFlags){
    cout << "Score: " << currentScore << "\n";
    cout << "Flags: " << numberOfFlags << "\n\n";
}


//displays the ending message
void displayEnding(int currentScore) {
    cout << "█▀▀ █▀█ █▄░█ █▀▀ █▀█ ▄▀█ ▀█▀ █░█ █░░ ▄▀█ ▀█▀ █ █▀█ █▄░█ █▀ █ █\n"
            "█▄▄ █▄█ █░▀█ █▄█ █▀▄ █▀█ ░█░ █▄█ █▄▄ █▀█ ░█░ █ █▄█ █░▀█ ▄█ ▄ ▄\n"
            "\n"
            "█▄█ █▀█ █░█   █▀▀ █ █▄░█ █ █▀ █░█ █▀▀ █▀▄   ▄▀█   █▀▀ ▄▀█ █▀▄▀█ █▀▀\n"
            "░█░ █▄█ █▄█   █▀░ █ █░▀█ █ ▄█ █▀█ ██▄ █▄▀   █▀█   █▄█ █▀█ █░▀░█ ██▄\n"
            "\n"
            "█▀█ █▀▀   █▀▄▀█ █ █▄░█ █▀▀ █▀ █░█░█ █▀▀ █▀▀ █▀█ █▀▀ █▀█ █\n"
            "█▄█ █▀░   █░▀░█ █ █░▀█ ██▄ ▄█ ▀▄▀▄▀ ██▄ ██▄ █▀▀ ██▄ █▀▄ ▄\n\n";
    cout << "Your final score is " << currentScore << "\n\n";
    cout << "When you enter your name, the score will be\n"
            "saved to the leaderboard and the program will end.\n"
            "We hope you enjoyed the game!\n\n";
}
