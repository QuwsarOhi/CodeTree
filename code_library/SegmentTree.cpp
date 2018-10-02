// Segment Tree

// Only Supports Range Value SET (NOT UPDATE) and Point Query
struct SegTreeSetVal {
    vector<int>tree;
    vector<bool>prop;
    
    void Resize(int n) {
        tree.resize(n*5);
        prop.resize(n*5);
    }
    
    void propagate(int pos, int l, int r) {
        if(!prop[pos] || l == r) return;
        tree[pos<<1|1] = tree[pos<<1] = tree[pos];
        prop[pos<<1|1] = prop[pos<<1] = 1;
        prop[pos] = 0;
    }
    
    void SetVal(int pos, int l, int r, int L, int R, int val) {     // Set value val in range [L, R]
        if(r < L || R < l) return;
        propagate(pos, l, r);
        if(L <= l && r <= R) {
            tree[pos] = val;
            prop[pos] = 1;
            return;
        }
        int mid = (l+r)>>1;
        SetVal(pos<<1, l, mid, L, R, val);
        SetVal(pos<<1|1, mid+1, r, L, R, val);
    }
    
    int query(int pos, int l, int r, int idx) {             // Can be modified to range query
        if(l == r) return tree[pos];
        propagate(pos, l, r);
        int mid = (l+r)>>1;
        if(idx <= mid)  return query(pos<<1, l, mid, idx);
        else            return query(pos<<1|1, mid+1, r, idx);
}};


// Segment Tree Range Sum : Lazy with Propagation (MOD used)
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
        if(prop[pos] == 0 || l == r) return;
        int mid = (l+r)>>1;
        
        sum[pos<<1] = (sum[pos<<1] + prop[pos]*(mid-l+1))%MOD;
        sum[pos<<1|1] = (sum[pos<<1|1] + prop[pos]*(r-mid))%MOD;
        prop[pos<<1] = (prop[pos<<1] + prop[pos])%MOD;
        prop[pos<<1|1] = (prop[pos<<1|1] + prop[pos])%MOD;
        prop[pos] = 0;
    }

    void update(int pos, int l, int r, int L, int R, ll val) {
        if(r < L || R < l) return;
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
        if(r < L || R < l) return 0;
        propagate(pos, l, r);
        if(L <= l && r <= R) return sum[pos];
        int mid = (l+r)>>1;
        return (query(pos<<1, l, mid, L, R) + query(pos<<1|1, mid+1, r, L, R))%MOD;
}};


// Dynamic Range Segment Tree (values can be deleted from right)
// Resize the Segment Tree with the maximum length of value
// Segment Tree Range Sum, Range Update, And Single point Value Change (If the last value was deleted)
// http://codeforces.com/contest/283/problem/A

// Range Sum with Carry Value
struct SegSum {
    int tree[MAX*4], carry[MAX*4];
    
    void init() {
        memset(tree, 0, sizeof tree);
        memset(carry, 0, sizeof carry);
    }
    
    void Update(int pos, int l, int r, int x, int y, ll val) {              // Update value at range/point
        if(y < l || x > r) return;
        if(x <= l && r <= y) {
            tree[pos] += (r-l+1)*val;
            carry[pos] += val;
            return;
        }
        int mid = (l+r)>>1;
        Update(pos<<1, l, mid, x, y, val);
        Update(pos<<1|1, mid+1, r, x, y, val);
        tree[pos] = tree[pos<<1] + tree[pos<<1|1] + (r-l+1)*carry[pos];
    }

    ll Read(int pos, int l, int r, int x, int y, ll Carry = 0) {            // Read value at range/point
        if(y < l || x > r)      return 0;
        if(x <= l && r <= y)    return tree[pos] + Carry * (r-l+1);
        ll mid = (l+r)>>1;	
        ll lft = Read(pos<<1, l, mid, x, y, Carry + carry[pos]);
        ll rht = Read(pos<<1|1, mid+1, r, x, y, Carry + carry[pos]);
        return lft + rht;
    }

