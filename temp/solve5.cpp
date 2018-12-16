#include <bits/stdc++.h>
using namespace std;

void trigger(int x, int y, int G[]) {
	// horizontal 
    for(int i = 0; i < m; ++i)
        G[x] ^= (1 << i);
    
    // vertical
    for(int i = 0; i < n; ++i)
        G[i] ^= (1 << y);
    
    // diagonals
    int xx = x, yy = y;
    while(xx >= 0 and yy >= 0)
    	G[xx--] ^= (1 << yy--);
    xx = x, yy = y;
    while(xx < n and yy < m)
    	G[xx++] ^= (1 << yy++);

    //
    xx = x, yy = y;
    while(xx < n and yy >= 0)
        G[xx++] ^= (1 << yy--);
    xx = x, yy = y;
    while(xx >= 0 and yy < m)
        G[xx--] ^= (1 << yy++);

    Toggle(x, y, v);
    G[x] ^= (1 << y);
    return v;
}

bool isOK(const int G[]) {
	for(int i = 0; i < n; ++i)
		if(G[i] != (1 << j)-1)
			return 0;
	return 1;
}

int G[8], dp[(1<<7)+10][(1<<7)+10];


int recur(int pst, int pres) {
	if(pres == n)
		return isOK(G) ? 0:INF;

	int ret = INF;
	for(int i = 0; i < m; ++i) {
		if(pst != -1 and pst == (1 << m)-1)
			ret = min(ret, recur(pres, pres+1));
		trigger(i, j, G);
		ret = min(ret, recur(pres, pres+1)+1);
		trigger(i, j, G);
	}

	return ret;
}

int main() {
	int t;
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


	}
}