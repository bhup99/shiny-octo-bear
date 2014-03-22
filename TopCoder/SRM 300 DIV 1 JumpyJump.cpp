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
#include <cstdio>

using namespace std;

#define ll long long
#define pb push_back
#define fl(i, n, m)		for(int i=n; i<m; i++)

class JumpyNum
{

    int countMany(string l, string h, int len, int index, int start)
    {
        if(len == l.size())
        {
            if(index == l.size())
            for(int i = start; i <'9'; i++)
            {
                countMany(l, h, len, index+1, i);
            }
        }
        else if(len == h.size())
        {

        }
        else
        {

        }
    }
    public:

    int howMany(int low, int high)
    {
        ostringstream ss;
        string l, h;
        ss << low;
        l = ss.str();
        ss << high;
        h = ss.str();
        for(int i = l.size(); i <= h.size(); i++)
            countMany(l, h, i, 0, l[0]);
    }
};
