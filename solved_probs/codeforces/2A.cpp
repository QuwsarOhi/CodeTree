// Codeforces
// A. Winner
// http://codeforces.com/problemset/problem/2/AA

#include <bits/stdc++.h>
using namespace std;

/*
5
a 11
b 5
a -5
b 5
a 4
*/


int main() {
    vector<pair<string, int> >v;
    unordered_map<string, int>mp[1010];
    int n, mx = -1e6, x;
    string s;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> s >> x;
        v.push_back({s, x});
    }

    for(int i = 0; i < n; ++i) {
        if(i == 0)
            mp[i][v[i].first] += v[i].second;
        else {
            for(auto it : mp[i-1]) {
                mp[i][it.first] += it.second;
            }
            mp[i][v[i].first] += v[i].second;
        }
    }

    for(auto it : mp[n-1])
        mx = max(it.second, mx);

    unordered_map<string, bool>winner;

    for(auto it : mp[n-1]) {
        if(it.second == mx) {
            winner[it.first] = 1;
        }
    }

    for(int i = 0; i < n; ++i) {
        for(auto it : mp[i]) {
            if(it.second >= mx && winner[it.first]) {
                cout << it.first << endl;
                return 0;
            }
        }
    }

    return 0;
}
