#include <iostream>

using namespace std;

class EratosthenSieve2
{
    public:
    int nthElement(int n)
    {
        int N[1000];
        for(int i = 0; i < 1000; i++)
            N[i] = 1;

        int count = 0;
        for(int i = 1; i < 10; i++)
        {
            count = 0;
            for(int j = 0; j < 1000; j++)
            {
                if(count == i && N[j] == 1)
                    count = N[j] = 0;
                if(N[j] == 1)
                    count++;
            }
        }

            for(int j = 0; j < 1000; j++)
                if(N[j] == 1)
                    cout << j + 1 << " ";
            cout << endl;
        count = 0;
        int i;
        for(i = 0; i < 1000; i++)
        {
            if(count == n - 1 && N[i] == 1)
                break;

            if(N[i] == 1)
                count++;
        }
        return i + 1;
    }
};

int main()
{
    EratosthenSieve2 ob;
    cout << ob.nthElement(25);
}
