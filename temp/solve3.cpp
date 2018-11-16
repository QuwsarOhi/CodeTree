#include <bits/stdc++.h>
using namespace std;

int tt[20];
vector<int>mx;
long long dp[18][18][2][2][2];

long long recur(int l, int r, bool nonZero, bool lftTight, bool rightGreater) {
    if(l > r) {
        if(lftTight == 1 && rightGreater == 1)
            return 0;
        return 1;
    }

    long long &ret = dp[l][r][nonZero][lftTight][rightGreater];
    if(ret != -1)
        return ret;

    ret = 0;
    int lim = lftTight ? mx[l]:9;

    for(int d = 0; d <= lim; ++d) {
        bool newTight = d == lim ? lftTight:0;
        bool newRightGreater = mx[r] < d ? 1 : 0;
        if(l == r)
            newRightGreater = rightGreater;

        if(nonZero == 0 && d == 0) {
        	tt[l] = d;
            ret += recur(l+1, r, nonZero, newTight, newRightGreater);
            continue;
        }

        tt[l] = tt[r] = d;
        ret += recur(l+1, r-1, 1, newTight, newRightGreater);
    }

    return ret;
}


long long solve(long long x) {
    if(x < 0) return 0;
    if(x == 0) return 1;

    mx.clear();
    while(x) {
        mx.push_back(x%10);
        x/=10;
    }

    reverse(mx.begin(), mx.end());
    memset(dp, -1, sizeof dp);
    return recur(0, (int)mx.size()-1, 0, 1, 0);
}

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

    int t;
    long long a, b;
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lld%lld", &a, &b);
        if(a > b) swap(a, b);
        printf("Case %d: %lld\n", Case, solve(b)-solve(a-1));
    }

    return 0;
}