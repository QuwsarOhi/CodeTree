// Codeforces
// A. Rook, Bishop and King
// http://codeforces.com/problemset/problem/370/A

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
#define Equal(a, b) (abs(a-b) < EPS)
#define Greater(a, b) (a >= (b+EPS))
#define GreaterEqual(a, b) (a > (b-EPS)) 
#define fr(i, a, b) for(register int i = (a); i < (int)(b); i++)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbug(vari) cerr << #vari << " = " << (vari) <<endl
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;


int main() {
	int x1,x2,y1,y2;
	sf("%d %d %d %d", &x1, &y1, &x2, &y2);
	
	// Rook
	if(x1 == x2 || y1 == y2)
		pf("1 ");
	else
		pf("2 ");
	
	// Bishop
	if((x1+y1)%2 != (x2+y2)%2)
		pf("0 ");
	else if(x1!=x2 && y1 != y2 && ((x1+y1 == x2+y2) || (x1-y1 == x2-y2)))
		pf("1 ");
	else
		pf("2 ");
	
	// King
	pf("%d\n", max(abs(x1-x2), abs(y1-y2)));
	
	return 0;
}
