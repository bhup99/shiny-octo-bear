#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class NewAlbum
{
    public:

    int leastAmountOfCDs(int nSongs, int length, int cdCapacity)
    {
        if(length > cdCapacity)
            return 0;

        int countS = 1, cdCount = 0;

        cdCapacity -= length;
        length++;
        countS += min(cdCapacity/length, nSongs-1);
        cout << countS;
        if(countS%13 == 0)
            countS--;
        cdCount = nSongs/countS + (nSongs%countS != 0);
        cout << endl << cdCount << endl;
        if((nSongs%countS != 0) && (nSongs%countS)%13 == 0)
        {
            int leftOver = cdCapacity - (nSongs%countS)*length;
            if((countS-1)%13 == 0)
            {
                if(2*length > leftOver)
                    cdCount++;
            }
        }
        return cdCount;
    }
};


int main()
{
    NewAlbum ob;
    cout << ob.leastAmountOfCDs(100, 10000, 10000);
}
