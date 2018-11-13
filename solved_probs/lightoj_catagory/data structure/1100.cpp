// LightOJ
// 1100 - Again Array Queries
// http://lightoj.com/volume_showproblem.php?problem=1100

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

struct QQuery {
    int l, r, id;
};

const int block = 450;          // For 100000   : 320
QQuery q[10100];
int ans[10100], v[100100];

// extra DS
int cnt[1010];

bool cmp2(const QQuery &a, const QQuery &b){                       // Faster Comparison function
    if(a.l/block !=b.l/block)   return a.l < b.l;
    if((a.l/block)&1)           return a.r < b.r;
    return a.r > b.r;
}

void init() {
    memset(cnt, 0, sizeof cnt);
}

void add(int idx) {
    ++cnt[v[idx]];
}

void remove(int idx) {
    --cnt[v[idx]];
}

int process() {
    int ret = INF;
    for(int i = 1, pst = INF; i <= 1000; ++i) {
        if(cnt[i] == 1) {
            ret = min(ret, abs(i-pst));
            pst = i;
        }
        else if(cnt[i] > 1)
            return 0;
    }
    return ret;
}

int main() {
    //fileRead("in");
    //fileWrite("out");

    int t, n, Q;
    sf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        sf("%d%d", &n, &Q);
        for(int i = 0; i < n; ++i) sf("%d", &v[i]);

        for(int i = 0; i < Q; ++i) {
            sf("%d%d", &q[i].l, &q[i].r);
            q[i].id = i;
        }

        sort(q, + q+Q, cmp2);
        int l = 0, r = -1;
        init();
        for(int i = 0; i < Q; ++i) {
            while(l > q[i].l)   add(--l);
            while(r < q[i].r)   add(++r);
            while(l < q[i].l)   remove(l++);
            while(r > q[i].r)   remove(r--);
            ans[q[i].id] = process();
        }

        pf("Case %d:\n", Case);
        for(int i = 0; i < Q; ++i)
            pf("%d\n", ans[i]);
    }
}