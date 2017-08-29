// Codefoces
// B. Two Buttons
// http://codeforces.com/problemset/problem/520/B
// Graph, BFS

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9;
#define INF 1e9
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define sf scanf
#define pf printf
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define msi map<string, int>
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
#define vii vector<pair<int, int> >
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
	int n, m;
	
	sf("%d%d", &n, &m);
	
	//unordered_map<int, bool>visited;
	bitset<100010>visited;
	queue<pii>q;
	q.push({n, 0});
	
	while(!q.empty()) {
		int u = q.front().fi;
		int l = q.front().se;
		
		if(u == m) {
			pf("%d\n", l);
			return 0;
		}
		
		q.pop();
		if(visited[u])
			continue;
		
		visited[u] = 1;
		
		if(u-1 > 0 && !visited[u-1])
			q.push({u-1, l+1});
		if(2*u <= 4*m && !visited[2*u])
			q.push({2*u, l+1});
	}
	
	return 0;
}
