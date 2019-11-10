Data Structure:
 * Policy Based Data Structure : insert, erase, and binary search in log(n) with element index
 * DSU : Disjoint Set Union, Bipartite DSU, Weighted DSU
 * Trie : Dynamic Trie, Static Trie
 * Sparse Table : Implemented in LCA and Suffix Array
 * Square Root Decomposition : Block Decomposition
 * MOs Offline Decomposition :  MOs on array 
                                MOs on tree parent node
                                MOs on tree path
 * Fenwick Tree: Point Query Range Update + Range Update Point Query
                 Inverse Cumulative sum [Csum from 1 to idx, instead of idx to MaxVal]
                 2D, 3D Fenwick Tree
 * Segment Tree: Range Sum with propagation
                 Find Kth value and insert/erase [can be done in Policy Based DS]
                 Merge Sort Tree
                 Maximum cumulative sum from all possible range in a segment
                 Valid bracket sequence check in range and single pos update
                 Longest valid bracket sequence in range
                 Compression
                 Offline Processing
 * Persistant Segment Tree

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define at(X)          find_by_order(X)
#define lessThan(X)    order_of_key(X)
using namespace __gnu_pbds;
template<class T> using ordered_set = tree< T, null_type, less_equal<T>, 
                                            rb_tree_tag, tree_order_statistics_node_update>;
/* Key, Mapped-Policy, Key Comparison Func, underlying data Structure, updating node policy
   Key Comparison Func : Defines how data will be stored (incleasing, decrasing order)
            less<int>          -   Same value occurs once & increasing                      SET
            less_equal<int>    -   Same value occurs one or more & increasing          MULTISET
            greater<int>, greater_equal<int>
   find_by_order(x) returns x'th elements iterator
   order_of_key(x) returns number of values less than (or equal to) x */

