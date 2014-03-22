/*
ID: bhupesh1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    string necklace;
    vector< pair<int, char> > s;
    s.clear();
    int lastCount, n, j;
    int redCount = 0, blueCount = 0, maxCount = 0, whiteCount = 0;
    char lastBead;

    int size, determiner = 0;
    size = necklace.size();
    fin >> n >> necklace;
    //n = 3;
    //necklace = "rrr";

    lastBead = necklace[0];
    lastCount = 1;

    for(int i = 1; i < n; i++)  {
        if(necklace[i] != lastBead) {
            s.push_back(make_pair(lastCount, lastBead));
            lastBead = necklace[i];
            lastCount = 1;
        }
        else
            lastCount++;
    }
    s.push_back(make_pair(lastCount, lastBead));

    if((s[0].second == 'w' && s[1].second == 'b') || s[0].second == 'b')
        determiner = 1;
    n = s.size();

    //for(int i = 0; i < n; i++)  {
        //cout << "(" << s[i].first << "," << s[i].second << ")\t";
    //}
    //cout << endl;
    int i;
    for(j = 0; j < n;)  {
        i = j;
        if(determiner%2 == 0)   {
            redCount = 0;
            while(s[i%n].second != 'b')    {
                redCount += s[i%n].first;
                //cout << i << " " << s[i%n].second << "\t";
                i++;
                if(i%n == j)
                    break;
            }
            cout << endl;
            determiner++;
            redCount += whiteCount;
            if(blueCount > 0)
                blueCount -= whiteCount;
        }
        else    {
            blueCount = 0;
            while(s[i%n].second != 'r')    {
                blueCount += s[i%n].first;
                i++;
                if(i%n == j)
                    break;
            }
            determiner++;
            blueCount += whiteCount;
            if(redCount > 0)
                redCount -= whiteCount;
        }

        if(s[(i - 1 + n)%n].second == 'w')
            whiteCount = s[(i - 1 + n)%n].first;
        else
            whiteCount = 0;

        if(redCount + blueCount > maxCount)
            maxCount = redCount + blueCount;
        j = i;
        //cout << "MaxCount " << whiteCount << " " << redCount << " " << blueCount << " " << maxCount << " " << i << endl;
    }

    fout << maxCount << endl;
}

