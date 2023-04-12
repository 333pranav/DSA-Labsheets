#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    set<int> oneLoss;
    set<int> dq;
    for(int i = 0; i < n; i++)
    {
        int w, l;
        cin >> w >> l;
        if(!oneLoss.count(l)) oneLoss.insert(l);
        else dq.insert(l);
    }
    for(int i = 0; i < k; i++) if(!dq.count(i+1)) cout << i + 1 << " ";
}