/* ------------------------------ DSU with Path Compression ------------------------------ */
struct DSU {
    vector<int>u_list, u_set;                       // u_list[x] : the size of a set x
    DSU() {}                                        // u_set[x]  : the root of x
    DSU(int SZ) { init(SZ); }
    int unionRoot(int n) {                          // Root of node n
        if(u_set[n] == n) return n;
        return u_set[n] = unionRoot(u_set[n]); }
    int makeUnion(int a, int b) {                   // Union making with compression
        int x = unionRoot(a), y = unionRoot(b);
        if(x == y) return x;                        // If both are in same set
        else if(u_list[x] > u_list[y]) {            // Makes x root (y -> x)
            u_set[y] = x;
            u_list[x] += u_list[y];                 // Root's size is increased
            return x; 
        } else {                                      // Makes y root (x -> y)
            u_set[x] = y;
            u_list[y] += u_list[x];                 // Root's size is increased
            return y;
    }} void init(int len) {                            // Initializer
        u_list.resize(len+5), u_set.resize(len+5);
        for(int i = 0; i <= len+3; i++)
            u_set[i] = i, u_list[i] = 1;
    }
    bool isRoot(int x)              { return u_set[x] == x; }
    bool isRootContainsMany(int x)  { return (isRoot(x) && (u_list[x] > 1)); }
    bool isSameSet(int a, int b)    { return (unionRoot(a) == unionRoot(b));
}};
// Bipartite DSU (Tested)
struct BipartiteDSU {
    vector<int>u_list, u_set, u_color;                      // u_color : color of nodes
    vector<bool>missmatch;                                  // Bicolor missmatch
    BipartiteDSU() {}
    BipartiteDSU(int SZ) { init(SZ); }
    pll unionRoot(int n) {                                  // Finds root of node n
        if(u_set[n] == n) return {n, u_color[n]};           // returns : {root_node, color}
        pll root = unionRoot(u_set[n]);
        if(missmatch[u_set[n]] or missmatch[n])
            missmatch[n] = missmatch[u_set[n]] = 1;
        u_color[n] = (u_color[n] + root.second)&1;
        u_set[n] = root.first;
        return {u_set[n], u_color[n]};
    } int makeUnion(int a, int b) {
        int x = unionRoot(a).first, y = unionRoot(b).first;
        if(x == y) {
            if(u_color[a] == u_color[b]) missmatch[x] = 1;
            return x;
        } if(missmatch[x] or missmatch[y]) {            // Checks if Bipartite missmatch exists
            missmatch[x] = missmatch[y] = 1;
        } if(u_list[x] < u_list[y]) {                      // Makes y root
            u_set[x] = y, u_list[x] += u_list[y];
            u_color[x] = (u_color[a]+u_color[b]+1)&1;      // Setting color of component
            return y;                                      // y according to the color of a & b
        } else {                                           // Makes x root
            u_set[y] = x, u_list[y] += u_list[x];
            u_color[y] = (u_color[a]+u_color[b]+1)&1;
            return x;
    }} void init(int len) {                                // Initializer
        u_list.resize(len+5), u_set.resize(len+5);
        u_color.resize(len+5), missmatch.resize(len+5);
        for(int i = 0; i <= len+3; i++)
            u_set[i] = i, u_list[i] = 1, u_color[i] = 0, missmatch[i] = 0;
}};
// Dynamic Weighted DSU  ------ Not Tested !!!!!!!!!!!!
struct WeightedDSU {
    vector<int>u_list, u_set, u_weight, weight;
    WeightedDSU() {}
    WeightedDSU(int SZ) { init(SZ); }
    int unionRoot(int n) {
        if(u_set[n] == n) return n;
        return u_set[n] = unionRoot(u_set[n]);
    } void changeWeight(int u, int w, bool first = 1) {        // Change any component's weight
        if(first) w = w - weight[u];
        u_weight[u] += w;
        if(u_set[u] != u)
            changeWeight(u_set[u], w, 0);
    } int makeUnion(int a, int b) {                            // Union making with compression
        int x = unionRoot(a), y = unionRoot(b);
        if(x == y) return x;
        if(u_list[x] > u_list[y]) {                        
            u_set[y] = x, u_list[x] += u_list[y];                        
            u_weight[x] += u_weight[y];                
            return x;
        } else {                                             
            u_set[x] = y, u_list[y] += u_list[x];                         
            u_weight[y] += u_weight[x];                     
            return y;
    }} void init(int len) {                                    // Initializer
        u_list.resize(len+5), u_set.resize(len+5);
        u_weight.resize(len+5), weight.resize(len+5);
        for(int i = 0; i <= len+3; i++)
            u_set[i] = i, u_list[i] = 1, u_weight[i] = weight[i] = 0;
}};
/* -------------------------------------- Trie --------------------------------------
 Complexity : making a trie : O(S), searching : O(S)

    Trie of a string abca, abcb:  
                                               (b)    {isEnd = 1}
                                            |---------> node5
   [start] ----> node1 ----> node2 ----> node3 ----->  node4
           (a)         (b)         (c)         (a)   {isEnd = 1}
    Edges are the next[x] pointers, that direct to the next node of the trie */
// Dynamic Trie (with pointers)
struct dynamicTrie {
    struct node {
        bool isEnd;
        node *next[CHARS];                                      // CHARS: number of charachters
        node() {
            isEnd = false;
            for(int i = 0; i < 10; i++) next[i] = NULL;
    }}; 
    bool create(char str[], int len, node *current) {
        for(int i = 0; i < len; i++) {
            int pos = str[i] - '0';
            if(current->next[pos] == NULL)      current->next[pos] = new node();
            current = current->next[pos];
            if(current->isEnd)                  return true;
        } current->isEnd = true;
        return false; 
    } void del(node *current) {
        for(int i = 0; i < CHARS; i++)
            if(current->next[i] != NULL)
                del(current->next[i]);
        delete current; 
    } void check(node *current) {
        for(int i = 0; i < CHARS; i++)
            if(current->next[i] != NULL)
                check(current->next[i]);
        if(found) return;
        if(current->isEnd && !found) {
            for(int i = 0; i < CHARS && !found; i++)
                if(current->next[i] != NULL) {
                    found = 1;
}}}};
// Non-Dynamic implementation
// root node is at 0 index of tree
// root node counter contains total number of string insertion
// each inserted char counter is on the child node of the edges
struct Trie {
    struct node {
        int cnt;                    // number of edges, or number of times this node is visited
        int nxt[CHARS];                // if nxt[x] == -1, there is no edge from this node to x
    };
    int nodes;
    node tree[MAX];
    void newNode() {
        tree[nodes].cnt = 0;
        memset(tree[nodes].nxt, -1, sizeof tree[nodes].nxt);
        ++nodes; 
    } void init() { nodes = 0; newNode(); }
    int getId(char x) {
        if(x >= 'A' and  x <= 'Z')
            return (x - 'A' + 27);
        return (x - 'a' + 1);
    } void insert(string &str, int len = 0, int idx = 0) {
        tree[idx].cnt++;
        if(len == str.size()) return;
        int id = getId(str[len]);
        if(tree[idx].nxt[id] == -1) {
            tree[idx].nxt[id] = nodes;
            newNode();
        } insert(str, len+1, tree[idx].nxt[id]);
    } int search(string &str, int len = 0, int idx = 0) {
        if(len == str.size())       return -2;
        int id = getId(str[len]);
        if(tree[idx].nxt[id] == -1) return -1;
        if(tree[idx].cnt == 1)      return len;
        return search(str, len+1, tree[idx].nxt[id]);
}};

