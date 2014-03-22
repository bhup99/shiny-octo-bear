#include <iostream>
#include <vector>

using namespace std;

class Chooser
{
    public:

    int numSets(vector <int> param0, vector <int> param1, vector <int> param2)
    {
        int sum = 0, count = 0;
        int i, j, k;
        i = j = k = 0;
        for(i = 0; i < param0.size(); i++)
            for(j = 0; j < param1.size(); j++)
                for(k = 0; k < param2.size(); k++)
                {
                    sum = param0[i] + param1[j] + param2[k];
                    if(sum >= 60 && sum <= 75)
                        count++;
                }

        return count;
    }
};
