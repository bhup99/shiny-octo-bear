#include <iostream>
#include <vector>

using namespace std;

class BigBurger
{
    public:

    int maxWait(vector <int> arrival, vector <int> service)
    {
        int wait = 0, curTime = arrival[0], maxTime = 0;
        for(int i = 0; i < arrival.size() - 1; i++)
        {
            if(curTime > arrival[i])
                curTime = arrival[i];
            curTime += service[i];
            wait = (curTime > arrival[i + 1]) ? curTime - arrival[i + 1] : 0;
            maxTime = max(wait, maxTime);
        }
        return maxTime;
    }
};
