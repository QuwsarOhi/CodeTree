// LightOJ
// 1046 - Rider

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


bool vis[15][15][15];
vector<pair<pii, int> >rider, Move;
int n, m, TotalDis[15][15], dis[15][15][15], dx[] = {1, 1, 2, 2, -1, -1, -2, -2}, dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

void Krider(int x, int y, int k) {
    if(k == 0)
        return;
    
    for(int i = 0; i < 8; ++i) {
        int _x = x+dx[i];
        int _y = y+dy[i];
        
        if(_x < 0 || _y < 0 || _x >= m || _y >= n)
            continue;
        
        if(vis[_x][_y][k] == 0) {
            vis[_x][_y][k] = 1;
            Move.pb(mp(mp(_x, _y), k));
            Krider(_x, _y, k-1);
        }
    }
}


void bfs(int x, int y, const int k) {
    priority_queue<pair<int, pii> >q;            // distance, x, y
    q.push(mp(0, mp(x, y)));
    vis[x][y][0] = 1;
    dis[x][y][0] = 0;
    
    int d;
    
    while(!q.empty()) {
        x = q.top().se.fi;
        y = q.top().se.se;
        d = (-q.top().fi)+1;
        q.pop();
        
        Move.clear();
        Krider(x, y, k);
        
        for(int i = 0; i < SIZE(Move); ++i) {
            int _x = Move[i].fi.fi;
            int _y = Move[i].fi.se;
            int _k = Move[i].se;
            
            if(dis[_x][_y][_k] == -1)
                dis[_x][_y][_k] = 0;
            dis[_x][_y][_k] += d;
            
            q.push(mp(-d, mp(_x, _y)));
        }
    }
}


void AddMinimumDis(int k) {
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            int minDist = INF;
            for(int l = 0; l <= k; ++l) {
                if(dis[i][j][l] != -1)
                    minDist = min(minDist, dis[i][j][l]);
            }
            TotalDis[i][j] += minDist;
        }
    }
}

int main() {
    //fileRead("in");
    //fileWrite("out");
    
    int t;
    char s;
    
    sf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        sf("%d %d", &m, &n);
        pf("Case %d: ", Case);
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                sf(" %c", &s);
                if(s != '.')
                    rider.pb(mp(mp(i, j), int(s-'0')));
            }
        }
    
        memset(TotalDis, 0, sizeof TotalDis);
    
        for(int i = 0; i < SIZE(rider); ++i) {
            memset(vis, 0, sizeof vis);
            memset(dis, -1, sizeof dis);
            bfs(rider[i].fi.fi, rider[i].fi.se, rider[i].se);
            AddMinimumDis(rider[i].se);
        }
        
        int minMove = INF;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                minMove = min(minMove, TotalDis[i][j]);
                
        if(minMove != INF)
            pf("%d\n", minMove);
        else
            pf("-1\n");
        
        rider.clear();
    }
    
    return 0;
}
