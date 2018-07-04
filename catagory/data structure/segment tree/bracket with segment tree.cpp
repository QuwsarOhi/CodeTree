// CodeForces
// http://codeforces.com/contest/380/problem/C
// Right Max Bracket Sequence in Range

#include <bits/stdc++.h>
using namespace std;
#define MAX                 1000100
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

// Outputs Largest Balanced Bracket Sequence in range [L, R]
struct MaxBracketSeq {
    struct node {
        ll lftBracket, rhtBracket, Max;
        node(ll lft=0, ll rht=0, ll Max=0) {
            this->lftBracket = lft;
            this->rhtBracket = rht;
            this->Max = Max;
    }};
    
    node tree[MAX*4];
    node Merge(const node &lft, const node &rht) {
        ll common = min(lft.lftBracket, rht.rhtBracket);
        ll lftBracket = lft.lftBracket + rht.lftBracket - common;
        ll rhtBracket = lft.rhtBracket + rht.rhtBracket - common;
        return node(lftBracket, rhtBracket, lft.Max+rht.Max+common);
    }
    
    void init(ll pos, ll l, ll r, char s[]) {
        if(l == r) {
            if(s[l-1] == '(')   tree[pos] = node(1, 0, 0);
            else                tree[pos] = node(0, 1, 0);
            return;
        }
        ll mid = (l+r)>>1;
        init(pos<<1, l, mid, s);
        init(pos<<1|1, mid+1, r, s);
        tree[pos] = Merge(tree[pos<<1], tree[pos<<1|1]);
    }

    node query(ll pos, ll l, ll r, ll L, ll R) {
        if(r < L || R < l)      return node();
        if(L <= l && r <= R)    return tree[pos];
        ll mid = (l+r)>>1;
        node lft = query(pos<<1, l, mid, L, R);
        node rht = query(pos<<1|1, mid+1, r, L, R);
        return Merge(lft, rht);
    }
    
    int MaxSequence(int SEQ_SIZE, int l, int r) {
        return 2*query(1, 1, SEQ_SIZE, l, r).Max;
}};

char str[MAX];
MaxBracketSeq ST;

int main() {
    ll q, l, r;
    FastRead;
    cin >> str;
    cin >> q;
    int len = strlen(str);
    ST.init(1, 1, len, str);
    while(q--) {
        cin >> l >> r;
        //cout << 2*query(1, 1, SIZE(str), l, r).Max << "\n";
        cout << ST.MaxSequence(len, l, r) << "\n";
    }
    
    return 0;
}
