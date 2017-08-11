// UVa
// 11572 - Unique Snowflakes
// Maximum range of unique values

#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, n, x, mx, cnt, last_occur, idx;
	map<int, int>last_found;
	
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		mx = cnt = last_occur = 0;
		last_found.clear();
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &x);
			idx = last_found[x];
			if(idx != 0) {
				last_occur = max(last_occur, idx);
				cnt = i - last_occur - 1;
			}
			++cnt;
			mx = max(mx, cnt);
			last_found[x] = i;
		}
		printf("%d\n", mx);
	}
	return 0;
}
