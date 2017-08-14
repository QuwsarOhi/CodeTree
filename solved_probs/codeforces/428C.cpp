#include <bits/stdc++.h>
using namespace std;

vector<int>G[100010];
bitset<100010>visited;
double ans = 0;

void tree(int u, double probability, int level, bool isRoot) {
	visited[u] = 1;
	int child = G[u].size();
	if(!isRoot)
		child -= 1;
	bool isLeaf = 1;
	for(auto v : G[u]) {
		if(!visited[v]) {
			isLeaf = 0;
			tree(v, probability/double(child), level+1, 0);
		}
	}
	
	if(isLeaf)
		ans += (level*((double)probability));
}
		

int main() {
	
	//freopen("in", "r", stdin);
	
	int n, u, v;
	scanf("%d", &n);
	visited.reset();
	--n;
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	tree(1, 1, 0, 1);
	
	printf("%.10lf\n", ans);
	return 0;
}
