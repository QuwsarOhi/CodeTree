// Codeforces
// http://codeforces.com/contest/895/problem/B
// B. XK Segments
// Binary Search

// All sub-ranges i and j (v[i] >= v[j]) in which x (or multiple of x) exists exactly y times (v[i] <= x <= v[j])

#include <bits/stdc++.h>
using namespace std;
#define MAX                 1e6
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

typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<ll, ll>mll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<ll>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;

ll n, x, k, v[1000000];

ll Search(ll lft, ll rht) {
    ll lftpos = lower_bound(v, v+n, lft) - v;
    ll rhtpos = upper_bound(v, v+n, rht) - v-1;
    //cout << "Search " <<  lftpos << " " << rhtpos << endl;
    return rhtpos-lftpos+1;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    cin >> n >> x >> k;
    
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    
    sort(v, v+n);
    ll ans = 0;
    
    for(int i = 0; i < n; ++i) {
        ll y = (v[i]-1)/x;
        ll lft = max(x*(y+k), v[i]);
        ll rht = x*(y+k+1)-1;
        if(lft <= v[n-1] && rht >= v[0])
            ans += Search(lft, rht);
        //cout << v[i] << " :: " << lft << " " << rht << " " << ans << endl;
    }
    
    cout << ans << endl;
    
    return 0;
}