/* ---------------------------------- Sqrt Decompose ---------------------------------- */
int BlockSize, seg[1010];                        // BlockSize is the size of each Block
void SqrtDecompose(int v[], int len) {           // Builds Sqrt segments
    int idx, pos, val = 0;
    BlockSize = sqrt(len);                       // Calculating Block size
    for(int i = 0; i < len; ++i) {
        idx = i/BlockSize;                       // Index of block
        pos = i%BlockSize;                       // Index of block element
        /* perform operation */
}} void Update(int v[], int l, int val) {           // Updates value in position l : val
    int idx = l/BlockSize;                          // Block Index
    int startPos = (l/BlockSize)*BlockSize;         // The starting position from where
    for(int i = 1; i < BlockSize; ++i) {            // the block contains value of the input
        seg[idx][i] = v[startPos++];                // array v[]
}} int Query(int l, int r) {                        // Query in range l -- r
    int Count = 0, val = 0;
    while(l%BlockSize != 0 && l < r) {             // l partially lies inside of a sqrt segment
        /* perform operation from the input array */
        ++l;
    } while(l+BlockSize <= r) {                       // for all full sqrt segment
        /* perform operation from seg[l/BlockSize] */
        l += BlockSize;
    } while(l <= r) {                                 // rightmost partial sqrt segment
        /* perform operation from the input array */
        ++l;
    } return Count;
}
/* ------------------------------------- MO's on array ------------------------------------- 
 Complexity : (N+Q)*sqrt(N)*InsertEraseConstant + (Q*QueryProcessingConstant) */
struct query {
    int l, r, id;
} q[MAX];
const int block = 320;                  // For N = 100000, sqrt(N) = 320, always use as const
// MO's tree ordering with only query processing
bool cmp(query &a,query &b){                                    // Faster Comparison function
    if(a.l/block !=b.l/block)   return a.l < b.l;
    if((a.l/block)&1)           return a.r < b.r;               // Even-Odd sorting
    return a.r > b.r;
}                                                // MOs might work fast for a larger block size
void add(int x) {}                                  // Add x'th value in range 
void remove(int x) {}                               // Remove x'th value from range   
void MOs() {  
    sort(q, q+Q, cmp);
    int l = 0, r = -1;
    for(int i = 0; i < Q; ++i) {
        while(l > q[i].l)   add(--l);
        while(r < q[i].r)   add(++r);
        while(l < q[i].l)   remove(l++);
        while(r > q[i].r)   remove(r--);
        ans[q[i].id] =                              // Add Constraints
}}
/* ----------------------------------- MO's on SubTree -----------------------------------  
 Sort subtree parents according to l = in[u] and r = out[u], ID[timer] = node
 Iterate over the dfs timer and apply MOs in the [l, r] range, add/remove is same as above
*/
int timer = -1;
void dfs(int u, int p = 0) {                                        // MO's Sub-Tree DFS Timing
    in[u] = ++timer;
    ID[timer] = u;
    for(auto v : G[u])
        if(v != p) dfs(v, u);
    out[u] = timer;
}
/* ----------------------------------- MO's on Tree Path ----------------------------------  
   Perform Query operation from path u to v, iterate over dfs-time */
