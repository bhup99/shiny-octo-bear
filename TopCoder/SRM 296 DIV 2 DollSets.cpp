#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class DollSets
{
    public:

    int maximumQuantity(vector<int> dollSizes, int K)
    {
        sort(dollSizes.begin(), dollSizes.end());
        int x, c = 0;
        for(int i = 0; i < dollSizes.size(); i++)
        {
            x = dollSizes[i];
            if(find(dollSizes.begin(), dollSizes.end(), (x*K)) != dollSizes.end())
            {
                c++;
                dollSizes.erase(find(dollSizes.begin(), dollSizes.end(), (x*K)));
            }
        }
        return c;
    }
}
