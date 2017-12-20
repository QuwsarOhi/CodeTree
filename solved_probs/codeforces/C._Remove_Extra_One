// C. Remove Extra One
// http://codeforces.com/problemset/problem/900/C

#include <bits/stdc++.h>
using namespace std;
#define MAX                 200100
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


int main() {
    int n, cnt[100010] = {0}, x;
    set<int>Set;
    sf("%d", &n);
    
    for(int i = 0; i < n; ++i) {
        sf("%d", &x);
        auto it = Set.lower_bound(x);           // search for minumum value in past which is equal to x
        if(it == Set.end())                     // value doesn't exist
            cnt[x]--;
        else {
            //cout << "Greater than " << x << " exists : " << *it << endl;
            auto tmp = it;
            tmp++;
            if(tmp == Set.end())                // 'it' is the only value for which x is invalid (x is not a record)
                cnt[*it]++;
        }
        Set.insert(x);
    }
    
    //for(int i = 1; i <= n; ++i)
        //pf("%d : %d\n", i, cnt[i]);
    
    int mx = INT_MIN, val;
    
    for(int i = 1; i <= n; ++i) {
        if(cnt[i] > mx) {
            mx = cnt[i];
            val = i;
        }
    }
    
    cout << val << endl;
    
    return 0;
}
