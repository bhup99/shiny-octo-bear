/*
ID: bhupesh1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int n;

    fin >> n;
    int weekDays[] = {0, 1, 2, 3, 4, 5, 6};
    int thiries[] = {4, 6, 9, 11};
    int numOfDays, curDay = 1;
    int dayPercent[7] = {0};

    for(int i = 1900; i < 1900 + n; i++)
    {
        for(int j = 1; j <= 12; j++)
        {
            if(j == 2)
                numOfDays = 28 + (i % 4 == 0 && (i%100 != 0 || i %400 == 0));
            else if(j == 4 || j == 6 || j == 9 || j == 11)
                numOfDays = 30;
            else
                numOfDays = 31;

            curDay += 5;
            curDay = curDay % 7;
            dayPercent[curDay]++;
            curDay += numOfDays - 12;

        }
    }
    fout << dayPercent[6];
    for(int i = 0; i < 6; i++)
        fout << " " << dayPercent[i%7];
    fout << endl;
    return 0;
}

