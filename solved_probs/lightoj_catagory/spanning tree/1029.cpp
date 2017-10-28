// LightOJ
// 1029 - Civil and Evil Engineer 
// Spanning Tree

#include <bits/stdc++.h>
using namespace std;

bitset<110>taken;
vector<int> G[110], W[110];
priority_queue<pair<int, int> > pq;

void MinProcess(int u) {
	taken[u] = 1;
	
	for(int i = 0; i < (int)G[u].size(); ++i) {
		int v = G[u][i];
		int w = W[u][i];
		
		if(!taken[v])
			pq.push(make_pair(-w, -v));
	}
}

int MinSt() {
	int MinW = 0;
	taken.reset();
	MinProcess(0);
	
	while(!pq.empty()) {
		int u = -pq.top().second;
		int w = -pq.top().first;
		pq.pop();
		
		if(!taken[u]) {
			MinProcess(u);
			MinW += w;
		}
	}
	return MinW;
}

void MaxProcess(int u) {
	taken[u] = 1;
	
	for(int i = 0; i < (int)G[u].size(); ++i) {
		int v = G[u][i];
		int w = W[u][i];
		
		if(!taken[v])
			pq.push(make_pair(w, v));
	}
}

int MaxSt() {
	int MaxW = 0;
	taken.reset();
	MaxProcess(0);
	
	while(!pq.empty()) {
		int u = pq.top().second;
		int w = pq.top().first;
		pq.pop();
		
		if(!taken[u]) {
			MaxProcess(u);
			MaxW += w;
		}
	}
	return MaxW;
}

int main() {
	int t, V, u, v, w;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &V);
		
		while(scanf("%d %d %d", &u, &v, &w)) {
			if(u == 0 && v == 0 && w == 0)
				break;
			G[u].push_back(v);
			G[v].push_back(u);
			W[u].push_back(w);
			W[v].push_back(w);
		}
		
		printf("Case %d: ", Case);
		
		int b = MaxSt();
		int a = MinSt();
		
		
		//cout << a << " " << b << endl;
		
		if((a+b)%2 == 0)
			printf("%d\n", (a+b)/2);
		else
			printf("%d/2\n", a+b);
			
		for(int i = 0; i <= V; ++i) {
			G[i].clear();
			W[i].clear();
		}
	}
	return 0;
}	
