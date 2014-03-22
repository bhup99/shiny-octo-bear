#include<iostream>
#include<sstream>
#include<string.h>

using namespace std;

class Time
{
    public:
    string whatTime(int seconds)
    {
        string out;
        int hh, mm, s;
        s = seconds%60;
        seconds = seconds / 60;
        mm = seconds % 60;
        hh = seconds / 60;
        stringstream ss;
        ss << hh << ":" << mm << ":" << s ;
        out = ss.str();
        return out;
    }
};
int main()
{
    Time test;
    string result;
    result = test.whatTime(3661);
    cout << result;
}
