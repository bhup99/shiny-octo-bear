#include <iostream>

using namespace std;

int main()
{
	int test, n;
	cin >> test;

	for(int i = 0; i < test; i++)
	{
		cin >> n;
		cout << n*n + (n *(n - 1)*(n + 1)) / 6 << endl;
	}
	return 0;
}