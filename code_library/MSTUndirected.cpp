// MST Kruskal + Union Find Disjoint Set (DSU)
// Complexity of MST : O(E logV)

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

//Minimum Spanning Tree
//Prim's Algorithm
//Complexity : O(E logV)

vector<int> G[MAX], W[MAX];
priority_queue<pair<int, int> >pq;
bitset<MAX>taken;

void process(int u) {
    taken[u] = 1;
    for(int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        int w = W[u][i];
        if(!taken[v])
            pq.push(make_pair(-w, -v));
    }
}

int main() {
    taken.reset();
    process(0);    //taking 0 node as default
    int mst_cost = 0;
    while(!pq.empty()) {
        w = -pq.top().first;
        v = -pq.top().second;
        pq.pop();

        //if the node is not taken, then use this node
        //as it contains the minimum edge
        
        if(!taken[v])
            mst_cost += w, process(v);
    }
    
    printf("Prim's MST cost : %d\n", mst_cost);
    return 0;
}
