#include <bits/stdc++.h>
using namespace std;
#define MAX                 20
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
#define FOR(i, a, b)        for(register int i = (a); i < (int)(b); ++i)
#define FORR(i, a, b)       for(register int i = (a); i > (int)(b); --i)
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

ull G[MAX][MAX], dp[1<<MAX][MAX], V, E;

string bit(int x) {
    bitset<4>b(x);
    return b.to_string();
}

// CF :: http://codeforces.com/contest/11/problem/D
// states : [contains nodes which can be visited from the first ON node][currently the node which I'm at]
// contains how many times I can come to each state
ull SimpleCycle() {
    for(int i = 0; i < V; ++i) dp[1<<i][i] = 1;             // Initial state (V = vertices)
    ull ans = 0, first;
    for(int mask = 1; mask < (1<<V); ++mask) {
        for(first = 0; first < V and not isOn(mask, first); ++first);       // Finding first node
        for(int from = first; from < V; ++from) {           // Finding all possible answers where
            if(not isOn(mask, from)) continue;              // we start from 'first' and come to 
            for(int to = first+1; to < V; ++to) {           // 'to' node visiting all other ON nodes
                if(not isOn(mask, to) or not G[from][to] or from == to) continue;
                dp[mask][to] += dp[mask^(1<<to)][from];
        }}
        // Double Counting occurs : 1-2-3-4-1 and 1-3-2-4-1 is considered same (As they are rings)
        for(int from = first+1; from < V; ++from)           // If we can go to the first node, this means
            if(isOn(mask, from) and G[from][first] and __builtin_popcount(mask) >= 3)   // we can traverse
                ans += dp[mask][from];                      //  all the nodes and go to the starting node
    }
    return ans/2;
}

int main() {
    int u, v;
    cin >> V >> E;
    for(int i = 0; i < E; ++i) {
        cin >> u >> v;
        --u, -- v;
        G[u][v] = G[v][u] = 1;
    }

    cout << SimpleCycle() << endl;
    return 0;
}

/*

3 3
1 2
2 3
3 1

5 10
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
4 5

*/