#include <iostream>
#include <string.h>
#include <stdio.h>
#define INF 0x3f3f3f3f
using namespace std;

char s[200];
int dp[104][104];

// Given a bracket sequence of () and [] which can be non-accurate
// Have to make it accurate such as the accurate sequence length is minimum
int recur(int l, int r) {
	int &ret = dp[l][r];
	if(l > r)					// No more placing required
		return ret = 0;
	if(l == r)					// We need to place an extra bracket
		return ret = 2;
	if(ret != INF)
		return ret;
	ret = min(recur(l+1, r), recur(l, r-1))+2;	// First we assume that we
	char lft = s[l];							// need to place brackets on first or on last
	if(lft == '(' or lft == '[')				// If this segment starts with opening bracket
		for(int i = l+1; i <= r; ++i)			// Then we try to slice the segment into two parts
			if((lft == '(' and s[i] == ')') or (lft == '[' and s[i] == ']'))
				ret = min(ret, recur(l+1, i-1)+recur(i+1, r)+2);	// +2 is the lenght of () or []
	return ret;
}

void go(int l, int r) {
    if(l > r) return;
	if(l == r) {
        if(s[l] == '(' or s[l] == ')')
            printf("()");
        else
            printf("[]");
        return;
	}

	char lft = s[l];
	if(lft == '(' or lft == '[')
	for(int i = l+1; i <= r; ++i)
		if(((lft == '(' and s[i] == ')') or (lft == '[' and s[i] == ']')) and (dp[l][r] == dp[l+1][i-1]+dp[i+1][r]+2)) {
			printf("%c", s[l]);
			go(l+1, i-1);
			printf("%c", s[i]);
			go(i+1, r);
			return;
		}

	if(dp[l][r] == dp[l+1][r]+2) {
		if(lft == ')' or lft == '(')
			printf("()");
		else
			printf("[]");
		go(l+1, r);
	}
	else {
		go(l, r-1);
		if(s[r] == ')' or s[r] == '(')
			printf("()");
		else
			printf("[]");
	}
}

int main() {
	scanf("%s", s);
	int len = strlen(s);
	memset(dp, INF, sizeof dp);
	int ret = recur(0, len-1);
	go(0, len-1);
	printf("\n");
	return 0;
}

/*

[][[]][()]

*/