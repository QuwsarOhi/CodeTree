// LightOj
// 1266 - Points in Rectangle
// 2D Fenwick Tree

#include <bits/stdc++.h>
using namespace std;

/*
    /\
 y  |
    |   (x1,y2) -------- (x2,y2)
    |          |       |
    |          |       |
    |          |       |
    |          ---------
    |   (x1,y1)			(x2, y1)
    |
    |___________________________
   (0, 0)                   x-->
*/



long long tree[1010][1010];
int xMax = 1001, yMax = 1001;

void update(int x, int y, int val) {
	int y1;
	while(x <= xMax) {
		y1 =  y;
		while(y1 <= yMax) {
			tree[x][y1] += val;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}

long long read(int x, int y) {
	long long sum = 0;
	int y1;
	while(x > 0) {
		y1 = y;
		while(y1 > 0) {
			sum += tree[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return sum;
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, x1, x2, y1, y2, c, q;
	scanf("%d", &t);
	map<pair<int, int>, bool>mp;
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &q);
		mp.clear();
		memset(tree, 0, sizeof(tree));
		printf("Case %d:\n", Case);
		while(q--) {
			scanf("%d", &c);
			
			if(c == 0) {
				scanf("%d %d", &x1, &y1);
				++x1, ++y1;
				if(!mp[make_pair(x1, y1)]) {
					update(x1, y1, 1);
					mp[make_pair(x1, y1)] = 1;
				}
			}
			else {
				scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
				++x1, ++x2, ++y1, ++y2;
				//printf("%d %d\n", read(x2+1, y2+1), read(x1, x2));
				printf("%lld\n", read(x2, y2) + read(x1-1, y1-1) - read(x1-1, y2) - read(x2, y1-1));
			}
		}
	}
	
	return 0;
}
