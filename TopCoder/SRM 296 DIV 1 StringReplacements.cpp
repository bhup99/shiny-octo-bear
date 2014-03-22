#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
#include <map>
#include <fstream>
#include <stdlib.h>

using namespace std;

#define ll long long
#define pb push_back
#define fl(i, n, m)		for(int i=n; i<m; i++)

class StringReplacements
{
public:
    vector<int> substringCounter(string letter, int left, int right, int nSeconds)
    {
        string backup;
        vector<int> res;
        res.resize(3);
        res[0] = res[1] = res[2] = 0;
        fl(i, 0, nSeconds)
        {
            backup = "";
            fl(j, 0, letter.size())
            {
                if(letter[j] == 'a')
                    backup += "acb";
                else if(letter[j] == 'b')
                    backup += "baa";
                else if(letter[j] == 'c')
                    backup += "bcb";
                else
                    backup += letter[i];
            }
            letter = backup;
        }
        fl(i, left, right+1)
        {
            if(letter[i] >= 'a' && letter[i] < 'd')
                res[letter[i] - 'a']++;
        }
        return res;
    }
};

int main()
{
    StringReplacements ob;
    vector<int> r;
    r = ob.substringCounter("b", 4, 12, 3);
    cout << r[0] << " " << r[1] << " " << r[2] << endl;
}
