#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

typedef struct link
{
    int sum;
    struct link *next, *pre;
}list;

class VendingMachine
{
    int calColLen(string s)
    {
        int n, i = 0;
        istringstream ss(s)
        while(ss >> n)
        {
            i++;
        }
        return i;
    }

    public:

    list *head;
    VendingMachine()
    {
        head = NULL;
    }
    int motorUse(vector <string> prices, vector <string> purchases)
    {
        int columnSum[50] = {0}, rowLen = 0, colLen = 0;
        int i, j, n;
        rowLen = prices.size();
        colLen = calColLen(prices[0]);
        for(i = 0; i < row; i++)
        {
            j = 0;
            istringstream ss(prices[i]);
            while(ss >> n)
            {
                columnSum[j] += n;
                j++;
            }
        }
        manageList(head)
    }
}

