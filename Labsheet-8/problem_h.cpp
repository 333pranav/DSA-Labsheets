#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    set <string> subs;
    set <string> repeated;
    int ans = 0;
    for(int i = 0; i < s.length() - 9; i++)
    {
        string sub = s.substr(i, 10);
        if(subs.count(sub) && !repeated.count(sub)) 
        {
            repeated.insert(sub);
            ans++;
        }
        else subs.insert(sub);   
    }
    cout << ans << "\n";
    for(string x: repeated) cout << x << "\n";
}