// SPOJ
// MSUBSTR - Mirror Strings !!!
// https://www.spoj.com/problems/MSUBSTR/
// HASH + Binary Search

#include <bits/stdc++.h>
using namespace std;
#define MAX                 7000
#define EPS                 1e-9
#define INF                 1e7
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

#include <ext/pb_ds/assoc_container.hpp>    // rb_tree_tag
#include <ext/pb_ds/tree_policy.hpp>        // tree_order_statistics_node_update
#define at(X)          find_by_order(X)
#define lessThan(X)    order_of_key(X)
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

const ll p = 31;
const ll mod = 1e9+9;

vl Power;
void PowerGen(int n) {
    Power.resize(n+1);
    Power[0] = 1;
    for(int i = 1; i < n; ++i)
        Power[i] = (Power[i-1] * p)%mod;
}

vl Hash(char s[], int len) {
    ll hashVal = 0;
    vector<ll>v;
    for(int i = 0; i < len; ++i) {
        hashVal = (hashVal + (s[i] - 'a' + 1)* Power[i])%mod;
        v.push_back(hashVal);
    }
    return v;
}

ll SubHash(vl &Hash, ll l, ll r, ll LIM = 7000) {
    ll H;
    H = (Hash[r] - (l-1 >= 0 ? Hash[l-1]:0) + mod)%mod;
    H = (H * Power[LIM-l])%mod;
    return H;
}

vl H1, H2;
char str[MAX], revstr[MAX]; 

int checker(int clen, int len) {
    int cnt = 0;
    //cerr << "LEN " << clen << endl;
    for(int i = 0; i+clen-1 < len; ++i) {
        //cerr << i << endl;
        ll h1 = SubHash(H1, i, i+clen-1);
        int mirrorIdx = len-i-1;
        mirrorIdx = mirrorIdx - clen + 1;
        ll h2 = SubHash(H2, mirrorIdx, mirrorIdx+clen-1);
        //cerr << str+i << endl;
        //cerr << revstr+mirrorIdx << endl;

        if(h1 == h2)
            ++cnt;
    }
    return cnt;
}

pii BSeven(int lo, int hi, int len) {
    pii ans = {0, 0};
    while(lo <= hi) {
        int mid = (lo+hi)>>1;
        int eLen = 2*mid+1;
        int cnt = checker(eLen, len);

        if(cnt > 0) {
            ans = max(ans, mp(eLen, cnt));
            lo = mid+1;
        }
        else
            hi = mid-1;
    }
    return ans;
}

pii BSodd(int lo, int hi, int len) {
    pii ans = {0, 0};
    while(lo <= hi) {
        int mid = (lo+hi)>>1;
        int eLen = 2*mid;
        int cnt = checker(eLen, len);

        if(cnt > 0) {
            ans = max(ans, mp(eLen, cnt));
            lo = mid+1;
        }
        else
            hi = mid-1;
    }
    return ans;
}



int main() {
    int t;
    sf("%d", &t);
    PowerGen(7000+100);

    while(t--) {
        sf("%s", str);
        int len = strlen(str);
        for(int i = 0, j = len-1; i < len; ++i, --j)
            revstr[i] = str[j];
        revstr[len] = '\0';

        //cerr << str << "\n" << revstr << endl;

        H1 = Hash(str, len);
        H2 = Hash(revstr, len);

        pii ans = max(BSeven(1, len/2, len), max(BSodd(1, len/2, len), mp(1, len)));
        pf("%d %d\n", ans.fi, ans.se);
    }
    return 0;
}