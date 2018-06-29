#include <bits/stdc++.h>
#define MOD 998244353
#define MAX 200
using namespace std;
typedef long long ll;


// Solution only exists if d | c (i.e : c is divisable by d)
ll gcdExtended(ll a, ll b, ll *x, ll *y) {          // C function for extended Euclidean Algorithm
    if (a == 0) {                                   // Base Case
        *x = 0, *y = 1;
        return b;
    }
    ll x1, y1;                                     // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
 
ll modInverse(ll a, ll mod) {
    ll x, y;
    ll g = gcdExtended(a, mod, &x, &y);
    if(g != 1) return -1;                   // ModInverse doesnt exist
    ll res = (x%mod + mod) % mod;           // m is added to handle negative x
    return res;
}

ll fa[MAX];                                 // fa must be in global
ll C(ll n, ll r) {                          // Usable if MOD value is present
    if(fa[0] == 0) {                        // Auto initialize
        fa[0] = 1;
        for(int i = 1; i < MAX; ++i)
            fa[i] = (fa[i-1]*i) % MOD;      // Constant MOD
    }
    if(n < 0 || r < 0 || n-r < 0) return 0;     // Exceptional Cases
    ll b = (fa[r] * fa[n-r]) % MOD;
    return (fa[n] * modInverse(b, MOD)) %MOD;
}



bool isGOOD(vector<int>&V, int p = 0) {
    if(p == (int)V.size())
        return 1;
    else if(p > (int)V.size())
        return 0;
    
    if(V[p] <= 0) return 0;
    
    return isGOOD(V, p+V[p]+1);
}

vector<int>T;
int ans, n;
ll v[101];

void recur(int pos = -1) {
    if((int)T.size() >= 2) {
        ans += isGOOD(T);
        
        /*for(auto it : T)
            cout << it << " ";
            
        cout << (isGOOD(T) ? "GOOD":"notGOOD") << endl;*/
    }
    
    for(int i = pos+1; i < n; ++i) {
        if(T.empty() && (v[i] <= 0 || v[i] >= 100))
            continue;
        
        T.push_back(v[i]);
        recur(i);
        T.pop_back();
    }
}

int main() {
    //freopen("in", "r", stdin);
    
    cin >> n;
    
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    
    //recur();
    
    dp[n] = 1;
    for(int i = n-1; i >= 0; --i) {
        for(int j = i+v[i]+1; j < n and v[i] >= 0; ++j) {
            dp[i] += (dp[j] * C(j-i-1, v[i]))%MOD;
            dp[i] %= MOD;
        }
    }
    
    cout << ans << endl;
    return 0;
}
    
    
