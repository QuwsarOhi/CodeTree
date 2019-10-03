#include <bits/stdc++.h>
#define MAX 200011
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;
typedef long long int ll;

struct BIT {
	int tree[MAX];
	int MaxVal;
	void init(int sz) {
		for(int i = 0; i <= sz+3; ++i)
			tree[i] = 0;
		MaxVal = sz+1;
	}
	void update(int idx, int val) {
		for( ; idx <= MaxVal; idx += (idx & -idx))
			tree[idx] += val;
	}
	int read(int idx) {
		int ret = 0;
		for( ; idx > 0; idx -= (idx & -idx))
			ret += tree[idx];
		return ret;
	}
};

BIT d;
int v[2][MAX], idx[2][MAX];

int check1(int x, int y, int n) {	// y changes w.r.t x
	int ret = 0;
	d.init(n);

	int cst = 0;
	for(int i = 1; i <= n; ++i) {
		int val = v[x][i];

		int p = d.read(idx[y][val]) + idx[y][val];
		int q = i+cst;

		if(p != q) {
			--cst, ++ret;
			d.update(idx[y][val], -1);
		}
	}

	return ret*2;
}

int check2(int x, int y, int n) {	// y repositioned w.r.t x
	int ret = 0;
	d.init(n+1);
	cerr << x << ", " << y << ", " << n << endl;

	for(int i = 1; i <= n; ++i) {
		int val = v[x][i];
		int j = idx[y][val] + d.read(idx[y][val]);

		cerr << i << " vs " << j << " : " << val << ", " << v[y][j] << " -> " << idx[y][val] << " ";

		if(i != j) {
			cerr << "Replace " << i << " " << idx[y][val] << endl;
			d.update(i, 1);
			d.update(idx[y][val]+1, -1);
			ret++;
		}
		else
			cerr << "\n";
	}

	return ret*2;
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
		int ans2 = min(check2(0, 1, n), check2(1, 0, n));
		cerr << ans1 << " " << ans2 << endl;
		printf("Case %d: %d\n", Case, min(ans1, ans2));
	}

	return 0;
}


/*

1
4
2 3 4 1
1 2 3 4


2
5
1 3 5 4 2
1 5 4 3 2
4
1 2 4 3
3 4 2 1

1
4
3 1 4 2
2 1 3 4

1
5
5 4 3 2 1
3 2 5 1 4

1
5
5 2 3 4 1
1 2 4 3 5

1
5
2 5 3 1 4 
1 2 3 4 5

*/