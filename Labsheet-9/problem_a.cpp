#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a; 
        arr[i] = a;
    }
    sort(arr, arr+n, greater<int>());
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum < 0)
        {
            cout << i;
            break;
        }
    }
    if (sum >= 0) cout << n;
    cout << "\n";
    return 0;
}