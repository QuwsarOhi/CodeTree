// A. Fox and Box Accumulation
// http://codeforces.com/problemset/problem/388/A

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

vi v, taken; //stk[110];

int main() {
    //fileRead("in");
    
    int n, x, sz, stacks = 0;
    
    cin >> n;
    
    while(n--) {
        cin >> x;
        v.pb(x);
        taken.pb(0);
    }
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < SIZE(v); ++i) {
        if(taken[i])
            continue;
        stacks++;
        sz = 1;
        stk[stacks].pb(v[i]);
        for(int j = i+1; j < SIZE(v); ++j) {
            if(sz <= v[j] && !taken[j]) {
                taken[j] = 1;
                sz++;
                stk[stacks].pb(v[j]);
            }
        }
    }
    
    /*int sum = 0;
    for(int i = 1; i <= stacks; ++i) {
        for(auto it : stk[i])
            cout << it << " ";
        cout << endl;
        sum += SIZE(stk[i]);
    }
    cout << "Total " << sum << endl; 
    */
    
    cout << stacks << endl;
    return 0;
}
