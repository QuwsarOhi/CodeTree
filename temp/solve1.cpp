#include <bits/stdc++.h>
using namespace std;
#define MAX                 1e6
#define EPS                 1e-9
#define INF                 1e9+10
#define MOD                 1000000007
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

void init(int pos, int L, int R) {
    if(L == R) {
        tree[pos] = cnt[v[L]];
        return;
    }
    
    int mid = (L+R)>>1;
    init(pos<<1, L, mid);
    init(pos<<1|1, mid+1, R);
    
    tree[pos] = max(tree[pos<<1], tree[pos<<1|1]);
}

int query(int pos, int L, int R, int l, int r) {
    if(r < L || R < l)
        return 0;
    
    if(l <= L && R <= r)
        return tree[pos];
    
    int mid = (L+R)>>1;
    int lft = query(pos<<1, L, mid, l, r);
    int rht = query(pos<<1|1, mid+1, R, l, r);
    
    return max(lft, rht);
}


int main() {
    int n, t;
    sf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        sf("%d %d %d", &n, &x, &q);
    
        Start[1] = 1;
        for(int i = 2; i <= n; ++i) {
            sf("%d", &v[i]);
            cnt[v[i]]++;
            if(v[i] != v[i-1])
                Start[i] = i;
            else
                Start[i] = Start[i-1];
        }
        
        End[n] = n;
        for(int i = n-1; i >= 1; --i) {
            if(End[i] != End[i+1])
                End[i] = i;
            else
                End[i] = End[i+1];
        }
    
        while(q--) {
            sf("%d %d", &l, &r);
            
        }
    }
    
    return 0;
}