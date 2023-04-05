#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    make_heap(v.begin(), v.end());
    long long sum = 0;
    for(int i = 0; i < k; i++)
    {
        int given = ceil(v[0] / 2.0);
        v[0] -= given;
        sum += given;
        make_heap(v.begin(), v.end());
    }
    cout << sum << endl;
    return 0;
}