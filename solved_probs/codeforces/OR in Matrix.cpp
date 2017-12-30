// Codeforces
// B. OR in Matrix
// http://codeforces.com/problemset/problem/486/B

#include <bits/stdc++.h>
using namespace std;
#define MAX                 200100
#define EPS                 1e-9
#define INF                 1e9+10
#define MOD                 1000000007
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

int v[110][110], a[110][110], mark[110][110], n, m;

bool rowCheck(int r) {
    for(int i = 0; i < m; ++i)
        if(v[r][i] != 1)
            return 0;
    return 1;
}

bool colCheck(int c) {
    for(int i = 0; i < n; ++i)
        if(v[i][c] != 1)
            return 0;
    return 1;
}

void makeZero(int r, int c) {
    for(int i = 0; i < m; ++i)
        mark[r][i] = 0;
    for(int i = 0; i < n; ++i)
        mark[i][c] = 0;
}

int main() {
    //fileRead("in");
    
    cin >> n >> m;
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) {
            cin >> v[i][j];
            mark[i][j] = v[i][j];
        }
        
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) {
            if(v[i][j]) {
                if(rowCheck(i) && colCheck(j)) {
                    makeZero(i, j);
                    a[i][j] = 1;
                }
            }
        }
    
    bool ok = 1;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(mark[i][j] != 0)
                ok = 0;
    

    //for(int i = 0; i< n; ++i, cout << "\n")
    //    for(int j = 0; j < m; ++j, cout << " ")
    //        cout << mark[i][j];

    
    if(!ok)
        cout << "NO\n";
    else {
        cout << "YES\n";
        for(int i =0 ; i < n; ++i, cout << "\n")
            for(int j = 0; j < m; ++j, cout << " ")
                cout << a[i][j];
    }
    
    return 0;
}