struct query {
    int id, ut, vt, lca;        // timing of node u, node v and lca of (u & v)
} q[MAX];
int timer = -1;
void dfs(int u, int p = 0) {
    in[u] = ++timer;
    ID[timer] = u;
    for(auto v : G[u])
        if(v != p) dfs(v, u);
    out[u] = ++timer;
} bitset<MAX> proc;
void process(int ut) {      // ADD and REMOVE in same function
    if(proc[ID[ut]]) {}     // ADD:    if proc = 0, then add the node and set proc = 1
    else             {}     // REMOVE: else remove the node and set proc = 0
} void MOs_Tree() {
    for(int i = 0, j = 0; j < Q; ++i, ++j) {        // Input Processing
        scanf("%d%d", &u, &v);
        q[i].id = i, q[i].lca = LCA(u, v);
        if(in[u] > in[v])       swap(u, v);
        if(q[i].lca == u)       q[i].ut = in[u], q[i].vt = in[v];
        else                    q[i].ut = out[u], q[i].vt = in[v];
    } sort(q, q+Q, cmp);
    int l = 0, r = -1;
    for(int i = 0; i < Q; ++i) {
        while(l > q[i].ut)   proccess(--l);
        while(r < q[i].vt)   proccess(++r);
        while(l < q[i].ut)   proccess(l++);
        while(r > q[i].vt)   proccess(r--);
        u = ID[l], v = ID[r];
        if(q[i].lca != u and q[i].lca != v) proccess(in[q[i].lca]);
        ans[q[i].id] =      // Calculate the answer
        if(q[i].lca != u and q[i].lca != v) proccess(in[q[i].lca]);
}}

/* ------------------------------------ 1D Fenwick Tree ------------------------------------ */
struct BIT {
    ll tree[MAX], MaxVal;
    void init(int sz=1e7) {
        memset(tree, 0, sizeof tree), MaxVal = sz+1;
    } void update(int idx, ll val) {
        for( ;idx <= MaxVal; idx += (idx & -idx))   tree[idx] += val; 
    } void update(int l, int r, ll val) {
        if(l > r) swap(l, r);
        update(l, val), update(r+1, -val); 
    } ll read(int idx) {
        ll sum = 0;
        for( ;idx > 0; idx -= (idx & -idx))         sum += tree[idx];
        return sum;
    } ll read(int l, int r) {
        ll ret = read(r) - read(l-1);
        return ret;
    } ll readSingle(int idx) {                      // Point read in log(n), haven't used often
        ll sum = tree[idx];
        if(idx > 0) {
            int z = idx - (idx & -idx);
            --idx;
            while(idx != z) {
                sum -= tree[idx];
                idx -= (idx & -idx);
        }} return sum;
    } int search(int cSum) {                  
        int pos = -1, lo = 1, hi = MaxVal, mid;
        while(lo <= hi) {                   
            mid = (lo+hi)/2;
            if(read(mid) >= cSum)   pos = mid, hi = mid-1;  
            else                    lo = mid+1;     // read(mid) >= cSum : lowest index of cSum
        } return pos;                              // read(mid) == cSum : highest index of cSum
    }
    ll size() { return read(MaxVal); }
    // Modified BIT, this section can be used to add/remove/read 1 to all elements from 1 to pos
    // all of the inverse functions must be used, for any manipulation
    ll invRead(int idx) { return read(MaxVal-idx); }           // gives summation from 1 to idx
    void invInsert(int idx) { update(MaxVal-idx, 1); }     // adds 1 to all index less than idx
    void invRemove(int idx) { update(MaxVal-idx, -1); }    // removes 1 from idx
    void invUpdate(int idx, ll val) { update(MaxVal-idx, val); }
};
/* --------------------------- 2D Fenwick Tree -------------------------
  /\|   (x1,y2) -------- (x2,y2)
  | |          |       |
  y |          ---------
    |   (x1,y1)         (x2, y1)
    |___________________________
(0, 0)                     x-->        */
struct FTree2D {
    ll tree[MAX][MAX] = {0};
    int xMax, yMax;
    void init(int xx, int yy) { xMax = xx, yMax = yy; }
    void update(int x, int y, int val) {
        for(int x1 = x; x1 <= xMax; x1 += x1 & -x1)
            for(int y1 = y; y1 <= yMax; y1 += y1 & -y)
                tree[x1][y1] += val; 
    } ll read(int x, int y) {
        ll sum = 0;
        for(int x1 = x; x1 > 0; x1 -= x1 & -x1)
            for(int y1 = y; y1 > 0; y1 -= y1 & -y1)
                sum += tree[x1][y1];
        return sum;
    } ll readSingle(int x, int y) {
        return read(x, y) - read(x-1, y) - read(x, y-1) + read(x-1, y-1);
    } void updateSquare(int x1, int y1, int x2, int y2, int val) {
        update(x1, y1, val),    update(x1, y2+1, -val);
        update(x2+1, y1, -val), update(x2+1, y2+1, val);               // p1 : lower left point
    } ll readSquare(int x1, int y1, int x2, int y2) {                 // p2 : upper right point
        return  read(x2, y2) - read(x1-1, y2) - read(x2, y1-1) + read(x1-1, y1-1);
}};

