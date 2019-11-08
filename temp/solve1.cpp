// LightOJ
// 1428 - Melody Comparison
// Suffix Array + (KMP / Hash)

#include <bits/stdc++.h>
#define MAX 51000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

struct Hash {
	const ll mod = 1e9+9, p = 31;
	ll hash[2][MAX], Power[MAX], Len[2];

	void init() {
		//cout << "INIT DONE\n";
	    Power[0] = 1;
	    for(int i = 1; i < MAX; ++i)
	        Power[i] = (Power[i-1] * p)%mod;
	}
	void hashCal(char s[], int len, int idx) {
		Len[idx] = len;
	    for(int i = 0; i < len; ++i) {
	        hash[idx][i] = ((s[i]-'a'+1)* Power[i])%mod;
	        if(i)
	        	hash[idx][i] = (hash[idx][i-1] + hash[idx][i])%mod;
	    }
	}
	bool match(int p, int q, int len, char ss[], char pp[]) {
		ll h1 = hash[0][p+len-1];
		ll h2 = hash[1][q+len-1];
		if(p > 0)
			h1 = (h1 - hash[0][p-1] + mod)%mod;
		if(q > 0)
			h2 = (h2 - hash[2][q-1] + mod)%mod;

		h1 = (h1 * Power[MAX-p-1])%mod;
		h2 = (h2 * Power[MAX-q-1])%mod;

		if(h1 == h2) {
			bool ok = 1;
			for(int i = p, j = q, x = 0; x < len-1 and ok; ++i, ++j, ++x)
				if(ss[i] != pp[j])
					ok = 0;
			return ok;
		}

		return 0;
	}
};

struct suffix {
	int idx;
	pair<int, int> rank;
	bool operator < (suffix x) {
		return rank < x.rank;
	}
} suff[MAX];

int order(char x) {
	return x;
}

int idxToRank[MAX];
void SuffixArray(char s[], int len) {
	for(int i = 0, j = 1; i < len; ++i, ++j) {
		suff[i].idx = i;
		suff[i].rank.first = order(s[i]);
		suff[i].rank.second = (j < len) ? order(s[j]):-1;
		idxToRank[i] = 0;
	}
	sort(suff, suff+len);
	for(long long k = 4; k/2 < len; k *= 2) {
		int rank = 0;
		int prevRank = suff[0].rank.first;
		suff[0].rank.first = 0;
		idxToRank[suff[0].idx] = 0;

		for(int i = 1; i < len; ++i) {
			if(suff[i].rank == make_pair(prevRank, suff[i-1].rank.second)) {
				prevRank = suff[i].rank.first;
				suff[i].rank.first = rank;
			}
			else {
				prevRank = suff[i].rank.first;
				suff[i].rank.first = ++rank;
			}
			idxToRank[suff[i].idx] = i;
		}
		for(int i = 0; i < len; ++i) {
			int nxtIdx = suff[i].idx + k/2;
			suff[i].rank.second = nxtIdx < len ? suff[idxToRank[nxtIdx]].rank.first:-1;
		}
		sort(suff, suff+len);
	}
	for(int i = 0; i < len; ++i)
		idxToRank[suff[i].idx] = i; 
}

int lcp[MAX];
void Kasai(char s[], int len) {
	int match = 0;
	memset(lcp, 0, sizeof lcp);

	for(int idx = 0; idx < len; ++idx) {
		if(idxToRank[idx] == len-1) {
			match = 0;
			continue;
		}
		int nxtRankIdx = suff[idxToRank[idx]+1].idx;
		int p = idx+match, q = nxtRankIdx+match;
		while(p < len and q < len and s[p] == s[q])
			++p, ++q, ++match;

		lcp[nxtRankIdx] = match;
		match -= match > 0;
	}
}


set<int> mpos;
char s[MAX], p[MAX];
Hash h;

ll cal(int len, int plen) {
	ll ret = 0;
	for(int rank = 0; rank < len; ++rank) {
		int idx = suff[rank].idx;
		int r = len;

		set<int> :: iterator it = mpos.lower_bound(idx);

		if(it != mpos.end())
			r = *it + plen - 1;

		//cout << rank << " " << idx << " " << r << " " << r-idx-lcp[idx] << endl;
		ret += max(r-idx-lcp[idx], 0);
	}
	return ret;
}

int main() {
	int t;
	h.init();
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%s%s", s, p);
		int slen = strlen(s);
		int plen = strlen(p);
		
		SuffixArray(s, slen);
		Kasai(s, slen);
		h.hashCal(s, slen, 0);
		h.hashCal(p, plen, 1);
		mpos.clear();

		for(int i = 0; i+plen-1 < slen; ++i)
			if(h.match(i, 0, plen, s, p)) {
				//cout << "Match at " << i << endl;
				mpos.insert(i);
			}

		//for(int i = 0; i < slen; ++i)
		//	printf("%3d %3d %3d   %s\n", slen-suff[i].idx, lcp[suff[i].idx], suff[i].idx, s+suff[i].idx);

		int ans = 0;
		printf("Case %d: %lld\n", Case, cal(slen, plen));
	}
	return 0;
}