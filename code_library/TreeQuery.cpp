// Tree Max Distance Node
// Set any node as root, then do dfs and find the farthest node, then again from that farthest node
// do dfs for farthest node, the two nodes are the farthest node

pii dfs(int u, int par, int d) {
    pii ret(d, u);                                      // {distance, node}
    for(int i = 0; i < (int)G[u].size(); ++i)
        if(G[u][i] != par)
            ret = max(ret, dfs(G[u][i], u, d+W[u][i]));
    return ret;
}

int GetDistance() {
    pii left = dfs(0, -1, 0);
    pii right = dfs(left.second, -1, 0);
    return right.first;
}

// Codeforces :E. Propagating tree ( http://codeforces.com/contest/384/problem/E )
// Given a tree (node 1 - n)
// perform two operations:
// 1. Add x value to node u, Add -x value to node u's immediate children, Add x to their immediate children, and so on
// in other words, add value x to all childs where (parentLevel%2 == childLevel%2), add -val otherwise
// 2. Output value of node u 

vector<int> G[MAX];
int sTime[MAX], eTime[MAX], level[MAX], cst[MAX], timer;
BIT EvenNode, OddNode;

/* sTime/in  : starting time of node n
   eTime/out : finishing time of node n
     1   
    / \
   5   6
      / \
     7   4
        / \
       2   3
discover nodes : {1, 5, 6, 7, 4, 2, 3}
sTime[] = {1, 6, 7, 5, 2, 3, 4}                 index starts from 1, 
eTime[] = {7, 6, 7, 7, 2, 7, 4}                 i'th index contains start time of i'th node
Calculate Child : 
for node 6 : childs are in range sTime[6] - eTime[6] : 3 - 7
so child nodes are : 6, 7, 4, 2, 3 (discover node index range)
we don't need discover time vector to calculate distance
notice, if we only update with sTime and eTime, the range update will always be right */

void dfs(int u, int lvl) {
    sTime[u] = ++timer;
    level[u] = lvl;
    for(int i = 0; i < (int)G[u].size(); ++i)
        if(sTime[G[u][i]] == 0)
            dfs(G[u][i], lvl+1);
    eTime[u] = timer;
}

void AddVal(int node, int val) {
    if(level[node]%2 == 0) {
        EvenNode.update(sTime[node], eTime[node], val);
        OddNode.update(sTime[node], eTime[node], -val);
    }
    else {
        EvenNode.update(sTime[node], eTime[node], -val);
        OddNode.update(sTime[node], eTime[node], val);
}}

int GetVal(int node) {                                      // cst[node] contains initial cost (if exists)
    return cst[node] + (level[node]%2==0 ? EvenNode.read(sTime[node]):OddNode.read(sTime[node]));
}


// Complete Binary Tree
// Sum of distance from a node "n" such that every nodes distance from node "n" is less than or equal to k
// http://mishadoff.com/blog/dfs-on-binary-tree-array/

vector<ll>v[MAX], w, sum[MAX];          // W[i] contains weight of I'th node
int n, m;
void dfs(int node = 1) {                // node starts from 1
    if(node > n) return;
    
    ll lft = node<<1, rht = node<<1|1;
    dfs(lft), dfs(rht);
    ll lftSize = v[lft].size(), rhtSize = v[rht].size();
    ll nodeSize = lftSize+rhtSize+1;
    v[node].resize(nodeSize);
    v[node][0] = 0;                             // distance from this node to this node
        
    //printf("node : %d, nodeSize : %d, lftSize : %d, rhtSize : %d\n", node, nodeSize, lftSize, rhtSize);
    ll l = 0, r = 0;
    for(ll i = 1; i < nodeSize; ++i) {
        if(l == lftSize)
            v[node][i] = v[rht][r++] + w[rht];
        else if(r == rhtSize)
            v[node][i] = v[lft][l++] + w[lft];
        else {
            int lftW = v[lft][l] + w[lft], rhtW = v[rht][r] + w[rht];
            if(lftW < rhtW) {
                v[node][i] = lftW;
                l++;
            }
            else {
                v[node][i] = rhtW;
                r++;
}}}}

ll single(int node, ll d, ll delta) {
    if(d < 0) return 0;
    ll n = upper_bound(v[node].begin(), v[node].end(), d) - v[node].begin();
    return sum[node][n-1] + delta*n;                                    // delta is the common distance of all nodes
}

ll query(int node, ll k) {
    ll ans = single(node, k, 0);
    ll totlen = 0;
    while(node/2) {
        totlen += w[node];
        ll tmp = single(node/2, k-totlen, totlen);                      // distances from parent node
        tmp -= single(node, k-totlen-w[node], totlen + w[node]);        // common overlapped distance (of child node) from parent node
        ans += tmp;
        node /= 2;
    }
    return ans;
}

void PreCal() {                             // First run dfs(), then run PreCal()
    for(int i = 1; i <= n; ++i) {
        sum[i].resize(v[i].size());
        sum[i][0] = v[i][0];
        for(int j = 1; j < SIZE(v[i]); ++j)
            sum[i][j] = sum[i][j-1] + v[i][j];
}}
