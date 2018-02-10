#include <bits/stdc++.h>
#define MAX 100

using namespace std;

vector<int>G[MAX], ChainWeight;
int sparse[MAX][20], parent[MAX], level[MAX], nextNode[MAX], chain[MAX], num[MAX], val[MAX], numToNode[MAX], top[MAX], ChainSize[MAX], mx[MAX], ChildNode[MAX];
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
    
    //ChainWeight[ChainNo].push_back(val[u]); 
    
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

void MERGE(vector<int> &u, vector<int> &v, int i, int j) {
    cout << " I " << numToNode[i] << " J " << numToNode[j] <<  " " << i << " " << j << endl;
    if(i > j)
        swap(i, j);
    for(; i <= j; ++i)
        u.push_back(ChainWeight[i]);
    sort(u.begin(), u.end());
    while(u.size() > 10)
        u.pop_back();
}

vector<int>tmp;

void GetSum(int u, int v) {
    //  int res = 0;
    
    while(chain[u] != chain[v]) {                           // While two nodes are not in same chain
        if(level[top[chain[u]]] < level[top[chain[v]]])     // u is the chain which's topmost node is deeper
            swap(u, v);
        int start = top[chain[u]];
        //res += query(1, 1, n, num[start], num[u]);          // Run query in u node's chain
        //tmp.reserve(tmp.size()+abs(start-u)+1);
        //tmp.insert(tmp.end(), ChainWeight.begin()+start, ChainWeight.begin()+u+1);
        MERGE(tmp, ChainWeight, num[start], num[u]);
        u = parent[start];                                  // go to the upper chain of u
    }
    
    if(num[u] > num[v])
        swap(u, v);
    
   // tmp.reserve(tmp.size()+abs(u-v)+1);
    //res += query(1, 1, n, num[u], num[v]);
    //tmp.insert(tmp.end(), ChainWeight.begin()+u, ChainWeight.begin()+v+1);
    //return res;
    MERGE(tmp, ChainWeight, num[u], num[v]);
}

void NumToNode(int V) {
    for(int i = 1; i <= V; ++i)
        numToNode[num[i]] = i;
}


int main() {
    freopen("in", "r", stdin);
    int n, m, q, u, v;
    
    cin >> n >> m >> q;
    
    for(int i = 1; i < n; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        cout << "Edge " << u << " " << v << endl;
    }
    
    
    cout << "DONE EDGE\n";
    
    for(int i = 1; i <= m; ++i)
        cin >> val[i];
    for(int i = m+1; i <= n; ++i)
        val[i] = 10000000;
    
    cout << "DONE\n";
    memset(parent, -1, sizeof parent);
    memset(nextNode, -1, sizeof nextNode);
    ChainNo = 1, all = 1;
    
    dfs(1, -1, 0);
    
    cout << "DFS DONE\n";
    
    memset(ChainSize, 0, sizeof ChainSize);
    HLD(1, -1);
    
    
    for(int i = 1; i <= n; ++i) {
        cout << i << " " << num[i] << " " << chain[i] << endl;
    }
    
    NumToNode(n);
    
    ChainWeight.resize(n+1);
    
    for(int i = 1; i <= n; ++i)
        ChainWeight[num[i]] = val[i];
    
    cout << " WEIGHT ";
    for(auto x : ChainWeight)
        cout << x << " ";
    cout << endl;
    
    while(q--) {
        cin >> u >> v >> m;
        tmp.clear();
        GetSum(u, v);
        
        cout << "SZ " << tmp.size() << " :";
        for(auto x : tmp)
            cout << " " << x;
        cout << endl;
    }
    
    return 0;
}
