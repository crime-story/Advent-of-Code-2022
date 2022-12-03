#include <fstream>
#include <vector>
#include <set>

using namespace std;

ifstream fin("inputFile.in");
ofstream fout("inputFile.out");

int main() {
    string currentBackpack;
    int totalScore = 0;

    while (!fin.eof()) {
        vector<string> group3;
        set<char> firstCompartment, secondCompartment, commonLetters;
        getline(fin, currentBackpack);

        for (char &letter : currentBackpack)
            firstCompartment.insert(letter);

        getline(fin, currentBackpack);

        for (char &letter : currentBackpack)
            secondCompartment.insert(letter);

        getline(fin, currentBackpack);

        for (char &currentLetter: currentBackpack)
            if (firstCompartment.count(currentLetter) && secondCompartment.count(currentLetter) &&
                !commonLetters.count(currentLetter)) {
                commonLetters.insert(currentLetter);
                if (currentLetter >= 'a' && currentLetter <= 'z')
                    totalScore += currentLetter - 'a' + 1;
                else if (currentLetter >= 'A' && currentLetter <= 'Z')
                    totalScore += currentLetter - 'A' + 27;
            }
    }
    fin.close();

    fout << totalScore;

    fout.close();
    return 0;
}