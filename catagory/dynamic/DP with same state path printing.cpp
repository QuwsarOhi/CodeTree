// CodeForces
// http://codeforces.com/contest/349/problem/B

// DP with Same State occurance
// Path printing

#include <bits/stdc++.h>
using namespace std;
#define MAX                 200100
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
#define error(args...)      { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

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

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {                                                  // Debugger error(a, b, ....)
	cerr << *it << " = " << a << "\n";
	err(++it, args...);
}

//const int dx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};                                                      // Four side 
//const int dxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};                     // Eight side
//----------------------------------------------------------------------------------------------------------

int COLOR, v[12], dp[10][1000001], track[10][1000001];
vi ans;

int recur(int pos, int val) {
    if(dp[pos][val] != -1)
        return dp[pos][val];
    
    int ret1 = INT_MIN, ret2 = INT_MIN;
    
    if(val + v[pos] <= COLOR)               // Stay in this node
        ret1 = recur(pos, val+v[pos])+1;
    if(pos-1 > 0)                           // Go for next node
        ret2 = recur(pos-1, val);
    
    int ret = max(max(ret1, ret2), 0);
    
    if(ret1 >= ret2)                        // Track array indicates if the state (pos) remained in same position for the maximum value
        track[pos][val] = 1;
    else
        track[pos][val] = 0;
    
    return dp[pos][val] = ret;
}


void print(int pos, int val) {
    if(val >= COLOR)
        return;
    
    if(track[pos][val]) {
        if(val+v[pos] > COLOR)
            return;
        printf("%d", pos);
        print(pos, val+v[pos]);
    }
    else 
        print(pos-1, val);
}


int main() {
    cin >> COLOR;
    
    fr(i, 1, 10)
        cin >> v[i];
        
    
    memset(dp, -1, sizeof dp);
    int ret = recur(9, 0);
    
    if(ret == 0) {
        cout << -1 << endl;
        return 0;
    }
    
    print(9, 0);
    
    for(auto it : ans) cout << it;
    
    return 0;
}
