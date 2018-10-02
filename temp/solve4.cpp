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

#include <ext/pb_ds/assoc_container.hpp>    // rb_tree_tag
#include <ext/pb_ds/tree_policy.hpp>        // tree_order_statistics_node_update
#define at(X)          find_by_order(X)
#define lessThan(X)    order_of_key(X)
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------


// Suffix Array
// Complexity : N log(N)

int o[2][MAX], t[2][MAX];
int idxToRank[MAX], rankToIdx[MAX], A[MAX], B[MAX], C[MAX], D[MAX];

void SuffixArray(char str[], int len, int maxAscii = 256) {
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
	l = idxToRank[l], r = idxToRank[r];
	if(l > r) swap(l, r);
	++l;
    int k = log2(r - l + 1);                                // log(2);
    return min(lcp[rankToIdx[table[l][k]]], lcp[rankToIdx[table[r - (1 << k) + 1][k]]]);
}

// Merge Sort Tree
struct MergeSortTree {
    vector<pii>tree[MAX*4];
    int len;
    void init(int llen, int val[], int rnk[]) {
    	len = llen;
    	init(1, 1, len, val, rnk);
    }
    ll query(int l, int r, int k1, int k2, int ln) {
    	cerr << "Query at " << l << " - " << r << " len " << len <<  endl;
    	return query(1, 1, len, l+1, r+1, k1, k2, ln);
    }
    void init(int pos, int l, int r, int val[], int rnk[]) {
        tree[pos].clear();                              // Clears past values
        if(l == r) {
            tree[pos].push_back({val[l-1], rnk[l-1]});
            return;
        }
        int mid = (l+r)>>1;
        init(pos<<1, l, mid, val, rnk);
        init(pos<<1|1, mid+1, r, val, rnk);
        merge(tree[pos<<1].begin(), tree[pos<<1].end(), tree[pos<<1|1].begin(), tree[pos<<1|1].end(), back_inserter(tree[pos]));
    }
    ll query(int pos, int l, int r, int L, int R, int k1, int k2, int ln) {
    	//cerr << "pos " << l << ", " << r << endl;
        if(r < L || R < l) return 0;
        if(L <= l && r <= R) {
        	cerr << "AT range " << l << ", " << r << " : ";
        	for(auto it : tree[pos]) cerr << "(" << it.fi << ", " << it.se << "), ";
        	
            auto it = *upper_bound(All(tree[pos]), mp(k2, ln));
            auto it2 = *lower_bound(All(tree[pos]), mp(k1, ln));

            cerr << "BS " << it.fi << " " << it.se << ", " << it2.fi << " " << it2.se << endl;

            ll ret = (ll)(upper_bound(All(tree[pos]), mp(k2, ln)) - lower_bound(All(tree[pos]), mp(k1, ln)));
            cerr << " Got " << ret << endl;
            return ret;        // MODIFY
        }
        int mid = (l+r)>>1;
        return query(pos<<1, l, mid, L, R, k1, k2, ln) + query(pos<<1|1, mid+1, r, L, R, k1, k2, ln);
}};


char str[3*MAX], tok[MAX];
int strIdx[MAX], arr[MAX], strLen[MAX], rankLcp[MAX];
ordered_set<int> ZEROS;
MergeSortTree ST;

pii genRange(int idx) {
	int itl = *ZEROS.at(ZEROS.lessThan(idx)-1);
	int itr = *ZEROS.upper_bound(idx);

	//cout << itl << " + " << itr << endl;
	itr--;
	return {itl, itr};
}

int main() {
	int n, q, len = 0;
	sf("%d%d", &n, &q);

	for(int i = 0; i < n; ++i) {
		sf("%s", tok);
		int tokLen = strlen(tok);
		
		if(len != 0)
			str[len++] = '~';

		strIdx[i] = len;
		strLen[i] = tokLen;
		for(int j = 0; j < tokLen; ++j)
			str[len++] = tok[j];
	}

	SuffixArray(str, len);
	Kasai(str, len);
	buildSparseTableRMQ(len);

	cerr << str << endl;

	for(int i = 0; i < len; ++i)
		cerr << i << " : " << rankToIdx[i] << " = " << str+rankToIdx[i] << " :: " << lcp[rankToIdx[i]] << endl;

	/*for(int i = 0; i < n; ++i)
		for(int j = i+1; j < n; ++j)
			cout << strIdx[i] << " & " << strIdx[j] << " :: " << sparseQueryRMQ(strIdx[i], strIdx[j]) << endl;

	arr[1] = strLen[0];
	for(int i = 2; i <= n; ++i)
		arr[i] = sparseQueryRMQ(strIdx[i-2], strIdx[i-1]);

	for(int i = 1; i <= n; ++i)
		cout << arr[i] << " ";*/

	for(int rnk = 0; rnk < len; ++rnk)
		if(lcp[rankToIdx[rnk]] == 0)
			ZEROS.insert(rnk);

	cerr << "ZEROS ";
	for(auto it : ZEROS)
		cerr << it << " ";
	cerr << endl;

	for(int i = 0; i < n; ++i) {
		pii b = genRange(idxToRank[strIdx[i]]);
		cerr << strIdx[i] << " = " << idxToRank[strIdx[i]] << " :: " << b.fi << ", " << b.se << endl;
	}

	for(int i = 0; i < len; ++i)
		rankLcp[i] = lcp[rankToIdx[i]];

	ST.init(len, rankToIdx, rankLcp);

	cerr << "Rank to IDX" << " :: ";
	for(int i = 0; i < len; ++i)
		cerr << rankToIdx[i] << " ";
	cerr << endl;

	int l, r, k;
	while(q--) {
		sf("%d%d%d", &l, &r, &k);
		pii rr = genRange(idxToRank[strIdx[k-1]]);
		cerr << rr.fi << ", " << rr.se << endl;
		if(rr.fi > rr.se)
			pf("0\n");
		else if(rr.fi == rr.se)
			pf("1");
		else {
			l = strIdx[l-1], r = strIdx[r-1] + strLen[r];
			k = strLen[k-1];
			cerr << l << " and " << r << " k " << k << endl;
			pf("%lld\n", ST.query(rr.fi, rr.se, l, r, k)+1);
		}
	}

	return 0;
}

/*
3 0
a
ab
aba
*/


/*
5 5
a
ab
abab
ababab
b
1 5 1
3 5 1
1 5 2
1 5 3
1 4 5
*/