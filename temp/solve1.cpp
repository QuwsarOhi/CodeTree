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
#define PI                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define All(S)              S.begin(), S.end()              
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastIO              ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FileRead(S)         freopen(S, "r", stdin);
#define FileWrite(S)        freopen(S, "w", stdout);
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

vii v, o;

pii pointRotate(pii p, pii origin) {
    p = {p.fi - origin.fi, p.se - origin.se};
    p = {-p.se, p.fi};
    p = {p.fi + origin.fi, p.se + origin.se};
    return p;
}

bool isSquare(int p) {
    int cnt = 0;
    for(int i = p+1; i < p+4; ++i)
        if(v[p].se == v[i].se)
            ++cnt;
        else if(v[p].fi == v[i].fi)
            ++cnt;
        else
            cnt += ((abs(v[p].fi-v[i].fi) == abs(v[p].se - v[i].se)) || (abs(v[p].fi + v[p].se) == abs(v[i].fi + v[i].se)));
    
    if(cnt == 3)
        cout << v[p].fi << " " << v[p].se << " " << v[p+1].fi << " " << v[p+1].se << " " << v[p+2].fi << " " << v[p+2].se << " " << v[p+3].fi << " " << v[p+3].se << endl;
    return cnt == 3;
}


int recur(int pos, int r[]) {
    int TOT = r[0]+r[1]+r[2]+r[3];
    
    if(isSquare(pos))
        return TOT;
    
    if(TOT == 16)
        return INF;
    
    int ret = INF;
    for(int i = pos, j = 0; i < pos+4; ++i, ++j) {
        for(int c = r[j]; c <= 4; ++c) {
            pii TMP = v[pos];
            v[pos] = pointRotate(v[pos], o[pos]);
            r[pos]++;
            ret = min(recur(pos, r), ret);
            v[pos] = TMP;
            r[pos]--;
        }
    }
    
    return ret;
}

int main() {
    int n, x, y, a, b;
    sf("%d", &n);
    
    for(int i = 0; i < 4*n; ++i) {
        sf("%d%d%d%d", &x, &y, &a, &b);
        v.pb({x, y});
        o.pb({a, b});
    }
    
    
    for(int i = 0; i < 4*n; i += 4) {
        int T[] = {0, 0, 0, 0};
        int ret = recur(i, T);
        pf("%d\n", (ret == INF ? -1:ret));
    }
    
    return 0;
}
