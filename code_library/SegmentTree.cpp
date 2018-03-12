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

ll val[10];

// Only Supports Range Value set and Point Query
struct SegTreeProp {
    vector<int>tree;
    vector<bool>prop;
    
    void Resize(int n) {
        tree.resize(n*5);
        prop.resize(n*5);
    }
    
    void propagate(int pos, int l, int r) {
        if(!prop[pos] || l == r)
            return;
        tree[pos<<1|1] = tree[pos<<1] = tree[pos];
        prop[pos<<1|1] = prop[pos<<1] = 1;
        prop[pos] = 0;
    }
    
    void update(int pos, int l, int r, int L, int R, int val) {
        if(r < L || R < l)
            return;
        
        propagate(pos, l, r);
        if(L <= l && r <= R) {
            tree[pos] = val;
            prop[pos] = 1;
            return;
        }
        
        int mid = (l+r)>>1;
        update(pos<<1, l, mid, L, R, val);
        update(pos<<1|1, mid+1, r, L, R, val);
    }
    
    int query(int pos, int l, int r, int idx) {
        if(l == r)
            return tree[pos];
        
        propagate(pos, l, r);
        int mid = (l+r)>>1;
        if(idx <= mid)
            return query(pos<<1, l, mid, idx);
        else
            return query(pos<<1|1, mid+1, r, idx);
    }
};



// Segment Tree Lazy with Propagation (MOD used)
struct SegTreeRSQ {
    vector<ll>sum, prop;

    void Resize(int n) {
        sum.resize(5*n);
        prop.resize(5*n);
    }

    void init(int pos, int l, int r, ll val[]) {
        sum[pos] = prop[pos] = 0;
        if(l == r) {
            sum[pos] = val[l]%MOD;
            return;
        }
        int mid = (l+r)>>1;
        init(pos<<1, l, mid, val);
        init(pos<<1|1, mid+1, r, val);
        sum[pos] = (sum[pos<<1] + sum[pos<<1|1])%MOD;
    }

    void propagate(int pos, int l, int r) {
        if(prop[pos] == 0 || l == r)
            return;

        int mid = (l+r)>>1;
        sum[pos<<1] = (sum[pos<<1] + prop[pos]*(mid-l+1))%MOD;
        sum[pos<<1|1] = (sum[pos<<1|1] + prop[pos]*(r-mid))%MOD;
        prop[pos<<1] = (prop[pos<<1] + prop[pos])%MOD;
        prop[pos<<1|1] = (prop[pos<<1|1] + prop[pos])%MOD;
        prop[pos] = 0;
    }

    void update(int pos, int l, int r, int L, int R, ll val) {
        if(r < L || R < l)
            return;

        propagate(pos, l, r);
        if(L <= l && r <= R) {
            sum[pos] = (sum[pos] + val*(r-l+1))%MOD;
            prop[pos] = (prop[pos] + val)%MOD;
            return;
        }

        int mid = (l+r)>>1;
        update(pos<<1, l, mid, L, R, val);
        update(pos<<1|1, mid+1, r, L, R, val);
        sum[pos] = (sum[pos<<1] + sum[pos<<1|1])%MOD;
    }

    ll query(int pos, int l, int r, int L, int R) {
        if(r < L || R < l)
            return 0;

        propagate(pos, l, r);
        if(L <= l && r <= R)
            return sum[pos];

        int mid = (l+r)>>1;
        return (query(pos<<1, l, mid, L, R) + query(pos<<1|1, mid+1, r, L, R))%MOD;
    }
};



// SegTree with Lazy Propagation (Flip Count in Range)
// Prop :
// 0 : No prop operation
// 1 : Prop operation should be done

struct Node {
    int val, prop;
};

struct SegProp {
    vector<Node>tree;
    void init(int L, int R, int pos, ll val[]) {
        if(L == R) {
            tree[pos].val = 0;
            tree[pos].prop = 0;
            return;
        }
    
        int mid = (L+R)>>1;
        init(L, mid, pos<<1, val);
        init(mid+1, R, pos<<1|1, val);
        tree[pos].val = tree[pos].prop = 0;
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
        tree[pos<<1].val = (mid-L+1) - tree[pos<<1].val;                    // Set left & right child value
        tree[pos<<1|1].val = (R-mid) - tree[pos<<1|1].val;
        tree[pos<<1].prop = flipProp(tree[pos].prop, tree[pos<<1].prop);    // Flip child prop according to problem
        tree[pos<<1|1].prop = flipProp(tree[pos].prop, tree[pos<<1|1].prop);
        tree[pos].prop = 0;                                                 // Clear parent propagation tag
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
};


// ----------------------- Segment Tree Range Maximum Sum -----------------------

struct node {
	ll sum, prefix, suffix, ans;
	
	node(ll val = 0) {
		sum = prefix = suffix = ans = val;
	}
	
