#include <bits/stdc++.h>
using namespace std;
#define MAX                 100100
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

struct node {
    int val, prop;
    node() {
        val = 0;
        prop = -1;
    }
};

node tree[1510000];
queue<pair<pii, int> >query;
vi point;

void propagate(int pos, int l, int r) {
    if(tree[pos].prop == -1 || l==r)
        return;
    
    int mid = (l+r)>>1;
    if(tree[pos].prop) {
        tree[pos<<1].val = point[mid]-point[l]+1;
        tree[pos<<1|1].val = point[r]-point[mid+1]+1;
    }
    else {
        tree[pos<<1].val = 0;
        tree[pos<<1|1].val = 0;
    }
    tree[pos<<1].prop = tree[pos<<1|1].prop = tree[pos].prop;
    tree[pos].prop = -1;
}

void update(int pos, int l, int r, int lft, int rht, int flag) {
    if(rht < point[l] || point[r] < lft)
        return;
    
    //if(tree[pos].val == flag)
    //    return;
    
    propagate(pos, l, r);
    
    if(lft <= point[l] && point[r] <= rht) {
        //pf("update at %d- %d : ", point[l], point[r]);
        if(flag)
            tree[pos].val = point[r]-point[l]+1;
        else
            tree[pos].val = 0;
        //pf("%d\n", tree[pos].val);
        tree[pos].prop = flag;
        return;
    }
    
    int mid = (l+r)>>1;
    update(pos<<1, l, mid, lft, rht, flag);
    update(pos<<1|1, mid+1, r, lft, rht, flag);
    
    tree[pos].val = tree[pos<<1].val + tree[pos<<1|1].val;
    //pf("%d - %d : %d\n%d - %d : %d\n", point[l], point[mid], tree[pos<<1].val, point[mid+1], point[r], tree[pos<<1|1].val);
}
    

int main() {
    FastRead;
    fileRead("in");
    int n, q, l, r, k;
    cin >> n >> q;
    
    point.pb(0);       // dummy
    while(q--) {
        cin >> l >> r >> k;
        k = (k==1 ? 1:0);
        query.push({{l, r}, k});
        
        point.pb(l);
        point.pb(r);
    }
    //cout << "DONE" << endl;
    sort(point.begin()+1, point.end());
    point.erase(unique(point.begin()+1, point.end()), point.end());
    
    //for(int i = 1; i < SIZE(point); ++i)
    //    cout << point[i] << " ";
    //cout << "DONE " << SIZE(point)-1<< endl;
    while(!query.empty()) {
        l = query.front().fi.fi, r = query.front().fi.se, k = query.front().se;
        query.pop();
        
        update(1, 1, SIZE(point)-1, l, r, k);
        cout << n-tree[1].val << endl;
    }
    
    return 0;
}
