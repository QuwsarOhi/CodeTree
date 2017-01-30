//UVa
//193 - Graph Coloring
//Special thanks to Brainfry
//Max Independent Set
#include <bits/stdc++.h>
using namespace std;

vector<int>g[110];
bitset<110>color, ans;
int V, E;

//1 -> black
//0 -> white

bool can_be_black(int u)
{
	for(int i = 0; i < (int)g[u].size(); i++) {
		int v = g[u][i];
		if(color[v] == 1)
			return 0;
	}
	return 1;
}

void backtrack(int u)
{
	if(u > V) {
		if(color.count() > ans.count()) {
			ans.reset();
			ans = color;
		}
		return;
	}
	if(can_be_black(u)) {
		color[u] = 1;
		backtrack(u+1);
		color[u] = 0;
	}
	backtrack(u+1);
}

int main()
{
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	register int t, u, v;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &V ,&E);
		for(register int i = 0; i < E; i++) {
			scanf("%d %d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		//for(int i = 1; i <= V; i++) {
			color.reset();
			backtrack(1);
		//}
		bool first = 1;
		printf("%d\n", (int)ans.count());
		for(register int i = 0; i <= V; i++)
			if(ans[i]) {
				if(first) {
					printf("%d", i);
					first = 0;
				}
				else
					printf(" %d", i);
			}
		printf("\n");
		for(register int i = 1; i <= V; i++)
			g[i].clear();
		ans.reset();
	}
	return 0;
}