	void merge(node left, node right) {
		sum = left.sum + right.sum;
		prefix = max(left.prefix, left.sum+right.prefix);
		suffix = max(right.suffix, right.sum+left.suffix);
		ans = max(left.ans, max(right.ans, left.suffix+right.prefix));
	}
};


struct SegTreeRMS {
    vector<node>tree;

    void init(int pos, int l, int r, ll val[]) {
        if(l == r) {
            tree[pos] = node(val[l]);
            return;
        }
	
        int mid = (l+r)/2;
	
        init(pos*2, l, mid, val);
        init(pos*2+1, mid+1, r, val);
	
        tree[pos] = node(-INF);
        tree[pos].merge(tree[pos*2], tree[pos*2+1]);
    }

    void update(int pos, int l, int r, int x, int val) {
        if(x < l || r < x)
            return;
            
        if(l == r && l == x) {
            tree[pos] = node(val);
            return;
        }
	
        int mid = (l+r)/2;
        update(pos*2, l, mid, x, val);
        update(pos*2+1, mid+1, r, x, val);
        tree[pos] = node(-INF);
        tree[pos].merge(tree[pos*2], tree[pos*2+1]);
    }

    node query(int pos, int l, int r, int x, int y) {
        if(r < x || y < l)
            return node(-INF);
	
        if(x <= l && r <= y)
            return tree[pos];
	
        int mid = (l+r)/2;	
        node lft = query(pos*2, l, mid, x, y);
        node rht = query(pos*2+1, mid+1, r, x, y);
        node parent = node(-INF);
        parent.merge(lft, rht);
        return parent;
    }
};

// Merge Sort Tree
struct MergeSortTree {
    vector<int>tree[1200000];

    void init(int pos, int l, int r, ll val[]) {
        if(l == r) {
            tree[pos].pb(val[l]);
            return;
        }
    
        int mid = (l+r)>>1;
        init(pos<<1, l, mid, val);
        init(pos<<1|1, mid+1, r, val);
        merge(tree[pos<<1].begin(), tree[pos<<1].end(), tree[pos<<1|1].begin(), tree[pos<<1|1].end(), back_inserter(tree[pos]));
    }

    int query(int pos, int l, int r, int L, int R, int k) {
        if(r < L || R < l)
            return 0;
    
        if(L <= l && r <= R)
            return (int)tree[pos].size() - (upper_bound(tree[pos].begin(), tree[pos].end(), k) - tree[pos].begin());
    
        int mid = (l+r)>>1;
        return query(pos<<1, l, mid, L, R, k) + query(pos<<1|1, mid+1, r, L, R, k);
    }
};



// Segment Tree Sequence (Lazy Propagation):: Contains sequnce A + 2A + 3A + ..... nA
struct SegTreeSeq {
    vector<ll>sum, prop;

    void Resize(int n) {
        sum.resize(n*5);
        prop.resize(n*5);
    }

    ll intervalSum(ll l, ll r, ll val) {
        ll interval = (r*(r+1))/2LL - (l*(l-1))/2LL;
        return (interval*val+MOD)%MOD;
    }

    void propagate(int pos, int l, int r) {
        if(prop[pos] == 0 || l == r)
            return;
        
        int mid = (l+r)>>1;
        sum[pos<<1] = (sum[pos<<1] + intervalSum(l, mid, prop[pos]))%MOD;
        sum[pos<<1|1] = (sum[pos<<1|1] + intervalSum(mid+1, r, prop[pos]))%MOD;
        prop[pos<<1] = (prop[pos<<1] + prop[pos])%MOD;
        prop[pos<<1|1] = (prop[pos<<1|1] + prop[pos])%MOD;
        prop[pos] = 0;
    }

    void init(int pos, int l, int r, ll val[]) {
        sum[pos] = prop[pos] = 0;
        if(l == r) {
            sum[pos] = (val[l]*l)%MOD;
            return;
        }
        int mid = (l+r)>>1;
        init(pos<<1, l, mid, val);
        init(pos<<1|1, mid+1, r, val);
        sum[pos] = (sum[pos<<1] + sum[pos<<1|1])%MOD;
    }

    void update(int pos, int l, int r, int L, int R, ll val) {      // Range Update
        if(r < L || R < l)
            return;
        propagate(pos, l, r);
        if(L <= l && r <= R) {
            sum[pos] = (intervalSum(l, r, val) + sum[pos])%MOD;
            prop[pos] = (val + prop[pos])%MOD;
            return;
        }
        int mid = (l+r)>>1;
        update(pos<<1, l, mid, L, R, val);
        update(pos<<1|1, mid+1, r, L, R, val);
        sum[pos] = (sum[pos<<1] + sum[pos<<1|1])%MOD;
    }
    
    ll query(int pos, int l, int r, int L, int R) {     // Range Query
        if(r < L || R < l || L > R)
            return 0;
        propagate(pos, l, r);
        if(L <= l && r <= R)
            return sum[pos];
        int mid = (l+r)>>1;
        return (query(pos<<1, l, mid, L, R) + query(pos<<1|1, mid+1, r, L, R))%MOD;
    }
};


int main() {
    return 0;
}
