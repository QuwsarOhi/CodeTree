#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int level[MAX], table[MAX][22], parent[MAX];
vector<int>G[MAX], W[MAX];

void dfs(int Parent, int u, int Level) {
	parent[u] = Parent;
	level[u] = Level;
	
	for(int i = 0; i < (int)G[u].size(); ++i) {
		int v = G[u][i];
		if(parent[v] == Parent)
			continue;
		dfs(u, v, Level+1);
	}
}

void LCAinit(int n) {
	memset(table, -1, sizeof(table));
	for(int i = 0; i < n; ++i)
		table[i][0] = parent[i];
		
	for(int j = 1; (1 << j) <= n; ++j)
		for(int i = 0; i < n; ++i)
			table[i][j] = table[table[i][j-1]][j-1];
}

int LCAquery(int n, int p, int q) {
	int point = 1;
	
	if(level[p] < level[q])
		swap(p, q);
		
	while((1 << (point+1)) <= level[p])
		++point;
	
	printf("point : %d (%d)   level: %d\n", point, (1<<point), level[p]);
	printf("p : %d\n", p);
	for(int i = point; i >= 0; --i)
		if(level[p] - (1 << i) >= level[q])
			p = table[p][i];
	
	printf("p : %d\n", p);
	if(p == q)
		return p;
	
	for(int i = point; i >= 0; --i) 
		if(table[p][i] != -1 && table[p][i] != table[q][i]) {
			printf("p : %d | q : %d  ||  p : %d | q : %d\n", p, q, level[p], level[q]);
			p = table[p][i], q = table[q][i];
			printf("*p : %d | q : %d\n", p, q);
		}
	
	return parent[p];
}
	
void sparseRMQ() {
	memset(parentMaxWeight, 0, sizeof(parentMaxWeight));
	for(int i = 0; i < n; ++i)
		parentMaxWeight[i][0] = parentWeight[i];
	
	for(int j = 1; 1 << j <= n; ++j)
		for(int i = 0; i + (1 << j) - 1 < n; ++i)
			parentMaxWeight[i][j] = max(parentMaxWeight[i][j-1], parentMaxWeight[i + (1 << (j-1))][j-1]);
}
		
	

int main(void) {
	int n = 17;
	G[0].push_back(1);
	G[1].push_back(2);
	G[1].push_back(8);
	G[2].push_back(3);
	G[3].push_back(4);
	G[4].push_back(5);
	G[5].push_back(6);
	G[6].push_back(14);
	G[6].push_back(7);
	G[8].push_back(9);
	G[9].push_back(10);
	G[10].push_back(11);
	G[11].push_back(15);
	G[11].push_back(12);
	G[12].push_back(13);
	G[12].push_back(16);
	
	memset(parent, -1, sizeof(parent));
	dfs(0, 0, 0);
	LCAinit(n);
	for(int i = 0; i < n; ++i)
		printf("%d ", level[i]);
	printf("\n");
	for(int i = 0; i < n; ++i)
		printf("%d ", parent[i]);
	printf("\n");
	printf( "%d\n", LCAquery(n, 14,12) );
	return 0;
}
