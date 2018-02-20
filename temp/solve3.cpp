// Codeforces
// http://codeforces.com/contest/550/problem/C

// Digit DP
// Eleminate zero or more numbers so that it is divisible by 8

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

int dp[110][10];
string str;
vi ans;


bool recur(int pos, int pstVal, bool ok) {               // Must present at least one value
    if(pos == (int)str.size())
        return ((pstVal == 0) && ok);
    
    if(dp[pos][pstVal] != -1)
        return dp[pos][pstVal];
    
    int val = (str[pos]-'0');
    
    ans.pb(pos);                                        // Save take this value as answer
    if(recur(pos+1, (val+pstVal*10)%8, 1))              // don't skip
        return 1;
        
    ans.pop_back();                                     // Remove this value from answer

    if(recur(pos+1, pstVal, ok))                        // Skip
        return 1;
    
    return (dp[pos][pstVal] = 0);
}

int main() {
    cin >> str;
    memset(dp, -1, sizeof dp);
    
    if(!recur(0, 0, 0)) {
        cout << "NO\n";
        return 0;
    }
    
    cout << "YES\n";
    
    for(auto it : ans)
        cout << str[it];
    
    return 0;
}
