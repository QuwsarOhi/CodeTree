#include <bits/stdc++.h>
using namespace std;
#define MAX                 100009
#define EPS                 1e-9
#define INF                 1e17
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


struct SegTree {
    int sum[4*MAX], propl[4*MAX], propr[4*MAX];
    
    // No init added
    
    ll getSum(ll l, ll r, ll n) {
        if(l > r) swap(l, r);
        ll d = (l-r)/(n-1);
        return (n*(2*l + (n-1)*d))/2;
    }
    
    void propS(int pos, int l, int r) {
        if(l == r || propl[pos] == 0) return;
        
        
    }
    
    void updateS1(int pos, int l, int r, int L, int R) {
        if(r < L || R < l) return;
        if(L <= l && r <= R) {
            int s = L-l+1, r = L-l+1 + (r-l);
            propl[pos] += s, propr[pos] += r, sum[pos] += getSum(s, r, r-l+1);
            return;
        }
        int mid = (l+r)>>1;
        updateS1(pos<<1, l, mid, L, R);
        updateS1(pos<<1|1, mid+1, r, L, R);
    }
    
    void updateS2(int pos, int l, int r, int L, int R) {
        if(r < L || R < l) return;
        if(L <= l && r <= R) {
            int r = R-r+1, s = R-r+1 + (r-l);
            propl[pos] += s, propr[pos] += r, sum[pos] += getSum(s, r, r-l+1);
            return;
        }
        int mid = (l+r)>>1;
        updateS2(pos<<1, l, mid, L, R);
        updateS2(pos<<1|1, mid+1, r, L, R);
    }