    // Sets value at idx
    void Set(int pos, int l, int r, int idx, ll val, ll Carry = 0) {
        if(l == r) {
            tree[pos] = val + (-1*Carry);   // Extra carry values are eleminated in such way
            carry[pos] = 0;                 // that the subtraction is always the new value
            return;
        }
        int mid = (l+r)>>1;
        if(idx <= mid)  Set(pos<<1, l, mid, idx, val, Carry + carry[pos]);
        else            Set(pos<<1|1, mid+1, r, idx, val, Carry + carry[pos]);
        tree[pos] = tree[pos<<1] + tree[pos<<1|1] + (r-l+1) * carry[pos];
}};

// SegTree with Lazy Propagation (Flip Count in Range)
// Prop :
// 0 : No prop operation
// 1 : Prop operation should be done

struct SegProp {
    struct Node { int val, prop; };
    
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
        if(parentVal == childVal) return 0;
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
        if(r < L || R < l) return;
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
        if(r < L || R < l) return 0;
        propagate(L, R, pos);
        if(l <= L && R <= r) return tree[pos].val;
        int mid = (L+R)>>1;
        int lft = querySum(L, mid, l, r, pos<<1);
        int rht = querySum(mid+1, R, l, r, pos<<1|1);
        return lft+rht;
}};

// ----------------------- Segment Tree Range Maximum Sum -----------------------
struct SegTreeRMS {
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
    }};

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
        if(x < l || r < x) return;
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
        if(r < x || y < l)      return node(-INF);
        if(x <= l && r <= y)    return tree[pos];
        int mid = (l+r)/2;	
        node lft = query(pos*2, l, mid, x, y);
        node rht = query(pos*2+1, mid+1, r, x, y);
        node parent = node(-INF);
        parent.merge(lft, rht);
        return parent;
}};

// Segment Tree Insert/Remove value, Find I'th Value
struct SegTreeInsertRemove {                    // Finds/Deletes I'th value from array/SegTree
    int tree[MAX*4];
    void init(int pos, int L, int R) {
        if(L == R) {
            tree[pos] = 1;
            return;
        }
        int mid = (L+R)>>1;
        init(pos<<1, L, mid);
        init(pos<<1|1, mid+1, R);
        tree[pos] = tree[pos<<1]+tree[pos<<1|1];
    }
    int SearchVal(int pos, int L, int R, int I, bool removeVal = 0) {         // Find I'th value in Segment Tree, removes it if removeVal = 1 
        if(L == R) {
            tree[pos] = (removeVal ? 0:1);
            return L;
        }
        int mid = (L+R)>>1;
        if(I <= tree[pos<<1]) {
            int idx = SearchVal(pos<<1, L, mid, I, removeVal);
            if(removeVal) tree[pos] = tree[pos<<1] + tree[pos<<1|1];
            return idx;
        }
        else {
            int idx = SearchVal(pos<<1|1, mid+1, R, I-tree[pos<<1], removeVal);
            if(removeVal) tree[pos] = tree[pos<<1] + tree[pos<<1|1];
            return idx;
}}};

// Segment Tree Range Bit flip, set, reset and Query
// propataion tags:
// 0 - no change, 1 - all set to one, 2 - all set to zero, 3 - all need to be flipped
struct RangeBitQuery {
    vector<pair<int, int> >tree;
    RangeBitQuery() { tree.resize(MAX*4); }
    
    void init(int pos, int L, int R, string &s) {
        tree[pos].second = 0;
        if(L == R) {
            tree[pos].first = (s[L] == '1');
            return;
        }
        int mid = (L+R)>>1;
        init(pos<<1, L, mid, s);
        init(pos<<1|1, mid+1, R, s);
        tree[pos].first = tree[pos<<1].first + tree[pos<<1|1].first;
    }

