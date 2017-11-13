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



// ----------------------------NOT tested 2D segment tree-----------------------

// reference:
// https://stackoverflow.com/questions/25121878/2d-segment-quad-tree-explanation-with-c/25122078#25122078

#include <stdio.h>
#include <string.h>
//#include <bits/stdc++.h>
//using namespace std;

// x1, y1 is upper left point, x2, y2 lower point
// 

int tree[4100][4100];


/*
void init(int px, int py, int x1, int y1, int x2, int y2) {
    if(x1 > x2 || y1 > y2)
        return;
    if(x1 == x2 && y1 == y2) {
        tree[pos] = v[x1][y1];
        return;
    }
    int midX = (x1+x2)>>1, midY = (y1+y2)>>1;
    int Px = 2*px, Py = 2*py;    

    init(Px, Py, x1, y1, midX, midY);          // lftUp
    init(Px+1, Py, midX+1, y1, x2, midY);        // rhtUp
    init(Px, Py+1, x1, midY+1, midX, y2);          // lftDown
    init(Px+1, Py+1, midX+1, midY+1, x2, y2);      // rhtDown
    
    //tree[pos] = lftUp + rhtUp + lftDown + rhtDown;      // fix this
    tree[px][py] = tree[Px][Py]+tree[Px+1][Py]+tree[Px][Py+1]+tree[Px+1][Py+1];
}*/

void update(int px, int py, int x1, int y1, int x2, int y2, int x, int y, int val) {
    if(x1 > x2 || y1 > y2)
        return;
    if(x > x2 || y > y2 || x < x1 || y < y1)
        return;
    if(x1 == x2 && y1 == y2) {
        //cout << "set at " << x1 << " " << y1 << " :: " << pos << endl;
        tree[pos] += val;
        return;
    }
    
    int midX = (x1+x2)>>1, midY = (y1+y2)>>1;
    int Px = 2*px, Py = 2*py;    

    update(Px, Py, x1, y1, midX, midY, x, y, val);
    update(Px+1, Py, midX+1, y1, x2, midY, x, y, val);
    update(Px, Py+1, x1, midY+1, midX, y2, x, y, val);
    update(Px+1, Py+1, midX+1, midY+1, x2, y2, x, y, val);

    tree[px][py] = tree[Px][Py]+tree[Px+1][Py]+tree[Px][Py+1]+tree[Px+1][Py+1];
}

int query(int px, int py, int x1, int y1, int x2, int y2, int xq1, int yq1, int xq2, int yq2) {
    printf("outQ : %d : %d %d %d %d :: %d\n", pos, x1, y1, x2, y2, tree[pos]);
    if(x1 > x2 || y1 > y2)
        return 0;
    
    if(xq1 > x2 || yq1 > y2 || xq2 < x1 || yq2 < y1)
        return 0;

    if(x1 >= xq1 && x2 <= xq2 && y1 >= yq1 && y2 <= yq2) {
        printf("q : %d : %d %d %d %d :: %d\n", pos, x1, y1, x2, y2, tree[pos]);
        return tree[pos];
    }
    
    int midX = (x1+x2)>>1, midY = (y1+y2)>>1;
    int Px = 2*px, Py = 2*py;    

    int lftUp = query(Px, Py, x1, y1, midX, midY, xq1, yq1, xq2, yq2);
    int rhtUp = query(Px+1, Py, midX+1, y1, x2, midY, xq1, yq1, xq2, yq2);
    int lftDown = query(Px, Py+1 x1, midY+1, midX, y2, xq1, yq1, xq2, yq2);
    int rhtDown = query(Px+1, Py+1, midX+1, midY+1, x2, y2, xq1, yq1, xq2, yq2);
    
    return (lftUp + rhtUp + lftDown + rhtDown);
}

int query(int px, int py, int x1, int x2, int y1, int y2)

void printer(int pos, int x1, int y1, int x2, int y2) {
    if(x1 > x2 || y1 > y2)
        return;
        
    printf("pos %d: %d %d %d %d :: %d\n", pos, x1, y1, x2, y2, tree[pos]);
    if(x1 == x2 && y1 == y2) {
        return;
    }
    int midX = (x1+x2)>>1, midY = (y1+y2)>>1;
    
    printer(4*pos-2, x1, y1, midX, midY);          // lftUp
    printer(4*pos-1, midX+1, y1, x2, midY);        // rhtUp
    printer(4*pos, x1, midY+1, midX, y2);          // lftDown
    printer(4*pos+1, midX+1, midY+1, x2, y2);      // rhtDown
}

int main() {
    int t, q, n, x1, x2, y1, y2, val;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &q);
        while(q--) {
            scanf("%d", &n);
            if(n == 0) {
                scanf("%d %d", &x1, &y1);
                if(query(1, 1, 1000, 1000, x1, y1))    
    }
}
