// MST Kruskal + Union Find Disjoint Set
// Complexity of MST : O(E logV)

vector<int>u_list, u_set;               // u_list[x] contains the size of a set x
                                        // u_set[x] contains the root of x
int unionRoot(int n) {
    if(u_set[n] == n)
        return n;
    else
        return u_set[n] = unionRoot(u_set[n]);
}

int makeUnion(int a, int b) {
    int x = unionRoot(a);
    int y = unionRoot(b);
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
    }
}

void unionInit(int len) {
    u_list.resize(len+5, 1);
    u_set.resize(len+5);
    for(int i = 0; i <= len+3; i++)
        u_set[i] = i, u_list[i] = 0;
}

bool isSameSet(int a, int b) {
    if(unionRoot(a) == unionRoot(b))
        return 1;
    return 0;
}

// Let a graph be G1, and the MST of the graph is MST1
// and a graph G2, where G2 contains same edges as G1 with some new edges
// then the new MST of graph G2 will be :
// MST2 = MST(of the edges used in M1 (MST of G1) + new added edges)

vector<pair<int, pair<int, int> > > Edge;               // If edges are inserted frequently, use STL SET

int MST(int V) {
    sort(Edge.begin(), Edge.end());                     // Not needed if C++ SET is used
	int mst_cost = 0, selected_edge = 0;                // There exists no MST if, Selected Edges < V-1
	unionInit(V);
	for(int i = 0; i < (int)Edge.size() && selected_edge < V; i++) {
		u = Edge[i].second.first;
		v = Edge[i].second.second;
		w = Edge[i].first;
		if(!isSameSet(u, v))
			selected_edge++, mst_cost += w, makeUnion(u, v);
    }}
    return mst_cost;
}

int main() {
	int V, E, u, v, w;
	scanf("%d %d", &V, &E);
	for(int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		Edge.push_back(make_pair(w, make_pair(u, v)));
	}
	printf("MST in Kruskal : %d\n", MST(V));
	Edge.clear();
	return 0;
}
