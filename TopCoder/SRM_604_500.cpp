/*Fox Ciel has a robot. The robot is located on an infinite plane. At the beginning, the robot starts at the coordinates (0, 0). The robot can then make several steps. The steps are numbered starting from 0.  In each step, Ciel must choose one of two directions for the robot: right (x coordinate increases) or up (y coordinate increases). In step k, the robot will move 3^k units in the chosen direction. It is not allowed to skip a step.  You are given ints x and y. Return "Possible" (quotes for clarity) if it is possible that the robot reaches the point (x,y) after some (possibly zero) steps. Otherwise, return "Impossible".*/

#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <stdio.h>
#include <stack>
#include <memory.h>

using namespace std;

map<pair<int,int>, bool> mp;

class PowerOfThreeEasy
{
    public:

    void dfs(long long x, long long y, long long thee)
    {
        if(x > 1000000000 || y > 1000000000)
            return;
        mp[make_pair(x, y)] = 1;
        dfs(x + thee, y, thee*3);
        dfs(x, y + thee, thee*3);
    }

    string ableToGet(int x, int y)
    {
        dfs(0, 0, 1);
        if(mp[make_pair(x, y)] == 1)
            return "Possible";
        return "Impossible";
    }
};

int main()
{
    PowerOfThreeEasy ob;
    cout << ob.ableToGet(1029, 729*3);
}

