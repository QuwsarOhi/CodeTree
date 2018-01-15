#include <bits/stdc++.h>
using namespace std;
#define MAX                 100100
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000003
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

string s1, s2;
int freq[12];

ll check(int pos, ll val, int tight) {
    if(pos == SIZE(s1))
        return val;
    for(int i = 9; i >= 0; --i) {
        if(freq[i] > 0) {
            if(tight && i > (s2[pos]-'0'))
                continue;
            bool ntight = tight && ((s2[pos]-'0') == i);
            freq[i]--;
            ll ans = check(pos+1, val*10 + i, ntight);
            freq[i]++;
            if(ans != -1)
                return ans;
        }
    }
    return -1;
}
    
int main() {
    cin >> s1 >> s2;
    
    for(auto it : s1)
        freq[it-'0']++;
    
    if(s1.size() == s2.size())
        cout << check(0, 0, 1) << endl;
    else
        cout << check(0, 0, 0) << endl;
    return 0;
}
