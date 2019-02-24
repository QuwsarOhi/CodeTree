// UVa
// 11536 - Smallest Sub-Array

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cnt[1005], x[1000009];
set<ll>s;
int k; 

void genSeq(int n, int m) {
	x[1] = 1, x[2] = 2, x[3] = 3;
	
	for(int i = 4; i <= n; ++i)
		x[i] = (x[i-1] + x[i-2] + x[i-3])%m + 1;
}

bool canRemove(int v) {
	if(v > k)
		return 1;
	if(cnt[v]-1 >= 1)
		return 1;
	return 0;
}

void Add(int v) {
	if(v > k)
		return;
	cnt[v]++;
	if(cnt[v] == 1)
		s.insert(v);
}

void Remove(int v) {
	if(v > k)
		return;
	cnt[v]--;
	if(cnt[v] == 0)
		s.erase(v);
}

int getSize(int n) {
	int l = 1, r = 1, ans = 1000010;

	s.clear();
	memset(cnt, 0, sizeof cnt);
	Add(x[1]);

	while(r < n) {
		while(l+1 <= r and canRemove(x[l]))
			Remove(x[l++]);

		if(s.size() == k)
			ans = min(ans, r-l+1);

		Add(x[++r]);
		if(s.size() == k)
			ans = min(ans, r-l+1);
	}

	return ans;
}

int main() {
	int t, n, m;
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d%d%d", &n, &m, &k);
		genSeq(n, m);

		int ans = getSize(n);

		if(ans != 1000010)
			printf("Case %d: %d\n", Case, ans);
		else
			printf("Case %d: sequence nai\n", Case);
	}

	return 0;
}