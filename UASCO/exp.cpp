#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()	{
	pair<int, char> s;
	s = make_pair(4, 'r');
	cout << s.first << " " << s.second << endl;
}