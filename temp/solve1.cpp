#include <bits/stdc++.h>
#define MAX 1000010
#define MOD 1000000007
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

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
			suff[i].rank.second = (nxtIdx < len) ? suff[idxToRank[nxtIdx]].rank.first:-1;
		}
		sort(suff, suff+len);
	}
	for(int i = 0; i < len; ++i)
		idxToRank[suff[i].idx] = i;
}

int lcp[MAX];
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
ll p[MAX], cum[MAX];

void pgen() {
	p[0] = 1;
	for(int i = 1; i < MAX; ++i)
		p[i] = (p[i-1] * 26LL) % MOD;
	p[0] = 0;
	for(int i = 1; i < MAX; ++i)
		p[i] = (p[i] + p[i-1])%MOD;
}

void gen(int len) {
	memset(cum, 0, sizeof cum);
	for(int i = 0; i < len-1; ++i) {
		int idx = suff[i].idx;
		int r = len - idx - 1;

		//cout << i << " -> " << r-lcp[idx] << " " << r << endl;
		if(r-lcp[idx] > 0) {
			cum[1] += 1;
			cum[r-lcp[idx]+1] -= 1;
		}
	}

	ll x = 0;
	for(int i = 1; i <= len+1; ++i) {
		x += cum[i];
		cum[i] = (x + cum[i-1] + MOD)%MOD;
		//printf("%d -> %lld\n", i, cum[i]);
	}
}

int main() {
	int t;
	pgen();
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%s", s);

		int len = strlen(s);
		s[len++] = '~';
		s[len] = '\0';

		SuffixArray(s, len);
		Kasai(s, len);
		gen(len);

		//for(int i = 0; i < len; ++i)
		//	printf("%d %d %d %s\n", i, suff[i].idx, lcp[suff[i].idx], s+suff[i].idx);

		int q, l, r;
		scanf("%d", &q);
		printf("Case %d:\n", Case);

		while(q--) {
			scanf("%d%d", &l, &r);
			ll ans = (p[r] - p[l-1] + MOD)%MOD;
			ans = (ans - (cum[r] - cum[l-1] + MOD)%MOD + MOD)%MOD;
			printf("%lld\n", ans);
		}
	}
	return 0;
}


/*

1
abcab

a
b
c
ab
bc
ca
abc
bca
cab
abca
bcab
abcab

*/