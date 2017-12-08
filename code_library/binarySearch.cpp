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

ll v[] = {10,20,30,30,20,10,10,20};
int n = sizeof(v)/sizeof(ll);

ll UpperBound(ll lo, ll hi, ll key) {               // Returns lowest position where v[i] > key
    ll mid, ans = -1;                               // 10 10 10 20 20 20 30 30
    while(lo <= hi) {                               //                   ^
        mid = (lo + hi)>>1;
        if(key >= v[mid]) {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return ans+1;                               // Tweaking this line will return the last position of key
}

ll LowerBound(ll lo, ll hi, ll key) {           // Returns lowest position where v[i] == key (if value is present more than once)
    ll mid, ans = -1;                           // 10 10 10 20 20 20 30 30
    while(lo <= hi) {                           //          ^
        mid = (lo+hi)>>1;
        if(key <= v[mid]) { 
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return ans;
}

ll BinarySearch(ll lo, ll hi, ll key) {         // Basic Binary Search, returns -1 if value not found
    ll mid;
    while(lo <= hi) {
        mid = (lo+hi)>>1;
        if(key == v[mid])
            return mid;
        else if(key > v[mid])
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return -1;
}

/*
// lo : lower value, hi : upper value, est : estimated output of the required result, delta : number of iteration in search
double bisection(double lo, double hi, double est, int delta) {
    double mid, ans = -1;
    for(int i = 0; i < delta; ++i) {
        mid = (lo+hi)/2.0;
        if(Equal(TestFunction(mid), est)) {
            ans = mid;
            lo = mid;
        }
        else if(Greater(TestFunction(mid), est))        // TestFunction outputs the estimated value of the input param
            hi = mid;
        else
            lo = mid;
    }
    return ans;
}
*/
    
int main() {
    sort(v, v+n);
    cout << n << endl;
    cout << UpperBound(0, n-1, 20) << endl;
    cout << LowerBound(0, n-1, 20) << endl;
    cout << BinarySearch(0, n-1, 20) << endl;
    return 0;
}
