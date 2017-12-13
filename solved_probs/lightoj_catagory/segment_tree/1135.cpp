// LightOJ
// 1135 - Count the Multiples of 3

#include <bits/stdc++.h>
using namespace std;
#define MAX                 1e9
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

int tree[500000][3], prop[500000];

void init(int pos, int L, int R) {
    if(L == R) {
        tree[pos][0] = 1;
        tree[pos][1] = tree[pos][2] = 0;
        return;
    }
    
    int mid = (L+R)>>1;
    
    init(pos<<1, L, mid);
    init(pos<<1|1, mid+1, R);
    
    for(int i = 0; i < 3; ++i)
        tree[pos][i] = tree[pos<<1][i] + tree[pos<<1|1][i];
}

void shiftVal(int pos, int step) {
    step %= 3;
    if(step == 0)
        return;
    swap(tree[pos][2], tree[pos][1]);
    swap(tree[pos][1], tree[pos][0]);
    if(step == 2) {
        swap(tree[pos][2], tree[pos][1]);
        swap(tree[pos][1], tree[pos][0]);
    }
}


void propagate(int pos, int L, int R) {
    if(L == R) {
        prop[pos] = 0;
        return;
    }

    shiftVal(pos<<1, prop[pos]);
    shiftVal(pos<<1|1, prop[pos]);
    
    if(L != R) {
        prop[pos<<1] += prop[pos];
        prop[pos<<1|1] += prop[pos];
    }
    prop[pos] = 0;
}

void update(int pos, int L, int R, int l, int r) {
    if(r < L || R < l)
        return;
    
    if(prop[pos] != 0)
        propagate(pos, L, R);
    
    if(l <= L && R <= r) {
        shiftVal(pos, 1);
        prop[pos] += 1;
        return;
    }
    
    int mid = (L+R)>>1;
    update(pos<<1, L, mid, l, r);
    update(pos<<1|1, mid+1, R, l, r);
    
    for(int i = 0; i < 3; ++i)
        tree[pos][i] = tree[pos<<1][i] + tree[pos<<1|1][i];
}

int query(int pos, int L, int R, int l, int r) {
    if(r < L || R < l)
        return 0;
    
    if(prop[pos] != 0)
        propagate(pos, L, R);
    
    if(l <= L && R <= r)
        return tree[pos][0];
    
    int mid = (L+R)>>1;
    int lft = query(pos<<1, L, mid, l, r);
    int rht = query(pos<<1|1, mid+1, R, l, r);
    
    return lft+rht;
}

int main() {
    //fileRead("in");
    //fileWrite("out");
    
    int t, l, r, n, c, q;
    sf("%d", &t);
    for(int Case = 1; Case <= t; ++Case) {
        sf("%d %d", &n, &q);
        init(1, 1, n);
        memset(prop, 0, sizeof prop);
        pf("Case %d:\n", Case);
        while(q--) {
            sf("%d", &c);
            if(c == 1) {
                sf("%d %d", &l, &r);
                pf("%d\n", query(1, 1, n, l+1, r+1));
            }
            else {
                sf("%d %d", &l, &r);
                update(1, 1, n, l+1, r+1);
            }
        }
    }
    return 0;
}
