#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>

using namespace std;

void setUp();
bool isNumAppropriate(vector<int> key);
vector<int> checkNum(vector<int> numToCheck, vector<int> key);
int arrayToNum(vector<int> key);
void firstPlayerTurn();
void secondPlayerTurn();

vector<int> firstPlayerSavedNum = vector<int>();
vector<int> secondPlayerSavedNum = vector<int>();
vector<vector<int>> firstPlayerSuggestedNums = vector<vector<int>>();
vector<vector<int>> secondPlayerSuggestedNums = vector<vector<int>>();
vector<int> bufferNum = vector<int>();

int main() {
    setUp();

    if (clock() % 2 == 0){
        firstPlayerTurn();
    } else {
        secondPlayerTurn();
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

        if (buf < 0){
            continue;
        }

        int length = to_string(buf).length();

        for (int i = 0; i < length; ++i) {
            firstPlayerSavedNum.push_back(buf % 10);
            buf = buf / 10;
        }

    } while (!isNumAppropriate(firstPlayerSavedNum));

    reverse(firstPlayerSavedNum.begin(), firstPlayerSavedNum.end());
//    for (int i : firstPlayerSavedNum) {
//        cout << i;
//    }
    cout << endl;

    cout << "Second Player:" << "\n";

    do {
        secondPlayerSavedNum.clear();
        cout << "Enter 4-digit number with unique numerals" << "\n";
        cin >> buf;

        if (buf < 0){
            continue;
        }

        int length = to_string(buf).length();

        for (int i = 0; i < length; ++i) {
            secondPlayerSavedNum.push_back(buf % 10);
            buf = buf / 10;
        }
    } while (!isNumAppropriate(secondPlayerSavedNum));

    reverse(secondPlayerSavedNum.begin(), secondPlayerSavedNum.end());
//    for (int i : secondPlayerSavedNum) {
//        cout << i;
//    }
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

void firstPlayerTurn(){
    vector<int> resultArray;

    cout << "First Player Turn:" << "\n";
    cout << "\t" << "Previously Suggested Numbers:" << "\n";

    for (int i = 0; i < firstPlayerSuggestedNums.size(); i++) {
        cout << "\t" << "\t" << firstPlayerSuggestedNums.at(i).at(0) << "   Amount Of Cows: " << firstPlayerSuggestedNums.at(i).at(1) << "   Amount Of Bulls: " << firstPlayerSuggestedNums.at(i).at(2) << "\n";
    }

    int buf;
    do {
        bufferNum.clear();
        cout << "\t" << "Suggest New 4-digit Number" << "\n";
        cin >> buf;

        int length = to_string(buf).length();

        for (int i = 0; i < length; ++i) {
            bufferNum.push_back(buf % 10);
            buf = buf / 10;
        }
    } while (!isNumAppropriate(bufferNum));

    reverse(bufferNum.begin(), bufferNum.end());

    resultArray.clear();
    resultArray = checkNum(secondPlayerSavedNum, bufferNum);

    firstPlayerSuggestedNums.push_back(vector<int>{arrayToNum(bufferNum), resultArray.at(0) - resultArray.at(1), resultArray.at(1)});

    cout << "\t" << "Amount Of Cows: " << resultArray.at(0) - resultArray.at(1) << "   Amount Of Bulls: " << resultArray.at(1) << "\n";

    if (resultArray.at(1) == 4){
        cout << "FIRST PLAYER WINS";
    } else {
        secondPlayerTurn();
    }

}

void secondPlayerTurn(){
    vector<int> resultArray;

    cout << "Second Player Turn:" << "\n";
    cout << "\t" << "Previously Suggested Numbers:" << "\n";

    for (int i = 0; i < secondPlayerSuggestedNums.size(); i++) {
        cout << "\t" << "\t" << secondPlayerSuggestedNums.at(i).at(0) << "   Amount Of Cows: " << secondPlayerSuggestedNums.at(i).at(1) << "   Amount Of Bulls: " << secondPlayerSuggestedNums.at(i).at(2) << "\n";
    }

    int buf;
    do {
        bufferNum.clear();
        cout << "\t" << "Suggest New 4-digit Number" << "\n";
        cin >> buf;

        int length = to_string(buf).length();

        for (int i = 0; i < length; ++i) {
            bufferNum.push_back(buf % 10);
            buf = buf / 10;
        }
    } while (!isNumAppropriate(bufferNum));

    reverse(bufferNum.begin(), bufferNum.end());

    resultArray.clear();
    resultArray = checkNum(firstPlayerSavedNum, bufferNum);

    secondPlayerSuggestedNums.push_back(vector<int>{arrayToNum(bufferNum), resultArray.at(0) - resultArray.at(1), resultArray.at(1)});

    cout << "\t" << "Amount Of Cows: " << resultArray.at(0) - resultArray.at(1) << "   Amount Of Bulls: " << resultArray.at(1) << "\n";

    if (resultArray.at(1) == 4){
        cout << "SECOND PLAYER WINS";
    } else {
        firstPlayerTurn();
    }

}

vector<int> checkNum(vector<int> numToCheck, vector<int> key){
    vector<int> result = {0, 0};

    for (int i = 0; i < numToCheck.size(); ++i) {
        for (int j = 0; j < key.size(); ++j) {
            if (numToCheck.at(i) == key.at(j)){
                result.at(0)++;
                if (i == j){
                    result.at(1)++;
                }
            }
        }
    }

    return result;
}

int arrayToNum(vector<int> key){
    int result = 0;

    result += key.at(3);
    result += key.at(2) * 10;
    result += key.at(1) * 100;
    result += key.at(0) * 1000;

    return result;
}