// UVa
// 11348 - Exhibition
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=2323&mosmsg=Submission+received+with+ID+21797329

#include <bits/stdc++.h>
using namespace std;
#define MAX                 110
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

int cnt[10010];
bitset<10010>found, tot;
vi v[60];

int main() {
    //fileRead("in");
    //fileWrite("out");
    
    int t, x, n, m;
    sf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        sf("%d", &n);
        tot.reset();
        memset(cnt, 0, sizeof cnt);
        
        for(int i = 0; i < n; ++i) {
            sf("%d", &m);
            v[i].clear();
            found.reset();
            v[i].pb(m);
            for(int j = 0; j < m; ++j) {
                sf("%d", &x);
                if(not found[x])
                    found[x] = 1, cnt[x]++;
                v[i].pb(x);
                tot[x] = 1;
            }
        }
        
        pf("Case %d:", Case);
        int unique = 0;
        for(int i = 0; i < n; ++i) {
            found.reset();
            for(int j = 1; j < v[i][0]+1; ++j) {
                if(not found[v[i][j]]) {
                    found[v[i][j]] = 1;
                    unique += cnt[v[i][j]] == 1;
                }
            }
        }
        
        //cerr << unique << endl;
        for(int i = 0; i < n; ++i) {
            double sum = 0;
            found.reset();
            for(int j = 1; j < v[i][0]+1; ++j) {
                if(not found[v[i][j]]) {
                    found[v[i][j]] = 1;
                    sum += cnt[v[i][j]] == 1;
                }
            }
            //cerr << i << " " << sum << " " << (sum/unique)*100 << endl;
            if(unique == 0) pf(" 0.000000");
            else            pf(" %.6f%%", (sum/unique)*100);
        }
        pf("\n");
    }
    return 0;
}
