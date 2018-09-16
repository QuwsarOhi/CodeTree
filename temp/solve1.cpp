// UVa
// 11019 Matrix Matcher

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

const ll p1 = 31, p2 = 51, mod1 = 1e9+9, mod2 = 1e7+7;

vll Power;
void PowerGen(int n) {
    Power.resize(n+1);
    Power[0] = {1, 1};
    for(int i = 1; i < n; ++i) {
        Power[i].first = (Power[i-1].first * p1)%mod1;
        Power[i].second = (Power[i-1].second * p2)%mod2;
}}

ll Minus(ll x, ll y, ll m) {
    return ((x-y)%m+m)%m;
}

const int lineOffset = 1010;                                    // use the 2DLim to distinguish between rows
vector<vll> Gen2DHash(int r, int c, char str[][1010]) {         // row, column, string
    vector<vll> hash(r);
    for(int i = 0, offset = 0; i < r; ++i, offset += lineOffset) {          // Powers of every row r starts from r*offset
        pll h = {0, 0};
        for(int j = 0; j < c; ++j) {
            h.first = ((str[i][j] - 'a' + 1)*Power[j+offset].first)%mod1;
            h.second = ((str[i][j] - 'a' + 1)*Power[j+offset].second)%mod2;
            hash[i].push_back(h);
    }}

    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            if(i > 0) {
                hash[i][j].first = (hash[i][j].first + hash[i-1][j].first)%mod1;
                hash[i][j].second = (hash[i][j].second + hash[i-1][j].second)%mod2;
            }
            if(j > 0) {
                hash[i][j].first = (hash[i][j].first + hash[i][j-1].first)%mod1;
                hash[i][j].second = (hash[i][j].second + hash[i][j-1].second)%mod2;
            }
            if(i > 0 and j > 0) {
                hash[i][j].first = (hash[i][j].first - hash[i-1][j-1].first + mod1)%mod1;
                hash[i][j].second = (hash[i][j].second - hash[i-1][j-1].second + mod2)%mod2;
            }
            hash[i][j].first = (hash[i][j].first)%mod1;
            hash[i][j].second = (hash[i][j].second)%mod2;
    }}
    return hash;
}

const ll LIM = 1025000;
pll SubHash2D(vector<vll> &H, int x, int y, int r, int c) {       // generates hash which's upper left point is x, y
    int xx = x+r-1, yy = y+c-1;
    pll ret = H[xx][yy];
    if(x > 0) {
        ret.first = (ret.first - H[x-1][yy].first + mod1)%mod1;
        ret.second = (ret.second - H[x-1][yy].second + mod2)%mod2;
    }
    if(y > 0) {
        ret.first = (ret.first - H[xx][y-1].first + mod1)%mod1;
        ret.second = (ret.second - H[xx][y-1].second + mod2)%mod2;
    }
    if(x > 0 and y > 0)
        ret.first += H[x-1][y-1].first, ret.second += H[x-1][y-1].second;
    ret.first = ret.first%mod1;
    ret.second = ret.second%mod2;
    ret.first = (ret.first*Power[LIM-(x*lineOffset+y)].first)%mod1;
    ret.second = (ret.second*Power[LIM-(x*lineOffset+y)].second)%mod2;
    return ret;
}

vector<vll>strH, pattH;
char str[1010][1010];


int main() {
    //fileRead("in");
    //fileWrite("out");

    int t, n, m, x, y;
    sf("%d", &t);

    PowerGen(LIM+100);
    for(int Case = 1; Case <= t; ++Case) {
        sf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i)
            sf("%s", str[i]);
        strH = Gen2DHash(n, m, str);
        
        sf("%d%d", &x, &y);
        for(int i = 0; i < x; ++i)
            sf("%s", str[i]);
        pattH = Gen2DHash(x, y, str);


        pattH[x-1][y-1].first = (pattH[x-1][y-1].first * Power[LIM].first)%mod1;
        pattH[x-1][y-1].second = (pattH[x-1][y-1].second * Power[LIM].second)%mod2;

        int cnt = 0;
        for(int i = 0; i+x-1 < n; ++i)
            for(int j = 0; j+y-1 < m; ++j) {
                //cerr << "at " << i << " " << j << " :: " << ((pattH[x-1][y-1] == SubHash2D(strH, i, j, x, y)) ? "Yes":"No") << endl;
                cnt += (pattH[x-1][y-1] == SubHash2D(strH, i, j, x, y));
            }

        pf("%d\n", cnt);
    }
    return 0;
}