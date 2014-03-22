#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class JimmyLightning
{
    public:
    vector<int> roomNo, value, theftTime, maxStayingTime;
    vector<int> copyDoor;
    int n, timeCount;

    int show()
    {
        for(int i = 0; i < n; i++)
            cout << "\"" << roomNo[i] << " " << value[i] << " " << theftTime[i] << "\"" << endl;

        cout << "Max Staying Time :-" ;
        for(int i = 0; i < n; i++)
            cout << maxStayingTime[i] << " ";

        cout << endl << endl;
    }

    void insertionSort()
    {
        int j, key;
        for(int i = 1; i < n; i++)
        {
            j = i - 1;
            key = value[i];
            while(j >= 0 && value[j] / theftTime[j] > value[j + 1] / theftTime[j + 1])
            {
                value[j + 1] = value[j] + value[j + 1] - (value[j] = value[j + 1]);
                roomNo[j + 1] = roomNo[j] + roomNo[j + 1] - (roomNo[j] = roomNo[j + 1]);
                theftTime[j + 1] = theftTime[j] + theftTime[j + 1] - (theftTime[j] = theftTime[j + 1]);
                j--;
            }

        }
    }

    int calMaxDiamond(int iter)
    {
        int count;
        int doorOpening;
        maxStayingTime[roomNo[iter] - 1] -= timeCount;
        copyDoor[roomNo[iter] - 1] -= timeCount;
        doorOpening = min(maxStayingTime[roomNo[iter] - 1], copyDoor[roomNo[iter] - 1]);
        doorOpening = max(0, doorOpening);

        count = doorOpening / theftTime[iter];
        cout << maxStayingTime[roomNo[iter] - 1] << " " << copyDoor[roomNo[iter] - 1] << " " << doorOpening << " " << theftTime[iter] << endl;
        cout << count << " ";
        timeCount += count * theftTime[iter];
        count = count * value[iter];
        if(copyDoor[roomNo[iter] - 1] % theftTime[iter] == 0 && count)
        {
            count -= value[iter];
            timeCount -= theftTime[iter];
        }
        cout << count << endl;
        return count;
    }


    int robTheBank(vector <int> doors, vector <string> diamonds)
    {
        roomNo.clear();
        value.clear();
        theftTime.clear();
        int x;
        copyDoor = doors;
        n = diamonds.size();
        cout << "N is " << n << endl;
        for(int i = 0; i < n; i++)
        {
            istringstream ss;
            ss.str(diamonds[i]);
            ss >> x;
            value.push_back(x);
            ss >> x;
            theftTime.push_back(x);
            ss >> x;
            roomNo.push_back(x);

            if(i == 0)
                maxStayingTime.push_back(doors[i]);
            else
                maxStayingTime.push_back(min(doors[i], maxStayingTime[i - 1]));

        }

        insertionSort();
        show();
        int totalDiamond = 0, iter = n - 1;
        timeCount = 0;
        while(iter >= 0)
        {
            totalDiamond += calMaxDiamond(iter);
            cout << totalDiamond << endl;
            iter--;
        }
        return totalDiamond;
    }
};

int main()
{
    vector<int> door;
    door.push_back(5);

    vector<string> diamonds;
    diamonds.push_back("6 1 1");
    diamonds.push_back("10 2 1");
    diamonds.push_back("12 3 1");
    JimmyLightning ob;

    cout << endl << ob.robTheBank(door, diamonds);
}
