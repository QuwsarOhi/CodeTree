#include <bits/stdc++.h>
using namespace std;
#define MAX                 13333333
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
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
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


int main() {
    int c[2], x, n;
    
    cin >> c[0] >> c[1] >> x;
    n = c[0]+c[1];
    int pst = c[0] > c[1] ? 0:1;
    
    int i = 0;
    if(x > 1) {
    //if(x > 1) {
        for(; i < n; ++i) {
            if(x-1-(c[pst]-1 > 0 and c[pst^1] > 0) >= 0) {
                c[pst]--;
                cout << pst;
                x -= 1;
                pst ^= 1;
            }
            else {
                //cerr << " AT " << i << " " << x << endl;
                break;
            }
        }
    }
    //pst = c[0] > c[1] ? 0:1;
    for(; i < n; ++i) {
        if(c[pst] > 0) {
            cout << pst;
            c[pst]--;
        }
        else {
            --i;
            pst ^= 1;
        }
    }
    
    
    cout << endl;
    return 0;
}
