#include <bits/stdc++.h>
using namespace std;
#define MAX                 15500
#define EPS                 1e-9
#define INF                 0x3f3f3f3f
#define pb                  push_back
#define mp                  make_pair
#define xx                  first
#define yy                  second
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

int o[2][MAX], t[2][MAX];
int idxToRank[MAX], rankToIdx[MAX], A[MAX], B[MAX], C[MAX], D[MAX];

void SuffixArray(char str[], int len, int maxAscii = 256) {     // use ~ as a distinguishing charechter
    int x = 0;
    memset(A, 0, sizeof A);
    memset(C, 0, sizeof C);
    memset(D, 0, sizeof D);
    memset(o, 0, sizeof o);
    memset(t, 0, sizeof t);

    for(int i = 0; i < len; ++i) A[(str[i]-'a')] = 1;
    for(int i = 1; i < maxAscii; ++i) A[i] += A[i-1];
    for(int i = 0; i < len; ++i) o[0][i] = A[(int)(str[i]-'a')];
 
    for (int j = 0, jj = 1, k = 0; jj < len && k < len; ++j, jj <<= 1) {
        memset(A, 0, sizeof A);
        memset(B, 0, sizeof B);
        for(int i = 0; i < len; ++i) {
            ++A[ t[0][i] = o[x][i] ];
            ++B[ t[1][i] = (i+jj<len) ? o[x][i+jj] : 0 ];
        }
        for(int i = 1; i <= len; ++i) {
            A[i] += A[i-1];
            B[i] += B[i-1];
        }
        for(int i = len-1; i >= 0; --i)
            C[--B[t[1][i]]] = i;
        for(int i = len-1; i >= 0; --i)
            D[--A[t[0][C[i]]]] = C[i];
        x^=1;
        o[x][D[0]] = k = 1;
        for(int i = 1; i < len; ++i)
            o[x][D[i]]= (k += (t[0][D[i]] != t[0][D[i-1]] || t[1][D[i]] != t[1][D[i-1]]));
    }
    for(int i = 0; i < len; i++) {
        idxToRank[i] = o[x][i]-1;
        rankToIdx[o[x][i]-1] = i;
}}

// Longest Common Prefix: Kasai's Algorithm
// Complexity: O(n)

int lcp[MAX];
void Kasai(int len, char str[]) {               // Matches Same charechters with i'th rank & (i+1)'th rank
    int match = 0;
    for(int idx = 0; idx < len; ++idx) {
        if(idxToRank[idx] == len-1) {
            match = 0;
            continue;
        }
        int nxtRankIdx = rankToIdx[idxToRank[idx]+1];
        while(idx+match < len and nxtRankIdx+match < len and str[idx+match] == str[nxtRankIdx+match])
            ++match;
        lcp[nxtRankIdx] = match;                // the lcp match of i'th & (i+1)'th is stored in
        match -= match>0;                       // the index of (i+1)'th suffix's index
}}

char s[3][5050], str[MAX];
int len[3], l[3], r[3];

bool check(int x, int y) {
    return (l[y] <= x and x <= r[y]);
}

int main() {
    //fileRead("in");
    //fileWrite("out");

    int t;
    sf("%d", &t);
    for(int Case = 1; Case <= t; ++Case) {
        sf("%s%s%s", s[0], s[1], s[2]);

        for(int i = 0, p = 0; i < 3; ++i) {
            len[i] = strlen(s[i]);
            for(int j = 0; j < len[i]; ++j, ++p)
                str[p] = s[i][j];
            str[p++] = '~';
        }

        //cerr << str << endl;
        int ll = len[0]+1+len[1]+1+len[2];
        
        l[0] = 0, r[0] = len[0]-1;
        l[1] = r[0]+2, r[1] = len[0]+len[1];
        l[2] = r[1]+2, r[2] = ll-1;

        SuffixArray(str, ll);
        Kasai(ll, str);

        int ans = 0;
        for(int i = 1; i+2 < ll; ++i) {
            if(check(rankToIdx[i], 0) and check(rankToIdx[i+1], 1) and check(rankToIdx[i+2], 2))
                ans = max(ans, min(lcp[rankToIdx[i+1]], lcp[rankToIdx[i+1]]));
            if(check(rankToIdx[i], 0) and check(rankToIdx[i+1], 2) and check(rankToIdx[i+2], 1))
                ans = max(ans, min(lcp[rankToIdx[i+1]], lcp[rankToIdx[i+1]]));
            else if(check(rankToIdx[i], 1) and check(rankToIdx[i+1], 1) and check(rankToIdx[i+2], 2))
                ans = max(ans, min(lcp[rankToIdx[i+1]], lcp[rankToIdx[i+1]]));
            else if(check(rankToIdx[i], 1) and check(rankToIdx[i+1], 2) and check(rankToIdx[i+2], 1))
                ans = max(ans, min(lcp[rankToIdx[i+1]], lcp[rankToIdx[i+1]]));
            else if(check(rankToIdx[i], 2) and check(rankToIdx[i+1], 0) and check(rankToIdx[i+2], 1))
                ans = max(ans, min(lcp[rankToIdx[i+1]], lcp[rankToIdx[i+1]]));
            else if(check(rankToIdx[i], 2) and check(rankToIdx[i+1], 1) and check(rankToIdx[i+2], 0))
                ans = max(ans, min(lcp[rankToIdx[i+1]], lcp[rankToIdx[i+1]]));
        }

        pf("Case %d: %d\n", Case, ans);
    }
    return 0;
}