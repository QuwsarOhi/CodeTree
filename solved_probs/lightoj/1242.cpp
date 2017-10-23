// LightOJ
// 1242 - Similar Trees (II) 
// WA

#include <bits/stdc++.h>
using namespace std;

multiset<int>Tlevel[150], Jlevel[150];
vector<int>T[150], J[150];
int TmaxLevel, JmaxLevel;
bitset<150>visited;

void Tdfs(int u, int level) {
	if((int)T[u].size() != 0)
		Tlevel[level].insert((int)T[u].size());
	TmaxLevel = max(TmaxLevel, level);
	visited[u] = 1;
	for(int i = 0; i < (int)T[u].size(); ++i) {
		int v = T[u][i];
		if(!visited[v])
			Tdfs(v, level+1);
	}
}

void Jdfs(int u, int level) {
	if((int)J[u].size() != 0)
		Jlevel[level].insert((int)J[u].size());
	JmaxLevel = max(JmaxLevel, level);
	visited[u] = 1;
	for(int i = 0; i < (int)J[u].size(); ++i) {
		int v = J[u][i];
		if(!visited[v])
			Jdfs(v, level+1);
	}
}


int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	
	int t, Jnode, Tnode, u, v;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &Jnode);
		TmaxLevel = JmaxLevel = 0;
		
		for(int i = 1; i < Jnode; ++i) {
			scanf("%d %d", &u, &v);
			J[u].push_back(v);
			J[v].push_back(u);
		}
		
		scanf("%d", &Tnode);
		
		for(int i = 1; i < Tnode; ++i) {
			scanf("%d %d", &u, &v);
			T[u].push_back(v);
			T[v].push_back(u);
		}
		
		for(int i = 1; i <= Jnode; ++i) {
			for(auto it : J[i])
				cout << it <<  " ";
			cout << endl;
		}
		
		visited.reset();
		Tdfs(1, 0);
		visited.reset();
		Jdfs(1, 0);
		cout << "JLevel " << JmaxLevel << endl;
		for(int i = 0; i <= JmaxLevel; ++i) {
			for(auto it: Jlevel[i])
				cout << it << " ";
			cout << endl;
		}
		
		cout << "TLevel " << TmaxLevel << endl;
		for(int i = 0; i <= TmaxLevel; ++i) {
			for(auto it: Tlevel[i])
				cout << it << " ";
			cout << endl;
		}
		
		
		bool ok = 1;
		for(int i = 0; i <= TmaxLevel && ok; ++i) {
			while(!Tlevel[i].empty()) {
				multiset<int>::iterator it1 = Tlevel[i].end();
				--it1;
				multiset<int>::iterator it2 = Jlevel[i].upper_bound((*it1)-1);
				if(it2 == Jlevel[i].end() || Jlevel[i].size() < Tlevel[i].size()) {
					ok = 0;
					break;
				}
				Jlevel[i].erase(it2);
				Tlevel[i].erase(it1);
			}
		}
		
		printf("Case %d: ", Case);
		if(ok)
			printf("Yes\n");
		else
			printf("No\n");
			
		for(int i = 0; i < 140; ++i)
			Tlevel[i].clear();
		for(int i = 0; i < 140; ++i)
			Jlevel[i].clear();
		for(int i = 0; i < 140; ++i)
			J[i].clear();
		for(int i = 0; i < 140; ++i)
			T[i].clear();
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

bitset<250>visited;
int lft[250], rht[250], TMaxlevel, JMaxlevel, Jnodes, Tnodes, Tparent[250], Jparent[250];
vector<int>G[250], T[250], J[250], Tlevel[250], Jlevel[250];

bool VertexCover(int u, int parentOutdegree) {
	visited[u] = 1;
	for(int i = 0; i < (int)G[u].size(); ++i) {
		int v = G[u][i];
		int parent = Jparent[v-Tnodes];
		if(visited[v] || (int)J[parent].size() < parentOutdegree)
			continue;
		visited[v] = 1;
		
		if(lft[v] == -1) {
			lft[v] = u;
			rht[u] = v;
			return 1;
		}
		
		else if(VertexCover(lft[v], parentOutdegree)) {
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
		if(!visited[v]) {
			Tparent[v] = u;
			Tdfs(v, level+1);
		}
	}
}


void Jdfs(int u, int level) {
	JMaxlevel = max(JMaxlevel, level);
	visited[u] = 1;
	Jlevel[level].push_back(u);
	
	for(int i = 0; i < (int)J[u].size(); ++i) {
		int v = J[u][i];
		if(!visited[v]) {
			Jparent[v] = u;
			Jdfs(v, level+1);
		}
	}
}


int main() {
	int t, u, v;
	scanf("%d", &t);
	
	
	for(int Case = 1; Case <= t; ++Case) {
		TMaxlevel = JMaxlevel = 0;
		memset(Tparent, 0, sizeof Tparent);
		memset(Jparent, 0, sizeof Jparent);
		
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
					if(J[v].size() >= T[u].size()) {
						G[u].push_back(v+Tnodes);
						G[v+Tnodes].push_back(u);;
					}
				}
			}
		}
		
		memset(lft, -1, sizeof lft);
		memset(rht, -1, sizeof rht);
	
		int cnt = 0;
		for(int i = 1; i <= Tnodes; ++i) {
			visited.reset();
			int x = VertexCover(i, T[Tparent[i]].size());
			cnt += x;
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

/*
1
10
1 2
1 3
3 4
3 5
3 6
2 7
7 8
7 9
9 10
9
1 3
1 2
2 7
3 4
3 5
3 6
4 8
4 9
NO*/
/*
1
10
1 2
1 3
3 4
3 5
3 6
2 7
4 8
4 9
9 10
9
1 3
1 2
2 7
3 4
3 5
3 6
4 8
4 9
YES*/

/*
1
4
1 2
2 3
2 4
3
1 2
1 3
YES*/

