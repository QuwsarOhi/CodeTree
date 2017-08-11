//UVa
//469 - Wetlands of Florida
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
bool adjmat[110][110], tag, f, breaker, visited[110][110], first = 1;
int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dc[] = {-1, 0, 1, -1, 1, -1, 0, 1}, cnt, i, j, t; 
char a[110];


void dfs(int p, int q)
{
	cnt++;
	visited[p][q] = 1;
	for(int k = 0; k < 8; k++) {
		if((p + dr[k] < i) && (p + dr[k] > 0) && (q + dc[k] > 0) && (q + dc[k] < j) && (adjmat[p + dr[k]][q + dc[k]] == tag )&& (!visited[p + dr[k]][q + dc[k]]))
			dfs(p + dr[k], q + dc[k]);
	}
}

int main()
{
	sf("%d", &t);
	f = 1;
	wh(1) {
		if(!first) pf("\n");
		first = 0;
		i = 1;
		wh(1) {
			if(f) sf(" %[^\n]", a);
			if(isalpha(a[0])) {
			j = strlen(a);
			f = 0;
			for(int k = 1; k-1 < j; k++) {
				if(a[k-1] == 'L')
					adjmat[i][k] = 1;
				else 
					adjmat[i][k] = 0;
			}
			i++;
			}
			else break;
			sf(" %[^\n]", a);
		}
		j++;
		wh(1) {
			stringstream s;
			s << string(a);
			int p, q;
			s >> p;
			s >> q;
			tag = adjmat[p][q];
			cnt = 0;
			memset(visited, 0, sizeof(visited));
			dfs(p, q);
			pf("%d\n", cnt);
			if(sf(" %[^\n]", a) == EOF) {
				breaker = 1;
				break;
			}
			if(isalpha(a[0])) break;
		}
		if(breaker) break;
	}
	return 0;
}
