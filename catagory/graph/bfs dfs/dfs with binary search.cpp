// CodeForces
// http://codeforces.com/contest/920/problem/E

// Dense Graph DFS with Binary Search
// Binary Search is used to find unvisited nodes with minimum number of iterations

// DFS complexity: O(V+E log V) but faster than normal DFS as this can auto skip visited node iterations

// Given edges which doesnt exist in the graph (Undirected Graph)
// Find total Connected Components

#include <bits/stdc++.h>
using namespace std;


set<pair<int, int> >noEdge;             // Contains edge pair {u, v} which doesn't exist
set<int>unVisited;                      // Contains nodes which are unvisited
vector<int>components;
int ComponentSize;
bitset<210000>visited;


void dfs(int u) {
    visited[u] = 1;                     // For O(1) visited checking
    ComponentSize++;                    // Count Component Size
    unVisited.erase(u);                 // Erasing from unvisited node set, as this node is visited
    
    int bound = 0;                      // Binary Seach boundary
    while(!unVisited.empty()) {
        auto v = unVisited.upper_bound(bound);      // Searching node v where v > bound
        
        if(v == unVisited.end())
            return;
            
        bound = *v;                                 // increasing boundary for the next search
        if(noEdge.count({u, *v}))                   // if there is no edge {u, v} skip
            continue;
            
        dfs(*v);                                    // going for the node
    }
}


int main() {
    int V, E, u, v;
    cin >> V >> E;
    
    for(int i = 0; i < E; ++i) {                    // Input of edges that doesn't exist
        cin >> u >> v;
        noEdge.insert({u, v});
        noEdge.insert({v, u});
    }
    
    for(int u = 1; u <= V; ++u)                     // Creating a unVisited node set
        unVisited.insert(u);
    
    for(int u = 1; u <= V; ++u) {
        if(!visited[u]) {
            ComponentSize = 0;
            dfs(u);
            components.push_back(ComponentSize);    // Adding component size to store answer
        }
    }
    
    sort(components.begin(), components.end());
    
    cout << components.size() << "\n";
    for(auto it : components)
        cout << it << " ";
    
    return 0;
}
