// Codeforces
// C. Bombs
// http://codeforces.com/problemset/problem/350/C
// Manhattan Distance

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


vector<pair<int, pii> >v;

int main() {
    int n, line = 0, x, y;
    cin >> n;
    
    while(n--) {
        cin >> x >> y;
        v.pb({abs(x)+abs(y), {x, y}});
    }
    
    sort(v.begin(), v.end());       // Points closer to (0, 0) must be processed first
    
    stringstream ss;
    for(auto it : v) {
        int X = it.se.fi;
        int Y = it.se.se;
        
        // Go from (0, 0) to (X, Y)
        if(X > 0 && X != 0) {
            line++;
            ss << "1 " << X << " R\n";
        }
        else if(X != 0){
            line++;
            ss << "1 " << -X << " L\n";
        }
        if(Y > 0 && Y != 0) {
            line++;
            ss << "1 " << Y << " U\n";
        }
        else if(Y != 0){
            line++;
            ss << "1 " << -Y << " D\n";
        }
        line++;
        ss << "2\n";
        
        // Return from (X, Y) to (0, 0)
        if(X > 0 && X != 0) {
            line++;
            ss << "1 " << X << " L\n";
        }
        else if(X != 0){
            line++;
            ss << "1 " << -X << " R\n";
        }
        if(Y > 0 && Y != 0) {
            line++;
            ss << "1 " << Y << " D\n";
        }
        else if(Y != 0){
            line++;
            ss << "1 " << -Y << " U\n";
        }
        line++;
        ss << "3\n";
    }
    cout << line << endl;
    cout << ss.str();
    
    return 0;
}
