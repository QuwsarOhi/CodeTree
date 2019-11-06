#include <bits/stdc++.h>
#define MAX 10100
using namespace std;
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
void SuffixArray(char s[], int len) {
	for(int i = 0, j = 1; i < len; ++i, ++j) {
		suff[i].idx = i;
		suff[i].rank.first = order(s[i]);
		suff[i].rank.second = (j < len) ? order(s[j]):'~';
		idxToRank[i] = 0;
	}
	sort(suff, suff+len);
	for(int k = 4; k < (2*len); k *= 2) {
		int rank = 0;
		int prevRank = suff[0].rank.first;
		suff[0].rank.first = 0;
		idxToRank[suff[0].idx] = 0;
		
		for(int i = 1; i < len; ++i) {
			prevRank = suff[i].rank.first;
			if(suff[i].rank == make_pair(prevRank, suff[i-1].rank.second))
				suff[i].rank.first = rank;
			else
				suff[i].rank.first = ++rank;
			idxToRank[suff[i].idx] = i;
		} 
		for(int i = 0; i < len; ++i) {
			int nxtIdx = suff[i].idx + k/2;
			suff[i].rank.second = (nxtIdx < len) ? suff[idxToRank[nxtIdx]].rank.first:'~';
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
	for(int i = 0; i < len; ++i) {
		if(idxToRank[i] == len-1) {
			match = 0;
			continue;
		}
		int nxtRankIdx = suff[idxToRank[i]+1].idx;
		while(i+match < len and nxtRankIdx+match < len and s[i+match] == s[nxtRankIdx+match])
			++match;
		lcp[nxtRankIdx] = match;
		match -= match>0;
}}


char s[MAX];
int main() {
	int t, l, r;
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%s%d%d", s, &l, &r);
		if(l > r)
			swap(l, r);

		int len = strlen(s);
		SuffixArray(s, len);
		Kasai(s, len);

		for(int i = 0; i < len; ++i) {
			printf("%d %d %s\n", suff[i].idx, lcp[suff[i].idx], s+suff[i].idx);
		}

		ll ans = 0;
		for(int i = 0; i < len; ++i) {
			int idx = suff[i].idx;
			int tot = len - suff[i].idx - lcp[idx];

			cout << i << " " << idx << " " << tot << " -> " << min(tot-l, r-l+1) << endl;
			ans += max(min(tot-l, r-l+1), 0);
		}
	}

	return 0;
}