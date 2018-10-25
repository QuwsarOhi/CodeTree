#include <bits/stdc++.h>
using namespace std;

int d[8][2] = { {0, 1}, {-1, 1}, {1, 1}, 
				{0, -1}, {-1, -1}, {1, -1},
				{-1, 0},
				{1, 0}
			};

int nn, mm;
int cnt[60][60];
pair<int, int>p[60];
map<int, int, greater<int> >MAP;

void dfs(int x, int y, int id) {
	if(x < 0 or y < 0 or x >= nn or y >= mm) return;
	++cnt[x][y];
	dfs(x+d[id][0], y+d[id][1], id);
}

void PP(int y) {
	int x = MAP[y];
	if(x == -1 or y == 0)
		printf("*");
	else
		printf("%d", x);
}

int main() {
	freopen("out", "w", stdout);
	
	int n, c, pos;
	char s;

	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i) {
		scanf("%d", &p[i].first);
		p[i].second = i+1;
	}

	scanf("%d%d%d", &nn, &mm, &c);

	//cerr << "DONE\n";
	for(int i = 0; i < c; ++i) {
		scanf(" %c %d", &s, &pos);
		//cerr << s << " " << pos << endl;
		pos--;
		if(s == 'L') {
			dfs(pos, 0, 0);
			dfs(pos-1, 0, 1);
			dfs(pos+1, 0, 2);
		}
		else if(s == 'R') {
			dfs(pos, mm-1, 3);
			dfs(pos-1, mm-1, 4);
			dfs(pos+1, mm-1, 5);
		}
		else if(s == 'D') {
			dfs(nn-1, pos, 6);
			dfs(nn-1, pos-1, 4);
			dfs(nn-1, pos+1, 1);
		}
		else {
			dfs(0, pos, 7);
			dfs(0, pos-1, 5);
			dfs(0, pos+1, 2);
		}
	}

	//for(int i = 0; i < nn; ++i, printf("\n"))
	//	for(int j = 0; j < mm; ++j)
	//		printf("%2d ", cnt[i][j]);

	sort(p, p+n, greater<pair<int, int> >());
	for(int i = 0; i < nn; ++i)
		for(int j = 0; j < mm; ++j)
			MAP[cnt[i][j]] = -1;

	if(MAP.size() < n) {
		printf("No Solution Mr. Problem. Sorry!\n");
		return 0;
	}

	int idx = 0;
	for(auto it = MAP.begin(); it != MAP.end() and idx < n; ++it, ++idx)
		it->second = p[idx].second;

	for(int i = 0; i < nn; ++i, printf("\n")) {
		PP(cnt[i][0]);
		for(int j = 1; j < mm; ++j) {
			printf(" ");
			PP(cnt[i][j]);
		}
	}

	return 0;
}

/*
2
1 2
5 8 4
U 3
L 3
R 4
D 6
*/