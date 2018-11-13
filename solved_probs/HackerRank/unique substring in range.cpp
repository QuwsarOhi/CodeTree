// HackerRank
// Sherlock and Unique Substrings
// https://www.hackerrank.com/contests/101hack26/challenges/sherlock-and-unique-substrings/problem 
// Suffix Array + Segment Tree + Offline

#include <bits/stdc++.h>
using namespace std;
#define MAX                 200000
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

struct SegTree {
	ll tree[MAX*4] = {0}, prop[MAX*4] = {0};
	void pushDown(int pos, int l, int r) {
		tree[pos] += prop[pos]*(r-l+1);
		if(l == r) {
			prop[pos] = 0;
			return;
		}
		prop[pos<<1] += prop[pos];
		prop[pos<<1|1] += prop[pos];
		prop[pos] = 0;
	}
	void update(int pos, int l, int r, int L, int R, ll val) {
		pushDown(pos, l, r);
		if(r < L or R < l) return;
		if(L <= l and r <= R) {
			prop[pos] += val;
			pushDown(pos, l, r);
			return;
		}
		int mid = (l+r)>>1;
		update(pos<<1, l, mid, L, R, val);
		update(pos<<1|1, mid+1, r, L, R, val);
		tree[pos] = tree[pos<<1] + tree[pos<<1|1];
	}
	ll query(int pos, int l, int r, int L, int R) {
		pushDown(pos, l, r);
		if(r < L or R < l) return 0;
		if(L <= l and r <= R) return tree[pos];
		int mid = (l+r)>>1;
		return query(pos<<1, l, mid, L, R) + query(pos<<1|1, mid+1, r, L, R);
}};


struct suffix{
    int idx;                        // Start index of suffix
    pair<int, int> rank;            // Sorting Ranks
};

suffix suff[MAX];

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

char str[MAX];
vi lcp;
vl ANS;
queue<int>lquery;
SegTree ST;
map<int, vii>MAP;

int main() {
	//fileRead("in");
	//fileWrite("out");

	int q, l, r;
	sf("%s", str);
	int len = strlen(str);
	SuffixArray(str, len);
	lcp = Kasai(len, suff, str);

	sf("%d", &q);


	//for(int i = 0; i < len; ++i)
	//	cerr << suff[i].idx << " :: " << (str + suff[i].idx) << endl;

	/*while(q--) {
		sf("%d%d", &l, &r);
		--l, --r;
		int ans = 0;
		for(int i = l; i <= r; ++i) {
			int maxLcp = consecutiveMaxLCP(i, len, lcp);
			ans += max((r-i+1)-maxLcp, 0);

			cerr << i << " :: " << maxLcp << " -> " << (r-i+1)-maxLcp << endl;
		}

		cerr << "COrrect " << ans << endl;

		int maxLcp = consecutiveMaxLCP(l, len, lcp);
		cerr << maxLcp << " " << r-l+1 << endl;
		pf("%d\n", max((r-l+1)-maxLcp, 0));
	}*/

	ANS.resize(q);
	for(int i = 0; i < q; ++i) {
		sf("%d%d", &l, &r);
		--l, --r;
		MAP[l].pb({r, i});
	}

	for(int i = 0; i < len; ++i) {
		int maxLcp = consecutiveMaxLCP(i, len, lcp);
		if(i+maxLcp < len) {
			ST.update(1, 1, len, i+maxLcp, len, 1);
			lquery.push(i);
		}
	}

	for(auto it : MAP) {
		int l = it.first;
		vii vec = it.second;
		sort(All(vec));

		while(not lquery.empty() and lquery.front() < l) {
			int ll = lquery.front();
			int maxLcp = consecutiveMaxLCP(ll, len, lcp);
			if(ll+maxLcp < len)
				ST.update(1, 1, len, ll+maxLcp, len, -1);
			lquery.pop();
		}

		for(auto it2 : vec) {
			int r = it2.first, idx = it2.second;
			ANS[idx] = ST.query(1, 1, len, l, r);
		}
	}

	for(int i = 0; i < q; ++i)
		pf("%lld\n", ANS[i]);

    return 0;
}