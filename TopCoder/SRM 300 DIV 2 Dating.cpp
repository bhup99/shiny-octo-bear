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

class Dating
{
public:
    string dates(string circle, int k)
    {
        char hottest;
        std::string::iterator it;
        string res = "";
        int i = 0, x, y, n;
        n = circle.size();
        while(n != 0)
        {

            i = i+k-1;
            i = i%n;
            cout << i << " " << endl;
            x = circle[(i+1)%n];
            y = circle[(i+2)%n];
            hottest = 127;
            fl(j, 0, circle.size())
            {
                if(circle[i] >= 'a' && circle[i] <= 'z')
                {
                    if(circle[j] >= 'A' && circle[j] <= 'Z' && circle[j] < hottest)
                        hottest = circle[j];
                }
                else
                {
                    if(circle[j] >= 'a' && circle[j] <= 'z' && circle[j] < hottest)
                        hottest = circle[j];
                }
            }
            if(hottest == 127)
                return res;
            if(res.size() != 0)
                res += ' ';
            cout << circle[i] << " " << hottest << " " << circle << endl;
            res += circle[i];
            res += hottest;
            circle.erase(circle.begin()+i);
            circle.erase(find(circle.begin(), circle.end(), hottest));
            cout << circle << endl;

            for(i = 0; i < circle.size(); i++)
                if(circle[i] == x)
                    break;
            if(i == circle.size())
                for(i = 0; i < circle.size(); i++)
                    if(circle[i] == y)
                        break;
            cout << i << endl;
            //cout << res << " " << i << endl;
            n = circle.size();
        }
        return res;
    }
};

int main()
{
    Dating ob;
    cout << ob.dates("ABCDEFGHIJKLMNOPQRSTUVWXYabcdefghijklmnopqrstuvwxy", 100);
}
