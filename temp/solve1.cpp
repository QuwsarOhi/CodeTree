#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define INF 1e9+10
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define sf scanf
#define pf printf
#define ull unsigned long long
#define ll long long
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define frr(i, a, b) for(register int i = a; i >= b; --i)
#define msi map<string, int>
#define mii map<int, int>
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vii vector<pair<int, int> >
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
	int n, m, x, c[100100] = {0}, v[100100];
	unordered_map<int, bool>mp;
	sf("%d%d", &n, &m);
	
	for(int i = 0; i < n; ++i) {
		sf("%d", &v[i]);
	}
	
	for(int i = n-1; i >= 0; --i) {
		c[i] = c[i+1];
		if(mp.find(v[i]) == mp.end()) {
			c[i]++;
			mp[v[i]] = 1;
		}
		//cout << i << " " << c[i] << endl;
	}
	
	while(n--) {
		sf("%d", &x);
		pf("%d\n", c[x-1]);
	}
	
	return 0;
}
			
