#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;


vector<ll> CountInterval(int n) {                       // returns number of overlaps of all inclusive points
    vector<pair<ll, int> >v;                            // segments start/end and marker (segments are l - r inclusive)
    vector<ll>ret(n+1);                                 // returns : ret[number_of_overlaps] = total_number_of_points
    ll l, r;
    while(n--) {
        cin >> l >> r;                                  // input
        v.push_back({l, 1}), v.push_back({r+1, -1});    // r+1 as l - r is segment boundary
    }
    sort(v.begin(), v.end());
    for(int i = 0, cnt = v[0].second; i < (int)v.size(); ++i, cnt += v[i].second)       // cnt contains the overlaps
        if(i+1 < (int)v.size() and v[i].first != v[i+1].first)                          // v[i].first == v[i+1].first then 
            ret[cnt] += v[i+1].first - v[i].first;                      // there may exist more points at front, so take them first
    return ret;
}

int main() {
    int n;
    cin >> n;
    
    vector<ll> ret = CountSegment(n);
    
    for(int i = 1; i < (int)ret.size()-1; ++i)
        cout << ret[i] << " ";
    cout << ret[n] << "\n";
    return 0;
}
