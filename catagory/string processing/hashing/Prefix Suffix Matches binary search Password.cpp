// Codeforces
// B. Password
// http://codeforces.com/problemset/problem/126/B

// Generate all Prefix and Suffix Match
// Then Binary search for the longest Match string using that Hash values

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll mod1 = 1e9+9, mod2 = 1e9+7, p = 31;

string s;
vector<pll>Hash, Power;
vector<pair<int, pll> >Match;

void PowerGen(int n) {
    Power.resize(n+1);
    Power[0] = {1, 1};
    
    for(int i = 1; i < n; ++i) {
        Power[i].first = (Power[i-1].first * p)%mod1;
        Power[i].second = (Power[i-1].second * p)%mod2;
    }
}

vector<pair<ll, ll> > doubleHash(string s, int len, ll mod1 = 1e9+9, ll mod2 = 1e9+7) {
    ll hashVal1 = 0, hashVal2 = 0;
    vector<pair<ll, ll> >v;
    
    for(int i = 0; i < len; ++i) {
        hashVal1 = (hashVal1 + (s[i] - 'a' + 1)* Power[i].first)%mod1;
        hashVal2 = (hashVal2 + (s[i] - 'a' + 1)* Power[i].second)%mod2;
        v.push_back({hashVal1, hashVal2});
    }
    
    return v;
}


// Returns True if the Hashval of length len exists in subrange [l, r] of Hash vector
bool MatchSubStr(int l, int r, vector<pll>&Hash, pll HashVal, int len) {
    for(int Start = l, End = l+len-1; End <= r; ++End, ++Start) {
        pll pattHash;
        pattHash.first = (HashVal.first*Power[Start].first)%mod1;
        pattHash.second = (HashVal.second*Power[Start].second)%mod2;
        
        pll strHash;
        strHash.first = (Hash[End].first - Hash[Start-1].first + mod1)%mod1;
        strHash.second = (Hash[End].second - Hash[Start-1].second + mod2)%mod2;
        
        if(strHash == pattHash)
            return 1;
    }
    return 0;
}

int main() {
    getline(cin, s);
    int len = s.size();
    
    PowerGen(len+10);
    Hash = doubleHash(s, len, mod1, mod2);
    
    // Prefix Suffix Match
    pll SuffHash = {0, 0};
    for(int i = 0, j = len-1; i < len-1; ++i, --j) {
        SuffHash.first = (SuffHash.first*p + (s[j] - 'a' + 1))%mod1;
        SuffHash.second = (SuffHash.second*p + (s[j] - 'a' + 1))%mod2;
        
        if(Hash[i] == SuffHash)
            Match.push_back({i, Hash[i]});
    }
    
    if(Match.empty()) {
        cout << "Just a legend\n";
        return 0;
    }
    
    MatchSubStr(1, len-1, Hash, Hash[2], 3);
    
    int low = 0, hi = (int)Match.size() - 1, ans = -1;
    
    while(low <= hi) {
        int mid = (low+hi)>>1;
        
        if(MatchSubStr(1, len-2, Hash, Match[mid].second, Match[mid].first+1)) {
            low = mid+1;
            ans = mid;
        }
        else
            hi = mid-1;
    }
    
    if(ans < 0)
        cout << "Just a legend\n";
    else
        cout << s.substr(0, Match[ans].first+1) << "\n";
    
    return 0;
}
