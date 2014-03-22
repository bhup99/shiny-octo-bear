#include <iostream>
#include <vector>

using namespace std;

class FoxConnection2
{
    int s, K, n;
    vector<int> A1, B1, block;
    public:

    long long fun(int s, int K)
    {
        long long count = 0;
        if(K == 0)
            return 1;
        for(int i = 0; i < n; i++)
        {
            if(block.find(A1[i]) < n)
            {
                block.push_back(A[i]);
                block.push_back(B[i]);
                count += fun(B1[i], K - 1);
                block.pop_back();
                block.pop_back();
                count = count % 1000000007;
            }
        }
        return count;
    }

    int ways(vector <int> A, vector <int> B, int k)
    {
        vector<int> p;
        long long count = 0;
        n = A.size();

        for(int i = 0; i < n + 1; i++)
        {
            p.push_back(0);
        }

        for(int i = 0; i < n; i++)
            p[B[i] - 1] = A[i];

        for(int i = 0; i < n; i++)
            if(p[i] == 0)
            {
                s = i + 1;
                break;
            }

        A1 = A;
        B1 = B;
        K = k;

        for(int i = 0; i < n; i++)
        {
            block.push_back(A[i]);
            block.push_back(B[i]);
            count += fun(A[i], k - 1);
            block.pop_back();
            block.pop_back();
            count = count % 1000000007;
        }

        return (int) count;

    }
};

int main()
{
    vector<int> a, b;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    b.push_back(2);
    b.push_back(3);
    b.push_back(4);
    FoxConnection2 ob;
    cout << ob.ways(a, b, 2);
}
