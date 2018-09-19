#include <bits/stdc++.h>
using namespace std;
#define MAX                 300000
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
 

struct suffix{
    int idx;                        // Start index of suffix
    pair<int, int> rank;            // Sorting Ranks
};

suffix suff[200000];

bool cmp(suffix a, suffix b) {
    return a.rank < b.rank;
}

int order(char x) {                 // Ordering : Number < Capital Letter < Small Letter
    if(isdigit(x))
        return x-'0';
    else if(isupper(x))
        return x-'A'+10;
    else if(islower(x))
        return x-'a'+36;
    else
        return 110;                 // Adding a big constant : {, }, #..
}

void SuffixArray(char str[], int n) {
    // First initial 1st and 2nd ranks for all suffix and sort once
    for(int i = 0, j = 1; i < n; ++i, ++j) {
        suff[i].idx = i;
        suff[i].rank.fi = order(str[i]);
        suff[i].rank.se = (j<n) ? order(str[j]):-1;                 // if 2nd rank is out of range, assign -1
    }
    
    sort(suff, suff+n, cmp);
    int Rank[n];                                    // index to position mapping
    
    for(ll k = 4; k < (2*n); k *= 2) {
        // Assigning new first rank for all suffix
        int rank = 0;
        int prevRank = suff[0].rank.fi;             // prevRank contains previous suffix's first rank
        suff[0].rank.fi = 0;                        // first rank is always zero 
        Rank[suff[0].idx] = 0;

        for(int i = 1; i < n; ++i) {
            if(suff[i].rank == make_pair(prevRank, suff[i-1].rank.se)) {
                prevRank = suff[i].rank.fi;         // we'll manipulate this first rank, so saving it for later use
                suff[i].rank.fi = rank;             // assigning the new rank to this suffix first rank
            }
            else {
                prevRank = suff[i].rank.fi;         // saving this first rank as this will be manipulated
                suff[i].rank.fi = ++rank;           // as this is not as same as previous rank, increment rank by one
            }
            Rank[suff[i].idx] = i;
        }
        
        // Assign the second rank
        
        for(int i = 0; i < n; ++i) {
            int nxtIdx = suff[i].idx + k/2;         // finding index at where the substring is as same as this strings [idx, idx+k/2]
            suff[i].rank.se = (nxtIdx < n) ? suff[Rank[nxtIdx]].rank.fi:-1;     // the newIdx contains next segments second half's rank
        }
        sort(suff, suff+n, cmp);
    }
}

// Longest Common Prefix: Kasai's Algorithm
// Complexity: O(n) ~ O(n logn)

vi idxToRank;
vi Kasai(int len, suffix suff[], char str[]) {
	vi idxLcp(len);

	idxToRank.resize(len);
	for(int rank = 0; rank < len; ++rank)
		idxToRank[suff[rank].idx] = rank;
	
	int match = 0;
	for(int idx = 0; idx < len; ++idx) {
		if(idxToRank[idx] == len-1) {
			match = 0;
			continue;
		}
		int nxtRankIdx = suff[idxToRank[idx]+1].idx;
		while(idx+match < len and nxtRankIdx+match < len and str[idx+match] == str[nxtRankIdx+match])
			++match;
		idxLcp[nxtRankIdx] = match;
		match -= match>0;
	}
	return idxLcp;
}

int consecutiveMaxLCP(int idx, int len, vi &idxLcp) {
	int r = idxToRank[idx];
	int ret = idxLcp[idx];
	if(r+1 < len)
		ret = max(ret, idxLcp[suff[r+1].idx]);
	return ret;
}

int main() {
    char str[200000];
    scanf("%s", str);
    int len = strlen(str);
    
    SuffixArray(str, len);
    
    for(int i = 0; i < len; ++i)                // i : rank
        printf("%d %s\n", suff[i].idx, (str+suff[i].idx), suff[i].rank.fi);            // idx: starting index of suffix
        //printf("%d\n", suff[i].idx);
   	
   	vi lcp = Kasai(len, suff, str);

   	pf("\n");
   	for(int i = 0; i < len; ++i) {
   		printf("%d 	%d\n", lcp[suff[i].idx], consecutiveMaxLCP(suff[i].idx, len, lcp));
   	}
    
    return 0;
}