// TOPH
// New Divisor Problem
// Intra AUST Programming Contest Fall 2017


#include <bits/stdc++.h>
using namespace std;
#define MAX                 200100
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


int val[100100], IDX[1001000], ans[100100], Div[1000100];
set<pair<pii, pii > >Boundary;

struct node {
    int val[241];
    node *lft, *rht;
    
    node(node *l = NULL, node *r = NULL) {
        lft = NULL;
        rht = NULL;
        memset(val, 0, sizeof val);
    }
};


void update(node *pos, int l, int r, int idx, int divCount, int val) {
    if(l == r) {
        pos->val[divCount] += val;
        return;
    }
    
    int mid = (l+r)>>1;
    
    if(idx <= mid) {
        if(!(pos->lft))
            pos->lft = new node();
        update(pos->lft, l, mid, idx, divCount, val);
    }
    else {
        if(!(pos->rht))
            pos->rht = new node();
        update(pos->rht, mid+1, r, idx, divCount, val);
    }
    
    pos->val[divCount]+=val;
}


int query(node *pos, int l, int r, int L, int R, int divCount) {      // Max DivCount = 240
    if(!pos || r < L || R < l)
        return 0;
    
    if(L <= l && r <= R)
        return pos->val[divCount];
    
    int mid = (l+r)>>1;
    
    int x = query(pos->lft, l, mid, L, R, divCount);
    int y = query(pos->rht, mid+1, r, L, R, divCount);
    
    return x+y;
}


void ClearTree(node *pos) {
    if(pos == NULL) {
        delete pos;
        return;
    }

    ClearTree(pos->lft);
    ClearTree(pos->rht);
    
    delete pos;
}

void DivCal(int n) {
    for(int i = 1; i <= n; ++i)
        for(int j = i; j <= n; j+=i)
            ++Div[j];
}


int main() {
    int t, n, l, r, q, k;
    DivCal(1000010);
    
    sf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        sf("%d", &n);
        
        node *root = new node();
        
        for(int i = 1; i <= n; ++i)
            sf("%d", &val[i]);
        
        pf("Case %d:\n", Case);
        sf("%d", &q);
    
        for(int i = 0; i < q; ++i) {
            sf("%d %d %d", &l, &r, &k);
            Boundary.insert({{r, l}, {k, i}});
        }
    
        int pos = 1;
        
        memset(IDX, -1, sizeof IDX);
    
        for(auto it : Boundary) {
            r = it.first.first, l = it.first.second;
            k = it.second.first;
            
            for( ; pos <= r; ++pos) {
                if(IDX[val[pos]] == -1) {
                    IDX[val[pos]] = pos;
                    update(root, 1, n, pos, Div[val[pos]], 1);
                }
                else {
                    int pstPos = IDX[val[pos]];
                    IDX[val[pos]] = pos;
                    update(root, 1, n, pos, Div[val[pos]], 1);
                    update(root, 1, n, pstPos, Div[val[pstPos]], -1);
                }
            }
            
            if(k <= 240)
                ans[it.second.second] = query(root, 1, n, l, r, k);
            else
                ans[it.second.second] = 0;
        }
        
        for(int i = 0; i < q; ++i)
            pf("%d\n", ans[i]);
        Boundary.clear();
        ClearTree(root);
    }
    
    return 0;
}
