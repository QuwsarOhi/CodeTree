// UVa
// 11338 - Minefield
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2313

#include <bits/stdc++.h>
using namespace std;
#define MAX                 110
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
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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

int w, h;
double d;
set<pair<double, double> >inQueue;
vector<pair<double, double> >p;
map<pair<double, double>, double>dst;

double dist(double x1, double y1, double x2, double y2) {
    double x = x1-x2, y = y1-y2;
    return sqrt(x*x + y*y);
}

bool dikjstra(double x = 0, double y = 0) {
    queue<pair<double, double> >q;
    q.push({x, y});
    
    inQueue.clear();
    inQueue.insert({x, y});
    
    dst.clear();
    dst[{x, y}] = 0;
    
    while(not q.empty()) {
        x = q.front().fi, y = q.front().se;
        q.pop();
        inQueue.erase({x, y});
        
        double dstU = dst[{x, y}];
        for(auto it : p) {
            double dd = dist(x, y, it.fi, it.se) + dstU;
            if(dd > d) continue;
            
            if(dist(x, y, it.fi, it.se) > 1.5) continue;
            
            if(dst.find({it.fi, it.se}) == dst.end() or dst[{it.fi, it.se}] > dd) {
                dst[{it.fi, it.se}] = dd;
                if(inQueue.find({it.fi, it.se}) == inQueue.end()) {
                    inQueue.insert({it.fi, it.se});
                    q.push({it.fi, it.se});
                }
            }
        }
    }
    return dst.find({w, h}) != dst.end();
}

int main() {
    int n;
    double x, y;
    
    while(sf(" %d %d", &w, &h) == 2) {
        sf("%d", &n);
        p.clear();
        
        for(int i = 0; i < n; ++i) {
            sf("%lf%lf", &x, &y);
            p.pb({x, y});
        }
        
        p.pb({w, h});
        sf("%lf", &d);
        
        if(dist(0, 0, w, h) <= d and dikjstra())
            puts("I am lucky!");
        else
            puts("Boom!");
        //cerr << dst[{w, h}] << endl;
    }
    return 0;
}
