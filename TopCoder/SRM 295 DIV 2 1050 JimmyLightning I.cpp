#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

typedef struct
{
    int value, theftTime, roomNo;
}infoDiamond;;

class JimmyLightning
{
    public:

    int dp[10000];

    int robTheBank(vector <int> doors, vector <string> diamonds)
    {
        vector<int> maxStayingTime;
        vector<infoDiamond> d;
        d.resize(diamonds.size());
        maxStayingTime.resize(doors.size());

        dp[0] = 0;
        for(int i = 0; i < diamonds.size(); i++)
        {
            stringstream ss(diamonds[i]);
            ss >> d[i].value >> d[i].theftTime >> d[i].roomNo;
        }

        for(int i = 0; i < doors.size(); i++)
        {
            if(i == 0)
                maxStayingTime[i] = doors[i];
            else
                maxStayingTime[i] = min(maxStayingTime[i - 1], doors[i]);
        }

        for(int i = 1; i < 10000; i++)
        {
            dp[i] = dp[i - 1];
            for(int j = 0; j < diamonds.size(); j++)
            {
                if(d[j].theftTime <= i && maxStayingTime[d[j].roomNo - 1] > i)
                    dp[i] = max(dp[i], dp[i - d[j].theftTime] + d[j].value);
            }
        }

        cout << maxStayingTime[0] << endl;
        for(int i = 0; i < 7; i++)
            cout << dp[i] << " ";
        cout << endl;
        return dp[9999];
    }
};

int main()
{
    vector<int> door;
    door.push_back(1000);

    vector<string> diamonds;
    diamonds.clear();
    JimmyLightning ob;

    cout << endl << ob.robTheBank(door, diamonds);
}
