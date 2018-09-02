// SPOJ
// https://www.spoj.com/problems/FINDSR/

#include <bits/stdc++.h>
using namespace std;
#define MAX                 200010
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
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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

void PrefixTable(int n, char str[], int table[]) {
    int len = 0, i = 1;
    table[0] = 0;
    while(i < n) {
        if(str[i] == str[len]) {
            ++len;
            table[i] = len;
            ++i;
        }
        else {
            if(len != 0)
                len = table[len-1];
            else
                table[i] = 0, ++i;
        }
    }
}

int table[MAX];
char str[MAX];

bool TRY(char str[], int len, int prefLen) {
    for(int i = 0; i < len; ) {
        for(int j = 0; j < prefLen; ++i, ++j)
            if(str[i] != str[j])
                return 0;
    }
    return 1;
}

int main() {
    while(sf("%s", str) and str[0] != '*') {
        int len = strlen(str);
        PrefixTable(len, str, table);
        //cerr << "DONE\n";
        int match = len - table[len-1];
        
        //cerr << "MATCHED " << match << endl;
        
        if(match != 0 and len%match == 0 and TRY(str, len, match))
            pf("%d\n", len/match);
        else
            pf("1\n");
    }
    return 0;
}
