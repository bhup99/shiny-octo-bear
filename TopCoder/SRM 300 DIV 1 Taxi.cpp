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
#include <math.h>

using namespace std;

#define ll long long
#define pb push_back
#define fl(i, n, m)		for(int i=n; i<m; i++)

class Taxi
{
public:
    double maxDis(int maxX, int maxY, int taxiDis)
    {
        if(maxX + maxY < taxiDis)
            return -1;
        ll a, b=0;
        double d;
        a = (ll)max(maxX, maxY);
        if(a != maxX)
            maxX = maxX + maxY - (maxY = maxX);
        a = (ll)min(maxX, taxiDis);
        if(a == maxX)
            b = taxiDis - a;
        d = sqrt(a*a + b*b);
        return d;

    }
};

int main()
{
    Taxi ob;
    cout << ob.maxDis(976421,976421,1000000);
}
