/*
Author :- Bhupesh Kumar
Dated :- 12Dec2013
*/

#include <iostream>

using namespace std;

int min(int n, int m, int k[100][100], int col)
{
    if(m == 0)
        return (k[n][0] > k[n][1])?k[n][1]:k[n][0];
    if(m == (col - 1))
        return (k[n][m] > k[n][m - 1])?k[n][m - 1] : k[n][m];
    int x, y, z;
    x = (k[n][m] > k[n][m - 1])? k[n][m - 1] : k[n][m];
    y = (x > k[n][m + 1]) ? k[n][m + 1] : x;
    return y;
}

int main()
{
    int n, m;
    int i, j, s, t;
    cin >> n >> m;
    int dp[100][100], k[100][100];
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            cin >> k[i][j];

    for(i = 0; i < m; i++)
        dp[n - 1][i] = k[n - 1][i];

    for(i = n - 2; i >= 0; i--)
    {
        for(j = 0; j < m; j++)
        {
            dp[i][j] = min(i + 1, j, dp, m) + k[i][j];
        }
    }
    s = dp[0][0];
    for(i = 1; i < m; i++)
    {
        //cout << dp[0][i] <<  " ";
        if(s > dp[0][i])
            s = dp[0][i];
    }
    cout << s << endl;
    return 0;
}
