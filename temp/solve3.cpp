#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

char s[200], ans[400];
int dp[104][104];

int recur(int l, int r) {
	int &ret = dp[l][r];
	if(l > r)
		return ret = 0;
	if(l == r)
		return ret = 2;
	if(ret != -1) {
		//cerr << "HIT\n";
		return ret;
	}
	ret = INF;
	char lft = s[l];
	if(lft == '(' or lft == '[')
	for(int i = l+1; i <= r; ++i)
		if((lft == '(' and s[i] == ')') or (lft == '[' and s[i] == ']'))
			ret = min(ret, recur(l+1, i-1)+recur(i+1, r)+2);
	ret = min(ret, min(recur(l+1, r), recur(l, r-1))+2);
	return ret;
}

void go(int l, int r, int lp) {
    //cerr << l << ", " << r << " :: " << lp << endl;
    if(l > r) return;
	if(l == r) {
        if(s[l] == '(' or s[l] == ')')
            ans[lp] = '(', ans[lp+1] = ')';
        else
            ans[lp] = '[', ans[lp+1] = ']';
        return;
	}

	char lft = s[l];
	if(lft == '(' or lft == '[')
	for(int i = l+1; i <= r; ++i)
		if(((lft == '(' and s[i] == ')') or (lft == '[' and s[i] == ']')) and (dp[l][r] = dp[l+1][i-1]+dp[i+1][r]+2)) {
			int rp = lp + dp[l+1][i-1]+1;
			//cerr << "PLACING " << lp << ", " << rp << endl;
			if(lft == '(') 	ans[lp] = '(', ans[rp] = ')';
			else			ans[lp] = '[', ans[rp] = ']';
			go(l+1, i-1, lp+1);
			go(i+1, r, rp+1);
			return;
		}

	if(dp[l][r] == dp[l+1][r]+2) {
		if(lft == ')' or lft == '(')
			ans[lp] = '(', ans[lp+1] = ')';
		else
			ans[lp] = '[', ans[lp+1] = ']';
		go(l+1, r, lp+2);
	}
	else {
		int rp = lp + dp[l][r-1] + 1;
		if(s[r] == ')' or s[r] == '(')
			ans[rp] = '(', ans[rp+1] = ')';
		else
			ans[rp] = '[', ans[rp+1] = ']';
		go(l, r-1, lp);
	}
}

int main() {
	scanf("%s", s);
	int len = strlen(s);
	memset(dp, -1, sizeof dp);
	int ret = recur(0, len-1);
	//cout << ret << endl;
	go(0, len-1, 0);
	ans[ret] = '\0';
	printf("%s\n", ans);
	return 0;
}