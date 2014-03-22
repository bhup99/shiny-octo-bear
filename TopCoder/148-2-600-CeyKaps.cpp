#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CeyKaps
{
    public:

    string decipher(string typed, vector <string> switches)
    {
        int ind1, ind2;
        string corOut = "";
        char alpha[26], temp;;
        for(int i = 0; i < 26; i++)
            alpha[i] = 'A' + i;

        for(int i = 0; i < switches.size(); i++)
        {
            ind1 = switches[i][0] - 'A';
            ind2 = switches[i][2] - 'A';
            while(alpha[ind1] != switches[i][0])
                ind1 = alpha[ind1] - 'A';

            while(alpha[ind2] != switches[i][2])
                ind2 = alpha[ind2] - 'A';

            temp = alpha[ind1];
            alpha[ind1] = alpha[ind2];
            alpha[ind2] = temp;
        }

        for(int i = 0; i < typed.size(); i++)
        {
            corOut += alpha[typed[i] - 'A'];
        }
        return corOut;
    }
};
