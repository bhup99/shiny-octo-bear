/*
ID: bhupesh1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef struct
{
    int initialSum, finalSum;
}account;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    int numOfTeen, activeIndex, money, friendsCount;
    vector<string> nameOfTeen;
    map<string, int> nameToIndex;
    string activeName, giftTaker;


    fin >> numOfTeen;
    account savings[numOfTeen];
    nameOfTeen.resize(numOfTeen);

    for(int i = 0; i < numOfTeen; i++)
    {
        fin >> nameOfTeen[i];
        nameToIndex[nameOfTeen[i]] = i;
        savings[i].initialSum = savings[i].finalSum = 0;
    }

    for(int i = 0; i < numOfTeen; i++)
    {
        fin >> activeName;
        activeIndex = nameToIndex[activeName];
        fin >> money >> friendsCount;
        savings[nameToIndex[activeName]].initialSum = money;
        cout << "HI!!!" << endl;
        for(int j = 0; j < friendsCount; j++)
        {
            fin >> giftTaker;
            if(friendsCount != 0)
                savings[nameToIndex[giftTaker]].finalSum += money / friendsCount;
        }
        if(friendsCount != 0)
        savings[nameToIndex[activeName]].finalSum += money % friendsCount;
        cout << "BYE!!!" << endl;
    }

    for(int i = 0; i < numOfTeen; i++)
        fout << nameOfTeen[i] << " " << savings[i].finalSum - savings[i].initialSum << endl;
    return 0;
}

