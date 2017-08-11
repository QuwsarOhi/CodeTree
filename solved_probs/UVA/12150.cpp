// UVa
// 12150 - Pole Position
// 1D array manipulation

#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	int n, car[1010], pos[1010], ans[1010], new_pos;
	long long sum;
	while(1) {
		scanf("%d", &n);
		if(n == 0)
			break;
		sum = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d %d", &car[i], &pos[i]);
			sum += pos[i];
		}
		if(sum != 0) {
			printf("-1\n");
			continue;
		}
		bool found = 1;
		memset(ans, -1, sizeof(ans));
		for(int i = 0; i < n; i++) {
			new_pos = i + pos[i];
			if(new_pos < 0 || ans[new_pos] != -1 || new_pos >= n) {
				found = 0;
				break;
			}
			ans[new_pos] = car[i];
		}
		
		if(!found) {
			printf("-1\n");
			continue;
		}
		
		for(int i = 0; i < n-1; i++)
			printf("%d ", ans[i]);
		printf("%d\n", ans[n-1]);
	}
	return 0;
}