    int Convert(int tag) {          // This function generates output tag of child node if the parent node is set to 3 (fipped)
        if(tag == 1) return 2;
        if(tag == 2) return 1;
        if(tag == 3) return 0;
        return 3;
    }

    // On every layer of update or query, this Propagation func should be called to pre-process previous left off operations
    void Propagate(int L, int R, int parent) {      // Propagate parent node to child nodes (left and right)
        if(tree[parent].second == 0) return;        // and sets parent node's propagation tag to 0
        int mid = (L+R)>>1;
        int lft = parent<<1, rht = parent<<1|1;
        if(tree[parent].second == 1) {
            tree[lft].first = mid-L+1;
            tree[rht].first = R-mid;
        }
        else if(tree[parent].second == 2)
            tree[lft].first = tree[rht].first = 0;
        else if(tree[parent].second == 3) {
            tree[lft].first = (mid-L+1) - tree[lft].first;
            tree[rht].first = (R-mid) - tree[rht].first;
        }
        if(L != R) {                                // If the child nodes also contain propagate tag (and the childs are not leaf node)
            if(tree[parent].second == 1 || tree[parent].second == 2)
                tree[lft].second = tree[rht].second = tree[parent].second;
            else {
                tree[lft].second = Convert(tree[lft].second);
                tree[rht].second = Convert(tree[rht].second);
        }}
        tree[parent].second = 0;                                            // Parent node's prop tag set to zero
        if(L!=R) tree[parent].first = tree[lft].first + tree[rht].first;    // If this is not the leaf node, calculate child node's sum
    }

    void updateOn(int pos, int L, int R, int l, int r) {                // Turn on bits in range [l, r]
        if(r < L || R < l || L > R) return;
        Propagate(L, R, pos);
        if(l <= L && R <= r) {
            tree[pos].first = (R-L+1);
            tree[pos].second = 1;
            return;
        }
        int mid = (L+R)>>1;
        updateOn(pos<<1, L, mid, l, r);
        updateOn(pos<<1|1, mid+1, R, l, r);
        tree[pos].first = tree[pos<<1].first + tree[pos<<1|1].first;
    }

    void updateOff(int pos, int L, int R, int l, int r) {               // Turn off bits in range [l, r]
        if(r < L || R < l || L > R) return;
        Propagate(L, R, pos);
        if(l <= L && R <= r) {
            tree[pos].first = 0;
            tree[pos].second = 2;
            return;
        }
        int mid = (L+R)>>1;
        updateOff(pos<<1, L, mid, l, r);
        updateOff(pos<<1|1, mid+1, R, l, r);
        tree[pos].first = tree[pos<<1].first + tree[pos<<1|1].first;
    }

    void updateFlip(int pos, int L, int R, int l, int r) {              // Flip bits in range [l, r]
        if(r < L || R < l || L > R) return;
        Propagate(L, R, pos);
        if(l <= L && R <= r) {
            tree[pos].first = abs(R-L+1 - tree[pos].first);
            tree[pos].second = 3;
            return;
        }
        int mid = (L+R)>>1;
        updateFlip(pos<<1, L, mid, l, r);
        updateFlip(pos<<1|1, mid+1, R, l, r);
        tree[pos].first = tree[pos<<1].first + tree[pos<<1|1].first;
    }

    int querySum(int pos, int L, int R, int l, int r) {                 // Returns number of set bit in range [l, r]
        if(r < L || R < l || L > R) return 0;
        Propagate(L, R, pos);
        if(l <= L && R <= r) return tree[pos].first;
        int mid = (L+R)>>1;
        return querySum(pos<<1, L, mid, l, r) + querySum(pos<<1|1, mid+1, R, l, r);
}};

// Merge Sort Tree
struct MergeSortTree {
    vector<int>tree[MAX*4];

