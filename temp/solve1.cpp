#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;

string s, ans;
int dp[110][110];

int recur(int l, int r) {
    if(l > r)
        return 0;
    
    int &ret = dp[l][r];
    if(ret != -1)
        return ret;
    ret = INF;

    if(l == r)
        return ret = 2;
    
    if((s[l] == '(' and s[r] == ')') or (s[l] == '[' and s[r] == ']'))
        ret = min(ret, recur(l+1, r-1)+2);
    
    int tmp1 = recur(l+1, r)+2;
    int tmp2 = recur(l, r-1)+2;

    if(tmp1 == r-l)
        ret = min(ret, tmp1);

    cerr << l << " :: " << r << " = " << ret << endl;
    return ret;
}


void go(int l, int r, int lp, int rp) {
    cerr << l << ", " << r << " :: " << lp << ", " << rp << endl;
    if(l > r) return;
    if(l == r) {
        if(s[l] == '(' or s[l] == ')')
            ans[lp] = '(', ans[rp] = ')';
        else
            ans[lp] = '[', ans[rp] = ']';
        return;
    }

    if((s[l] == '(' and s[r] == ')') or (s[l] == '[' and s[r] == ']')) {
        if(s[l] == '(')
            ans[lp] = '(', ans[rp] = ')';
        else
            ans[lp] = '[', ans[rp] = ']';
        go(l+1, r-1, lp+1, rp-1);
    }
    else if(dp[l][r] == dp[l+1][r]+2) {
        if(s[l] == '(' or s[l] == ')')
            ans[lp] = '(', ans[lp+1] = ')';
        else
            ans[lp] = '[', ans[lp+1] = ']';
        go(l+1, r, lp+2, rp);
    }
    else {
        if(s[r] == '(' or s[r] == ')')
            ans[rp] = ')', ans[rp-1] = '(';
        else
            ans[rp] = ']', ans[rp-1] = '[';
        go(l, r-1, lp, rp-2);
    }
}

int main() {
    while(getline(cin, s)) {
        memset(dp, -1, sizeof dp);
        int sz = (int)s.size()-1;
        int ret = recur(0, sz);
        ans.resize(ret);
        go(0, sz, 0, ret-1);
        cout << ans << endl;
    }
    return 0;
}