/* --------------------------- 3D Fenwick Tree ------------------------- */
ll xMax = 100, yMax = 100, zMax = 100, tree[105][105][105];
void update(int x, int y, int z, ll val) {
    int y1, z1;
    while(x <= xMax) {
        y1 = y;
        while(y1 <= yMax) {
            z1 = z;
            while(z1 <= zMax) {
                tree[x][y1][z1] += val;
                z1 += (z1 & -z1);
            } y1 += (y1 & -y1);
        } x += (x & -x); 
}}
ll read(int x, int y, int z) {
    ll sum = 0, y1, z1;
    while(x > 0) {
        y1 = y;
        while(y1 > 0) {
            z1 = z;
            while(z1 > 0) {
                sum += tree[x][y1][z1];
                z1 -= (z1 & -z1);
            } y1 -= (y1 & -y1);
        } x -= (x & -x);
    } return sum;
}
ll readRange(ll x1, ll y1, ll z1, ll x2, ll y2, ll z2) {
    --x1, --y1, --z1;
    return  read(x2, y2, z2) - read(x1, y2, z2)
          - read(x2, y1, z2) - read(x2, y2, z1)
          + read(x1, y1, z2) + read(x1, y2, z1)
          + read(x2, y1, z1) - read(x1, y1, z1);
}
// Pattens to built BIT update read: always starts with first(starting point), take (1 to n) 
// elements from ending point with all combination add it to staring point, add (-1)^n * val
void updateRange(int x1, int y1, int z1, int x2, int y2, int z2) {      // Not tested yet!!!!!
    update(x1, y1, z1, val),     update(x2+1, y1, z1, -val);
    update(x1, y2+1, z1, -val),  update(x1, y1, z2+1, -val);
    update(x2+1, y2+1, z1, val), update(x1, y2+1, z2+1, val);
    update(x2+1, y1, z2+1, val), update(x2+1, y2+1, z2+1, -val);
}

