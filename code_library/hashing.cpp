// Hashing

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

// p = 31, 51
// MOD = 1e9+9, 1e7+7

const ll p = 31;
const ll mod1 = 1e9+9, mod2 = 1e9+7;

// Returns Single Hash Val
ll hash(char *s,  int len, ll mod = 1e9+9) {
    int p = 31;
    ll hashVal = 0;
    ll pPow = 1;
    
    for(int i = 0; i < len; ++i) {
        hashVal = (hashVal + (s[i] - 'a' + 1) * pPow)%mod;
        pPow = (pPow *p)%mod;
    }
    return hashVal;
}


// Generates Continious single Hash Val
vector<ll> ContHash(char *s, int len, ll mod = 1e9+9) {
    int p = 31;
    ll hashVal = 0;
    ll pPow = 1;
    vector<ll>v;
    
    for(int i = 0; i < len; ++i) {
        hashVal = (hashVal + (s[i] - 'a' + 1) * pPow)%mod;
        pPow = (pPow *p)%mod;
        v.push_back(hashVal);
    }
    
    return v;
}


// --------------- DOUBLE HASH GENERATORS ---------------


// Generates Hash of entire string without PowerGen func
vector<pair<ll, ll> > doubleHash(char *s, int len, ll mod1 = 1e9+9, ll mod2 = 1e9+7) {
    int p = 31;
    ll hashVal1 = 0, hashVal2 = 0;
    ll pPow1 = 1, pPow2 = 1;
    vector<pair<ll, ll> >v;
    
    for(int i = 0; i < len; ++i) {
        hashVal1 = (hashVal1 + (s[i] - 'a' + 1)* pPow1)%mod1;
        hashVal2 = (hashVal2 + (s[i] - 'a' + 1)* pPow2)%mod2;
        pPow1 = (pPow1 * p)%mod1;
        pPow2 = (pPow2 * p)%mod2;
        v.push_back({hashVal1, hashVal2});
    }
    
    return v;
}


// Genarates Powers
void PowerGen(int n) {
    Power.resize(n+1);
    Power[0] = {1, 1};
    
    for(int i = 1; i < n; ++i) {
        Power[i].first = (Power[i-1].first * p)%mod1;
        Power[i].second = (Power[i-1].second * p)%mod2;
    }
}

// Returns Double Hash vector for a full string
vector<pair<ll, ll> > doubleHash(string s, int len) {
    ll hashVal1 = 0, hashVal2 = 0;
    vector<pair<ll, ll> >v;
    
    for(int i = 0; i < len; ++i) {
        hashVal1 = (hashVal1 + (s[i] - 'a' + 1)* Power[i].first)%mod1;
        hashVal2 = (hashVal2 + (s[i] - 'a' + 1)* Power[i].second)%mod2;
        v.push_back({hashVal1, hashVal2});
    }
    
    return v;
}

// Returns Double Hash
pll doubleHashPatt(char s[], int len) {
    ll hashVal1 = 0, hashVal2 = 0;
    
    for(int i = 0; i < len; ++i) {
        hashVal1 = (hashVal1 + (s[i] - 'a' + 1)* Power[i].fi)%mod1;
        hashVal2 = (hashVal2 + (s[i] - 'a' + 1)* Power[i].se)%mod2;
    }
    return {hashVal1, hashVal2};
}

// Returns True if the Hashval of length len exists in subrange [l, r] of Hash vector
bool MatchSubStr(int l, int r, vector<pll>&Hash, pll HashVal, int len) {
    for(int Start = l, End = l+len-1; End <= r; ++End, ++Start) {
        pll pattHash;
        pattHash.first = (HashVal.first*Power[Start].first)%mod1;
        pattHash.second = (HashVal.second*Power[Start].second)%mod2;
        
        pll strHash;
        strHash.first = (Hash[End].first - (Start == 0 ? 0:Hash[Start-1].first) + mod1)%mod1;
        strHash.second = (Hash[End].second - (Start == 0 ? 0:Hash[Start-1].second) + mod2)%mod2;
        
        if(strHash == pattHash)
            return 1;
    }
    return 0;
}
