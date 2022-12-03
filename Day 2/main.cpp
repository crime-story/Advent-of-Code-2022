#include <fstream>
#include <unordered_map>

using namespace std;

ifstream fin("inputFile.in");
ofstream fout("inputFile.out");

/* Part one rules:
 * A and X is ROCK = 1          * LOSE = 0
 * B and Y is PAPER = 2         * DRAW = 3
 * C and Z is SCISSORS = 3      * WIN = 6
 */

unordered_map<string, int> outcomes = {
        {"A X", 4}, {"A Y", 8}, {"A Z", 3},
        {"B X", 1}, {"B Y", 5}, {"B Z", 9},
        {"C X", 7}, {"C Y", 2}, {"C Z", 6}
};


/* Part two rules:
 * A is ROCK = 1            * X is LOSE = 0
 * B is PAPER = 2           * Y is DRAW = 3
 * C is SCISSORS = 3        * Z is WIN = 6
 */

unordered_map<string, int> outcomes2 = {
        {"A X", 3}, {"A Y", 4}, {"A Z", 8},
        {"B X", 1}, {"B Y", 5}, {"B Z", 9},
        {"C X", 2}, {"C Y", 6}, {"C Z", 7}
};

int main() {
    string currentRound;
    int playerScore1= 0;
    int playerScore2 = 0;

    while (!fin.eof()) {
        getline(fin, currentRound);
        playerScore1 += outcomes[currentRound];
        playerScore2 += outcomes2[currentRound];
    }
    fin.close();

    fout << playerScore1 << " " << playerScore2;

    fout.close();
    return 0;
}