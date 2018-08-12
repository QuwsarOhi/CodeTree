// UVa
// 10860 - Many a Little makes a Mickle
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=1801&mosmsg=Submission+received+with+ID+21778309

#include <bits/stdc++.h>
using namespace std;
#define MAX                 15000
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define All(S)              S.begin(), S.end()              
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)

typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<ll, ll>mll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<long long>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;


//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

int dp[MAX], pattLen[70], d, slen;
char s[MAX], patt[70][150];

bool Match(int pos, int p) {
	for(int i = 0; i < pattLen[p]; ++i, ++pos)
		if(s[pos] != patt[p][i]) return 0;
	return 1;
}

bool MatchRev(int pos, int p) {
	for(int i = pattLen[p]-1; i >= 0; --i, ++pos)
		if(s[pos] != patt[p][i]) return 0;
	return 1;
}

int recur(int pos) {
	if(pos == slen)
		return 0;
	
	int &ret = dp[pos];
	if(ret != -1) return ret;
	ret = INF;
	
	for(int i = 0; i < d; ++i)
		if(pos+pattLen[i]-1 < slen and (Match(pos, i) or MatchRev(pos, i)))
			ret = min(ret, recur(pos+pattLen[i])+1);
	return ret;
}

int main() {
	//fileRead("in");
	//fileWrite("out");
	
	int t;
	sf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		sf("%s", s);
		slen = strlen(s);
		sf("%d", &d);
		
		for(int i = 0; i < d; ++i) {
			sf("%s", patt[i]);
			pattLen[i] = strlen(patt[i]);
		}
		
		memset(dp, -1, sizeof dp);
		int dp = recur(0);
		pf("Set %d: ", Case);
		
		if(dp >= INF)
			pf("Not possible.\n");
		else
			pf("%d.\n", recur(0));
	}
	return 0;
}
