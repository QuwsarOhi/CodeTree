#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll v[500100];
map<ll, vector<pair<ll, ll> > >Map;
set<pair<ll, ll> >Set;

bool Overlap(ll l, ll r) {
    auto it = Set.lower_bound({l, -1});
    
    
    if(it != Set.end()) {
        //if(it->first <= l and l <= it->second)
        //    return 0;
        //else if(it->first <= r and r <= it->second)
        //    return 0;
        if(it->second <= r)
            return 0;
    }
    
    Set.insert({r, l});
    return 1;
}
    

int main() {
    ll n, k;
    cin >> k >> n;
    
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    
    sort(v, v+n);
    
    map<ll, ll>TTTT;
    int TT = 0;
    for(int i = 0; i < n; ++i)  TTTT[v[i]];
    for(auto it = TTTT.begin(); it != TTTT.end(); ++it)
        it->second = ++TT;
    
    for(int i = 0; i+1 < n; ++i)
        Map[v[i+1] - v[i]].push_back({TTTT[v[i+1]], TTTT[v[i]]});
    
    for(auto it : Map) {
        cout << it.first << " :";
        for(auto it2 : it.second)
            cout << " [" << it2.first << " , " << it2.second << "]";
        cout << endl;
    }
    
    ll Ans = 0, skips = 0;
    while(1) {
        cout << "START " << Ans << " " << skips << endl;
        int cnt = 0, skp = 0;
        for(auto it1 : Map) {
            for(auto it2 : it1.second) {
                if(skp < skips) {
                    ++skp;
                    continue;
                }
                if(cnt == k) break;
                if(Overlap(it2.second, it2.first)) {
                    ++cnt;
                    cout << "Range " << it2.first << " " << it2.second << endl;
                    Ans += it1.first;
                }
            }
            if(cnt == k) break;
        }
        if(cnt != k)
            ++skips, Ans = 0;
        else
            break;
        getchar();
    }
    
    cout << Ans << endl;
    return 0;
}
