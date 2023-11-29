#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "score.h"

using namespace std;

//Prints scoreboard with recorded player's name and points
void printScoreboard(const vector<Score>& scoreboard) {
    cout << "Scoreboard:" << endl;
    for (const Score& score : scoreboard) {
        cout << "Player: " << score.playerName << ", Score: " << score.record << endl;
    }
}


// Comparator function to sort scores in descending order
bool compareScores(const Score& score1, const Score& score2) {
    return score1.record > score2.record;
}


// Function to sort the scores from highest to lowest
void sortScores(vector<Score>& scoreboard) {
    sort(scoreboard.begin(), scoreboard.end(), compareScores);
}


//Saves the contents of the scoreboard vector to a file named "scoreboard.txt"
void saveScoreboard(const vector<Score>& scoreboard) {
    ofstream file("scoreboard.txt");
    if (file.is_open()) {
        for (const Score& score : scoreboard) {
            file << score.playerName << " " << score.record << endl;
        }
        file.close();
    } else {
        cout << "Unable to open the scoreboard file." << endl;
    }
}


//Updates the scoreboard by adding a new Score entry with the given playerName and points
void updateScoreboard(const string& playerName, int points) {
    vector<Score> scoreboard;
    loadScoreboard(scoreboard);

    Score score;
    score.playerName = playerName;
    score.record = points;

    scoreboard.push_back(score);
    saveScoreboard(scoreboard);
}


//Loads the contents of a scoreboard file named "scoreboard.txt" into a vector scoreboard
void loadScoreboard(vector<Score>& scoreboard) {
    ifstream file("scoreboard.txt");
    if (file.is_open()) {
        Score score;
        while (file >> score.playerName >> score.record) {
            scoreboard.push_back(score);
        }
        file.close();
    } else {
        cout << "No previously saved scoreboard file found.\nYour score will be recorded on a new scoreboard.\n";
    }
}
