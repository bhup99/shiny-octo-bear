#include <stdlib.h>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

class BridgeCrossing
{
    public:

    int minTime(vector <int> times)
    {
        int n;
        n = times.size();
        vector<int> otherSide;
        sort(times.begin(), times.end());
        otherSide.resize(n);
        otherSide[0] = times[0];
        otherSide[1] = times[1];
        for(int i = 2; i < n; i++)
        {
            otherSide[i] = min(otherSide[i - 1] + times[0] + times[i],
                                    otherSide[i - 2] + times[1] * 2 + times[0] + times[i]);
        }
        return otherSide[n - 1];
    }
};

int main()
{
    vector<int> a;
    a.push_back(10);
    a.push_back(1);
    a.push_back(10);
    a.push_back(10);
    a.push_back(10);
    //a.push_back(100);

    /*a.push_back(1);
    a.push_back(2);
    a.push_back(5);
    a.push_back(10);*/
    BridgeCrossing ob;
    cout << ob.minTime(a);
}
