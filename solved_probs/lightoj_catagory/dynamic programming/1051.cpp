// LightOJ
// 1051 - Good or Bad

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

bool bad, good;
bool dp[55][6][12];
char s[60];
int len;

bool isVowel(char c) {
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return 1;
    return 0;
}


void recur(int pos, int v, int c) {
    if(v == 3 || c == 5) {  // the string is bad, so no need to go further
        bad = 1;
        return;
    }
    
    if(pos == len) {        // ending the string without getting any bad items
        good = 1;
        return;
    }
    
    if(dp[pos][v][c])       // if this state was previously calculated, return
        return;
        
    if(s[pos] == '?') {     // if the ? mark occurs
        recur(pos+1, v+1, 0);   // consider it as a vowel
        recur(pos+1, 0, c+1);   // consider it as consonant
    }
    else if(isVowel(s[pos]))
        recur(pos+1, v+1, 0);
    else
        recur(pos+1, 0, c+1);
    
    dp[pos][v][c] = 1;      // state is calculated
}

int main() {
    //fileRead("in");
    //fileWrite("out");
    
    int t;
    sf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        sf("%s", s);
        len = strlen(s);
        pf("Case %d: ", Case);
        bad = good = 0;
        memset(dp, 0, sizeof dp);
        recur(0, 0, 0);
        
        if(bad && good)
            pf("MIXED\n");
        else if(bad)
            pf("BAD\n");
        else
            pf("GOOD\n");
    }
    
    return 0;
}
