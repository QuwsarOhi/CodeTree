// UVa
// 11386 - Triples
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=2381&mosmsg=Submission+received+with+ID+21798603

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

vi v;
map<long, long>MAP;

// Building Pascle C(n, r)
ll p[5010][5];
void buildPascle() {                                // This Contains values of nCr : p[n][r] 
    p[0][0] = 1;
    p[1][0] = p[1][1] = 1;
    for(int i = 2; i <= 5001; i++)
        for(int j = 0; j <= 5; j++) {
            if(j == 0 || j == i)
                p[i][j] = 1;
            else
                p[i][j] = p[i-1][j-1] + p[i-1][j];
}}

ll C(int n, int r) {
    if (r<0 || r>n) return 0;
    return p[n][r];
}

// 1, 3, 6, 10, 15

int main() {
    //fileRead("in");
    //fileWrite("out");
    FastRead;
    
    buildPascle();
    ll n, x;
    while(cin >> n) {
        MAP.clear(), v.clear();
        for(int i = 0; i < n; ++i) {
            cin >> x;
            v.pb(x);
            MAP[x]++;
        }
        
        ll cnt = 0;
        for(auto it1 = MAP.begin(); it1 != MAP.end(); ++it1) {
            if(it1->se >= 2) {
                ll tot = it1->fi*2LL;
                if(MAP.find(tot) != MAP.end())
                    cnt += C(it1->se, 2)*MAP[tot];
            }
            for(auto it2 = it1; ; ) {
                it2++;
                if(it2 == MAP.end()) break;
                ll tot = it1->fi+it2->fi;
                if(MAP.find(tot) != MAP.end())
                    cnt += it1->se*it2->se*MAP[tot]*1LL;
            }
        }
                    
        cout << cnt << "\n";
    }
    return 0;
}
