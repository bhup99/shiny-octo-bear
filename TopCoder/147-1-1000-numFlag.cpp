#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <algorithm>
#define NO 0

using namespace std;

class Flags
{
    public:

    vector<vector <long long> > countFlag;

    long long totalFlag(int n)
    {
        long long x = 0;
        for(int i= 0; i < n; i++)
        {
            x += countFlag[countFlag.size() - 1][i];
        }
        cout << endl;
        return x;
    }

    int search(int j, string s)
    {
        int n, check = 0;
        if(s[0] == '0' && j == 0)
            check = 1;
        istringstream ss(s);
        while(ss >> n || check)
        {
            if(n == j)
                return 1;
            check = 0;
        }
        return 0;
    }

    long long numStripes(string numFlags, vector <string> forbidden)
    {
        istringstream ss(numFlags);
        vector<long long> spare;
        long long flagsTillNow = forbidden.size();
        long long x;
        ss >> x;

        int stripCount = 0;
        for(int i = 0; i < forbidden.size(); i++)
            spare.push_back(1);

        countFlag.push_back(spare);
        spare.clear();

        for(int i = 0; i < forbidden.size(); i++)
            spare.push_back(0);

        int zeCount = 0, oneCount = 0, y, n;
        bool infiCount = 0;

        for(int i = 0; i < forbidden.size(); i++)
        {
            y = forbidden.size();
            istringstream ss(forbidden[i]);
            while(ss >> n)
            {
                y--;
            }
            infiCount |= y > 1;
            zeCount += (y == 0);
            oneCount += y == 1;
        }

        if(!infiCount)
        {
            return (x - zeCount) / oneCount;
        }

        while(flagsTillNow < x)
        {
            stripCount++;
            countFlag.push_back(spare);
            for(int i = 0; i < forbidden.size(); i++)
            {
                for(int j = 0; j < forbidden.size(); j++)
                {
                    if(search(j, forbidden[i]) == 0)
                    {
                        countFlag[stripCount][i] += countFlag[stripCount - 1][j];
                    }
                }
            }
            flagsTillNow += totalFlag(forbidden.size());
        }
        flagsTillNow = countFlag.size();
        return flagsTillNow;
    }
};

int main()
{
    Flags ob;
    vector<string> a;
    string s;
    s = "100000000000000000";
    a.push_back("0");
    a.push_back("1");
    cout << endl << ob.numStripes(s, a);
}
