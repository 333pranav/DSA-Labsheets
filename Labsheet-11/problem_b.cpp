#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    int b[m];
    for(int i = 0; i < m; i++) cin >> b[i];
    int maxlen = 0;
    int dp[n+1][m+1];
    for(int i = 0; i < n + 1; i++)
    {
        for(int j = 0; j < m + 1; j++) dp[i][j] = 0;
    }
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = m - 1; j >= 0; j--)
        {
            if(a[i] == b[j]) dp[i][j] = dp[i+1][j+1] + 1;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++) maxlen = max(maxlen, dp[i][j]);
    }
    cout << maxlen << "\n";
    return 0;
}
