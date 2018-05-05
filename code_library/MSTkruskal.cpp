
vector<pair<int, pair<int, int> > > Edge;
vector<int>u_list, u_set;


int main()
{
	int V, E, u, v, w;

	scanf("%d %d", &V, &E);
	for(int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		Edge.push_back(make_pair(w, make_pair(u, v)));
	}
	sort(Edge.begin(), Edge.end());
	
	int mst_cost = 0, selected_edge = 0;
	unionInit(V);

	for(int i = 0; i < E && selected_edge < V; i++) {
		u = Edge[i].second.first;
		v = Edge[i].second.second;
		w = Edge[i].first;
		
		if(!isSameSet(u, v)) {
			selected_edge++;
			mst_cost += w;
			makeUnion(u, v);
		}}
	
	printf("MST in Kruskal : %d\n", mst_cost);
	Edge.clear();
	return 0;
}
