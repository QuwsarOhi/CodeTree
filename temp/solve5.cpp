#include <bits/stdc++.h>
using namespace std;
#define MAX                 501000
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000003
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

int tree[6*MAX], v[MAX], Turn = 0;
bool OK;

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

void init(int pos, int l, int r) {
    if(l == r) {
        tree[pos] = v[l];
        return;
    }
    
    int mid = (l+r)>>1;
    init(pos<<1, l, mid);
    init(pos<<1|1, mid+1, r);
    
    tree[pos] = __gcd(tree[pos<<1], tree[pos<<1|1]);
}

void update(int pos, int L, int R, int i, int val) {
    if(L==R) {
        tree[pos] = val;
        return;
    }
    int mid = (L+R)>>1;
    if(i <= mid) 
        update(pos*2, L, mid, i, val);
    else 
        update(pos*2+1, mid+1, R, i, val);
    tree[pos] = __gcd(tree[pos*2], tree[pos*2+1]);
}

void check(int pos, int L, int R, int val) {
    if(!OK)
        return;
    if(L==R) {
        Turn += (tree[pos]%val != 0);
        //cout << "Turn at " << L << " " << R << endl;
        if(Turn > 1)
            OK = 0;
        return;
    }
    bool Err = 0;
    int mid = (L+R)>>1;
    if(tree[pos<<1]%val) {
        Err = 1;
        check(pos<<1, L, mid, val);
    }
    if(!OK)
        return;
    if(tree[pos<<1|1]%val) {
        if(Err) {
            //cout << "Err " << tree[pos<<1] << " " << tree[pos<<1|1] << endl;
            OK = 0;
            return;
        }
        check(pos<<1|1, mid+1, R, val);
    }
}

int query(int pos, int L, int R, int l, int r, int val) {
    if(!OK)
        return 0;
    if(R < l || r < L)
		return -1;	            //depends on usage (return 0)
    if(l <= L && R <= r) {
        if(tree[pos]%val)
            check(pos, L, R, val);
		return tree[pos];	    //depends on usage
    }
    int mid = (L+R)/2;
    int x = query(pos*2, L, mid, l, r, val);
    int y = query(pos*2+1, mid+1, R, l, r, val);
    //pf("%d : %d %d\n", x, l, mid);
    //pf("%d : %d %d\n", y, mid+1, r);
    if(!OK)
        return 0;
    if(x == -1)
        return y;
    else if(y == -1)
        return x;
    else
        return __gcd(x, y);			        //depends on usage
}



int main() {
    //fileRead("in");
    FastRead;
    int n, l, r, val, t, q, idx;
    cin >> n;
    
    for(int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    
    init(1, 1, n);
    
    cin >> q;
    
    while(q--) {
        cin >> t;
        if(t== 1) {
            cin >> l >> r >> val;
            Turn = 0;
            OK = 1;
            int ans = query(1, 1, n, l, r, val);
            if(ans == val || (Turn <= 1 && OK))
                cout << "YES\n";
            else {
                //cout << ans << " " << Turn << endl;
                cout << "NO\n";
            }
        }
        else {
            cin >> idx >> val;
            update(1, 1, n, idx, val);
        }
    }
    
    return 0;
}