    void init(int pos, int l, int r, ll val[]) {
        tree[pos].clear();                              // Clears past values
        if(l == r) {
            tree[pos].push_back(val[l]);
            return;
        }
        int mid = (l+r)>>1;
        init(pos<<1, l, mid, val);
        init(pos<<1|1, mid+1, r, val);
        merge(tree[pos<<1].begin(), tree[pos<<1].end(), tree[pos<<1|1].begin(), tree[pos<<1|1].end(), back_inserter(tree[pos]));
    }

    int query(int pos, int l, int r, int L, int R, int k) {
        if(r < L || R < l) return 0;
        if(L <= l && r <= R)
            return (int)tree[pos].size() - (upper_bound(tree[pos].begin(), tree[pos].end(), k) - tree[pos].begin());        // MODIFY
        int mid = (l+r)>>1;
        return query(pos<<1, l, mid, L, R, k) + query(pos<<1|1, mid+1, r, L, R, k);
}};


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
        if(prop[pos] == 0 || l == r) return;
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
        if(r < L || R < l) return;
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
        if(r < L || R < l || L > R) return 0;
        propagate(pos, l, r);
        if(L <= l && r <= R) return sum[pos];
        int mid = (l+r)>>1;
        return (query(pos<<1, l, mid, L, R) + query(pos<<1|1, mid+1, r, L, R))%MOD;
}};

// Segment Tree Bracket Sequencing, Modify position bracket and check if it is valid
struct BracketTree {
    struct node{
        int BrcStart, BrcEnd;               // number of start bracket, number of end bracket
        bool isOk = 0;                      // is the sequence valid
    
        node(int a = 0, int b = 0) {
            BrcStart = a;
            BrcEnd = b;
            isOk = (BrcStart == 0 && BrcEnd == 0);
        }
        node(char c) {
            if(c == '(')    BrcStart = 1, BrcEnd = 0;
            else            BrcStart = 0, BrcEnd = 1;
        }
        void mergeNode(node lft, node rht) {
            if(lft.isOk && rht.isOk)
                BrcStart = 0, BrcEnd = 0, isOk = 1;
            else {
                int match = min(lft.BrcStart, rht.BrcEnd);
                BrcStart = lft.BrcStart - match + rht.BrcStart;
                BrcEnd = lft.BrcEnd + rht.BrcEnd - match;
                (BrcStart == 0 && BrcEnd == 0) ? isOk = 1: isOk = 0;
    }}};
 
    node tree[MAX*4];
    void init(int pos, int L, int R, char s[]) {
        if(L == R) {
            tree[pos] = node(s[L]);
            return;
        }
        int mid = (L+R)>>1;
        init(pos<<1, L, mid, s);
        init(pos<<1|1, mid+1, R, s);
        tree[pos].mergeNode(tree[pos<<1], tree[pos<<1|1]);
    }
    void update(int pos, int L, int R, int idx, char val) {         // idx : index of the changed value
        if(idx < L || R < idx) return;                              // val : changed bracket sequence in char ( or )
        if(L == R && L == idx) {
            tree[pos] = node(val);
            return;
        }
        int mid = (L+R)>>1;
        update(pos<<1, L, mid, idx, val);
        update(pos<<1|1, mid+1, R, idx, val);
        tree[pos].mergeNode(tree[pos<<1], tree[pos<<1|1]);
    }
    bool isValid() {                        // Returns True if sequence is valid
        return tree[1].isOk;
}};

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

// Path Compression Basics
// in segment tree comparison of index must be checked like (where l, r is the query range):
// outside of range [l, r]  :  r < point[L] || point[R] < l
// inside of range  [l, r]  :  l <= point[L] && point[R] <= r
// The Queries {l, r} will be in a queue, and processed after CompressPath and initialization is done

void CompressPath(vector<int> &point) {                                 // point contains all left and right boundary and query boundaries
	point.push_back(0);                                                 // push_back a minimum value which is lower than input values 
    sort(point.begin(), point.end());                                   // so that the input values start from index 1
	point.erase(unique(point.begin()+1, point.end()), point.end());     // Only unique points taken, this will be the compressed points
}

