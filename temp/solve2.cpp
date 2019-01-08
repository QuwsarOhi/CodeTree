#include <bits/stdc++.h>
using namespace std;
#define MAX                 510000
#define EPS                 1e-9
#define INF                 0x3f3f3f3f
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define xx                  first
#define yy                  second
#define pi                  acos(-1)
#define pf                  printf
#define sf(XX)              scanf("%lld", &XX)
#define SIZE(a)             ((ll)a.size())
#define ALL(S)              S.begin(), S.end()              
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define FastIO              ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FileRead(S)         freopen(S, "r", stdin);
#define FileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())
#define STOLL(X)            stoll(X, 0, 0)

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
typedef vector<ll>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;

//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

int n, m, g[60][60], gmx[60][60];
vector< vector<int> > v[51][51];

bool check(int x, int y, int v) {
    if(x-2 >= 0 and g[x-2][y] == v)
        return 0;
    if(y-2 >= 0 and g[x][y-2] == v)
        return 0;
    if(x+2 < n and g[x+2][y] == v)
        return 0;
    if(y+2 < m and g[x][y+2] == v)
        return 0;
    if(x-1 >= 0 and y-1 >= 0 and g[x-1][y-1] == v)
        return 0;
    if(x-1 >= 0 and y+1 < m and g[x-1][y+1] == v)
        return 0;
    if(x+1 < n and y-1 >= 0 and g[x+1][y-1] == v)
        return 0;
    if(x+1 < n and y+1 < m and g[x+1][y+1] == v)
        return 0;
    return 1;
}

int ans;
void recur(int x, int y, int mx, bool push) {
	if(ans <= min(n, m)+1) return;
	if(mx >= ans) return;
	if(mx > min(n, m)+1) return;

	if(y == m)
		return void(recur(x+1, 0, mx, push));
	if(x == n) {
		ans = mx;
		gmx[n][m] = mx;

		if(push) {
        	for(int i = 0; i < n; ++i) {
            	v[n][m].push_back(vector<int>());
            	for(int j = 0; j < m; ++j)
                	v[n][m][i].push_back(g[i][j]);
		}}
        else {
        	printf("%d\n", ans);
        	//ans = -1;
        	for(int i = 0; i < n; ++i, printf("\n")) {
            	printf("%d", g[i][0]);
            	for(int j = 1; j < m; ++j)
                	printf(" %d", g[i][j]);
        }}

		return;
	}

	for(int i = 1; i <= 5; ++i) {
		if(not check(x, y, i)) continue;
		g[x][y] = i;
		recur(x, y+1, max(i, mx), push);
		g[x][y] = 0;
	}
}

int main() {
	//freopen("out", "w", stdout);

	/*ans = 100;
	n = 50, m = 50;
	recur(0, 0, 0);

	g[0][0] = 0;
	for(int i = 1; i <= 50; ++i)
		for(int j = 1; j <= 50; ++j)
			g[i][j] = max(a[i][j], max(g[i][j-1], g[i-1][j]));*/



	int t;
	scanf("%d", &t);

	/*for(int i = 1; i <= 3; ++i)
		for(int j = 1; j <= 3; ++j) {
			ans = 100;
			n = i, m = j;
			recur(0, 0, 0);
			cerr << "DONE " << i << ", " << j << endl;
		}*/
	n = m = 50;
	ans = 100;
	recur(0, 0, 0, 1);

	while(t--) {
		scanf("%d%d", &n, &m);

		/*ans = 100;
		recur(0, 0, 0);
        
        printf("%d\n", ans);
        for(int i = 0; i < n; ++i, printf("\n")) {
            printf("%d", a[i][0]);
            for(int j = 1; j < m; ++j)
                printf(" %d", a[i][j]);
        }*/

		int nt = n, mt = m;

		if(n >= 3 and m >= 3) {
			n = 50, m = 50;

        	printf("%d\n", gmx[n][m]);
        	for(int i = 0; i < v[n][m].size() and i < nt; ++i, printf("\n")) {
            	printf("%d", v[n][m][i][0]);
            	for(int j = 1; j < v[n][m][i].size() and j < mt; ++j)
                	printf(" %d", v[n][m][i][j]);
        	}
        }
        else {
        	cerr << "BruteForce\n";
        	ans = 100;
        	memset(g, 0, sizeof g);
        	recur(0, 0, 0, 0);
        }
	}


	return 0;
}