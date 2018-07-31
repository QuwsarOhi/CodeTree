// Heavy Light Decomopse + Segment Tree
// Tree node value update, Tree node distance

int parent[MAX], level[MAX], nextNode[MAX], chain[MAX], num[MAX], val[MAX], numToNode[MAX], top[MAX], ChainSize[MAX], mx[MAX];
int ChainNo = 1, all = 1, n;
vi G[MAX];
void dfs(int u, int Parent) {
    parent[u] = Parent;             // Parent of u
    ChainSize[u] = 1;               // Number of child (initially the size is 1, contains only 1 node. itself) (resued array in hld)
    for(int i = 0; i < SIZE(G[u]); ++i) {
        int v = G[u][i];
        if(v == Parent)                         // if the connected node is parent, skip
            continue;
        level[v] = level[u]+1;                  // level of the child node is : level of parent node + 1
        dfs(v, u);
        ChainSize[u] += ChainSize[v];           // Modify this line if max Chain is needed
        if(nextNode[u] == -1 || ChainSize[v] > ChainSize[nextNode[u]])
            nextNode[u] = v;            // next selected node of u (select the node which has more child, (HEAVY))
}}
void hld(int u, int Parent) {
    chain[u] = ChainNo;                 // Chain Number
    num[u] = all++;                     // Numbering all nodes
    if(ChainSize[ChainNo] == 0)         // if this is the first node
        top[ChainNo] = u;               // mark this as the root node of the n'th chain
    ChainSize[ChainNo]++;
    if(nextNode[u] != -1)               // if this node has a child, go to it
        hld(nextNode[u], u);            // the next node is included in the chain
    for(int i = 0; i < SIZE(G[u]); ++i) {
        int v = G[u][i];                // if this node is parent node or, this node is already included in the chain, skip
        if(v == Parent || v == nextNode[u]) continue;
        ChainNo++;                          // this is a new (light) chain, so increment the chain no. counter
        hld(v, u);
}}
int GetSum(int u, int v) {
    int res = 0;
    while(chain[u] != chain[v]) {                           // While two nodes are not in same chain
        if(level[top[chain[u]]] < level[top[chain[v]]])     // u is the chain which's topmost node is deeper
            swap(u, v);
        int start = top[chain[u]];
        res += query(1, 1, n, num[start], num[u]);          // Run query in u node's chain
        u = parent[start];                                  // go to the upper chain of u
    }
    if(num[u] > num[v]) swap(u, v);
    res += query(1, 1, n, num[u], num[v]);
    return res;
}
void updateNodeVal(int u, int val) {
    update(1, 1, n, num[u], val);                   // Updating the value of chain
}
void numToNodeConv(int n) {
    for(int i = 1; i <= n; ++i) numToNode[num[i]] = i;
}
int main() {
    memset(nextNode, -1, sizeof nextNode);
    ChainNo = 1, all = 1;
    dfs(1, 1);
    memset(ChainSize, 0, sizeof ChainSize);     // array reused in hld
    hld(1, 1); 
    numToNodeConv(n);
    init(1, 1, n);
}
