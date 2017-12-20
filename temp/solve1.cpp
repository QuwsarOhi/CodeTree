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

vii Move;
vector<pair<pii, int> >rider;
int visCount[15][15], n, m, vis[15][15], dis[15][15], dx[] = {1, 1, 2, 2, -1, -1, -2, -2}, dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

void Krider(int x, int y, int k) {
    if(k == 0)
        return;
    vis[x][y] = 1;
    
    for(int i = 0; i < 8; ++i) {
        int _x = x+dx[i];
        int _y = y+dy[i];
        
        if(_x < 0 || _y < 0 || _x >= m || _y >= n)
            continue;
        
        if(!vis[_x][_y]) {
            Move.pb(mp(_x, _y));
            Krider(_x, _y, k-1);
        }
    }
}


void bfs(int x, int y, const int k) {
    queue<pair<pii, int> >q;
    q.push(mp(mp(x, y), 0));
    vis[x][y]++;
    int d;
    
    while(!q.empty()) {
        x = q.front().fi.fi;
        y = q.front().fi.se;
        d = q.front().se+1;
        q.pop();
        
        Move.clear();
        Krider(x, y, k);
        
        for(int i = 0; i < SIZE(Move); ++i) {
            int _x = Move[i].fi, _y = Move[i].se;
            dis[_x][_y] += d;
            visCount[_x][_y]++;
            pf("%d %d -> %d %d\n", x, y, _x, _y);
            q.push(mp(mp(_x, _y), d));
        }
    }
}

int main() {
    int t, riderCnt;
    char s[20][20];
    
    sf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        sf("%d %d", &m, &n);
        pf("Case %d: ", Case);
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                sf(" %c", &s[i][j]);
                if(s[i][j] != '.')
                    rider.pb(mp(mp(i, j), int(s[i][j]-'0')));
            }
        }
    
        memset(vis, 0, sizeof vis);
        memset(dis, 0, sizeof dis);
        memset(visCount, 0, sizeof visCount);
    
        for(int i = 0; i < SIZE(rider); ++i) {
            cout << "Running" << endl;
            memset(vis, 0, sizeof vis);
            bfs(rider[i].fi.fi, rider[i].fi.se, rider[i].se);
        }
        
        riderCnt = SIZE(rider);
        int minMove = INF;
    
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(visCount[i][j] == riderCnt)
                    minMove = min(minMove, dis[i][j]);
    
        if(minMove != INF)
            pf("%d\n", minMove);
        else
            pf("-1\n");
        
        rider.clear();
    }
    
    return 0;
}