#include <fstream>
#include <vector>

using namespace std;

ifstream fin("inputFile.in");
ofstream fout("inputFile.out");

struct intervals {
    pair<int, int> firstInterval;
    pair<int, int> secondInterval;
};

bool fullyContains(const intervals &currentPair) {
    pair<int, int> firstInterval = currentPair.firstInterval;
    pair<int, int> secondInterval = currentPair.secondInterval;

    if ((firstInterval.first >= secondInterval.first && firstInterval.second <= secondInterval.second) ||
        (secondInterval.first >= firstInterval.first && secondInterval.second <= firstInterval.second
        ))
        return true;
    return false;
}

bool partialContains(const intervals &currentPair) {
    pair<int, int> firstInterval = currentPair.firstInterval;
    pair<int, int> secondInterval = currentPair.secondInterval;

    int intersectionFirstCoordinate = max(firstInterval.first, secondInterval.first);
    int intersectionSecondCoordinate = min(firstInterval.second, secondInterval.second);

    if (intersectionFirstCoordinate <= intersectionSecondCoordinate)
        return true;

    return false;
}

int main() {
    string currentLine;
    vector<intervals> elves;
    int fullContainPairs = 0;
    int partialContainsPairs = 0;

    while (!fin.eof()) {
        int x1, y1, x2, y2;
        char delim;
        fin >> x1 >> delim >> y1 >> delim >> x2 >> delim >> y2;

        intervals currentInterval;
        currentInterval.firstInterval = make_pair(x1, y1);
        currentInterval.secondInterval = make_pair(x2, y2);
        elves.push_back(currentInterval);
    }
    fin.close();

    for (auto &currentElf: elves) {
        if (fullyContains(currentElf))
            fullContainPairs++;
        if (partialContains(currentElf))
            partialContainsPairs++;
    }

    fout << fullContainPairs << " " << partialContainsPairs;

    fout.close();
    return 0;
}