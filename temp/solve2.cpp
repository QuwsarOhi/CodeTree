// Codeforces
// C. Hacking Cypher
// http://codeforces.com/problemset/problem/490/C
// Math, Brute Force

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
	string x;
	ll a, b;
	cin >> x;
	cin >> a >> b;
	ll remain[1000010] = {0}, p = 1;
	for(int i = x.size()-1; i >= 0; --i) {
		remain[i] = ((x[i]-'0')*p + remain[i+1])%b;
		p = (p*10) %b;
	}
	
	ll remain2 = 0;
	for(int i = 1; i <= (int)x.size()-1; ++i) {
		remain2 *= 10;
		remain2 += (x[i-1] - '0');
		remain2 %= a;
		if(remain2 == 0 && remain[i] == 0 && x[i] != '0') {
			cout << "YES\n";
			cout << x.substr(0, i) << "\n" << x.substr(i) << endl;
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
