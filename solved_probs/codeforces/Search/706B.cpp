// Codeforces
// B. Interesting drink
// http://codeforces.com/problemset/problem/706/B

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
#define msi map<string, int>
#define mii map<int, int>
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vii vector<pair<int, int> >
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vi v;

int BiSearch(int low, int hi, int val) {
	int mid, ans = -1;
	
	for(int i = 0; i < 100; ++i) {
		mid = (low+hi)/2;
		
		if(v[mid] <= val) {
			ans = mid;
			low = mid+1;
		}
		else
			hi = mid-1;
	}
			
	return ans;
}

int main() {
	int n, x;
	sf("%d", &n);

	fr(i, 0, n) {
		sf("%d", &x);
		v.pb(x);
	}
	
	sort(v.begin(), v.end());
	
	sf("%d", &n);
	
	fr(i, 0, n) {
		sf("%d", &x);
		int pos = BiSearch(0, v.size()-1, x);
		if(pos == -1)
			pf("0\n");
		else
			pf("%d\n", pos+1);
	}
	
	return 0;
}
