// Codeforces
// http://codeforces.com/contest/588/problem/E

// LCA with distance


#include <bits/stdc++.h>
using namespace std;

#define MAX 100100
#define FastRead    ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int> G[MAX], W[MAX][20];
int level[MAX], parent[MAX], sparse[MAX][20];

void dfs(int u, int par, int lvl) {           // Tracks distance as well (From root 1 to all nodes)
    level[u] = lvl;                                 // parent[] and level[] is necessary
    parent[u] = par;                                
    
    for(auto v : G[u])
        if(parent[u] != v)
            dfs(v, u, lvl+1);
}


void LCAinit(int V) {    
    // Main initialization of sparse table LCA starts here
    memset(sparse, -1, sizeof sparse);
    
    for(int u = 1; u <= V; ++u)                 // node u's 2^0 parent
        sparse[u][0] = parent[u];
    
    int v;
    for(int p = 1; (1LL<<p) <= V; ++p)
        for(int u = 1; u <= V; ++u)
            if((v = sparse[u][p-1]) != -1)      // node u's 2^x parent = parent of node v's 2^(x-1) [ where node v : (node u's 2^(x-1) parent) ]
                sparse[u][p] = sparse[v][p-1];
}


void MERGE(vector<int>&u, vector<int>&v) {
    for(auto it : v)
        u.push_back(it);
    
    sort(u.begin(), u.end());
    
    while((int)u.size() > 10)
        u.pop_back();
}

vector<int> LCA(int u, int v) {
    vector<int> T;
    
    if(level[u] > level[v])     // v is deeper
        swap(u, v);
    
    int p = ceil(log2(level[v]));
    
    // Pull up v to same level as u
    for(int i = p ; i >= 0; --i)
        if(level[v] - (1LL<<i) >= level[u]) {
            MERGE(T, W[v][i]);
            v = sparse[v][i];
        }
    
    // if u WAS the parent
    if(u == v) {
        //cout << "LCA " << u << endl;
        MERGE(T, W[u][0]);
        return T;
    }
    
    // Pull up u and v together while LCA not found
    for(int i = p; i >= 0; --i)
        if(sparse[v][i] != -1 && sparse[u][i] != sparse[v][i]) {      // -1 check is if 2^i is out of calculated range
            MERGE(T, W[u][i]);
            MERGE(T, W[v][i]);
            u = sparse[u][i], v = sparse[v][i];
        }
    
    //cout << "*LCA " << parent[u] << endl;

    MERGE(T, W[u][0]);              // As W[x][0] denoted the x nodes weight
    MERGE(T, W[v][0]);              // every sparse node must be calculated
    MERGE(T, W[sparse[v][0]][0]);   // we can also calculate summation of distance like this
    return T;
}


int main() {
    //freopen("in", "r", stdin);
    FastRead;
    int n, m, k, u, v, x, q;
    
    cin >> n >> m >> q;
    
    for(int i = 1; i < n; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    memset(parent, -1, sizeof parent);
    dfs(1, -1, 0);
    LCAinit(n);
    
    for(int i = 1; i <= m; ++i) {
        cin >> x;
        W[x][0].push_back(i);                   // W[x][0] denotes the weight of this node
    }                                           // As this is different (less than one), we need to add two extra additions 
    
    for(int i = 1; i <= n; ++i) {
        sort(W[i][0].begin(), W[i][0].end());
        
        while((int)W[i][0].size() > 10)
            W[i][0].pop_back();
    }
    
    for(int p = 1; (1<<p)<= n; ++p) {
        for(u = 1; u <= n; ++u) {
            v = sparse[u][p-1];
            
            if(v == -1)
                continue;
            
            MERGE(W[u][p], W[u][p-1]);
            MERGE(W[u][p], W[v][p-1]);
        }
    }
    
    while(q--) {
        cin >> u >> v >> k;
        //cout << "IN " << u << " " << v << " " << k << endl;
        vector<int> ans = LCA(u, v);
        
        while((int)ans.size() > k)
            ans.pop_back();
        
        cout << ans.size();
        for(auto it : ans)
            cout << " " << it;
        cout << "\n";
    }
        
    return 0;
}

