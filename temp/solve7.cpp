#include <bits/stdc++.h>
using namespace std;
#define MAX                 100100
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

ll BS(ll lo, ll hi, ll lim, ll base) {
    ll ret = -1;
    while(lo <= hi) {
        ll mid = (lo+hi)>>1;
        
        ll T = base*mid;
        if(T <= lim) {
            ret = max(ret, T);
            lo = mid+1;
        }
        else
            hi = mid-1;
    }
    return ret;
}

int main() {
    ll t, a, b, x, y;
    cin >> t;
    
    while(t--) {
        cin >> a >> b >> x >> y;
        
        ll ans = abs(a-b);
        for(int i = 0; i <= 100; ++i) {
            ll newA = a + i*x;
            ll newB = newA-b;
            
            if(newB < 0) continue;
            
            ll mxB = BS(1, 100, newB, y);
            
            //cout << "GOT " << newA << " " << mxB << " " << newB << endl;
            
            ans = min(abs(mxB - newB),  ans);;
        }
        
        cout << ans << endl;
    }
    return 0;
}
