// LightOJ
// 1242 - Similar Trees (II) 
// WA

#include <bits/stdc++.h>
using namespace std;

multiset<int>Tlevel[150], Jlevel[150];
vector<int>T[150], J[150];
int TmaxLevel, JmaxLevel;

void Tdfs(int u, int level) {
	Tlevel[level].insert((int)T[u].size());
	TmaxLevel = max(TmaxLevel, level);
	for(int i = 0; i < (int)T[u].size(); ++i)
		Tdfs(T[u][i], level+1);
}

void Jdfs(int u, int level) {
	Jlevel[level].insert((int)J[u].size());
	JmaxLevel = max(JmaxLevel, level);
	for(int i = 0; i < (int)J[u].size(); ++i)
		Jdfs(J[u][i], level+1);
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
		}
		
		scanf("%d", &Tnode);
		
		for(int i = 1; i < Tnode; ++i) {
			scanf("%d %d", &u, &v);
			T[u].push_back(v);
		}
		
		Tdfs(1, 0);
		Jdfs(1, 0);
		//cout << "JLevel " << JmaxLevel << endl;
		//for(int i = 0; i <= JmaxLevel; ++i) {
			//for(auto it: Jlevel[i])
			//	cout << it << " ";
			//cout << endl;
		//}
		
		//cout << "TLevel " << TmaxLevel << endl;
		//for(int i = 0; i <= TmaxLevel; ++i) {
			//for(auto it: Tlevel[i])
			//	cout << it << " ";
			//cout << endl;
		//}
		
		
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
		for(int j = 0; j < 140; ++j)
			Jlevel[j].clear();
		for(int i = 0; i < 140; ++i)
			J[i].clear();
		for(int i = 0; i < 140; ++i)
			T[i].clear();
	}

	return 0;
}
