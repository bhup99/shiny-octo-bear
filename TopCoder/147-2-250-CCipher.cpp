#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CCipher
{
    public:
    string decode(string cipherText, int shift)
    {
        int decipher;
        string out = "";
        for(int i = 0; i < cipherText.size(); i++)
        {
            decipher = (int)(cipherText[i] - 'A');
            decipher = ((decipher - 2) % 26 + 26) % 26;
            decipher += 'A';
            out += (char)decipher;

        }
        return out;
    }
};
