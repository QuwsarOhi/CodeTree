// UVa
// 452 - Project Scheduling

#include <bits/stdc++.h>
using namespace std;
#define MAX                 50
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
#define StrToInt(STR)       stoi(STR, nullptr)
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

vi G[MAX], start;
int dp[MAX], W[MAX];

int dfs(int u) {
    if(dp[u] != -1)
        return dp[u];
    
    int ret = 0;
    for(auto v : G[u])
        ret = max(ret, dfs(v));

    return dp[u] = ret+W[u];
}

int main() {
    //fileRead("in");
    //fileWrite("out");
    
    int t, in, w, v, V;
    string str;
    bool first = 1;
    cin >> t;
    getline(cin, str);
    
    while(t--) {
        
        str.clear();
        
        if(!first)
            cout << "\n";
        else
            getline(cin, str);
        first = 0;
        
        while(1) {                  // input loop
            getline(cin, str);
            if(str.empty())
                break;
            
            stringstream ss(str);
            in = V = 0;
            
            bool zeroIndegree = 1;
            while(ss >> str) {
                if(in == 0)
                    v = str[0]-'A';
                else if(in == 1) {
                    w = stoi(str, nullptr);
                    W[v] = w;
                }
                else {
                    zeroIndegree = 0;
                    for(auto u : str)
                        G[u-'A'].pb(v);
                }
                ++in;
            }
            if(zeroIndegree)        // if indegree zero
                start.pb(v);
            ++V;
        }
        
        int ans = 0;
        memset(dp, -1, sizeof dp);
        
        for(auto u : start)
            ans = max(ans, dfs(u));
        
        cout << ans << "\n";
        
        for(int i = 0; i < MAX; ++i)
            G[i].clear();
        start.clear();
    }
    return 0;
}
