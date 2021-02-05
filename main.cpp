#include <vector>
#include <algorithm>
#include <iostream>
#include "cmath"

using namespace std;

void setUp();
bool isNumAppropriate(vector<int> key);
void gameLoop();

vector<int> firstPlayerSavedNum = vector<int>();
vector<int> secondPlayerSavedNum = vector<int>();
vector<int> firstPlayerSuggestedNums = vector<int>();
vector<int> secondPlayerSuggestedNums = vector<int>();
vector<int> bufferNum = vector<int>();
bool isGameRunning = true;

int main() {
    setUp();

    while (isGameRunning){
        gameLoop();
    }

    return 0;
}

void setUp(){

    int buf;
    cout << "First Player:" << "\n";

    do {
        firstPlayerSavedNum.clear();
        cout << "Enter 4-digit number with unique numerals" << "\n";
        cin >> buf;

        int length = to_string(buf).length();

        for (int i = 0; i < length; ++i) {
            firstPlayerSavedNum.push_back(buf % 10);
            buf = buf / 10;
        }

    } while (!isNumAppropriate(firstPlayerSavedNum));

    reverse(firstPlayerSavedNum.begin(), firstPlayerSavedNum.end());
    for (int i : firstPlayerSavedNum) {
        cout << i;
    }
    cout << endl;

    cout << "Second Player:" << "\n";

    do {
        secondPlayerSavedNum.clear();
        cout << "Enter 4-digit number with unique numerals" << "\n";
        cin >> buf;

        int length = to_string(buf).length();

        for (int i = 0; i < length; ++i) {
            secondPlayerSavedNum.push_back(buf % 10);
            buf = buf / 10;
        }
    } while (!isNumAppropriate(secondPlayerSavedNum));

    reverse(secondPlayerSavedNum.begin(), secondPlayerSavedNum.end());
    for (int i : secondPlayerSavedNum) {
        cout << i;
    }
    cout << endl;
}

bool isNumAppropriate(vector<int> key){
    bool flag = true;

    if (key.size() != 4){
        return false;
    }

    if (key.at(0) == key.at(1)){
        flag = false;
    } else if (key.at(0) == key.at(2)){
            flag = false;
    } else if (key.at(0) == key.at(3)){
            flag = false;
    } else if (key.at(1) == key.at(2)){
            flag = false;
    } else if (key.at(1) == key.at(3)){
            flag = false;
    } else if (key.at(2) == key.at(3)){
            flag = false;
    }

    return  flag;
}

void gameLoop(){

    cout << "First Player Turn:" << "\n";
    cout << "\t" << "Previously Suggested Numbers:" << "\n";
    for (int i : firstPlayerSuggestedNums) {
        cout << firstPlayerSuggestedNums.at(i) << "\n";
    }

    cout << "\t" << "Suggest New Number" << "\n";
}