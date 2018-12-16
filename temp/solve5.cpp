#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int n, m;

void trigger(int x, int y, int G[]) {
	G[x] ^= (1 << y);
	if(x-1 >= 0 and y-1 >= 0)
		G[x-1] ^= (1 << (y-1));
	if(x-1 >= 0)
		G[x-1] ^= (1 << y);
	if(x-1 >= 0 and y+1 < m)
		G[x-1] ^= (1 << (y+1));
	if(y-1 >= 0)
		G[x] ^= (1 << (y-1));
	if(y+1 < m)
		G[x] ^= (1 << (y+1));
	if(x+1 < n and y-1 >= 0)
		G[x+1] ^= (1 << (y-1));
	if(x+1 < n)
		G[x+1] ^= (1 << y);
	if(x+1 < n and y+1 < m)
		G[x+1] ^= (1 << (y+1)); 
}

bool isOK(const int G[]) {
	for(int i = 0; i < n; ++i)
		if(G[i] != (1 << m)-1)
			return 0;
	return 1;
}

void printer(int G[]) {
	for(int i = 0; i < n; ++i, printf("\n"))
		for(int j = 0; j < m; ++j)
			printf("%c ", (G[i] & (1 << j)) ? '*':'.');
	printf("\n");
}

int G[8], dp[(1<<7)+10][(1<<7)+10];

int recur(int pstR, int presR) {
	//printer(G);
	if(pstR == n)
		return 0;

	int ret = INF;
	for(int i = 0; i < m; ++i) {
		if(pstR == -1 or G[pstR] == (1 << m)-1) {
			//cout << "skip " << pstR << ", " << presR << endl;
			ret = min(ret, recur(presR, presR+1));
		}
		//if(presR < n) {
			trigger(presR, i, G);
			//cout << presR << ", " << i << endl;
			if(G[pstR] == (1 << m) - 1)
				ret = min(ret, recur(presR, presR+1)+1);
			trigger(presR, i, G);
		//}
	}

	return ret;
}

int main() {
	freopen("out", "w", stdout);

	int t;
	char cc;
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d%d", &n, &m);

		for(int i = 0; i < n; ++i) {
			G[i] = 0;
			for(int j = 0; j < m; ++j) {
				scanf(" %c", &cc);
				if(cc == '*')
					G[i] |= (1<<j);
			}
		}

		//printer(G);

		int ans = recur(-1, 0);
		printf("Case %d: %d\n", Case, ans);
	}

	return 0;
}

/*

1

3 3

***
*.*
***

*/