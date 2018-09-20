#include <bits/stdc++.h>
using namespace std;
#define MAX                 7000
#define EPS                 1e-9
#define INF                 1e7
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



struct suffix {
	int idx;
	pii rank;
	bool operator < (suffix x) {
		return rank < x.rank;
}};

int order(char x) {
	if(isdigit(x)) return x - '0';
	else if(isupper(x)) return x-'A'+10;
	else if(islower(x)) return x-'a'+36;
	else return 110;
}

int idxToRank[MAX];									// index to position mapping
suffix suff[MAX];

void SuffixArray(int len, char str[]) {				// First initial 1st and 2nd ranks for all suffix and sort once
    for(int i = 0, j = 1; i < len; ++i, ++j) {
        suff[i].idx = i;
        suff[i].rank.fi = order(str[i]);
        suff[i].rank.se = (j<len) ? order(str[j]):-1;	// if 2nd rank is out of range, assign -1
        idxToRank[i] = 0;
    }
    sort(suff, suff+len);                               
    for(ll k = 4; k < (2*len); k *= 2) {			// Assigning new first rank for all suffix
        int rank = 0;
        int prevRank = suff[0].rank.fi;             // prevRank contains previous suffix's first rank
        suff[0].rank.fi = 0;                        // first rank is always zero 
        idxToRank[suff[0].idx] = 0;
        for(int i = 1; i < len; ++i) {
            if(suff[i].rank == make_pair(prevRank, suff[i-1].rank.se)) {
                prevRank = suff[i].rank.fi;         // we'll manipulate this first rank, so saving it for later use
                suff[i].rank.fi = rank;             // assigning the new rank to this suffix first rank
            }
            else {
                prevRank = suff[i].rank.fi;         // saving this first rank as this will be manipulated
                suff[i].rank.fi = ++rank;           // as this is not as same as previous rank, increment rank by one
            }
            idxToRank[suff[i].idx] = i;
        }        
        for(int i = 0; i < len; ++i) {			// Assign the second rank
            int nxtIdx = suff[i].idx + k/2;   	// finding index at where the substring is as same as this strings [idx, idx+k/2]
            suff[i].rank.se = (nxtIdx < len) ? suff[idxToRank[nxtIdx]].rank.fi:-1;	
        }										// the newIdx contains next segments second half's rank
        sort(suff, suff+len);
}}

char str[MAX];

// abcxpcba
// aaaabbaaaakdjk
// axpayza

int strActualLen, maxPalinLen, maxPalinCount;
/*void PalinCheck(int idx1, int idx2, int match) {
    if(match == 0) return;
    //if(not(idx1 < strActualLen or idx2 < strActualLen)) return;
    //if(not((idx1 < strActualLen and idx2 > strActualLen) or (idx1 > strActualLen and idx2 < strActualLen)))
    //    return;
    cerr << idx1 << " and " << idx2 << " :: " << match << endl;
    if(idx1 > strActualLen) {
        int idx = idx1 - strActualLen - 1;
        idx = strActualLen - idx - 1;
        //if(abs(strActualLen-idx-1) != idx2) return;
        if(idx2+match-1 != idx) return;
    }
    if(idx2 > strActualLen) {
        int idx = idx2 - strActualLen - 1;
        idx = strActualLen - idx - 1;
        //if(abs(strActualLen-idx-1) != idx1) return;
        if(idx1+match-1 != idx) return;
    }

    cerr << idx1 << " and " << idx2 << endl;
    if(match > maxPalinLen) {
        maxPalinCount = 1;
        maxPalinLen = match;
        cout << "GOT new ----------------------------------------------------------------------------- " << match << endl;
        //cout << idx1 << " : " << (str+suff[i].idx) << " = " << suff[i].idx << " lcp " << lcp[suff[i].idx] << endl;
        int r1 = idxToRank[idx1], r2 = idxToRank[idx2];
        cout << str+suff[r1].idx << "\n\n";
        cout << str+suff[r2].idx << "\n\n";
    }
    else if(match == maxPalinLen)
        ++maxPalinCount;
}*/

// Longest Common Prefix: Kasai's Algorithm
// Complexity: O(n) ~ O(n logn)

int lcp[MAX];
void Kasai(int len, char str[]) {				// Matches Same charechters with i'th rank & (i+1)'th rank
	int match = 0;
	for(int idx = 0; idx < len; ++idx) {
		if(idxToRank[idx] == len-1) {
			match = 0;
			continue;
		}
		int nxtRankIdx = suff[idxToRank[idx]+1].idx;
		while(idx+match < len and nxtRankIdx+match < len and str[idx+match] == str[nxtRankIdx+match])
			++match;
        // Palindrome Check
        //PalinCheck(idx, nxtRankIdx, match);
		lcp[nxtRankIdx] = match;				// the lcp match of i'th & (i+1)'th is stored in
		match -= match>0;						// the index of (i+1)'th suffix's index
}}

int consecutiveMaxLCP(int idx, int len) {		// calculates max LCP of index idx
	int r = idxToRank[idx];						// comparing with the next rank string of idx's string
	int ret = lcp[idx];
	if(r+1 < len)
		ret = max(ret, lcp[suff[r+1].idx]);
	return ret;
}


int table[MAX][14];

void buildSparseTableRMQ(int n) {                           //  O(n Log n)
    for(int i = 0; i < n; ++i)
        table[i][0] = i;
    for(int j = 1; (1 << j) <= n; ++j)                      // 2^j
        for(int i = 0; i + (1 << j) - 1< n; ++i) {          // For every node
            if(lcp[suff[table[i][j-1]].idx] < lcp[suff[table[i + (1 << (j-1))][j-1]].idx])
                table[i][j] = table[i][j-1];
            else
                table[i][j] = table[i + (1 << (j-1))][j-1];
}}
int sparseQueryRMQ(int l, int r) {                          // O(1)
    int k = log2(r - l + 1);                                // log(2);
    return min(lcp[suff[table[l][k]].idx], lcp[suff[table[r - (1 << k) + 1][k]].idx]);
}


int main() {
    //fileRead("in");
    //fileWrite("out");
    int t;
    sf("%d", &t);

    while(t--) {
        sf("%s", str);
        int len = strlen(str);
        cerr << "len " << len << endl;
        strActualLen = len, maxPalinLen = maxPalinCount = 0;

        str[len] = '#';
        for(int i = len+1, j = len-1; j >= 0; ++i, --j)
            str[i] = str[j];
        len += len+1;
        str[len] = '\0';

        cerr << str << endl;

        SuffixArray(len, str);
        Kasai(len, str);
        buildSparseTableRMQ(len);

        for(int i = 0; i < len; ++i)
            cout << i << " : " << (str+suff[i].idx) << " = " << suff[i].idx << " lcp " << lcp[suff[i].idx] << endl;
        //if(maxPalinLen == 1)
        //    maxPalinCount = strActualLen;

        for(int i = 0, j = len-1; i != j; ++i, --j) {
            int l = idxToRank[i], r = idxToRank[j];
            if(l < r) ++l;
            else ++r;
            int rmq = sparseQueryRMQ(l, r);
            cerr << "Query idx " << i << " " << j << " :: " << l << " " << r << " = " << rmq << endl;
            if(rmq > maxPalinLen) {
                maxPalinLen = rmq;
                maxPalinCount = 1;
            }
            else if(rmq == maxPalinLen)
                maxPalinCount++;
        }        

        pf("%d %d\n", maxPalinLen, maxPalinCount);
    }
    return 0;
}