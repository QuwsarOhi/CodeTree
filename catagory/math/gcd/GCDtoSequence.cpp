// Codeforces
// C. Marco and GCD Sequence
// http://codeforces.com/contest/894/problem/C

// Given a set of GCD of some value (same gcd value of any subset is given only once)
// Generate the value if possible, else output -1

// Test Cases:
// Input:
// 4
// 2 4 6 12
// Output:
// 3
// 4 6 12
// Input:
// 2
// 2 3
// Output: -1
// Input: (Tricky)
// 3
// 1 15 25
// Output:
// 5
// 1 15 1 25 1

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define INF 1e12
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
#define SIZE(a) ((int)s.size())
#define fr(i, a, b) for(register int i = (a); i < (int)(b); i++)
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL)
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
typedef vector<ll>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;

int main() {
	int m, gcd = 1, v[1500];
	cin >> m;
	for(int i = 0; i < m; ++i) {
		cin >> v[i];
		if(i == 0)
			gcd = v[0];
		else
			gcd = __gcd(gcd, v[i]);
	}
	
	if(gcd == v[0]) {
		cout << m*2-1 << endl;
		cout << v[0];
		for(int i = 1; i < m; ++i)
			cout << " " << v[i] << " " << v[0];
		cout << endl;
	}
	else
		cout << "-1" << endl;
	
	return 0;
}
