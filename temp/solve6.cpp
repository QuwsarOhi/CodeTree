#include <bits/stdc++.h>
using namespace std;
#define MAX                 100100
#define EPS                 1e-2
#define INF                 0x3f3f3f3f
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

struct BIT {
    ll tree[MAX];
    int MaxVal;
    void init(int sz=1e7) {
        memset(tree, 0, sizeof tree);
        MaxVal = sz+1;
    }
    void update(int idx, ll val) {
        for( ;idx <= MaxVal; idx += (idx & -idx))
            tree[idx] += val;
    }
    void update(int l, int r, ll val) {
        if(l > r) swap(l, r);
        update(l, val);
        update(r+1, -val);
    }
    ll read(int idx) {
        ll sum = 0;
        for( ;idx > 0; idx -= (idx & -idx))
            sum += tree[idx];
        return sum;
    }
    ll read(int l, int r) {
        ll ret = read(r) - read(l-1);
        return ret;
    }
};

// Suffix Array
// Complexity : N log(N)

int o[2][MAX], t[2][MAX];
int idxToRank[MAX], rankToIdx[MAX], A[MAX], B[MAX], C[MAX], D[MAX];

void SuffixArray(char str[], int len, int maxAscii = 256) {     // use ~ as a distinguishing charachter
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


int lcp[MAX];
void Kasai(char str[], int len) {               // Matches Same charechters with i'th rank & (i+1)'th rank
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

// Longest Common Prefix [Sparse Table after running Kasai]
int table[MAX][14], lg[MAX];
void buildSparseTableRMQ(int n) {                           //  O(n Log n)
    for(ll i = 0; 1LL << i < n; i++)
        lg[1LL << i] = i;
    for(ll i = 1; i < n; i++)
        lg[i] = max(lg[i], lg[i - 1]);
    for(int i = 0; i < n; ++i)
        table[i][0] = i;
    for(int j = 1; (1 << j) <= n; ++j)                      // 2^j
        for(int i = 0; i + (1 << j) - 1< n; ++i) {          // For every node
            if(lcp[rankToIdx[table[i][j-1]]] < lcp[rankToIdx[table[i + (1 << (j-1))][j-1]]])
                table[i][j] = table[i][j-1];
            else
                table[i][j] = table[i + (1 << (j-1))][j-1];
}}

int sparseQueryRMQ(int l, int r) {          // Gives LCP of index l, r in O(1)
    //l = idxToRank[l], r = idxToRank[r];     // Remove this line if rankUp or rankDown is used
    if(l > r) swap(l, r);
    ++l;
    int k = lg[r - l + 1];                                // log(2);
    return min(lcp[rankToIdx[table[l][k]]], lcp[rankToIdx[table[r - (1 << k) + 1][k]]]);
}

// Gives Upper (lower index) for which the Range minimum LCP is tlen
// Call : 0, PosRank, strlen, totstring_len
int rankUP(int lo, int hi, int tlen, int len) {
    int mid, ret = hi, pos = hi;
    --hi;
    while(lo <= hi) {
        mid = (lo+hi)>>1;
        if(sparseQueryRMQ(mid, pos) >= tlen)
            hi = mid-1, ret = mid;
        else
            lo = mid+1;
    }
    return ret;
}

// Gives Lower (higher index) for which the Range minimum LCP is tlen
// Call : PosRank, len-1 strlen, totstring_len
int rankDown(int lo, int hi, int tlen, int len) {
    int mid, ret = lo, pos = lo;
    ++lo;
    while(lo <= hi) {
        mid = (lo+hi)>>1;
        if(sparseQueryRMQ(mid, pos) >= tlen)
            lo = mid+1, ret = mid;
        else
            hi = mid-1;
    }
    return ret;
}

char str[100100];
BIT FT;

int main() {
	int t, len1, len2, len;
	scanf("%d", &t);


	for(int Case = 1; Case <= t; ++Case) {
		scanf("%s", str);
		len1 = strlen(str);
		str[len1] = '~';
		scanf("%s", str+len1+1);
		len = strlen(str);
		len2 = len - (len1+1);

		cerr << str << " " << len1 << " " << len2 << " " << len << endl;

		SuffixArray(str, len);
		Kasai(str, len);
		buildSparseTableRMQ(len);
		FT.init(len);

		for(int idx = len1+1; idx < len; ++idx)
			FT.update(idxToRank[idx], 1);

		for(int idx = 0; idx < len1; ++idx) {
			
		}
	}
	return 0;
}