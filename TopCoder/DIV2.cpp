#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

class PowerOfThreeEasy
{
    public:

    string ableToGet(int x, int y)
    {
        string po = "Possible", im = "Impossible";
        int count = 0;
        long long a, b, c, d, theePow;
        a = (long long )x;
        b = (long long )y;
        while(1)
        {
            cout << a << " " << b << endl;
            if(a == 0 && b == 0)
                return po;
            if(a < 0 || b < 0)
                return im;

            theePow = pow(3, count);

            if(!a)
                b = b - theePow;
            else if(!b)
                a = a - theePow;
            else
            {
                if(a % (theePow*3) == 0 && b % (theePow*3) != 0)
                    b = b - theePow;
                else
                    a = a - theePow;
            }
            count++;
        }
    }
};

int main()
{
    PowerOfThreeEasy ob;
    cout << ob.ableToGet(1, 3);
}
