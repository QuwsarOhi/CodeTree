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


int n, m, g[60][60], mx[51][51];
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

bool recur(int x, int y, int tt, bool eve) {
    if(y == m)
        return recur(x+1, 0, tt, not eve);
    if(x == n) {
        //printf("%d -------------\n", tt);
        /*printf("%d\n", tt);
        for(int i = 0; i < n; ++i, printf("\n")) {
            printf("%d", g[i][0]);
            for(int j = 1; j < m; ++j)
                printf(" %d", g[i][j]);
        }*/
        mx[n][m] = tt;
        ans = tt;
        for(int i = 0; i < n; ++i) {
            v[n][m].push_back(vector<int>());
            for(int j = 0; j < m; ++j)
                v[n][m][i].push_back(g[i][j]);
        }
        return 1;
    }

    for(int i = 1+eve; i <= 5; ++i)
        if(check(x, y, i)) {
            g[x][y] = i;
            //cerr << x << " " << y << " :: " << i << endl;
            if(recur(x, y+1, max(i, tt), not eve)) {
                //g[x][y] = 0;
                return 1;
            }
            g[x][y] = 0;
        }
    return 0;
}

int main() {
    //freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    int t;
    scanf("%d", &t);

    /*for(int i = 1; i <= 50; ++i)
        for(int j = 1; j <= 50; ++j) {
            n = i, m = j;
            memset(g, 0, sizeof g);
            recur(0, 0, 0);
        }*/
    //cerr << "DONE\n";

    while(t--) {
        scanf("%d%d", &n, &m);
        cout << "working on " << n << " " << m << endl;
        ans = -1;
        memset(g, 0, sizeof g);
        if(not recur(0, 0, 0, 0))
            cout << "nooutput\n";

        printf("%d\n", ans);
        for(int i = 0; i < n; ++i, printf("\n")) {
            printf("%d", g[i][0]);
            for(int j = 1; j < m; ++j)
                printf(" %d", g[i][j]);
        }
        /*printf("%d\n", mx[n][m]);
        for(int i = 0; i < v[n][m].size(); ++i, printf("\n")) {
            printf("%d", v[n][m][i][0]);
            for(int j = 1; j < v[n][m][i].size(); ++j)
                printf(" %d", v[n][m][i][j]);
        }*/
    }

    return 0;
}

/*

4
1 2 2 3 1
1 3 4 4 1
2 3 1 2 2
2 4 1 3 4
1 4 2 3 1

*/