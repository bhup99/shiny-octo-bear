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


class TaroCards
{
    int store[51];
    ll s;
    public:
    TaroCards()
    {
        for(int i = 0; i <= 50; i++)
            store[i] = 0;
        s = 0;
    }

    void cun(vector<int>& first, vector<int>& second, int K, int index)
    {
        int tot = 0, x, y;
        if(index >= first.size())
        {
            for(int i=0; i <= 50; i++)
                if(store[i])
                    tot++;
            if(tot < K)
                s++;
        }
        cun(first, second, K, index+1);
        store[first[index]] = 1;
        store[second[index]] = 1;
        cun(first, second, K, index+1);
    }

    long long getNumber(vector <int> first, vector <int> second, int K)
    {
        cun(first, second, K, 0);
        return s;
    }
};


int main()
{
    TaroCards ob;
    vector<int> a, b;
    a.pb(1);
    a.pb(2);
    b.pb(2);
    b.pb(3);
    cout << ob.getNumber(a, b, 2);
}
