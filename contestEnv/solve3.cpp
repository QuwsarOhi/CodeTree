#include <bits/stdc++.h>
using namespace std;
#define MAX                 400100
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
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
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

int v[300], n, k;
int dp[202];
vii T;

int recur(int pos, int lastLen, int lstTaken) {
    if(pos >= n) {
        for(auto it : T)
            cout << it.first << " " << it.second << endl;
        cout << endl;
        return 1;
    }
        
    int &ret = dp[pos];
    //if(ret != -1) return ret;
    
    int lim = upper_bound(v, v+n, v[pos]+k) - v;
    //if(v[lim] <= v[pos]+k) ++lim;
    
    cout << "From " << pos << " to " << lim << endl;
    
    ret = 0;
    for(int i = pos; i < lim; ++i) {
        T.push_back({pos, i});
        ret += recur(i+1, i-pos+1, lstTaken+1);
        T.pop_back();
    }
    
    return ret;
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v, v+n);
    v[n] = 10000;
    memset(dp, -1, sizeof dp);
    
    cout << recur(0, 0, 0) << endl;
    
    for(int i = 0; i < n; ++i)
        cout << dp[i] << endl;
    return 0;
}
