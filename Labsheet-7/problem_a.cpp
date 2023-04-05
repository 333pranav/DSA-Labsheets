#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    make_heap(v.begin(), v.end());
    for(int i = 0; i < m; i++)
    {
        v[0] /= 2;
        make_heap(v.begin(), v.end());
    }
    long long sum = 0;
    for(int x: v) sum += x;
    cout << sum << endl;
    return 0;
}