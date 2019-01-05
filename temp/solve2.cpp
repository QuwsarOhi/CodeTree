#include <bits/stdc++.h>
using namespace std;
#define MAX                 510000
#define EPS                 1e-9
#define INF                 0x3f3f3f3f
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define xx                  first
#define yy                  second
#define pi                  acos(-1)
#define pf                  printf
#define sf(XX)              scanf("%lld", &XX)
#define SIZE(a)             ((ll)a.size())
#define ALL(S)              S.begin(), S.end()              
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define FastIO              ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FileRead(S)         freopen(S, "r", stdin);
#define FileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())
#define STOLL(X)            stoll(X, 0, 0)

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
typedef vector<ll>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;

//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

int main() {
    int k;
    string str;

    cin >> str;
    cin >> k;

    int c = 0, s = 0, len = 0;
    for(auto it : str) {
        if(it == '?')
            c++;
        else if(it == '*')
            s++;
        else
            len++;
    }

    if(len-c-s > k or (len < k and s == 0)) {
        cout << "impossible\n";
        return 0;
    }

    cerr << "DONE\n";
    while(len > k) {
        for(int i = 0; i < str.size(); ++i)
            if(str[i] == '*' or str[i] == '?') {
                str.erase(str.begin()+i);
                --len;
                cerr << str << "+\n";
            }
    }

    while(len < k) {
        for(int i = 0; i < str.size(); ++i)
            if(str[i] == '*') {
                str.insert(str.begin()+i, str[i-1]);
                ++len;
                cerr << str << "-\n";
            }
    }

    for(int i = 0; i < str.size(); ++i)
        if(str[i] != '*' and str[i] != '?')
            cout << str[i];
    cout << endl;
    return 0;
}