/*
ID: bhupesh1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    int p = 1, q = 1;
    string a, b;
    fin >> a >> b;
    for(int i = 0; i < a.size(); i++)
        p *= a[i] - 'A' + 1;
    for(int i = 0; i < b.size(); i++)
        q *= b[i] - 'A' + 1;
    p = p % 47;
    q = q % 47;
    if(p == q)
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;
    return 0;
}

