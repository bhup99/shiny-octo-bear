#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MNS
{
    public:

    bool validCheck(vector<int> numbers)
    {
        int a = numbers[0] + numbers[1] + numbers[2];
        int b = numbers[3] + numbers[4] + numbers[5];
        int c = numbers[6] + numbers[7] + numbers[8];

        int x = numbers[0] + numbers[3] + numbers[6];
        int y = numbers[1] + numbers[4] + numbers[7];
        int z = numbers[2] + numbers[5] + numbers[8];

        return (a == b && b == c && x == y && y == z);
    }

    int combos(vector <int> numbers)
    {
        sort(numbers.begin(), numbers.end());
        int check = 0;

        do
        {
            check += validCheck(numbers);
        }while(next_permutation(numbers.begin(), numbers.end()));

        return check;
    }
};