// Finding Number of Uniques in Range + OFFLINE processing
 
struct FindUnique {
    int tree[4*MAX], prop[4*MAX], v[MAX], IDX[MAX];
    map<int, vector<int> >Map;
    map<pair<int, int>, int>Ans;
    vector<pair<int, int> > Query;
    
    void init() {
        memset(IDX, -1, sizeof IDX);
        memset(tree, 0, sizeof tree);
        Ans.clear(), Map.clear(), Query.clear();
    }
    void update(int pos, int L, int R, int idx, int val) {
        if(idx < L || R < idx) return;
        if(L == R) {
            tree[pos]+= val;
            return;
        }
        int mid = (L+R)>>1;
        update(pos<<1, L, mid, idx, val);
        update(pos<<1|1, mid+1, R, idx, val);
        tree[pos] = tree[pos<<1] + tree[pos<<1|1];
    }
    int query(int pos, int L, int R, int l, int r) {
        if(r < L || R < l)      return 0;
        if(l <= L && R <= r)    return tree[pos];
        int mid = (L+R)>>1;
        int lft = query(pos<<1, L, mid, l, r);
        int rht = query(pos<<1|1, mid+1, R, l, r);
        return lft+rht;
    }
    void ArrayInput(int SZ) {
        for(int i = 1; i <= SZ; ++i) scanf("%d", &v[i]);
    }
    void QueryInput(int q) {
        int l, r;
        while(q--) {
            scanf("%d %d", &l, &r);
            Query.push_back(make_pair(l, r));
            Map[r].push_back(l);                        // Used for sorting
    }}
    void GenAns(int SZ) {
        map<int, vi> :: iterator it;
        int lPos = 0;
        for(it = Map.begin(); it != Map.end(); ++it) {      // For each query's right points
            while(lPos < it->first) {                       // Update from last left position to this queries right position
                lPos++;
                if(IDX[v[lPos]] == -1) {
                    IDX[v[lPos]] = lPos;
                    update(1, 1, SZ, lPos, 1);              // if new value found, increment 1 to the
                }
                else {
                    int pastIDX = IDX[v[lPos]];
                    IDX[v[lPos]] = lPos;
                    update(1, 1, SZ, pastIDX, -1);           // if value found previous, then remove 1 from previous index (add -1)
                    update(1, 1, SZ, lPos, 1);               // add 1 to the new position
            }}
            for(int i = 0; i < (int)(it->second).size(); ++i)       // Range sum query for all queries that ends on this point
                Ans[make_pair(it->second[i], it->first)] = query(1, 1, SZ, it->second[i], it->first);       
    }}
    void PrintAns() {
        for(int i = 0; i < (int)Query.size(); ++i)                    // Output according to input query
            printf("%d\n", Ans[mp(Query[i].first, Query[i].second)]);
}};

