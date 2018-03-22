// SPOJ
// http://www.spoj.com/problems/NHAY/
// NHAY - A Needle in the Haystack

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// p = 31, 51
// MOD = 1e9+9, 1e9+7

pair<ll, ll> doubleHash(string s, ll mod1 = 1e9+9, ll mod2 = 1e9+7) {
    int p = 31;
    ll hashVal1 = 0, hashVal2 = 0;
    ll pPow1 = 1, pPow2 = 1;
    //vector<pair<ll, ll> >v;
    
    for(int i = 0; i < (int)s.size(); ++i) {
        hashVal1 = (hashVal1 + (s[i] - 'a' + 1)* pPow1)%mod1;
        hashVal2 = (hashVal2 + (s[i] - 'a' + 1)* pPow2)%mod2;
        pPow1 = (pPow1 * p)%mod1;
        pPow2 = (pPow2 * p)%mod2;
    }
    return {hashVal1, hashVal2};
}


vector<pair<ll, ll> >ContDoubleHash(string s, ll mod1 = 1e9+9, ll mod2 = 1e9+7) {
    int p = 31;
    ll hashVal1 = 0, hashVal2 = 0;
    ll pPow1 = 1, pPow2 = 1;
    vector<pair<ll, ll> >v;
    
    for(int i = 0; i < (int)s.size(); ++i) {
        hashVal1 = (hashVal1 + (s[i] - 'a' + 1)* pPow1)%mod1;
        hashVal2 = (hashVal2 + (s[i] - 'a' + 1)* pPow2)%mod2;
        pPow1 = (pPow1 * p)%mod1;
        pPow2 = (pPow2 * p)%mod2;
        v.push_back({hashVal1, hashVal2});
    }
    return v;
}

vector<pair<ll, ll> >Hash;
pair<ll, ll>Patt;
string s;
const int p = 31;
const ll mod1 = 1e9+9, mod2 = 1e9+7;


int main() {
    //freopen("in", "r", stdin);
    
    ll n;
    
    while(scanf("%lld ", &n) == 1) {
        getline(cin, s);
        Patt = doubleHash(s, mod1, mod2);
        
        getline(cin, s);
        
        Hash = ContDoubleHash(s, mod1, mod2);
        bool ok = 0;
        
        for(int i = n-1; i < int(Hash.size()); ++i) {
            pair<ll, ll> RangeHash = Hash[i];
            
            if(i-n >= 0) {
                RangeHash.first = (RangeHash.first + mod1 - Hash[i-n].first)%mod1;
                RangeHash.second = (RangeHash.second + mod2 - Hash[i-n].second)%mod2;
            }
            
            if(Patt == RangeHash) {
                ok = 1;
                cout << i-n+1 << "\n";
            }
            
            Patt.first = (Patt.first * p)%mod1;
            Patt.second = (Patt.second * p)%mod2;
        }
        
        if(!ok) cout << "\n";
    }
    return 0;
}
