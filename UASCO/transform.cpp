/*
ID: bhupesh1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define pb push_back

using namespace std;

void rotatoryClub(vector<string> &square, int &count)
{
	string temp;
	temp = square[0];
	for(int i = 0; i )
}

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int n, count;
    cin >> n;
    vector<string> square.resize(n);
    for(int i = 0; i < n; i++)
    	cin >> square[i];

   	rotatoryClub(square, count)

    return 0;
}

