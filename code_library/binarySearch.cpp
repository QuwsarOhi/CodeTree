#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define INF 1e9
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define sf scanf
#define pf printf
#define fr(i, a, b) for(register int i = a; i < b; ++i)
#define msi map<string, int>
#define mii map<int, int>
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vii vector<pair<int, int> >
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef unsigned long long ull;



double Bisection(double lo, double hi) {
	double mid, ans = 0;
	for(int i = 0; i < 100; ++i) {
		mid = (lo+hi)/2;
		if(can(mid)) {
			hi = mid;
			ans = mid;
		}
		else
			lo = mid;
	}
	return ans;
}

