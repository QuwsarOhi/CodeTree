#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define INF 1e9+10
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define sf scanf
#define pf printf
#define Equal(a, b) (abs(a-b) < EPS)
#define Greater(a, b) (a >= (b+EPS))
#define GreaterEqual(a, b) (a > (b-EPS)) 
#define fr(i, a, b) for(register int i = (a); i < (int)(b); i++)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbug(vari) cerr << #vari << " = " << (vari) <<endl
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;

// Basic Segment Tree (Without Propagation)
vi tree;

void segment_build(int pos, int L, int R) {
    tree[pos] = 0;		//init is here, no need to manual init
    if(L==R) {
        tree[pos] = arr[L];
        return;
    }
    int mid = (L+R)/2;
    segment_build(pos*2, L, mid);
    segment_build(pos*2+1, mid+1, R);
    tree[pos] = tree[pos*2] * tree[pos*2+1];	//depends on usage
}

void segment_update(int pos, int L, int R, int i, int val) {
    if(L==R) {
        tree[pos] = val;
        return;
    }
    int mid = (L+R)/2;
    if(i <= mid) segment_update(pos*2, L, mid, i, val);
    else segment_update(pos*2+1, mid+1, R, i, val);
    tree[pos] = tree[pos*2] * tree[pos*2+1];		//depends on usage
}

int segment_query(int pos, int L, int R, int l, int r) {
    if(R < l || r < L)
		return 1;	//depends on usage (return 0)
    if(l <= L && R <= r) 
		return tree[pos];	//depends on usage
    int mid = (L+R)/2;
    int x = segment_query(pos*2, L, mid, l, r);
    int y = segment_query(pos*2+1, mid+1, R, l, r);
    return x*y;			//depends on usage
}




// Segment Tree Lazy Propagation (Without Propagation Update)

vector<pair<ull, ull> > tree;

// (l, r) : tree segment, (x, y) : update segment

void update(ll pos, ll l, ll r, ll x, ll y, ll val) {
	if(y < l || x > r)
		return;
	
	if(x <= l && r <= y) {		// Tree segment in update segment
		tree[pos].fi += (r-l+1)*val;
		tree[pos].se += val;	// Propagate
		return;
	}
	
	ll mid = (l+r)/2LL;
	
	update(pos*2LL, l, mid, x, y, val);
	update(pos*2LL + 1, mid+1, r, x, y, val);
	
	tree[pos].fi = tree[pos*2].fi + tree[pos*2+1].fi + (r-l+1)*tree[pos].se;
}

// Pass propagate value through carry
ll query(ll pos, ll l, ll r, ll x, ll y, ll carry) {
	if(y < l || x > r)
		return 0;
	
	if(x <= l && r <= y)
		return tree[pos].fi + (carry * (r-l+1));
	
	ll mid = (l+r)/2LL;
	
	ll lft = query(pos*2LL, l, mid, x, y, carry + tree[pos].se);
	ll rht = query(pos*2LL + 1, mid+1, r, x, y, carry + tree[pos].se);
	
	return lft + rht;
}



// Segment Tree Laze (With Propagation Update)

struct node {
    int val, prop;
};

// Prop :
// 0 : No prop operation
// 1 : Prop operation should be done

node tree[409000];

void init(int L, int R, int pos) {
    if(L == R) {
        tree[pos].val = 0;
        tree[pos].prop = 0;
        return;
    }
    
    int mid = (L+R)>>1;
    
    init(L, mid, pos<<1);
    init(mid+1, R, pos<<1|1);

    tree[pos].val = 0;
    tree[pos].prop = 0;
}

int flipProp(int parentVal, int childVal) {
    if(parentVal == childVal)
        return 0;
    return parentVal;
}
        

void propagate(int L, int R, int pos) {
    if(tree[pos].prop == 0 || L == R)       // If no propagation tag
        return;                             // or leaf node, then no need to change
    
    int mid = (L+R)>>1;
    tree[pos<<1].val = (mid-L+1) - tree[pos<<1].val;        // Set left & right child value
    tree[pos<<1|1].val = (R-mid) - tree[pos<<1|1].val;
    
    tree[pos<<1].prop = flipProp(tree[pos].prop, tree[pos<<1].prop);    // Flip child prop according to problem
    tree[pos<<1|1].prop = flipProp(tree[pos].prop, tree[pos<<1|1].prop);
    tree[pos].prop = 0;         // Clear parent propagation tag
}

void update(int L, int R, int l, int r, int pos) {
    if(r < L || R < l)
        return;
    
    propagate(L, R, pos);
    if(l <= L && R <= r) {
        tree[pos].val = (R-L+1) - tree[pos].val;    // Value updated
        tree[pos].prop = 1;                         // Propagation tag set
        return;
    }
    
    int mid = (L+R)>>1;
    update(L, mid, l, r, pos<<1);
    update(mid+1, R, l, r, pos<<1|1);
    tree[pos].val = tree[pos<<1].val + tree[pos<<1|1].val;
}

int querySum(int L, int R, int l, int r, int pos) {
    if(r < L || R < l)
        return 0;
        
    propagate(L, R, pos);
    if(l <= L && R <= r)
        return tree[pos].val;
    
    int mid = (L+R)>>1;
    int lft = querySum(L, mid, l, r, pos<<1);
    int rht = querySum(mid+1, R, l, r, pos<<1|1);
    return lft+rht;
}

