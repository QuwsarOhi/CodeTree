// Codeforces
// A. Fraction
// http://codeforces.com/contest/854/problem/A
// Math

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define INF 1e9+10
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define sf scanf
#define pf printf
#define fr(i, a, b) for(register int i = a; i < (int)b; i++)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;

int main() {
	int n, a = 0, b = 0;
	double x = 0;
	sf("%d", &n);
	
	for(int i = n-1; i >= 1; --i) {
		int t = n-i;
		if(i != t &&__gcd(i, t) == 1) {
			//cout << min(i, t)/(double)max(i, t) <<  " " << x << " "  << i << " " << t << endl;
			if(x < min(i, t)/(double)max(i, t)) {
				a = min(i, t);
				b = max(i, t);
				x = min(i, t)/(double)max(i, t);
			}
		}
	}
	
	pf("%d %d\n", a, b);
	
	return 0;
} 
