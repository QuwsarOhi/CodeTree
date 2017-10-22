#include <bits/stdc++.h>
using namespace std;

bitset<250>visited;
int lft[250], rht[250], TMaxlevel, JMaxlevel, Jnodes, Tnodes;
vector<int>G[250], T[250], J[250], Tlevel[250], Jlevel[250];

bool VertexCover(int u) {
	visited[u] = 1;
	for(int i = 0; i < (int)G[u].size(); ++i) {
		int v = G[u][i];
		if(visited[v])
			continue;
		visited[v] = 1;
		
		if(lft[v] == -1) {
			lft[v] = u;
			rht[u] = v;
			return 1;
		}
		
		else if(VertexCover(lft[v])) {
			lft[v] = u;
			rht[u] = v;
			return 1;
		}
	}
	return 0;
}

void Tdfs(int u, int level) {
	TMaxlevel = max(TMaxlevel, level);
	visited[u] = 1;
	Tlevel[level].push_back(u);
	
	for(int i = 0; i < (int)T[u].size(); ++i) {
		int v = T[u][i];
		if(!visited[v])
			Tdfs(v, level+1);
	}
}


void Jdfs(int u, int level) {
	JMaxlevel = max(JMaxlevel, level);
	visited[u] = 1;
	Jlevel[level].push_back(u);
	
	for(int i = 0; i < (int)J[u].size(); ++i) {
		int v = J[u][i];
		if(!visited[v])
			Jdfs(v, level+1);
	}
}


int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, u, v;
	scanf("%d", &t);
	
	
	for(int Case = 1; Case <= t; ++Case) {
		TMaxlevel = JMaxlevel = 0;
		
		scanf("%d", &Jnodes);
		for(int i = 1; i < Jnodes; ++i) {
			scanf("%d %d", &u, &v);
			J[u].push_back(v);
			J[v].push_back(u);
		}
		
		scanf("%d", &Tnodes);
		for(int i = 1; i < Tnodes; ++i) {
			scanf("%d %d", &u, &v);
			T[u].push_back(v);
			T[v].push_back(u);
		}
		
		visited.reset();
		Tdfs(1, 0);
		visited.reset();
		Jdfs(1, 0);
		
		for(int level = 0; level <= TMaxlevel; ++level) {
			for(int i = 0; i < (int)Tlevel[level].size(); ++i) {
				int u = Tlevel[level][i];
				for(int j = 0; j < (int)Jlevel[level].size(); ++j) {
					int v = Jlevel[level][j];		
					if(J[v].size() >= T[u].size()) {	// Numbering starts after tom's node numbers
						G[u].push_back(v+Tnodes);
						G[v+Tnodes].push_back(u);
						//cout << "Connecting " << u << " ----- " << v << endl;
					}
				}
			}
		}
		
		memset(lft, -1, sizeof lft);
		memset(rht, -1, sizeof rht);
	
		int cnt = 0;
		for(int i = 1; i <= Tnodes; ++i) { 	// n is the number of left-side nodes
			visited.reset();				// if left-side nodes are unspecified then do bicoloring
			cnt += VertexCover(i); 		// Cnt is the answer
		}
		
		printf("Case %d: ", Case);
		
		if(cnt == Tnodes)
			printf("Yes\n");
		else
			printf("No\n");
		
		for(int i = 0; i < 240; ++i) {
			G[i].clear();
			T[i].clear();
			J[i].clear();
			Tlevel[i].clear();
			Jlevel[i].clear();
		}
	}
	
	return 0;
}
