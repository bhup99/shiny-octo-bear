#include <iostream>

using namespace std;

class BuildBridge
{
    public:
    int howManyCards(int D, int L)
    {
        double sum = 0;
        int numer = 1;
        int denom = 2;
        int count = 0;

        while(sum < D)
        {
            sum += (numer * 1.0)/ denom;
            count++;
            denom += 2;
        }
        return count;
    }
};
