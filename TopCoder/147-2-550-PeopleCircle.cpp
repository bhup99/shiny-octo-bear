#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PeopleCircle
{
    public:
    string order(int numMales, int numFemales, int K)
    {
        int n, start = 0, index, modu;
        string out = "";
        n = numMales + numFemales;
        for(int i = 0; i < n; i++)
        {
            out += "M";
        }

        for(int i = 0; i < numFemales; i++)
        {
            index = (K - 1) % (n - i);
            for(int j = 0; j < index; )
            {
                modu = (start) % n;
                if(out[modu] == 'M')
                {
                    j++;
                    start++;
                }
                else
                    start++;
            }
            while(out[start % n] == 'F')
                start++;
            out[start % n] = 'F';
            start++;
        }
        return out;
    }
};

int main()
{
    PeopleCircle ob;
    cout << endl << ob.order(25, 25, 1000);
}
