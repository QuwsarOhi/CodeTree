// UVa
// 526 - String Distance and Transform Process

#include <bits/stdc++.h>
#define INF 1e7
using namespace std;

char s1[100], s2[100];
int len1, len2, dp[110][110];

int recur(int p1, int p2) {
    if(p1 == len1 && p2 == len2)
        return 0;
    if(p1 == len1 && p2 < len2)
        return len2-p2;
    if(p2 == len2 && p1 < len1)
        return len1-p1;
    
    if(dp[p1][p2] != INF)
        return dp[p1][p2];
    
    int ans = INF;
    
    if(s1[p1] == s2[p2])
        ans = min(recur(p1+1, p2+1), ans);
	
	ans = min(recur(p1+1, p2+1)+1, ans);
	ans = min(recur(p1+1, p2)+1, ans);
	ans = min(recur(p1, p2+1)+1, ans);

    return dp[p1][p2] = ans;
}

void printer(int opIdx, int x, int y, int strPos) {
	if(x == len1-1 && y == len2-1) {
		if(dp[x][y] == 1) {
			if(len1 == len2)
				printf("%d Replace %d,%c\n", opIdx, strPos, s2[y]);
			else if(len1 > len2)
				printf("%d Delete %d\n", opIdx, strPos);
			else
				printf("%d Insert %d,%c\n", opIdx, strPos, s2[y]);
		}
	}
    else if(dp[x+1][y+1] > dp[x][y+1] || x == len1-1) {
        if(dp[x][y] != dp[x][y+1])
			printf("%d Insert %d,%c\n", opIdx++, strPos, s2[y]);
        printer(opIdx, x, y+1, strPos+1);
    }
    else if(dp[x+1][y+1] > dp[x+1][y] || y == len2-1) {
        if(dp[x][y] != dp[x+1][y])
			printf("%d Delete %d\n", opIdx++, strPos--);
        printer(opIdx, x+1, y, strPos+1);
    }
    else {
		if(s1[x] != s2[y])
			printf("%d Replace %d,%c\n", opIdx++, strPos, s2[y]);
		printer(opIdx, x+1, y+1, strPos+1);
	}
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	bool first = 1;
    while(fgets(s1, 90, stdin)) {
		fgets(s2, 90, stdin);
		if(!first)
			printf("\n");
		first = 0;
		
        len1 = strlen(s1);
        len2 = strlen(s2);
        for(int i = 0; i < 100; ++i)
			for(int j = 0; j < 100; ++j)
				dp[i][j] = INF;
        printf("%d\n", recur(0, 0));
        printer(1, 0, 0, 1);
    }
    return 0;
}