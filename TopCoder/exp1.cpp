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

class TaroFriends
{
    public:
    int getNumber(vector <int> coordinates, int X)
    {
        int n = coordinates.size(), mid=100000002;
        int lefty = 100000001, righty = -100000001;
        float mean=0;
        for(int i = 0; i < n; i++)
            mean += coordinates[i];
        mean = mean / n;
        for(int i=0; i<n; i++)
        {
            if(coordinates[i] == (int)mean)
                mid = coordinates[i];
            else if(coordinates[i] > mean)
                coordinates[i] -= X;
            else if(coordinates[i] < mean)
                coordinates[i] += X;
        }

        for(int i = 0; i < n; i++)
        {
            if(lefty > coordinates[i])
                lefty = coordinates[i];
            if(righty < coordinates[i])
                righty = coordinates[i];
        }
        cout << lefty << " " << righty << " " << coordinates[0] << endl;
        if(mid != 100000002)
        {
            if(abs(mid-lefty) > abs(mid-righty))
                mid -= X;
            else
                mid += X;
        }
        cout << mid << endl;
        if(lefty > mid && mid != 100000002)
            lefty = mid;
        if(righty < mid && mid != 100000002)
            righty = mid;
        return abs(righty - lefty);
    }
};

int main()
{
    TaroFriends ob;
    vector<int> v;
    v.pb(4);
    v.pb(7);
    v.pb(-7);
    cout << ob.getNumber(v, 5);
}
