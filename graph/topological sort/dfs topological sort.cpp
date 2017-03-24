//UVa
//10305 - Ordering Tasks
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define f1(i, b) for(register int i = 1; i <= b; i++)
#define ss stringstream
#define mimx(a, b) if(a > b)swap(a, b)
#define msi map<string, int>
#define mii map<int, int>
#define vec vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sf scanf
#define pf printf
#define wh while
#define inf std::numeric_limits<int>::max()
#define ll long long
#define ui unsigned int
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<pair<int, int> >
#define ull unsigned long long
#define N 500000
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;

vi adlst[110];
bool visited[110];
stack<int>topsort;

void dfs2(int u)
{
	visited[u] = 1;
	for(size_t i = 0; i < adlst[u].size(); i++) {
		if(visited[adlst[u][i]] == 0)
			dfs2(adlst[u][i]);
	}
	topsort.push(u);
}

int main()
{
	int v, e, e1, e2;
	//pf("vertices, edge : ");
	wh(sf("%d %d", &e, &v) && (e || v)) {
		fr(i, 0, v) {
			sf("%d %d", &e1, &e2);
			adlst[e1].pb(e2);
		}
		memset(visited, 0, sizeof(visited));
		for(int i = 1; i <= e; i++)
			if(visited[i] == 0)
				dfs2(i);
		/*int k = 1;
		fr(i,1, e+1) {
			pf("%d : ", k++);
			for(size_t j = 0; j < adlst[i].size(); j++)
				pf("%d ", adlst[i][j]);
			pf("\n");
		}*/
		wh(!topsort.empty()) {
			if(topsort.size() == 1) pf("%d\n", topsort.top());
			else pf("%d ", topsort.top());
			topsort.pop();
		}
		fr(i, 0, 105) adlst[i].clear();
	}
	return 0;
}
