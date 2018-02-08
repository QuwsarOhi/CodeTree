// Codeforces
// Persistent Bookcase
// http://codeforces.com/contest/707/problem/D

// Propagation + Presistance

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

struct node {
    ll val;
    bool flip;
    node *lft, *rht;
    
    node(node *L = NULL, node *R = NULL, ll v = 0, bool f = 0) {
        lft = L;
        rht = R;
        val = v;
        flip = f;
    }
};

node *presis[1001000];

node *nCopy(node *x) {
    node *tmp = new node();
    if(x) {
        tmp->val = x->val;
        tmp->lft = x->lft;
        tmp->rht = x->rht;
        tmp->flip = x->flip;
    }
    return tmp;
}

bool flipProp(bool par, bool child) {
    if(par == child)
        return 0;
    return 1;
}

void propagate(node *pos, ll l, ll r) {
    if(l == r)
        return;
    
    pos->lft = nCopy(pos->lft);
    pos->rht = nCopy(pos->rht);
    
    
    if(!pos->flip)
        return;
    
    ll mid = (l+r)>>1;
    pos->lft->flip = flipProp(pos->flip, pos->lft->flip);
    pos->rht->flip = flipProp(pos->flip, pos->rht->flip);
    
    //if(pos->lft->flip)
        pos->lft->val = (mid-l+1)-pos->lft->val;
    //if(pos->rht->flip)
        pos->rht->val = (r-mid)-pos->rht->val;
    
    pos->flip = 0;
}


// Single Position update
void updateTrigger(node *pos, ll l, ll r, ll idx, ll val) {
    if(l == r) {
        pos->val = val;
        return;
    }
    
    propagate(pos, l, r);
    ll mid = (l+r)>>1;
    
    if(idx <= mid) {
        //pos->lft = nCopy(pos->lft);
        updateTrigger(pos->lft, l, mid, idx, val);
    }
    else {
        //pos->rht = nCopy(pos->rht);
        updateTrigger(pos->rht, mid+1, r, idx, val);
    }
    
    pos->val = 0;
    if(pos->lft)
        pos->val += pos->lft->val;
    if(pos->rht)
        pos->val += pos->rht->val;
}

void updateFlip(node *pos, ll l, ll r, ll L, ll R) {
    if(r < L || R < l)
        return;
    
    propagate(pos, l, r);
    if(L <= l && r <= R) {
        pos->flip = 1;
        pos->val = (r-l+1) - pos->val;
        return;
    }
    
    ll mid = (l+r)>>1;
    
    updateFlip(pos->lft, l, mid, L, R);
    updateFlip(pos->rht, mid+1, r, L, R);
    
    pos->val = 0;
    if(pos->rht)
        pos->val += pos->rht->val;
    if(pos->lft)
        pos->val += pos->lft->val;
}


int main() {
    FastRead;
    ll n, m, q, i, j, t, Time = 0;
    
    cin >> n >> m >> q;
    ll lim = n*m;
    presis[Time] = new node();
    
    while(q--) {
        cin >> t;
        
        ++Time;
        presis[Time] = nCopy(presis[Time-1]);
        
        if(t == 1 || t == 2) {
            cin >> i >> j;
            ll pos = (i-1)*m + j;
            //cout << "POS " << pos << endl;
            updateTrigger(presis[Time], 1, lim, pos, (t==1));
        }
        else if(t == 3) {
            cin >> i;
            //cout << "Range " << (i-1)*m+1 << " " << i*m << endl;
            updateFlip(presis[Time], 1, lim, (i-1)*m+1, i*m);
        }
        else {
            cin >> t;
            presis[Time] = nCopy(presis[t]);
        }
        
        cout << presis[Time]->val << "\n";
    }
    
    return 0;
}
