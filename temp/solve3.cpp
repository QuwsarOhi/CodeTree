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

vi v, s[100];

int main() {
    fileRead("in");
    
    int n, x, canTake = 0, stacks = 0;
    map<int, int>Map;
    cin >> n;
    
    for(int i = 0; i < n; ++i) {
        cin >> x;
        if(x)
            v.pb(x);
        Map[x]++;
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    for(int i = 0; i < SIZE(v); ++i) {
        if(Map[v[i]] == 0)
            continue;
        /*if(canTake != 0 && Map[canTake-1] > 0) {
            Map[canTake-1]--;
            canTake--;
            --i;
            s[stacks].pb(canTake-1);
        }*/
        if(canTake == 1) {
            for(auto it : Map)
                if(it.second > 0) {
                    it.second--;
                    s[stacks].pb(it.first);
                    canTake--;
                    break;
                }
        }
        else if(canTake == 0) {
            //cout << "taking " << v[i] << endl;
            canTake = v[i];
            stacks++;
            s[stacks].pb(v[i]);
            Map[v[i]]--;
        }
        else {
            canTake = min(canTake-1, v[i]);
            Map[v[i]]--;
            s[stacks].pb(v[i]);
        }
    }
    
    if(canTake > 0 && Map[0])
        Map[0];
    
    stacks += Map[0];
    
    for(int i = 1; i <= stacks; ++i) {
        for(auto it : s[i])
            cout << it << " ";
        cout << endl;
    }
    
    cout << stacks << endl;
    
    return 0;
}