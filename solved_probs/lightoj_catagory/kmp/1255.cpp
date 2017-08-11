// LightOJ
// 1255 - Substring Frequency
// Basic String Matching (KMP - Second Pattern Matching)


#include <bits/stdc++.h>
using namespace std;

int p[1000010], S_len, T_len;
char T[1000010], S[1000010]; 


void prefixTable() {
	p[0] = -1;
	int i = 0, j = -1;
	while(i < T_len) {
		while(j >= 0 && T[i] != T[j])
			j = p[j];
		++j, ++i;
		p[i] = j;
	}
}

int kmpSearch() {
	int i = 0, j = 0, match = 0;
	while(i < S_len) {
		while(j >= 0 && S[i] != T[j])
			j = p[j];
		++i, ++j;
		if(j == T_len) {
			++match;
			j = p[j];
		}
	}
	return match;
}


int main() {
	
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf(" %s %s", S, T);
		S_len = strlen(S);
		T_len = strlen(T);
		
		prefixTable();
		
		/*printf("T_len : %d\n", T_len);
		for(int i = 0; i < T_len; ++i) {
			printf("%c : %d\n", T[i], p[i]);
		}*/
		
		printf("Case %d: %d\n", Case, kmpSearch());
		
	}
	
	return 0;
}
