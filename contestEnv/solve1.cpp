#include <bits/stdc++.h>
using namespace std;
#define MAX                 13333333
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
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
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


int main() {
    string str;
    cin >> str;
    
    
    char p[] = {'a', 'b', 'c'};
    int k = 0;
    bool ok = true;
    for(int i = 0; i < SIZE(str) and ok; ++i) {
        
        
        if(str[i] != p[k])
            ++k;
        
        if(str[i] == 'a' and k != 0)
            ok = false;
        if(str[i] == 'b' and k != 1)
            ok = false;
        if(str[i] == 'c' and k != 2)
            ok = false;
        if(k >= 3)
            ok = false;
    }
    
    if(!ok) {
        cout << "NO\n";
        return 0;
    }

    int a= 0, b = 0, c = 0;
    
    for(auto it : str) {
        if(it == 'a')
            ++a;
        else if(it == 'b')
            ++b;
        else
            ++c;
    }
    
    if((a == c or b == c) and c > 0 and a > 0 and b > 0)
        cout << "YES\n";
    else
        cout << "NO\n";
    
    //main();
    return 0;
}
