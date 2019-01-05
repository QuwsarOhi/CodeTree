#include <bits/stdc++.h>
using namespace std;
#define MAX                 510000
#define EPS                 1e-9
#define INF                 0x3f3f3f3f
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define xx                  first
#define yy                  second
#define pi                  acos(-1)
#define pf                  printf
#define sf(XX)              scanf("%lld", &XX)
#define SIZE(a)             ((ll)a.size())
#define ALL(S)              S.begin(), S.end()              
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define FastIO              ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FileRead(S)         freopen(S, "r", stdin);
#define FileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())
#define STOLL(X)            stoll(X, 0, 0)

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

//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

vector<pll> a, b;
set<ll>s;

int BS(int idx, int m) {
    int lo = 0, hi = m, ans = m;

    while(lo <= hi) {
        int mid = (lo+hi)>>1;

        if(s.count(a[idx].first + b[mid].first))
            lo = mid+1;
        else {
            ans = min(ans, mid);
            hi = mid-1;
        }
    }

    return ans;
}

int main() {
    FastIO;
    int n, m;
    cin >> n >> m;

    a.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }

    b.resize(m);
    for(int i = 0; i < m; ++i) {
        cin >> b[i].first;
        b[i].second = i;
    }

    sort(ALL(a)), sort(ALL(b));

    int cnt = 0, lim = n+m-1;
    for(int i = 0; i < n and cnt < lim; ++i) {
        int j = BS(i, m);

        for( ; j < m and cnt < lim; ++j) {
            s.insert(a[i].first + b[j].first);
            ++cnt;
            cout << a[i].second << " " << b[j].second << "\n";
        }
    }

    return 0;
}