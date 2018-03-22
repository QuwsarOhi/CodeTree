// Hashing

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// p = 31, 51
// MOD = 1e9+9, 1e7+7


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


// Generates Continious Hash Val
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


pair<ll, ll> doubleHashPatt(string s, ll mod1 = 1e9+9, ll mod2 = 1e9+7) {
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


// Double Hash with power generator
vector<ll> power(int lim, ll st, ll mod) {
    vector<ll>p(lim+1);
    p[0] = 1;
    
    for(int i = 1; i < lim; ++i) {
        p[i] = p[i-1] * st;
        p[i] %= mod;
    }
}

vector<pll> ContHash(string s, vector<ll>&p1, vector<ll>&p2, ll mod1 = 1e9+9, mod2 = 1e9+7) {
    pll hash1 = 0, hash2 = 0;
    vector<pll>v;
    
    for(int i = 0; i < (int)s.size(); ++i) {
        hash1 = (hash1 + (s[i] - 'a' + 1) * p1[i])%mod1;
        hash2 = (hash2 + (s[i] - 'a' + 1) * p2[i])%mod2;
        v.push_back({hash1, hash2});
    }
    
    return v;
}
