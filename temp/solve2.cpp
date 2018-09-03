#include <bits/stdc++.h>
using namespace std;
#define MAX                 200010
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define x                  first
#define y                  second
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


double PointToArea(pll p1, pll p2, pll p3) {                            // Returns Positive Area in if the points are clockwise, Negative for Anti-Clockwise
	return (p1.x*(p2.y-p3.y) + p2.x*(p3.y-p1.y) + p3.x*(p1.y-p2.y))/2.0;	// Divide by 2 if Triangle area is needed
}

bool isColleniar(pll a, pll b, pll c) {
    return PointToArea(a, b, c)==0;
}

vector<pll> sqr;       // Used in convexHull
bool convexHull(vector<pll> &v) {
    if(v.size() < 3)
        return 0;
    
    // Finding Upper LeftMost point
    int l = 0;
    for(int i = 1; i < (int)v.size(); ++i)
        if(v[i].x < v[l].x)
            l = i;
    
    //printf("Starting %lld %lld\n", v[l].x, v[l].y);
    int p = l, q;
    do {
        sqr.push_back(v[p]);          // Hull point index is pushed
        
        q = (p+1) % v.size();
        // This checks if there exists same point twice (no need if points are unique)
        while(v[p] == v[q])
            q = (q+1) % v.size();
        
        for(int i = 0; i < (int)v.size(); ++i) {
            if(PointToArea(v[p], v[q], v[i]) < 0)                                                        // point i is on left w.r.t point pq
                q = i;
            // Use this commented code, if minimum number of points needed (points in same line is rejected)
            //else if(side == 0 and dist(v[p], v[q]) < dist(v[p], v[i]))          // if point i is on same line pq
            //    q = i;
        }
        p = q;
        if(SIZE(sqr) == 4) break;
    }while(p != l);
    return SIZE(sqr) == 4;
}


vll p;


int main() {
    int n;
    cin >> n;
    
    p.resize(n);
    for(int i = 0; i < n; ++i)
        cin >> p[i].x >> p[i].y;
    
    sort(All(p));
    
    bool found = 0;
    /*for(int i = 2; i < n; ++i) {
        cerr << i << " : " << p[i].x << ", " << p[i].y << " : " << PointToArea(p[0], p[1], p[i]) << endl;
        if(PointToArea(p[0], p[1], p[i]) >= 0) {
            cerr << "FOUND " << 2 << endl;
            found = 1;
            swap(p[i], p[2]);
            break;
        }
    }
    
    // if p[2] not found then output yes
    
    for(int i = 3; i < n; ++i) {
        cerr << i << " : " << p[i].x << ", " << p[i].y << " : " << PointToArea(p[1], p[2], p[i]) << endl;
        if(PointToArea(p[1], p[2], p[i]) > 0) {
            cerr << "FOUND " << 3 << endl;
            found = 1;
            swap(p[i], p[3]);
            break;
        }
    }*/
    
    cout << convexHull(p) << endl;
    
    
    for(int i = 0; i < SIZE(sqr); ++i)
        cout << sqr[i].x << ", " << sqr[i].y << endl;
    
    return 0;
}
