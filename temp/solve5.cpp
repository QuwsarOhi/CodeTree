#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;


vector<ll> power(int lim, ll st, ll mod) {
    vector<ll>p(lim+1);
    p[0] = 1;
    
    for(int i = 1; i < lim; ++i) {
        p[i] = p[i-1] * st;
        p[i] %= mod;
    }
    return p;
}

vector<pll> ContHash(string s, vector<ll>&p1, vector<ll>&p2, ll mod1 = 1e9+9, ll mod2 = 1e9+7) {
    ll hash1 = 0, hash2 = 0;
    vector<pll>v;
    
    for(int i = 0; i < (int)s.size(); ++i) {
        hash1 = (hash1 + (s[i] - 'a' + 1) * p1[i])%mod1;
        hash2 = (hash2 + (s[i] - 'a' + 1) * p2[i])%mod2;
        v.push_back({hash1, hash2});
    }
    
    return v;
}


string str;
vector<ll>p1, p2;
vector<pll>hashTable;
const ll mod1 = 1e9+9, mod2 = 1e9+7;
const int p = 31;


bool Match(int l, int r, int len) {
    if(l >= r)
        return 0;
        
    pll hash1 = {(hashTable[l].first*p1[r])%mod1, (hashTable[l].second*p2[r])%mod2};
    pll hash2 = {(hashTable[len-1].first - hashTable[r-1].first + mod1)%mod1, (hashTable[len-1].second - hashTable[r-1].second + mod2)%mod2};
    
    
    
    return (hash1 == hash2);
}

// 1 2 3 4 5 6
//   |   |

bool Match(int l, int r, int len, pll Hash) {
    for(int i = len+1; i < r; ++i) {
        pll tHash1 = {(hashTable[i].first - hashTable[i-len-1].first + mod1)%mod1, (hashTable[i].second - hashTable[i-len-1].second + mod2)%mod2};
        pll tHash2 = {(Hash.first*p1[i])%mod1, (Hash.second*p2[i])%mod2};
        
        if(tHash1 == tHash2)
            return 1;
    }
    return 0;
}
        
int main() {
    getline(cin, str);
    int len = str.size();
    
    p1 = power(len+2, p, mod1);
    p2 = power(len+2, p, mod2);
    
    hashTable = ContHash(str, p1, p2, mod1, mod2);
    
    int low = 0, hi = len+10, ans = -1;
    
    while(low <= hi) {
        int mid = (low+hi)>>1;
        
        cout << "MID " << mid << endl;
        
        if(!Match(mid, len-mid-1, len)) {
            cout << "PRE-SUFF NOT MATCH AT " << mid << endl;
            hi = mid-1;
        }
        else if(Match(1, len-1, mid, hashTable[mid])) {
            cout << "FULL MATCH FOUND at " << mid << endl;
            ans = mid;
            low = mid+1;
        }
        else
            hi = mid-1;
    }
    
    cout << ans << endl;
    
    return 0;
}
