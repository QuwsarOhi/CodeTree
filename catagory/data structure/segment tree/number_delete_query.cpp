// LightOJ
// 1187 - Lining up Students

#include <bits/stdc++.h>
using namespace std;
#define MAX                 100100
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


struct SegTreeInsertRemove {                    // Finds/Deletes I'th value from array/SegTree
    int tree[MAX*4];
    void init(int pos, int L, int R) {
        if(L == R) {
            tree[pos] = 1;
            return;
        }
        int mid = (L+R)>>1;
        init(pos<<1, L, mid);
        init(pos<<1|1, mid+1, R);
        tree[pos] = tree[pos<<1]+tree[pos<<1|1];
    }
    int SearchVal(int pos, int L, int R, int I, bool removeVal = 0) {         // Find I'th value in Segment Tree, removes it if removeVal = 1 
        if(L == R) {
            tree[pos] = (removeVal ? 0:1);
            return L;
        }
        int mid = (L+R)>>1;
        if(I <= tree[pos<<1]) {
            int idx = SearchVal(pos<<1, L, mid, I, removeVal);
            if(removeVal) tree[pos] = tree[pos<<1] + tree[pos<<1|1];
            return idx;
        }
        else {
            int idx = SearchVal(pos<<1|1, mid+1, R, I-tree[pos<<1], removeVal);
            if(removeVal) tree[pos] = tree[pos<<1] + tree[pos<<1|1];
            return idx;
}}};

int v[MAX];
SegTreeInsertRemove ST;

int main() {
    //fileRead("in");
    //fileWrite("out");
    
    int t, n, idx;
    sf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        sf("%d", &n);
        pf("Case %d: ", Case);
        ST.init(1, 1, n);
        for(int i = 1; i <= n; ++i)
            sf("%d", &v[i]);
        for(int i = n; i >= 1; --i) {
            idx = ST.SearchVal(1, 1, n, i-v[i], 1);
            if(i == 1)
                pf("%d\n", idx);
        }
    }
    
    return 0;
}
