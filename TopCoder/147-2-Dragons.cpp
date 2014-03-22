#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct
{
    long long numer, denom;
}fraction;

class Dragons
{
    public:

    inline string get(long long num)
    {
        if(num == 0)    return "0";
        string res; res.clear();
        while(num)
        {
            res = char(num % 10 + '0') + res;
            num = num / 10;
        }
        return res;
    }

    string snaug(vector <int> initialFood, int rounds)
    {
        if(!rounds) return get(initialFood[2]);
        long long a, b, c, denom = 1;
        a = initialFood[2] + initialFood[3] + initialFood[4] + initialFood[5];
        b = initialFood[0] + initialFood[1] + initialFood[4] + initialFood[5];
        c = initialFood[0] + initialFood[1] + initialFood[2] + initialFood[3];
        denom = 4;

        for(int i = 1; i < rounds; i++)
        {
            long long sa=a, sb=b, sc=c;
            a = sb + sc;
            b = sa + sc;
            c = sa + sb;
            denom *= 2;
        }
        long long gcd = __gcd(b, denom);
        b = b / gcd;
        denom = denom / gcd;

        if(denom == 1)
            return get(b);
        else
            return get(b) + "/" + get(denom);

    }
};

int main()
{
    vector<int> a;
    string snaug;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    Dragons ob;
    snaug = ob.snaug(a, 45);        //7 / 2
    cout << snaug;
}
