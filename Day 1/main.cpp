#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream fin("inputFile.in");
ofstream fout("inputFile.out");

int main() {
    string s;
    vector<int> elvesCaloriesSum;
    int index = 0;
    elvesCaloriesSum.push_back(index);

    while (!fin.eof()) {
        getline(fin, s);
        if (s != "") {
            elvesCaloriesSum[index] += atoi(s.c_str());
        } else {
            index++;
            elvesCaloriesSum.push_back(0);
        }
    }
    fin.close();

    int maxCaloriesSumElf1 = 0;
    int maxCaloriesSumElf2 = 0;
    int maxCaloriesSumElf3 = 0;

    for (auto &elfCaloriesSum: elvesCaloriesSum) {
        if (elfCaloriesSum > maxCaloriesSumElf1) {
            maxCaloriesSumElf3 = maxCaloriesSumElf2;
            maxCaloriesSumElf2 = maxCaloriesSumElf1;
            maxCaloriesSumElf1 = elfCaloriesSum;
        } else if (elfCaloriesSum > maxCaloriesSumElf2) {
            maxCaloriesSumElf3 = elfCaloriesSum;
            maxCaloriesSumElf2 = elfCaloriesSum;
        } else if (elfCaloriesSum > maxCaloriesSumElf3) {
            maxCaloriesSumElf3 = elfCaloriesSum;
        }
    }

    int sumCaloriesFirst3Elves = maxCaloriesSumElf1 + maxCaloriesSumElf2 + maxCaloriesSumElf3;

    fout << maxCaloriesSumElf1 << " " << maxCaloriesSumElf2  << " " << maxCaloriesSumElf3 << "\n";
    fout << sumCaloriesFirst3Elves;

    fout.close();
    return 0;
}
