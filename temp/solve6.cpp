#include <bits/stdc++.h>
using namespace std;
#define MAX                 400500
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

struct node {
    int val;
    node *lft, *rht;
    node(node *L = NULL, node *R = NULL, int v = 0) {
        lft = L;
        rht = R;
        val = v;
}};

node *persis[4*MAX], *null;

node *nCopy(node *x) {
    node *tmp = new node();
    if(x) {
        tmp->val = x->val;
        tmp->lft = x->lft;
        tmp->rht = x->rht;
    }
    return tmp;
}

void update(node *pos, int l, int r, int idx, int val = 1) {
    if(l == r) {
        pos->val += val;
        pos->lft = pos->rht = null;
        return;
    }
    int mid = (l+r)>>1;
    if(idx <= mid) {
        pos->lft = nCopy(pos->lft);
        if(!pos->rht) pos->rht = null;
        update(pos->lft, l, mid, idx, val);
    }
    else {
        pos->rht = nCopy(pos->rht);
        if(!pos->lft) pos->lft = null;
        update(pos->rht, mid+1, r, idx, val);
    }
    pos->val = 0;
    if(pos->rht) pos->val += pos->lft->val;
    if(pos->rht) pos->val += pos->rht->val;
}

int query(node *pos, int l, int r, int L, int R) {
    if(r < L || R < l || pos == NULL || pos == null)    return 0;
    if(L <= l and r <= R)                               return pos->val;
    int mid = (l+r)>>1;
    return query(pos->lft, l, mid, L, R) + query(pos->rht, mid+1, r, L, R);
}

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
int table[MAX][25], lg[MAX];
void lcpSuffixArray(int n) {                           //  O(n Log n)
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

int lcpRMQ(int l, int r) {                                  // Gives LCP of rank l, r in O(1)
    //l = idxToRank[l], r = idxToRank[r];
    if(l > r) swap(l, r);
    ++l;
    int k = lg[r - l + 1];                                // log(2);
    return min(lcp[rankToIdx[table[l][k]]], lcp[rankToIdx[table[r - (1 << k) + 1][k]]]);
}

// if BS is required for lower ranks use up = -1, for higher ranks use up = 1
int GetSameLCPrnk(int posRank, int tlen, int up, int len) {         // find max/min rnk where lcp >= tlen
    int lo = 1, hi, mid, tt, ret = 0;
    if(up == -1 and lcp[rankToIdx[posRank]] < tlen) return posRank;
    hi = up == 1? len-posRank:posRank;
    while(lo <= hi) {
        mid = (lo+hi)>>1;
        tt = posRank+up*mid;
        if(tt >= 0 and tt < len and lcpRMQ(posRank, tt) >= tlen)    // lcp on rank (NOT INDEX!!)
            lo = mid+1, ret = mid;
        else
            hi = mid-1;
    }
    return posRank+ret*up;
}

char str[MAX], tok[MAX];
int strIdx[MAX], arr[MAX], strLen[MAX], rankLcp[MAX];

int main() {
    int n, q, len = 0, l, r, k, lrnk, rrnk;
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
    lcpSuffixArray(len);
    
    //cerr << str << endl;
    //for(int i = 0; i < len; ++i)
    //    pf("%-3d : %-3d : %-3d = %s\n", i, rankToIdx[i], lcp[rankToIdx[i]], str+rankToIdx[i]);

    //cerr << "PERSISTANT\n";
    null = new node();
    null->lft = null;
    null->rht = null;
    persis[0] = new node();
    persis[0]->lft = persis[0]->rht = NULL;
    
    
    //cerr << "new done\n";
    for(int rnk = 0; rnk < len; ++rnk) {
        if(rnk) persis[rnk] = nCopy(persis[rnk-1]);
        //cerr << "RNK " << rnk << " :: " << rankToIdx[rnk]+1 << endl;
        update(persis[rnk], 1, len, rankToIdx[rnk]+1);
    }
    //cerr << "QUERY START\n";

    while(q--) {
        sf("%d%d%d", &l, &r, &k);
        l = strIdx[l-1];
        r = strIdx[r-1]+strLen[r-1]-1;

        //cerr << "QIDX " << l << " " << r << " " << k << " " << idxToRank[strIdx[k-1]] << " " << strLen[k-1] << endl;
        lrnk = GetSameLCPrnk(idxToRank[strIdx[k-1]], strLen[k-1], -1, len);
        rrnk = GetSameLCPrnk(idxToRank[strIdx[k-1]], strLen[k-1], 1, len);
        //cerr << lrnk << " " << rrnk << endl;
        
        //pf("%d\n", ST.query(1, 1, len, lrnk+1, rrnk+1, l, r));
        int ret = query(persis[rrnk], 1, len, l+1, r+1);
        //cerr << "ret " << ret << endl;
        if(lrnk > 0)
            ret -= query(persis[lrnk-1], 1, len, l+1, r+1);
        pf("%d\n", ret);
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

16 1
t
h
dvawooggk
ztqlqgvhzikkynxgbohjcptimzuothen
r
ucqy
rieye
eyklxwlvea
tf
h
chhvhhqro
uhymlqtrxpagbmn
j
hmo
hlzqe
k
4 15 13

4 4
a
aa
a
aa

1 4 4
1 3 1
4 4 2
1 4 1

*/