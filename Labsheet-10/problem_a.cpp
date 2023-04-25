#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() //Uses Kadane's Algorithm
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    long long sum = 0, tempsum = 0;
    for(int x: a)
    {
        tempsum = max((long long)0, tempsum+x);
        sum = max(sum, tempsum);
    }
    cout << sum << "\n";
    return 0;
}
