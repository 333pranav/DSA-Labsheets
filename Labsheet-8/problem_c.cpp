#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int x, y;
    cin >> x >> y;
    int ans = 0;
    map <int, int> mp;
    for(int i = n - 1; i > 0; i--)
    {
        mp[a[i] - y * i]++;
        ans += mp[a[i - 1] - x * (i - 1)]; 
    }
    cout << ans << "\n";
}