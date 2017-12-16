// LightOJ
// 1339 - Strongest Community

#include <bits/stdc++.h>
using namespace std;
#define MAX                 100010
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

int tree[5*MAX], cnt[MAX], v[MAX], Start[MAX], End[MAX];

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
    //fileRead("in");
    //fileWrite("out");
    
    int n, t, x, q, l, r;
    sf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        sf("%d %d %d", &n, &x, &q);
        pf("Case %d:\n", Case);
        
        for(int i = 0; i <= x; ++i)
            cnt[i] = 0;
        
        for(int i = 1; i <= n; ++i) {
            sf("%d", &v[i]);
            cnt[v[i]]++;
            if(i == 1 || v[i] != v[i-1])
                Start[i] = i;
            else
                Start[i] = Start[i-1];
        }
        
        for(int i = n; i >= 1; --i) {
            if(i == n || (v[i] != v[i+1]))
                End[i] = i;
            else
                End[i] = End[i+1];
        }
        
        //for(int i = 1; i <= n; ++i) {
            //pf("%d : %d %d :: %d\n", i, Start[i], End[i], cnt[v[i]]);
        //}
        
        init(1, 1, n);
        
        while(q--) {
            sf("%d %d", &l, &r);
            if(v[l] == v[r]) {
                //pf("Same found\n");
                pf("%d\n", r-l+1);
            }
            else {
                int cnt1 = End[l]-l+1;
                int cnt2 = r-Start[r]+1, cnt3 = -1;
                //pf("cnt1 %d : cnt2 %d\n", cnt1, cnt2);
                l = End[l]+1, r = Start[r]-1;
                if(l <= r)
                    cnt3 = query(1, 1, n, l, r);
                pf("%d\n",  max(cnt1, max(cnt2, cnt3)));
            }
        }
    }
    
    return 0;
}