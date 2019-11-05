#include <bits/stdc++.h>
#define MAX 1000009
#define MOD 1000000007
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

struct FT {
	ll tree[MAX], sz;
	void init(int s) {
		for(int i = 0; i <= s; ++i)
			tree[i] = 0;
		sz = s;
	}
	void update(int idx, int v) {
		for(int i = idx; i <= sz; i += i &-i)
			tree[i] += v;
	}
	ll query(int idx) {
		ll ret = 0;
		for(int i = ret; i > 0; i -= i &-i)
			ret += tree[i];
		return ret;
	}
	ll query(int l, int r) {
		if(l > r)
			swap(l, r);
		return query(r) - query(l-1);
}} F;


struct suffix {
	int idx;
	pair<int, int> rank;
	bool operator < (suffix x) {
		return rank < x.rank;
}} suff[MAX];


int order(char x) {
	return x;
}


int idxToRank[MAX];
void SuffixArray(char str[], int len) {
	for(int i = 0, j = 1; i < len; ++i, ++j) {
		suff[i].idx = i;
		suff[i].rank.first = order(str[i]);
		suff[i].rank.second = (j < len ? order(str[j]):-1);
		idxToRank[i] = 0;
	}	
	sort(suff, suff+len);
	for(int k = 4; k < (2*len); k *= 2) {
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
			suff[i].rank.se = (nxtIdx < len) ? suff[idxToRank[nxtIdx]].rank.first:-1;
		}
		sort(suff, suff+len);
	}
	
	for(int i = 0; i < len; ++i)
		idxToRank[suff[i].idx] = i;
}

ll lcp[MAX];
void Kasai(char str[], int len) {
	int match = 0;
	memset(lcp, 0, sizeof lcp);
	for(int idx = 0; idx < len; ++idx) {
		if(idxToRank[idx] == len-1) {
			match = 0;
			continue;
		}
		int nxtRankIdx = suff[idxToRank[idx]+1].idx;
		while(idx+match < len and nxtRankIdx+match < len and str[idx+match] == str[nxtRankIdx+match])
			++match;
		lcp[nxtRankIdx] = match;
		match -= (match > 0);
	}
}

char s[MAX];
ll p[MAX];
void gen(int len) {
	p[0] = 26;
	for(int i = 1; i < MAX; ++i)
		p[i] = (p[i-1] * 26) % MOD;

	for(int i = 0; i < len; ++i) {
		int l, r;

	}
}

int main() {
	int t;
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%s", s);

		int len = strlen(s);
		s[len++] = '~';
		s[len] = '\0';

		SuffixArray(s, len);
		Kasai(s, len);

		//for(int i = 0; i < len; ++i)
		//	printf("%d %d %d %s\n", i, suff[i].idx, lcp[suff[i].idx], s+suff[i].idx);

		ll ans = 0;
		for(int i = 0; i < len-1; ++i) {
			//cout << i << " " << (len - suff[i].idx - 1) - lcp[suff[i].idx] << endl;
			ans += (len - suff[i].idx - 1) - lcp[suff[i].idx];
		}

		printf("%lld\n", ans);
	}
	return 0;
}