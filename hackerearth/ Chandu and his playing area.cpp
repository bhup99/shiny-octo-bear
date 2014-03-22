#include <iostream>

using namespace std;

int main()
{
	int test, n;
	cin >> test;

	for(int i = 0; i < test; i++)
	{
		cin >> n;
		int half = n / 2, one, two;
		one = two = half / 2;
		if(half%2 != 0)
		{
			two++;
		}
		cout << one * two << endl;
	}
}