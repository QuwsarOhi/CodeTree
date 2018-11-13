// LightOJ
// 1347 - Aladdin and the Magical Lamp

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
int len[3], l[3], r[3], cum[3][MAX];

bool check(int x, int y) {
    x = rankToIdx[x];
    return (l[y] <= x and x <= r[y]);
}

bool isOK(int lp, int rp) {
    int cc[3] = {cum[0][rp], cum[1][rp], cum[2][rp]};
    for(int i = 0; i < 3; ++i)
        if(lp > 0) cc[i] -= cum[i][lp-1];
    return (cc[0] > 0 and cc[1] > 0 and cc[2] > 0);
}

// Longest Common Prefix [Sparse Table after running Kasai]
int table[MAX][14];
void buildSparseTableRMQ(int n) {                           //  O(n Log n)
    for(int i = 0; i < n; ++i)
        table[i][0] = i;
    for(int j = 1; (1 << j) <= n; ++j)                      // 2^j
        for(int i = 0; i + (1 << j) - 1< n; ++i) {          // For every node
            if(lcp[rankToIdx[table[i][j-1]]] < lcp[rankToIdx[table[i + (1 << (j-1))][j-1]]])
                table[i][j] = table[i][j-1];
            else
                table[i][j] = table[i + (1 << (j-1))][j-1];
}}

int sparseQueryRMQ(int l, int r) {                          // Gives LCP of index l, r in O(1)
    //l = idxToRank[l], r = idxToRank[r];
    //if(l > r) swap(l, r);
    ++l;
    int k = log2(r - l + 1);                                // log(2);
    return min(lcp[rankToIdx[table[l][k]]], lcp[rankToIdx[table[r - (1 << k) + 1][k]]]);
}

int main() {
    //fileRead("in.txt");
    //fileWrite("out.txt");

    int t;
    sf("%d", &t);
    for(int Case = 1; Case <= t; ++Case) {
        sf("%s%s%s", s[0], s[1], s[2]);

        int pppp = 0;
        for(int i = 0, p = 0; i < 3; ++i) {
            len[i] = strlen(s[i]);
            for(int j = 0; j < len[i]; ++j, ++p)
                str[p] = s[i][j];
            str[p++] = '}';
            if(pppp == 1)
                str[p-1] = '{';
            pppp++;

        }

        //cerr << str << endl;
        int TotLen = len[0]+1+len[1]+1+len[2];

        l[0] = 0, r[0] = len[0]-1;
        l[1] = r[0]+2, r[1] = len[0]+len[1];
        l[2] = r[1]+2, r[2] = TotLen-1;

        SuffixArray(str, TotLen);
        Kasai(TotLen, str);
        buildSparseTableRMQ(TotLen);

        for(int i = 0; i < TotLen; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(i) cum[j][i] =+ cum[j][i-1];
                if(check(i, j)) cum[j][i]++;
            }
        }

        int wl = 0, wr = 2;
        int ans = 0;

        //for(int i = 0; i < TotLen; ++i)
        //    cout << i << " " << rankToIdx[i] << " " << str+rankToIdx[i] << " " << lcp[rankToIdx[i]] << endl;

        while(wr < TotLen) {
                //cout << wl << ", " << wr << endl;
                if(isOK(wl, wr)) {
                    ans = max(ans, sparseQueryRMQ(wl, wr));
                    //cout << "New Ans " << ans << endl;
                }
                if(isOK(wl+1, wr)) {
                    wl++;
                    //cout << "wL\n";
                    continue;
                }
                //cout << "wR\n";
                wr++;
        }

        pf("Case %d: %d\n", Case, ans);
    }
    return 0;
}
