#include <bits/stdc++.h>
using namespace std;
#define MAX                 13333333
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define All(S)              S.begin(), S.end()              
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)

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


//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------


vl v1, v2;
priority_queue<ll>pq;

int main() {
    ll x, n, k1, k2;
    
    sf("%lld%lld%lld", &n, &k1, &k2);
    
    fr(i, 0, n) {
        sf("%lld", &x);
        v1.pb(x);
    }
    
    fr(i, 0, n) {
        sf("%lld", &x);
        v2.pb(x);
    }
    
    fr(i, 0, n) {
        ll T = abs(v1[i] - v2[i]);
        if(T > 0) pq.push(T);
    }
    
    ll TOT = k1+k2;
    while(TOT > 0 and !pq.empty()) {
        ll v = pq.top();
        pq.pop();
        
        ll T = min(v, TOT);
        TOT -= T;
        v -= T;
        
        if(v != 0)
            pq.push(v);
    }
    
    ll Ans = 0;
    
    while(!pq.empty()) {
        ll T = pq.top();
        pq.pop();
        Ans += T*T;
    }
    
    //cout << "Ans " << Ans << endl;
    
    ll avg = TOT/n;
    
    
    if(TOT > 0) {
        if(avg == 0)
            Ans = TOT;
        else {
            Ans = avg*avg*(n-1);
            ll T = (avg + (TOT%n));
            Ans += T*T;
        }
    }
    
    pf("%lld\n", Ans);
    
    return 0;
}
    