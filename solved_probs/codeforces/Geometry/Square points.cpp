// Codeforces
// A.Pashmak and Garden
// Points and Geometry

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
	pii p1, p2;
	
	sf("%d %d %d %d", &p1.fi, &p1.se, &p2.fi, &p2.se);
	
	if(abs(p1.fi - p2.fi) == abs(p1.se - p2.se))		// if p1 and p2 are Diagonal
		pf("%d %d %d %d\n", p1.fi, p2.se, p2.fi, p1.se);
	else if(p1.fi == p2.fi)		// x1 == x2
		pf("%d %d %d %d\n", p1.fi+abs(p1.se-p2.se), p1.se, p2.fi+abs(p1.se-p2.se), p2.se);
	else if(p1.se == p2.se)				// y1 == y2
		pf("%d %d %d %d\n", p1.fi, p1.se+abs(p1.fi - p2.fi), p2.fi, p2.se+abs(p1.fi - p2.fi));
	else
		pf("-1\n");
		
	return 0;
}
