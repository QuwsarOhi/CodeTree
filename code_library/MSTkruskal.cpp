// MST Kruskal + Union Find Disjoint Set (DSU)
// Complexity of MST : O(E logV)

struct DSU {
    vector<int>u_list, u_set;        // u_list[x] : the size of a set x,  u_set[x] : the root of x
    
    DSU() {}
    DSU(int SZ) { init(SZ); }
    
    int unionRoot(int n) {
        if(u_set[n] == n) return n;
        return u_set[n] = unionRoot(u_set[n]);
    }

    int makeUnion(int a, int b) {
        int x = unionRoot(a), y = unionRoot(b);
        if(x == y)
            return x;
        else if(u_list[x] > u_list[y]) {
            u_set[y] = x;
            u_list[x] += u_list[y];
            return x;
        }
        else {
            u_set[x] = y;
            u_list[y] += u_list[x];
            return y;
    }}

    void init(int len) {
        u_list.resize(len+5);
        u_set.resize(len+5);
        for(int i = 0; i <= len+3; i++)
            u_set[i] = i, u_list[i] = 0;
    }

    bool isSameSet(int a, int b) {
        return (unionRoot(a) == unionRoot(b));
    }
};

// Let a graph be G1, and the MST of the graph is MST1
// and a graph G2, where G2 contains same edges as G1 with some new edges
// then the new MST of graph G2 will be :
// MST2 = MST(of the edges used in M1 (MST of G1) + new added edges)

set<pair<int, pair<int, int> > >Edge;                   // USED STL SET!!

int MST(int V) {
    int mstCost = 0, edge = 0;                          // If Edge list is STL vector, then sort it!
    DSU U(V+5);
    set<pair<int, pair<int, int> > > :: iterator it = Edge.begin();     // Contains {Weight, {U, V}}
    
    for( ; it != Edge.end() && edge < V; ++it) {
        int u = (*it).second.first;
        int v = (*it).second.second;
        int w = (*it).first;
        
        if(!U.isSameSet(u, v))
            ++edge, mstCost += w, U.makeUnion(u, v);
    }
    
    if(edge != V-1) return -1;              // Some edge is missing, so no MST found!
    return mstCost;
}
