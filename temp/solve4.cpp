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

string str;

int dp[10][10000], v[10], MIN = INT_MAX, MAX_LEN;

int recur(int pos, int val, int len) {
    if(dp[pos][val] != -1)
        return dp[pos][val];
        
    if(pos == 0)
        return len == MAX_LEN;

    if(val-v[pos] >= 0 && recur(pos, val-v[pos], len+1)) {
        str.push_back(char('0'+pos));
        return dp[pos][val] = 1;
    }    
    else if(recur(pos-1, val, len))
        return dp[pos][val] = 1;
    
    dp[pos][val] = 0;
    return 0;
}
    
    
    


int main() {
    int val;
    string st;
    cin >> val;
    for(int i = 1; i <= 9; ++i) {
        cin >> v[i];
        MIN = min(v[i], MIN);
    }
    
    MAX_LEN = val/MIN;
    
    memset(dp, -1, sizeof dp);
    
    if(!recur(9, val, 0) || MIN > val) {
        cout << "-1\n";
        return 0;
    }
    
    reverse(str.begin(), str.end());
    cout << str << endl;
    
    return 0;
}
        
