#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class PowerOutage
{
    int adjacencyList[50][50];
    int fromTo[50][50];
    int flag[50];
    int i, j, n;

    public:

    PowerOutage()
    {
        for(i = 0; i < 50; i++)
            for(j = 0; j < 50; j++)
                fromTo[i][j] = adjacencyList[i][j] = -1;

        for(i = 0; i < 50; i++)
            flag[i] = 0;
    }


    int lengthOfPath(int s, vector<int> toJunction)
    {
        int k, min = 0;
        for(k = s; k < n; k++)
        {
            if(adjacencyList[s][toJunction[k]] >= 0)
                fromTo[s][toJunction[k]] = lengthOfPath(k, toJunction) + adjacencyList[s][toJunction[k]];
        }
        for(k = 0; k < n; k++)
            if(min > fromTo[s][k] && fromTo[s][k] > 0)
                min = fromTo[s][k];
        return (min <0) ? 0 : min ;
    }

    int checkOut(stack<int> s)
    {
        while(!s.empty())
        {
            if(flag[s.top()] == 0)
                return 1;
            s.pop();
        }
        return 0;
    }

    int estimateTimeout(vector<int> fromJunction, vector<int> toJunction, vector<int> ductLength)
    {
        int min = 100, timeTaken = 0;
        stack<int> s;

        n = fromJunction.size();
        for(i = 0; i < n; i++)
            adjacencyList[fromJunction[i]][toJunction[i]] = ductLength[i];

        for(i = 0; i < n; i++)
        {
            s.push(toJunction[i]);
            if(adjacencyList[0][toJunction[i]] >= 0)
                fromTo[0][toJunction[i]] = lengthOfPath(i, toJunction) + adjacencyList[0][toJunction[i]];
        }

        for(i = 0; i <= n; i++)
        {
            for(j = 0; j <= n; j++)
                cout << fromTo[i][j] << " ";
            cout << endl;
        }

        adjacencyList[0][0] = 0;
        for(j = 0; j < 3; j++)
        {
            timeTaken += adjacencyList[0][min];
            for(i = 0; i < n; i++)
                if(adjacencyList[0][i] < min && adjacencyList[0][i] >= 0)
                    min = i;
            timeTaken += adjacencyList[0][min];
            cout << "Hi!!!" << endl;
        }
    }
};

int main()
{
    PowerOutage ob1;
    vector<int> fromJunction, toJunction, ductLength;
    fromJunction.push_back(0);
    fromJunction.push_back(1);
    fromJunction.push_back(0);
    toJunction.push_back(1);
    toJunction.push_back(2);
    toJunction.push_back(3);
    ductLength.push_back(10);
    ductLength.push_back(10);
    ductLength.push_back(10);
    ob1.estimateTimeout(fromJunction, toJunction, ductLength);
}