struct STreeMultipleOf3 {
    int tree[4*MAX][3], prop[4*MAX];
    void init(int pos, int L, int R) {
        if(L == R) {
            tree[pos][0] = 1, tree[pos][1] = tree[pos][2] = 0;
            return;
        }
        int mid = (L+R)>>1;
        init(pos<<1, L, mid);
        init(pos<<1|1, mid+1, R);
        for(int i = 0; i < 3; ++i)
            tree[pos][i] = tree[pos<<1][i] + tree[pos<<1|1][i];
    }
    void shiftVal(int pos, int step) {
        step %= 3;
        if(step == 0) return;
        swap(tree[pos][2], tree[pos][1]);
        swap(tree[pos][1], tree[pos][0]);
        if(step == 2) {
            swap(tree[pos][2], tree[pos][1]);
            swap(tree[pos][1], tree[pos][0]);
    }}
    void propagate(int pos, int L, int R) {
        if(L == R || prop[pos] == 0) return;
        shiftVal(pos<<1, prop[pos]), shiftVal(pos<<1|1, prop[pos]);
        prop[pos<<1] += prop[pos], prop[pos<<1|1] += prop[pos];
        prop[pos] = 0;
    }
    void update(int pos, int L, int R, int l, int r) {              // update l to r by 1
        if(r < L || R < l) return;
        if(prop[pos] != 0) propagate(pos, L, R);
        if(l <= L && R <= r) {
            shiftVal(pos, 1);
            prop[pos] += 1;
            return;
        }
        int mid = (L+R)>>1;
        update(pos<<1, L, mid, l, r);
        update(pos<<1|1, mid+1, R, l, r);
        for(int i = 0; i < 3; ++i)
            tree[pos][i] = tree[pos<<1][i] + tree[pos<<1|1][i];
    }
    int query(int pos, int L, int R, int l, int r) {                // return number of multiple of 3 in range l to r
        if(r < L || R < l) return 0;
        propagate(pos, L, R);
        if(l <= L && R <= r) return tree[pos][0];
        int mid = (L+R)>>1;
        int lft = query(pos<<1, L, mid, l, r);
        int rht = query(pos<<1|1, mid+1, R, l, r);
        return lft+rht;
}};

// CS Academy Candles :https://csacademy.com/contest/archive/task/candles/statement/
struct SortedST {                                       // Performs -1 from n nodes and keeps nodes sorted (descending order)
    struct node { int val, prop; };
    node tree[5*MAX];
    void init(int pos, int l, int r, int val[]) {       // val[] must be sorted from hi to low
        if(l == r) {
            tree[pos].val = val[l];
            tree[pos].prop = 0;
            return;
        }
        int mid = (l+r)>>1;
        init(pos<<1, l, mid, val), init(pos<<1|1, mid+1, r, val);
        tree[pos].val = max(tree[pos<<1].val, tree[pos<<1|1].val);
        tree[pos].prop = 0;
    }
    void propagate(int pos, int l, int r) {
        if(tree[pos].prop == 0 || l == r) {
            tree[pos].prop = 0;
            return;
        }
        tree[pos<<1|1].prop += tree[pos].prop;
        tree[pos<<1].prop += tree[pos].prop;
        tree[pos<<1].val += tree[pos].prop;
        tree[pos<<1|1].val += tree[pos].prop;
        tree[pos].val = max(tree[pos<<1].val, tree[pos<<1|1].val);
        tree[pos].prop = 0;
    }
    int findVal(int pos, int l, int r, int idx) {               // Finds value in index idx
        if(l == r) return tree[pos].val;
        propagate(pos, l, r);    
        int mid = (l+r)>>1;
        if(idx <= mid)  return findVal(pos<<1, l, mid, idx);
        else            return findVal(pos<<1|1, mid+1, r, idx);
    }
    void update(int pos, int l, int r, int L, int R, int val) {
        if(r < L || R < l) return;
        propagate(pos, l, r);
        if(L <= l && r <= R) {
            tree[pos].val += val;
            tree[pos].prop += val;
            return;
        }
        int mid = (l+r)>>1;
        update(pos<<1, l, mid, L, R, val);
        update(pos<<1|1, mid+1, r, L, R, val);
        tree[pos].val = max(tree[pos<<1].val, tree[pos<<1|1].val);
    }
    int rightMost(int pos, int l, int r, int val) {             // Finds rightmost value in tree that contains val
        if(l == r) return l;
        if(tree[pos].val < val) return 0;
        propagate(pos, l, r);
        int mid = (l+r)>>1;
        if(tree[pos<<1|1].val >= val) return rightMost(pos<<1|1, mid+1, r, val);
        return rightMost(pos<<1, l, mid, val);
    }
    bool MinusQuery(int q, int n) {                             // Decreases q nodes by 1
        if(q > n) return 0;
        int posVal = findVal(1, 1, n, q);
        if(posVal <= 0) return 0;
        int r = rightMost(1, 1, n, posVal);
        int l = rightMost(1, 1, n, posVal+1);
        int rem = q - l;
        if(l >= 1)          update(1, 1, n, 1, l, -1);
        if(r-rem+1 <= r)    update(1, 1, n, r-rem+1, r, -1);
        return 1;
}};


