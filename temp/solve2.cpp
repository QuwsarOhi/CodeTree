// UVa
// 10309 - Turn the Lights Off

#include <bits/stdc++.h>
using namespace std;

bool g[12][12];
int ans;

void toggle(int x, int y) {
	g[x][y] ^= 1;
	if(x-1 >= 0)
		g[x-1][y] ^= 1;
	if(y-1 >= 0)
		g[x][y-1] ^= 1;
	if(x+1 < 10)
		g[x+1][y] ^= 1;
	if(y+1 < 10)
		g[x][y+1] ^= 1;
}

void printer() {
	for(int i = 0; i < 10; ++i) {
		for(int j = 0; j < 10; ++j)
			printf("%d", g[i][j]);
		printf("\n");
	}
	printf("\n");
}

void recur(int x, int y, int press) {
	if(y == 10)
		x++, y = 0;
	if(press > ans)
		return;
	if(x == 0) {
		recur(x, y+1, press);
		toggle(x, y);
		recur(x, y+1, press+1);
		toggle(x, y);
	}
	else if(x < 10) {
		if(g[x-1][y]) {
			toggle(x, y);
			recur(x, y+1, press+1);
			toggle(x, y);
		}
		else
			recur(x, y+1, press);
	}
	else {
		for(int i = 0; i < 10; ++i)
			if(g[x-1][i]) return;
			ans = min(ans, press);
	}
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	char s[50], c[11][12];
	while(gets(s)) {
		if(strcmp(s, "end") == 0)
			break;
		for(int i = 0; i < 10; ++i)
			gets(c[i]);
		for(int i = 0; i < 10; ++i)
			for(int j = 0; j < 10; ++j) {
				if(c[i][j] == 'O') g[i][j] = 1;
				else g[i][j] = 0;
			}
		ans = 1e7;
		recur(0, 0, 0);
		printf("%s %d\n", s, (ans == 1e7) ? -1:ans);
	}
	return 0;
}