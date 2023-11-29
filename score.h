#ifndef score_H
#define score_H
#include <vector>
#include <string>


struct Score {
    std::string playerName;
    int record;
};


void printScoreboard(const std::vector<Score>& scoreboard);
bool compareScores(const Score& score1, const Score& score2);
void sortScores(std::vector<Score>& scoreboard);
void saveScoreboard(const std::vector<Score>& scoreboard);
void updateScoreboard(const std::string& playerName, int points);
void loadScoreboard(std::vector<Score>& scoreboard);

#endif

