#include <bits/stdc++.h>

using namespace std;

#define FastRead    ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX         100100
#define INF         1e8

vector<int>G[MAX], W[MAX], ChainWeight[MAX][20];
int sparse[MAX][20], parent[MAX], level[MAX], nextNode[MAX], chain[MAX], num[MAX], val[MAX], numToNode[MAX], top[MAX], ChainSize[MAX], ChildNode[MAX];
int ChainNo = 1, all = 1;

// Heavy Light Decomposition Start

void dfs(int u, int par, int lvl) {
    parent[u] = par;
    level[u] = lvl;
    ChildNode[u] = 1;
    
    for(auto v : G[u]) {
        if(par == v)
            continue;
        
        dfs(v, u, lvl+1);
        
        ChildNode[u] += ChildNode[v];
        
        if(nextNode[u] == -1 || ChildNode[v] > ChildNode[nextNode[u]])
            nextNode[u] = v;
    }
}


void HLD(int u, int par) {
    chain[u] = ChainNo;
    num[u] = all++;
    
    if(ChainSize[ChainNo] == 0)
        top[ChainNo] = u;
    
    ChainSize[ChainNo]++;
    
    if(nextNode[u] != -1)
        HLD(nextNode[u], u);
    
    for(auto v : G[u]) {
        if(v == par || nextNode[u] == v)
            continue;
        ChainNo++;
        HLD(v, u);
    }
}


void NumToNode(int V) {
    for(int i = 1; i <= V; ++i)
        numToNode[num[i]] = i;
}

vector<int>tmp;

void MERGE(int i, int j, int k) {
    if(i > j)
        swap(i, j);
        
    for(; i <= j; ++i)
        for(auto val : ChainWeight[i])
            tmp.push_back(val);

    sort(tmp.begin(), tmp.end());
    while((int)tmp.size() > k)
        tmp.pop_back();
}



void GetVector(int u, int v, int k) {
    while(chain[u] != chain[v]) {                           // While two nodes are not in same chain
        if(level[top[chain[u]]] < level[top[chain[v]]])     // u is the chain which's topmost node is deeper
            swap(u, v);
        int start = top[chain[u]];
        MERGE(num[start], num[u], k);
        u = parent[start];                                  // go to the upper chain of u
    }
    
    if(num[u] > num[v])
        swap(u, v);

    MERGE(num[u], num[v], k);
}


int main() {
    //freopen("in", "r", stdin);
    FastRead;
    int n, m, q, u, v, k;
    
    cin >> n >> m >> q;
    
    for(int i = 1; i < n; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    memset(parent, -1, sizeof parent);
    memset(nextNode, -1, sizeof nextNode);
    ChainNo = 1, all = 1;
    
    dfs(1, -1, 0);
    
    memset(ChainSize, 0, sizeof ChainSize);
    HLD(1, -1);
    
    NumToNode(n);
    
    for(int i = 1; i <= m; ++i) {
        cin >> u;
        ChainWeight[num[u]][0].push_back(i);
    }
    
    tmp.reserve(n+100);
    
    while(q--) {
        cin >> u >> v >> k;
        tmp.clear();
        GetVector(u, v, k);
        
        cout << tmp.size();
        for(auto x : tmp)
            cout << " " << x;
        cout << endl;
    }
    
    return 0;
}
