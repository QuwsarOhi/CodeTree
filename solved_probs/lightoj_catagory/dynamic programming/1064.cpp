// LightOJ
// 1064 - Throwing Dice

#include <bits/stdc++.h>
using namespace std;
#define MAX                 100100
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000003
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS)) 
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbug(vari)          cerr << #vari << " = " << (vari) <<endl
#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<ll, ll>mll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<long long>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;

ull Q[30];
ll dp[26][170];
int totDice, reqSum;

ull dice(int diceNo, int sum) {
    if(diceNo == totDice)
        return (sum >= reqSum);
    
    if(dp[diceNo][sum] != -1)
        return dp[diceNo][sum];
    
    ull cnt = 0;
    for(int i = 1; i <= 6; ++i)
        cnt += dice(diceNo+1, sum+i);
    
    return dp[diceNo][sum] = cnt;
}

    
int main() {
    int t;
    
    Q[0] = 1;
    for(int i = 1; i < 25; ++i)
            Q[i] = Q[i-1]*6;
    
    sf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        sf("%d %d", &totDice, &reqSum);
        memset(dp, -1, sizeof dp);
        ull p = dice(0, 0);
        ull div = __gcd(p, Q[totDice]);
        p = p/div;
        ull q = Q[totDice]/div;
        
        pf("Case %d: ", Case);
        
        if(p == 0)
            pf("0\n");
        else if(q == 1)
            pf("%llu\n", p);
        else
            pf("%llu/%llu\n", p, q);
    }
    
    return 0;
}
