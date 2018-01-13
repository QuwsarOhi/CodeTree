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


int main() {
    int n, pos, l, r, ans = 0;
    
    cin >> n >> pos >> l >> r;
    if(r < l)
        swap(l,r);
        
    /*
    if(l == 1 && r == n) {      // all range
        cout << "0" << endl;
        return 0;
    }*/
    
    if(abs(pos-l) < abs(pos-r)) {       // go left
        if(pos != l && l != 1) {        // go left and delete           
            ans += abs(pos-l);
            pos = l;
        }
        if(l != 1)
            ++ans;
        if(r != n) {                    // go r7 and delete
            ans += abs(pos-r);
            ans++;
        }
    }
    else {
        //cout << "here" << endl;
        if(pos != r && r != n) {        // go r8 and delete
            ans += abs(pos-r);
            pos = r;
        }
        if(r != n)
            ++ans;
        if(l != 1) {                    // go lft and delete
            ans += abs(l-pos);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
