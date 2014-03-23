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

class TaroString
{
    public:
    string getAnswer(string S)
    {
        int flag = 0;
        for(int i = 0; i < S.size(); i++)
        {
            if(flag == 1)
                flag = i = 0;
            if(S[i] == 'C' || S[i] == 'A' || S[i] == 'T')
                continue;
            cout << S << " " << i << endl;
            S.erase(S.begin()+i);
            flag = 1;
        }
        cout << S << endl;
        if(S == "CAT")
            return "Possible";
        else
            return "Impossible";
    }
};

int main()
{
    TaroString ob;
    cout << ob.getAnswer("NOKCVFJFRMXOHAOWKBJZWUTWLJFRIMPMYHHZRIWKBRXBGFBEYH");
}
