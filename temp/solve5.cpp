#include <bits/stdc++.h>
using namespace std;
#define MAX                 300100
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000003
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS)) 
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbug(vari)          cerr << #vari << " = " << (vari) <<endl
#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

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

int color[MAX], dp[MAX][27], ans, track[27];
vi G[MAX];
string str;
bool cycle;
map<pii, bool>Map;

void dfs(int u, int pst) {
    color[u] = 1;           // visited this instance
    
    int idx = str[u-1]-'a';
    dp[u][idx]++;
    track[idx]++;
    ans = max(track[idx], ans);
    
    
    for(auto v : G[u]) {
        if(color[v] == 1 || cycle) {
            cycle = 1;
            return;
        }
        else if(color[v] == 2) {                    // Memoization
            for(int i = 0; i < 26; ++i)
                ans = max(track[i]+dp[v][i], ans);
        }
        else
            dfs(v, u);
    }
    
    
    track[idx]--;
    color[u] = 2;           // visited previous instance
    
    
    // Now pull up all the child value to top [THE DP PART]
    // Finding max chars
    int tmp[27] = {0};
    for(auto v : G[u]) {
        for(int i = 0; i < 26; ++i)
            tmp[i] = max(dp[v][i], tmp[i]);
    }
    
    // Adding them to this parent node dp
    for(int i = 0; i < 26; ++i)
        dp[u][i] += tmp[i];
}


int main() {
    int V, E, u, v;
    FastRead;
    cin >> V >> E;
    cin >> str;
    
    for(int i = 0; i < E; ++i) {
        cin >> u >> v;
        
        if(Map.find({u, v}) == Map.end())
            G[u].pb(v);
        
        Map[{u, v}];
        if(u == v)
            cycle = 1;
    }
    
    for(int u = 1; u <= V && !cycle; ++u)
        if(!color[u])
            dfs(u, -1);
    
    
    cout << (cycle == 1 ? -1:ans) << endl;
    return 0;
}
