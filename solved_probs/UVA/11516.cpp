// UVa
// 11516 - WiFi

#include <bits/stdc++.h>
using namespace std;
#define MAX                 200010
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

vector<int>v;

bool TRY(int r, double mid) {
    double range = v[0]+mid;
    int cnt = 1;
    //cerr << "R : " << range << " ";
    for(int i = 1; i < SIZE(v); ++i) {
        if(fabs(range-v[i]) > mid) {
            range = v[i]+mid;
            //cerr << range << " ";
            ++cnt;
        }
    }
    //cerr << endl;
    //cerr << "A: " << mid << " " << cnt << " " << (cnt <= r) << endl;
    return cnt <= r;
}
    

int main() {
    int r, n, t;
    sf("%d", &t);
    
    while(t--) {
        sf("%d%d", &r, &n);
        
        v.clear();
        v.resize(n);
        
        for(int i = 0; i < n; ++i)
            sf("%d", &v[i]);
        
        //for(int i = 0; i < n; ++i)
        //    cout << v[i] << endl;
        
        sort(All(v));
        
        double lo = 0, hi = 1e9, mid, ans = 1e9;
        for(int i = 0; i < 100; ++i) {
            mid = (lo+hi)/2.0;
            if(TRY(r, mid)) {
                //cerr << mid << " ok\n";
                ans = min(ans, mid);
                hi = mid;
            }
            else
                lo = mid;
        }
        pf("%.1f\n", ans);
    }
    return 0;
}
