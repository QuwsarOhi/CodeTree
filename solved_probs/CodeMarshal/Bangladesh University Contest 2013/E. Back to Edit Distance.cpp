// CodeMarshal
// E. Back to Edit Distance

#include <bits/stdc++.h>
#define MAX 200010
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;
typedef long long int ll;

int v[2][MAX], idx[2][MAX];

int check1(int x, int y, int n) {
	vector<int> lis;
	for(int i = 1; i <= n; ++i) {
		int p = idx[y][v[x][i]];

		auto it = lower_bound(lis.begin(), lis.end(), p);
		if(it == lis.end())
			lis.push_back(p);
		else
			lis[it-lis.begin()] = p;
	}
	return n*2 - lis.size()*2;
}

int main() {
	int t, n;
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &n);

		for(int i = 0; i < 2; ++i) {
			for(int j = 1; j <= n; ++j) {
				scanf("%d", &v[i][j]);
				idx[i][v[i][j]] = j;
			}
		}

		int ans1 = min(check1(0, 1, n), check1(1, 0, n));
		printf("Case %d: %d\n", Case, ans1);
	}

	return 0;
}