/* -------------------------------------- Segment Tree ------------------------------------- */
// Segment Tree Range Sum : Lazy with Propagation (MOD used)
struct SegTreeRSQ {
    vector<ll>sum, prop;
    void Resize(int n)      { sum.resize(5*n), prop.resize(5*n); }
    void init(int pos, int l, int r, ll val[]) {
        sum[pos] = prop[pos] = 0;
        if(l == r) { sum[pos] = val[l]; return; }
        int mid = (l+r)>>1;
        init(pos<<1, l, mid, val), init(pos<<1|1, mid+1, r, val);
        sum[pos] = (sum[pos<<1] + sum[pos<<1|1]);
    } void propagate(int pos, int l, int r) {
        if(prop[pos] == 0 || l == r) return;
        int mid = (l+r)>>1;
        sum[pos<<1]    = (sum[pos<<1] + prop[pos]*(mid-l+1));
        sum[pos<<1|1]  = (sum[pos<<1|1] + prop[pos]*(r-mid));
        prop[pos<<1]   = (prop[pos<<1] + prop[pos]);
        prop[pos<<1|1] = (prop[pos<<1|1] + prop[pos]);
        prop[pos]      = 0;
    } void update(int pos, int l, int r, int L, int R, ll val) {         // Range [L, R] Update
        if(r < L || R < l) return;
        propagate(pos, l, r);
        if(L <= l && r <= R) {
            sum[pos] = (sum[pos] + val*(r-l+1)), prop[pos] = (prop[pos] + val);
            return;
        } int mid = (l+r)>>1;
        update(pos<<1, l, mid, L, R, val), update(pos<<1|1, mid+1, r, L, R, val);
        sum[pos] = (sum[pos<<1] + sum[pos<<1|1]);
    } ll query(int pos, int l, int r, int L, int R) {                     // Range [L, R] Query
        if(r < L || R < l) return 0;
        propagate(pos, l, r);
        if(L <= l && r <= R) return sum[pos];
        int mid = (l+r)>>1;
        return (query(pos<<1, l, mid, L, R) + query(pos<<1|1, mid+1, r, L, R));
}};
// Segment Tree Insert/Remove value, Find K'th Value
struct KthValueInsertErase {                     // Finds/Deletes K'th value from array/SegTree
    int tree[MAX*4];
    void init(int pos, int L, int R) {
        if(L == R) { tree[pos] = 1; return; }
        int mid = (L+R)>>1;
        init(pos<<1, L, mid), init(pos<<1|1, mid+1, R);
        tree[pos] = tree[pos<<1]+tree[pos<<1|1];
    } int SearchVal(int pos, int L, int R, int I, bool removeVal = 0) {    // removeVal = 1 
        if(L == R) { tree[pos] = (removeVal ? 0:1); return L; }            // removes the value
        int mid = (L+R)>>1;
        if(I <= tree[pos<<1]) {
            int idx = SearchVal(pos<<1, L, mid, I, removeVal);
            if(removeVal) tree[pos] = tree[pos<<1] + tree[pos<<1|1];
            return idx;
        } else {
            int idx = SearchVal(pos<<1|1, mid+1, R, I-tree[pos<<1], removeVal);
            if(removeVal) tree[pos] = tree[pos<<1] + tree[pos<<1|1];
            return idx;
}}};
// Segment Tree Range Bit [set, reset, flip]                  [Problem: UVA 11402 Ahoy Pirates]
struct RangeBitQuery {
    vector<pair<int, int> >tree;                       // number of set bits, propagation state
    RangeBitQuery() { tree.resize(MAX*4); }
    void init(int pos, int L, int R, string &s) {
        tree[pos].second = 0;
        if(L == R) { tree[pos].first = (s[L] == '1'); return; }
        int mid = (L+R)>>1;
        init(pos<<1, L, mid, s), init(pos<<1|1, mid+1, R, s);
        tree[pos].first = tree[pos<<1].first + tree[pos<<1|1].first;
    } int Convert(int parentState) {              // Generates child state w.r.t parent's state
        if(parentState == 1) return 2;            // 2 : all set to zero
        if(parentState == 2) return 1;            // 1 : all set to one
        if(parentState == 3) return 0;            // 0 : no change
        return 3;                                 // 3 : all need to be flipped
    } void Propagate(int L, int R, int parent) {
        if(tree[parent].second == 0 or L == R) return;
        int mid = (L+R)>>1, lft = parent<<1, rht = parent<<1|1;
        if(tree[parent].second == 1)        tree[lft].first = mid-L+1, tree[rht].first = R-mid;
        else if(tree[parent].second == 2)   tree[lft].first = tree[rht].first = 0;
        else if(tree[parent].second == 3) { tree[lft].first = (mid-L+1) - tree[lft].first;
                                            tree[rht].first = (R-mid) - tree[rht].first; }
        if(tree[parent].second == 1 || tree[parent].second == 2)
            tree[lft].second = tree[rht].second = tree[parent].second;
        else {
            tree[lft].second = Convert(tree[lft].second);
            tree[rht].second = Convert(tree[rht].second); 
        } tree[parent].second = 0;                              // Clear parent node prop state
    } void updateOn(int pos, int L, int R, int l, int r) {      // Turn on bits in range [l, r]
        if(r < L || R < l || L > R) return;
        Propagate(L, R, pos);
        if(l <= L && R <= r) { tree[pos].first = (R-L+1), tree[pos].second = 1; return; }
        int mid = (L+R)>>1;
        updateOn(pos<<1, L, mid, l, r), updateOn(pos<<1|1, mid+1, R, l, r);
        tree[pos].first = tree[pos<<1].first + tree[pos<<1|1].first;
    } void updateOff(int pos, int L, int R, int l, int r) {    // Turn off bits in range [l, r]
        if(r < L || R < l || L > R) return;
        Propagate(L, R, pos);
        if(l <= L && R <= r) { tree[pos].first = 0, tree[pos].second = 2; return; }
        int mid = (L+R)>>1;
        updateOff(pos<<1, L, mid, l, r), updateOff(pos<<1|1, mid+1, R, l, r);
        tree[pos].first = tree[pos<<1].first + tree[pos<<1|1].first;
    } void updateFlip(int pos, int L, int R, int l, int r) {       // Flip bits in range [l, r]
        if(r < L || R < l || L > R) return;
        Propagate(L, R, pos);
        if(l <= L && R <= r) {
            tree[pos].first = abs(R-L+1 - tree[pos].first), tree[pos].second = 3;
            return;
        } int mid = (L+R)>>1;
        updateFlip(pos<<1, L, mid, l, r), updateFlip(pos<<1|1, mid+1, R, l, r);
        tree[pos].first = tree[pos<<1].first + tree[pos<<1|1].first;
    } int querySum(int pos, int L, int R, int l, int r) {          // Number of set bits [l, r]
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
        tree[pos].clear();                                               // Clears past values
        if(l == r) { tree[pos].push_back(val[l]); return; }
        int mid = (l+r)>>1;
        init(pos<<1, l, mid, val), init(pos<<1|1, mid+1, r, val);
        merge(tree[pos<<1].begin(), tree[pos<<1].end(), tree[pos<<1|1].begin(), 
              tree[pos<<1|1].end(), back_inserter(tree[pos]));
    } int query(int pos, int l, int r, int L, int R, int k) {
        if(r < L || R < l) return 0;
        if(L <= l && r <= R) {                                                  // Query Part
            return (int)tree[pos].size() - (upper_bound(tree[pos].begin(), tree[pos].end(), k) 
            - tree[pos].begin()); }        
        int mid = (l+r)>>1;
        return query(pos<<1, l, mid, L, R, k) + query(pos<<1|1, mid+1, r, L, R, k);
}};
// Maximum cumulative sum from all possible range in a segment
struct RangeMaxSumNode {                // Range maximum sum node is coded
    ll sum, prefix, suffix, ans;        // seg sum, max prefix sum, max suffix sum, max sum
    node(ll val = 0) { sum = prefix = suffix = ans = val; }
    void merge(node left, node right) {
        sum    =    left.sum + right.sum;
        prefix =    max(left.prefix, left.sum+right.prefix);
        suffix =    max(right.suffix, right.sum+left.suffix);
        ans    =    max(left.ans, max(right.ans, left.suffix+right.prefix));
}};
// Bracket segment validity check and update single position bracket
struct BracketTreeNode {                // Only node merge is coded in note
    int BrcStart, BrcEnd;               // number of start bracket, number of end bracket
    bool isOk = 0;                      // is the sequence valid
    node(int a = 0, int b = 0) {
        BrcStart = a, BrcEnd = b, isOk = (BrcStart == 0 && BrcEnd == 0);
    } node(char c) {
        if(c == '(')    BrcStart = 1, BrcEnd = 0;
        else            BrcStart = 0, BrcEnd = 1;
    } void mergeNode(node lft, node rht) {
        if(lft.isOk && rht.isOk)
            BrcStart = 0, BrcEnd = 0, isOk = 1;
        else {
            int match = min(lft.BrcStart, rht.BrcEnd);
            BrcStart = lft.BrcStart - match + rht.BrcStart;
            BrcEnd = lft.BrcEnd + rht.BrcEnd - match;
            (BrcStart == 0 && BrcEnd == 0) ? isOk = 1: isOk = 0;
}}};
// Outputs longest balanced bracket sequence in range [L, R]
struct node {
    ll lftBracket, rhtBracket, Max;
    node(ll lft=0, ll rht=0, ll Max=0) {      // Call: ( = node(1, 0, 0),   ) = node(0, 1, 0)
        this->lftBracket = lft;                     // number of left brackets
        this->rhtBracket = rht;                     // number of right brackets
        this->Max = Max;                            // The max len of bracket, output Max*2
    } void Merge(node lft, node rht) {
        ll common = min(lft.lftBracket, rht.rhtBracket);
        ll lftBracket = lft.lftBracket + rht.lftBracket - common;
        ll rhtBracket = lft.rhtBracket + rht.rhtBracket - common;
        return node(lftBracket, rhtBracket, lft.Max+rht.Max+common);
}};
// Path Compression
void CompressPath(vector<int> &point) {                           
    point.push_back(0);                                                
    sort(point.begin(), point.end());                                  
    point.erase(unique(point.begin()+1, point.end()), point.end());
}
// Offline Processing   [this code finds unique values in range l-r]
// The processing is done backwards, first we go to the right range r, then find ans in [l - r]
struct OfflineProcessing {
    int tree[4*MAX], v[MAX], IDX[MAX];      // IDX[x] keeps track of where x previously occured
    map<int, vector<int> > QueryEnd;            // Contains start positions for a end pos r
    map<pair<int, int>, int>Ans;                // Contains answer for ranges
    vector<pair<int, int> > Query;              // Contains query ranges 
    void ArrayInput(int arraySize) {  for(int i = 1; i <= SZ; ++i) scanf("%d", &v[i]); }
    void QueryInput(int querySize) {
        int l, r;
        while(q--) {
            scanf("%d %d", &l, &r);
            Query.push_back(make_pair(l, r));
            QueryEnd[r].push_back(l);                        // Used for sorting
    }} void Process(int arraySize) {
        map<int, vi> :: iterator it;
        int lPos = 0;
        for(it = QueryEnd.begin(); it != QueryEnd.end(); ++it) {
            while(lPos < it->first) {
                lPos++;
                if(IDX[v[lPos]] == -1) { IDX[v[lPos]] = lPos, update(1, 1, SZ, lPos, 1); }
                else {
                    int pastIDX = IDX[v[lPos]];
                    IDX[v[lPos]] = lPos;
                    update(1, 1, SZ, pastIDX, -1);      // Remove count from past-left index
                    update(1, 1, SZ, lPos, 1);          // Add count to the latest index
            }}
            for(int i = 0; i < (int)(it->second).size(); ++i)
                Ans[make_pair(it->second[i], it->first)] = 
                                                     query(1, 1, SZ, it->second[i], it->first);       
    }} void PrintAns() {
        for(int i = 0; i < (int)Query.size(); ++i)           // Output according to input query
            printf("%d\n", Ans[mp(Query[i].first, Query[i].second)]);
}};
/* ---------------------------- Persistant/Dynamic Segment Tree -----------------------------*/
struct node {
    ll val;
    node *lft, *rht;    
    node(node *L = NULL, node *R = NULL, ll v = 0) {
        lft = L, rht = R, val = v;
}};
node *persis[101000], *null = new node();
node *nCopy(node *x) {
    node *tmp = new node();
    if(x) { tmp->val = x->val, tmp->lft = x->lft, tmp->rht = x->rht; }
    return tmp;
} void init(node *pos, ll l, ll r) {
    if(l == r) { pos->val = val[l], pos->lft = pos->rht = null; return; }
    ll mid = (l+r)>>1;
    pos->lft = new node(), pos->rht = new node();
    init(pos->lft, l, mid), init(pos->rht, mid+1, r);
    pos->val = pos->lft->val + pos->rht->val;
} void update(node *pos, ll l, ll r, ll L, ll R, ll val) {                 // Range [L, R] update
    if(r < L || R < l) return;
    if(L <= l && r <= R)            { pos->prop += val, pos->val += (r-l+1)*val; return; }
    ll mid = (l+r)>>1;
    pos->lft = nCopy(pos->lft), pos->rht = nCopy(pos->rht);
    update(pos->lft, l, mid, L, R, val), update(pos->rht, mid+1, r, L, R, val);
    pos->val = pos->lft->val + pos->rht->val + (r-l+1)*pos->prop;
} ll query(node *pos, ll l, ll r, ll L, ll R) {                       // Range [L, R] Sum Query
    if(r < L || R < l || pos == NULL)   return 0;
    if(L <= l && r <= R)                return pos->val;
    ll mid = (l+r)/2LL;
    ll x = query(pos->lft, l, mid, L, R), y = query(pos->rht, mid+1, r, L, R);
    return x+y;
} void ClearTree(node *pos) {                   // Erasing A segment tree call: ClearTree(root)
    if(pos == NULL) { delete pos; return; }
    ClearTree(pos->lft), ClearTree(pos->rht);
    delete pos;
} int main() {
    null->lft = null->rht = null;               // MUST BE INITIALIZED
    for(int i = 1; i <= 10; ++i) {
        persis[i] = nCopy(persis[i-1]);
        update(persis[i], 1, n, idx, val);
    } return 0;
}
