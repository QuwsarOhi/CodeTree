//UVa
//762 - We Ship Cheap
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
#define ull unsigned long long
#define N 500000
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;
map<string, int>_mp;
map<int, string>__mp;
vec v[1000];
bool vis[1000], first = 1;
int past[1000], m, t, x, y;
char a[100], b[100];

int mapper(string x)
{
	if(_mp[x] == 0) {
		_mp[x] = m;
		__mp[m++] = x;
		return m-1;
	}
	else
		return _mp[x];
}

void bfs(int s)
{
	memset(vis, 0, sizeof(vis));
	memset(past, 0, sizeof(past));
	queue<int>qu;
	vis[s] = 1;
	past[s] = -1;
	qu.push(s);
	wh(!qu.empty()) {
		int p = qu.front();
		qu.pop();
		for(size_t ver = 0; ver < v[p].size(); ver++) {
			if(!vis[v[p][ver]]) {
				past[v[p][ver]] = p;
				vis[v[p][ver]] = 1;
				qu.push(v[p][ver]);
			}
		}
	}
}

int main()
{
	wh(sf(" %d", &t) != EOF) {
		if(!first) pf("\n");
		first = 0;
		m = 1;
		fr(i, 0, t) {
			sf(" %s %s", a, b);
			x = mapper(string(a));
			y = mapper(string(b));
			v[x].pb(y);
			v[y].pb(x);
		}
		sf(" %s %s", a, b);
		x = mapper(string(a));
		y = mapper(string(b));
		/*for(map<int, string>:: iterator it = __mp.begin(); it != __mp.end(); it++)
			pf("%d : %s\n", it->first, (it->second).c_str());
		for(int i = 0; i < 6; i++) {
			pf("%d : ", i);
			for(size_t j = 0; j < v[i].size(); j++)
				pf("%d ", v[i][j]);
			pf("\n");
		}*/
		bfs(x);
		//pf("%d\n", vis[y]);
		if(vis[y] == 0) pf("No route\n");
		else {
			stack<pair<string, string> > st;
			wh(1){
				if(__mp.find(y) != __mp.end() && __mp.find(past[y]) != __mp.end())
					st.push(mp(__mp[y], __mp[past[y]]));
				else
					break;
				y = past[y];
			}
			wh(!st.empty()) {
				pf("%s %s\n", (st.top().second).c_str(), (st.top().first).c_str());
				st.pop();
			}
		}
		_mp.clear();
		__mp.clear();
		fr(i, 0, m) v[i].clear();
	}
	return 0;
}
