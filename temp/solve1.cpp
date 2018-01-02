#include <bits/stdc++.h>
using namespace std;
#define MAX                 200100
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
    ll n, p1Sum = 0, p2Sum = 0, x;
    bool lastMove = 0;
    vl p1,p2;
    
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> x;
        if(x>0) {
            p1.pb(x);
            p1Sum += x;
        }
        else {
            p2.pb(-x);
            p2Sum -= x;
        }
        lastMove = (x>0);
    }
    
    if(p1Sum == p2Sum) {
        bool isSame = 1, winner;
        for(int i = 0; i < min(SIZE(p1), SIZE(p2)); ++i)
            if(p1[i]!=p2[i]) {
                winner = p1[i] > p2[i];
                isSame = 0;
                break;
            }
        isSame &= (SIZE(p1) == SIZE(p2));
        
        if(isSame)
            cout << (lastMove?"first":"second") << endl;
        else
            cout << (winner?"first":"second") << endl;
    }
    else 
        cout << (p1Sum > p2Sum ? "first":"second") << endl;
    
    return 0;
}
    
