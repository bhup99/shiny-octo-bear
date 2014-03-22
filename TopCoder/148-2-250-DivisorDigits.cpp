#include <iostream>

using namespace std;

class DivisorDigits
{
    public:

    int howMany(int number)
    {
        int r, d, count = 0;
        r = number;
        while(r)
        {
            d = number % 10;
            if(d != 0)
            {
                if(number % d == 0)
                    count++;
            }
            r = r / 10;
        }
        return count;
    }
};
