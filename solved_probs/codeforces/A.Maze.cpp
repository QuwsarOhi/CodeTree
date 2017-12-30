// Codeforces
// A. Maze
// http://codeforces.com/problemset/problem/377/A

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

int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0}, cnt = 0, n, m, k, s;
char g[550][550], g2[550][550];


void fill(int x, int y) {
    if(cnt == s)
        return;
    g[x][y] = 'X';
    ++cnt;
    for(int i = 0; i < 4; ++i) {
        int _x = x+dx[i];
        int _y = y+dy[i];
        
        if(_x < 0 || _y < 0 || _x >= n || _y >= m)
            continue;
        if(g[_x][_y] == '#' || g[_x][_y] == 'X')
            continue;
        
        fill(_x, _y);
    }
}
                


int main() {
    //fileRead("in");
    
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) {
            cin >> g[i][j];
            g2[i][j] = g[i][j];
            if(g[i][j] == '.')
                ++s;
        }
    
    s -= k;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(g[i][j] == '.' && cnt < s)
                fill(i, j);
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(g[i][j] == '.')
                g2[i][j] = 'X';
            
    for(int i = 0; i < n; ++i, cout << "\n")
        for(int j = 0; j < m; ++j)
            cout << g2[i][j];
    
    return 0;
}

