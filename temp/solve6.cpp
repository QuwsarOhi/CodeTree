
#include <bits/stdc++.h>
using namespace std;
#define MAX                 200100
#define EPS                 1e-9
#define INF                 1e9
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


// A = 0
// B = 1
// C = 2
// D = 3 (start, dest)

int dp[4][10001000];

int recur(int steps, int pos, int dest) {
    if(pos == 3 && steps == 0) {
        //cout << "pos " << pos << " steps " << steps << endl;
        return 1;
    }
    
    if(steps <= 0)
        return 0;
    
    if(dp[pos][steps] != -1)
        return dp[pos][steps];
    
    ll ret = 0;
    for(int i = 0; i < 4; ++i)
        if(i != pos) {
            //cout << "From " << pos << " to " << i << endl;
            ret = (ret + recur(steps-1, i, dest))%MOD;
        }
    
    return dp[pos][steps] = ret;
    //return ret;
}

ll iter(int N) {
    dp[3][0] = 1;
    
    for(int n = 1; n <= N; ++n) {
        for(int pstPos = 0; pstPos < 4; ++pstPos) {
            for(int newPos = 0; newPos < 4; ++newPos) {
                if(newPos != pstPos)
                    dp[newPos][n] = (dp[newPos][n] + dp[pstPos][n-1])%MOD;
            }
        }
    }
    
    return dp[3][N];
}

int main() {
    int N;
    cin >> N;
    
    //memset(dp, -1, sizeof dp);
    
    //cout << recur(N, 3, 3) << endl;
    cout << iter(N) << endl;
    return 0;
}
