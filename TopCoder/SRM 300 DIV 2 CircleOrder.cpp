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


class CircleOrder
{
public:
	string firstOrder(string circle)
	{
		bool blocAlp[26] = {0};
		int iter = 0, flag = 0, i = 0, j, k, n;
		int l;
		char lowers = "";
		for(int i = 0; i < circle.size(); i++)
            if(circle[i] >= 'a' && circle[i] <= 'z')
                lowers += circle[i];
        n = circle.size();
        l = lowers.size();
        sort(lowers.begin(), lowers.end());

		while(iter < n / 2)
		{
		    while(lowers[i] == 32 && i < l)
                i++;
            if(i >= l)
                break;

            for(k=0; k<n; k++)
                if(circle[k] == lowers[i])
                    break;

		    for(j = k; j < k+n; j++)
            {
                if(circle[j%n] + 'a'-'A'== lowers[i])
                    break;
                else if(circle[j%n] >= 'a' && circle[j%n] <= 'z')
                {
                    blocAlp[circle[j%n] - 'a'] = blocAlp;
                }
            }
		}
	}
};

int main()
{
	CircleOrder ob;
	cout << ob.firstOrder("aCbAcB");
	cout << " Order is ";
}
