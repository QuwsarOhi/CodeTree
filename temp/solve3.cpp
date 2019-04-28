#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

string s, ans;
int dp[102][102];

int recur(int l, int r) {
	if(l > r)
		return 0;
	int &ret = dp[l][r];
	if(l == r)
		return 2;
	if(ret != -1) {
		cerr << "HIT\n";
		return ret;
	}
	ret = INF;
	char lft = s[l];
	if(lft == '(' or lft == '[')
	for(int i = l+1; i <= r; ++i)
		if((lft == '(' and s[i] == ')') or (lft == '[' and s[i] == ']'))
			ret = min(ret, recur(l+1, i-1)+recur(i+1, r)+2);
	ret = min(ret, recur(l+1, r)+2);
	return ret;
}

void go(int l, int r, int lp) {
    cerr << l << ", " << r << " :: " << lp << endl;
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
			if(lft == '(') 	ans[lp] = '(', ans[rp] = ')';
			else			ans[lp] = '[', ans[rp] = ']';
			ans[lp] = '(', ans[rp] = ')';
			go(l+1, i-1, lp+1);
			go(i+1, r, rp+1);
			return;
		}

	if(lft == ')' or lft == '(')
		ans[lp] = '(', ans[lp+1] = ')';
	else
		ans[lp] = '[', ans[lp+1] = ']';
	cerr << "GO pass" << endl;
	go(l+1, r, lp+2);
}

int main() {
	while(getline(cin, s)) {
		int len = s.size();
		memset(dp, -1, sizeof dp);
		int ret = recur(0, len-1);
		ans.resize(ret);
		cout << ret << endl;
		go(0, len-1, 0);
		cout << ans << endl;
	}
	return 0;
}