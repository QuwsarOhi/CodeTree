#include <bits/stdc++.h>
using namespace std;

int color[100];     // Contains Color (1, 2)

void Bipartite(int u) {
	queue<int>q;
	q.push(u);
	color[u] = 1;           // Color is -1 initialized
	
	while(!q.empty()) {
		u = q.front();
		q.pop();
		
		for(int i = 0; i < (int)G[u].size(); ++i) {
			int v = G[u][i];
			if(color[v] == -1) {
				if(color[u] == 1)
					color[v] = 2;
				else
					color[v] = 1;
				q.push(v);
			}
		}
	}
}


int main() {
    memset(color, -1, sizeof color);
    Bipartite(u);
    return 0;
}
