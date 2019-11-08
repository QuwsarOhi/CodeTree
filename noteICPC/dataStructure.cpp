Data Structure:
 * Policy Based Data Structure : insert, erase, and binary search in log(n) with element index
 * DSU : Disjoint Set Union, Bipartite DSU, Weighted DSU
 * Trie : Dynamic Trie, Static Trie
 * Sparse Table : Implemented in LCA and Suffix Array
 * Square Root Decomposition : Block Decomposition

 * MOs Algorithm (Need TO edit)

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
            return x; }
        else {                                      // Makes y root (x -> y)
            u_set[x] = y;
            u_list[y] += u_list[x];                 // Root's size is increased
            return y;
    }}
    void init(int len) {                            // Initializer
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
    }
    int makeUnion(int a, int b) {
        int x = unionRoot(a).first, y = unionRoot(b).first;
        if(x == y) {
            if(u_color[a] == u_color[b]) missmatch[x] = 1;
            return x;
        }
        if(missmatch[x] or missmatch[y])                // Checks if Bipartite missmatch exists
            missmatch[x] = missmatch[y] = 1;
        if(u_list[x] < u_list[y]) {                     // Makes y root
            u_set[x] = y, u_list[x] += u_list[y];
            u_color[x] = (u_color[a]+u_color[b]+1)&1;      // Setting color of component
            return y;                                      // y according to the color of a & b
        }
        else {                                          // Makes x root
            u_set[y] = x, u_list[y] += u_list[x];
            u_color[y] = (u_color[a]+u_color[b]+1)&1;
            return x;
    }}
    void init(int len) {                // Initializer
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
    }
    void changeWeight(int u, int w, bool first = 1) {          // Change any component's weight
        if(first) w = w - weight[u];
        u_weight[u] += w;
        if(u_set[u] != u)
            changeWeight(u_set[u], w, 0);
    }
    int makeUnion(int a, int b) {                              // Union making with compression
        int x = unionRoot(a), y = unionRoot(b);
        if(x == y) return x;
        if(u_list[x] > u_list[y]) {                        
            u_set[y] = x, u_list[x] += u_list[y];                        
            u_weight[x] += u_weight[y];                
            return x;
        }
        else {                                             
            u_set[x] = y, u_list[y] += u_list[x];                         
            u_weight[y] += u_weight[x];                     
            return y;
    }}
    void init(int len) {                                    // Initializer
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
        }
        current->isEnd = true;
        return false; 
    }
    void del(node *current) {
        for(int i = 0; i < CHARS; i++)
            if(current->next[i] != NULL)
                del(current->next[i]);
        delete current; 
    }
    void check(node *current) {
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
    }
    void init() { nodes = 0; newNode(); }
    int getId(char x) {
        if(x >= 'A' and  x <= 'Z')
            return (x - 'A' + 27);
        return (x - 'a' + 1);
    }
    void insert(string &str, int len = 0, int idx = 0) {
        tree[idx].cnt++;
        if(len == str.size()) return;
        int id = getId(str[len]);
        if(tree[idx].nxt[id] == -1) {
            tree[idx].nxt[id] = nodes;
            newNode();
        }
        insert(str, len+1, tree[idx].nxt[id]);
    }
    int search(string &str, int len = 0, int idx = 0) {
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
        // perform operation
}}

void Update(int v[], int l, int val) {          // Updates value in position l : val
    int idx = l/BlockSize;                          // Block Index
    int startPos = (l/BlockSize)*BlockSize;         // The starting position from where
    for(int i = 1; i < BlockSize; ++i) {            // the block contains value of the input
        seg[idx][i] = v[startPos++];                // array v[]
}}

int Query(int l, int r) {                          // Query in range l -- r
    int Count = 0, val = 0;
    while(l%BlockSize != 0 && l < r) {             // l partially lies inside of a sqrt segment
        // perform operation from the input array
        ++l;
    }
    while(l+BlockSize <= r) {                       // for all full sqrt segment
        // perform operation from seg[l/BlockSize];
        l += BlockSize;
    }
    while(l <= r) {                                 // rightmost partial sqrt segment
        // perform operation from the input array
        ++l;
    }
    return Count;
}


// MO's Algo
// Complexity : (N+Q)*sqrt(N)

struct query {
    int l, r, id;
};

// block must be declared as const, as compilers do fast division with const values
const int block = 320;          // For 100000
query q[MAX];
int ans[MAX];

// MO's Tree Ordering
bool cmp(query &a,query &b){                       // Faster Comparison function
    if(a.l/block !=b.l/block)   return a.l < b.l;
    if((a.l/block)&1)           return a.r < b.r;
    return a.r > b.r;
}

void add(int x) {}       // Add x'th value in range 
void remove(int x) {}    // Remove x'th value from range   

void MOs() {  
    sort(q, q+Q, cmp);
    int l = 0, r = -1;
    for(int i = 0; i < Q; ++i) {
        while(l > q[i].l)   add(--l);
        while(r < q[i].r)   add(++r);
        while(l < q[i].l)   remove(l++);
        while(r > q[i].r)   remove(r--);
        ans[q[i].id] =                      // Add Constraints
}}

/* MOs on Tree [Subtree] */

int timer = -1;
void dfs(int u, int p = 0) {        // MO's Sub-Tree DFS Timing
    in[u] = ++timer;
    ID[timer] = u;
    for(auto v : G[u])
        if(v != p) dfs(v, u);
    out[u] = timer;
    ID[timer] = u;
}
// Sort subtree parents according to l = in[u] and r = out[u]
// Apply MOs in the [l, r] range, adding and removing is same as above


/* MOs on Tree [Tree Path] */

struct query {
    int id, ut, vt, lca;        // timing of node u, node v and lca of (u & v)
} q[MAX];

int timer = -1;
void dfs(int u, int p = 0) {    // DFS timing
    in[u] = ++timer;            // Also need to calculate LCA
    ID[timer] = u;
    for(auto v : G[u])
        if(v != p) dfs(v, u);
    out[u] = ++timer;
    ID[timer] = u;
}

bitset<MAX> proc;
void process(int ut) {          
    if(proc[ID[ut]]) {}     // if proc = 0, then add the node and set proc = 1
    else             {}     // else remove the node and set proc = 0
}

void MOs_Tree() {
    for(int i = 0, j = 0; j < Q; ++i, ++j) {        // Input Processing
        scanf("%d%d", &u, &v);
        q[i].id = i, q[i].lca = LCA(u, v);
        if(in[u] > in[v]) swap(u, v);
        
        if(q[i].lca == u)
            q[i].ut = in[u], q[i].vt = in[v];
        else
            q[i].ut = out[u], q[i].vt = in[v];
    }
    sort(q, q+Q, cmp);
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