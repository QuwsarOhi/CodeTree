#include <bits/stdc++.h>
using namespace std;
#define MAX                 50
#define EPS                 1e-9
#define INF                 1000000000
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


bitset<20>used;
int v[] = {1, 2, 3, 4};
int n = sizeof(v)/sizeof(v[0]);


// how would we generate all possible combination (not permutation) in pen & paper?

void allCombination(int pos) {
    if(used.count() > 0) {                  // print combination
        for(int i = 0; i < n; ++i)
            if(used[i])                     // if in this combination the i'th value is taken
                cout << v[i] << " ";
        cout << "\n";
    }
    
    for(int i = pos; i < n; ++i)            // take and go next
        if(!used[i]) {                      // if not taken
            used[i] = 1;                    // take it
            allCombination(i+1);            // go to the next state
            used[i] = 0;                    // again leave it
        }
}

int main() {
    used.reset();
    allCombination(0);
    return 0;
}
