// SPOJ - IOPC1207
// http://www.spoj.com/problems/IOPC1207/

// Segment Tree

#include <bits/stdc++.h>
using namespace std;
#define MAX                 110000
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
#define error(args...)      { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

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

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {                                                  // Debugger error(a, b, ....)
	cerr << *it << " = " << a << "\n";
	err(++it, args...);
}

//const int dx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};                                                      // Four side 
//const int dxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};                     // Eight side
//----------------------------------------------------------------------------------------------------------

struct SegTree {
    int tree[5*MAX];
    bool prop[5*MAX];
    
    void init() {
        for(int i = 0; i < 5*MAX; ++i) {
            tree[i] = 0;
            prop[i] = 0;
        }
    }
    
    void nodeSwap(int pos, int l, int r) {
        tree[pos] = r-l+1 - tree[pos];
        prop[pos] ^= 1;
    }
    
    void propagate(int pos, int l, int r) {
        if(!prop[pos] || l == r)
            return;
        int mid = (l+r)>>1;
        nodeSwap(pos<<1, l, mid);
        nodeSwap(pos<<1|1, mid+1, r);
        prop[pos] ^= 1;
    }
    
    void update(int pos, int l, int r, int L, int R) {
        if(r < L || R < l)
            return;
            
        propagate(pos, l, r);
        if(L <= l && r <= R) {
            tree[pos] = r-l+1 - tree[pos];
            //cout << "Set at range " << l << " " << r << " " << tree[pos] << endl;
            prop[pos] ^= 1;
            return;
        }
        
        int mid = (l+r)>>1;
        update(pos<<1, l, mid, L, R);
        update(pos<<1|1, mid+1, r, L, R);
        tree[pos] = tree[pos<<1] + tree[pos<<1|1];
    }
    
    int query(int pos, int l, int r, int L, int R) {
        if(r < L || R < l)
            return 0;
        
        propagate(pos, l, r);
        if(L <= l && r <= R)
            return tree[pos];
            
        int mid = (l+r)>>1;
        return query(pos<<1, l, mid, L, R) + query(pos<<1|1, mid+1, r, L, R);
    }
};

SegTree STree[3];
    
int main() {
    int t, x, y, z, l, r, axis, q, x1, x2, y1, y2, z1, z2;
    
    scanf("%d", &t);
    
    while(t--) {
        scanf("%d%d%d%d", &x, &y, &z, &q);
        
        STree[0].init();
        STree[1].init();
        STree[2].init();
        
        
        while(q--) {
            scanf("%d", &axis);
            if(axis < 3) {
                scanf("%d%d", &l, &r);
                ++l, ++r;
                
                if(axis == 0)
                    STree[0].update(1, 1, x, l, r);
                else if(axis == 1)
                    STree[1].update(1, 1, y, l, r);
                else
                    STree[2].update(1, 1, z, l, r);
            }
            else {
                scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
                ++x1, ++x2, ++y1, ++y2, ++z1, ++z2;
                
                ull xON = STree[0].query(1, 1, x, x1, x2);
                ull yON = STree[1].query(1, 1, y, y1, y2);
                ull zON = STree[2].query(1, 1, z, z1, z2);
                
                //cout << xON << " " << yON << " " << zON << endl;
                
                ull xOFF = x2 - x1 + 1 - xON;
                ull yOFF = y2 - y1 + 1 - yON;
                ull zOFF = z2 - z1 + 1 - zON;
                
                ull ans = xON * yON * zON;
                ans += xON * yOFF * zOFF;
                ans += xOFF * yON * zOFF;
                ans += xOFF * yOFF * zON;
                
                printf("%llu\n", ans);
            }
        }
    }
    
    return 0;
}
