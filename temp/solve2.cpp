// LightOJ
// DNA Sequence
// Unsolved

#include <bits/stdc++.h>
using namespace std;

char s[20][110];
int dp[110][110], len[20];
vector<char>lcs;

int LCS(int p1, int p2, int i, int j) {
	if(p1 >= len[i] || p2 >= len[j])
		return 0;
	
	if(dp[p1][p2] != -1)
		return dp[p1][p2];
	
	int ans = 0;
	if(s[i][p1] == s[j][p2])
		ans = LCS(p1+1, p2+1, i, j) + 1;
	else
		ans = max(LCS(p1, p2+1, i, j), LCS(p1+1, p2, i, j));
	
	return dp[p1][p2] = ans;
}

/*
void LCSprint(int p1, int p2, int i, int j) {
	cout << p1 << " " << p2 << endl;
	
	if(p1 < 0 && p2 < 0)
		return;
	if(dp[p1-1][p2-1] > max(dp[p1-1][p2], dp[p1][p2-1])) {
		//lcs[l] = s[i][p1];
		lcs.push_back(s[i][p1]);
		LCSprint(p1-1, p1-1, i, j);
	}
	else if(p1 != 0 && dp[p1-1][p2] > dp[p1][p2-1]) {
		//lcs[l] = s[i][p1];
		lcs.push_back(s[i][p1]);
		LCSprint(p1-1, p2, i, j);
	}
	else if(p2 != 0 && dp[p1][p2-1] > dp[p1-1][p2]) {
		//lcs[l] = s[j][p2];
		lcs.push_back(s[j][p2]);
		LCSprint(p1, p2-1, i, j);
	}
	else {
		cout << "here " << p1 << " " << p2 << endl;
		lcs.push_back(s[i][p1]);
		lcs.push_back(s[i][p1-1]);
		lcs.push_back(s[i][])
		if(p1 != 0 && s[i][p1] > s[j][p2]) {
			//lcs[l] = s[i][p1];
			lcs.push_back(s[i][p1]);
			LCSprint(p1-1, p2, i, j);
		}
		else if(p1 == 0 && p2 == 0)
			return;
		else {
			//lcs[l] = s[j][p2];
			lcs.push_back(s[j][p2]);
			LCSprint(p1, p2-1, i, j);
		}
		LCSprint(p1-1, p2-1, i, j);
	}
	return;
}*/

void LCSprint(int len1, int len2, char s1[], char s2[]) {
	int i = len1, j = len2;
	
	while(i > 0 && j > 0) {
		if(s1[i] == s2[j]) {
			lcs.push_back(s1[i]);
			--i, --j;
		}
		else if(dp[i-1][j] > dp[i][j-1])
			i--;
		else
			j--;
	}
}

int main() {
	int t, n;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &n);
		
		for(int i = 0; i < n; ++i) {
			scanf(" %s", s[i]);
			len[i] = strlen(s[i]);
		}
		
		memset(dp, -1, sizeof dp);
		
		LCS(0, 0, 0, 1);
		
		for(int i = 0; i < len[0]; ++i) {
			for(int j = 0; j < len[1]; ++j)
				printf(" %d", dp[i][j]);
			printf("\n");
		}
		
		LCSprint(len[0]-1, len[1]-1, s[0], s[1]);
		
		for(auto it : lcs)
			cout << it;
		cout << endl;
		lcs.clear();
	}
	return 0;
}
