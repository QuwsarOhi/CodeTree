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


struct DSU {
    vector<int>u_list, u_set;        // u_list[x] : the size of a set x,  u_set[x] : the root of x
    
    DSU() {}
    DSU(int SZ) { init(SZ); }
    
    int unionRoot(int n) {
        if(u_set[n] == n) return n;
        return u_set[n] = unionRoot(u_set[n]);
    }

    int makeUnion(int a, int b) {
        int x = unionRoot(a), y = unionRoot(b);
        if(x == y)
            return x;
        else if(u_list[x] > u_list[y]) {
            u_set[y] = x;
            u_list[x] += u_list[y];
            return x;
        }
        else {
            u_set[x] = y;
            u_list[y] += u_list[x];
            return y;
    }}

    void init(int len) {
        u_list.resize(len+5);
        u_set.resize(len+5);
        for(int i = 0; i <= len+3; i++)
            u_set[i] = i, u_list[i] = 1;
    }
    
    bool isRoot(int x) {
        return u_set[x] == x;
    }
    
    bool isRootContainsMany(int x) {
        return (isRoot(x) && (u_list[x] > 1));
    }
    
    bool isSameSet(int a, int b) {
        return (unionRoot(a) == unionRoot(b));
}};

DSU dsu;


int main() {
    scanf("%d%d", &n, &m);
    
    for(int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    
    while(m--) {
        scanf("%d", &t);
        
        if(t == 1) {
            scanf("%lld%lld", &x, &y);
            a[x] = y;
        }
        else if(t == 2) {
            scanf("%lld%lld", &x, &y);
            if(not dsu.isSameSet(x, y))
                dsu.makeUnion(x, y);
        }
        else {
            scanf("%lld%lld%lld", &x, &y, &v);
            if(dsu.isSameSet(x, y) and u_list[dsu.unionRoot(x)] == 2) {
                x = v*a[x], y = a[y];
                ll gcd = __gcd(x, y);
                x /= gcd, y /= gcd;
                
            }
            else
                printf("0\n");
        }
    }
    return 0;
}