struct HashTree {
    vector<ll>sum, propSum, propMul;
    ll mod, len;
    void init(int n, ll _mod, ll arr[]) {
        sum.resize(4*n);
        propSum.resize(4*n);
        propMul.resize(4*n);
        mod = _mod, len = n;
        init(1, 1, len, arr);
    }
    inline ll add(ll a, ll b) {
        //a = ((a%mod) + mod)%mod, b = ((b%mod) + mod)%mod;         // Can Cause TLE
        return (a+b)%mod;
    }
    inline ll mul(ll a, ll b) {
        //a = ((a%mod) + mod)%mod, b = ((b%mod) + mod)%mod;         // Can Cause TLE
        return (a*b)%mod;
    }
    void pushDown(int child, int par) {                             // just push down the values
        propSum[child] = mul(propSum[child], propMul[par]);
        propSum[child] = add(propSum[child], propSum[par]);
        propMul[child] = mul(propMul[child], propMul[par]);
    }
    void init(int pos, int l, int r, ll arr[]) {                              // NOTE: init must be called!!
        sum[pos] = propSum[pos] = 0, propMul[pos] = 1;
        if(l == r) {
            sum[pos] = arr[l];
            return;
        }
        int mid = (l+r)>>1;
        init(pos<<1, l, mid, arr);
        init(pos<<1|1, mid+1, r, arr);
        sum[pos] = add(sum[pos<<1], sum[pos<<1|1]);
    }
    void propagate(int pos, int l, int r) {                         // sets and pushes values to child
        if(propMul[pos] == 1 and propSum[pos] == 0) return;
        sum[pos] = add(mul(sum[pos], propMul[pos]), mul(r-l+1, propSum[pos]));
        if(l == r) {
            propMul[pos] = 1, propSum[pos] = 0;
            return;
        }
        pushDown(pos<<1, pos), pushDown(pos<<1|1, pos);
        propMul[pos] = 1, propSum[pos] = 0;
    }
    void update(int pos, int l, int r, int L, int R, ll val, int type) {
        propagate(pos, l, r);
        if(r < L or R < l) return;
        if(L <= l and r <= R) {
            if(type == 0)                               // add val in [L, R]
                propSum[pos] = add(propSum[pos], val);
            else if(type == 1) {                        // multiply val in [L, R]
                propSum[pos] = mul(propSum[pos], val);
                propMul[pos] = mul(propMul[pos], val);
            }
            else if(type == 2)                          // set all value = val
                propSum[pos] = val, propMul[pos] = 0;
            propagate(pos, l, r);
            return;
        }
        
        int mid = (l+r)>>1;
        update(pos<<1, l, mid, L, R, val, type);
        update(pos<<1|1, mid+1, r, L, R, val, type);
        sum[pos] = add(sum[pos<<1], sum[pos<<1|1]);
    }
    ll query(int pos, int l, int r, int L, int R) {
        propagate(pos, l, r);
        if(r < L || R < l) return 0;
        if(L <= l && r <= R) return sum[pos];
        int mid = (l+r)>>1;
        return add(query(pos<<1, l, mid, L, R), query(pos<<1|1, mid+1, r, L, R));
    }
    
    ll query(int l, int r)              { return query(1, 1, len, l, r); }
    void add(int l, int r, ll val)      { update(1, 1, len, l, r, val, 0); }
    void mul(int l, int r, ll val)      { update(1, 1, len, l, r, val, 1); }
    void set(int l, int r, ll val)      { update(1, 1, len, l, r, val, 2); }   
};
