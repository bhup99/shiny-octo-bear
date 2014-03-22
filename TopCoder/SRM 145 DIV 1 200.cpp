#include <iostream>
#include <vector>

using namespace std;

typedef struct
{
    int index, value;
}helper;

class Bonuses
{
    public:

    void mergeSort(helper side[], int left, int mid, int right)
    {
        int n1, n2;                                                 // size of temporary variables
        helper l[1000], r[1000];                                           // temporary storage
        int i, j, k;                                                //iterative variables
        n1 = mid - left + 1;
        n2 = right - mid;
        for(i = 0; i <= n1; i++)
            l[i] = side[left + i];
        l[i].value = 100000000;

        for(i = 0; i <= n2; i++)
            r[i] = side[mid + i];
        r[i].value = 100000000;

        j = k = 0;
        for(i = left; i <= right; i++)
        {
            if(l[j].value < r[k].value)
                side[i] = r[k++];
            else
                side[i] = l[j++];
        }
    }

    void sort(helper side[], int left, int right)
    {
        if(left >= right)
            return;
        int mid;
        mid = (left + right) / 2;
        sort(side, left, mid);
        sort(side, mid + 1, right);
        mergeSort(side, left, mid, right);
    }

    vector<int> getDivision(vector<int> points)
    {
        helper side[1000];
        vector<int> out;
        int n, sum = 0, i, j, checkSum = 0;
        n = points.size();
        for(i = 0; i < n; i++)
        {
            sum += points[i];
            side[i].index = i;
            side[i].value = points[i];
        }
        sort(side, 0, n - 1);
        for(i = 0; i < n; i++)
        {
            out.push_back((points[i]*100) / sum);
            checkSum += (points[i] * 100) / sum;
        }
        checkSum = 100 - checkSum;
        for(i = 0; i < checkSum; i++)
        {
            out[side[i].index]++;
        }
        return out;
    }
};

int main()
{
    int i;
    Bonuses ob1;
    vector<int> points, out;
    points.push_back(1);
    points.push_back(2);
    points.push_back(3);
    points.push_back(4);
    points.push_back(5);
    out = ob1.getDivision(points);
    for(i = 0; i < out.size(); i++)
        cout << out[i] << endl;
}
