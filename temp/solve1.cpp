// LightOJ
// 1205 - Palindromic Numbers
// Digit DP

#include <bits/stdc++.h>
using namespace std;

int dp[18][18][2][2][2];
vector<int>mx;

int recur(int l, int r, bool nonZero, bool lftTight, bool biggerRight) {
    if(l > r) {
        if(lftTight == 1 && biggerRight == 1)
            return 0;
        return 1;
    }

    int &ret = dp[l][r][nonZero][lftTight][biggerRight];
    if(ret != -1)
        return ret;
    ret = 0;

    int lim = lftTight ? mx[l]:9;

    for(int d = 0; d <= lim; ++d) {
        bool newNonZero = nonZero or d > 0;
        bool newLftTight = d == mx[l] ? lftTight:0;

        if(d == 0 && newNonZero == 0) {
            ret += recur(l+1, r, newNonZero, newLftTight, biggerRight);
            continue;
        }
        else if(l == r) {
            ret += recur(l+1, r-1, newNonZero, newLftTight, biggerRight);
            continue;
        }
        ret += recur(l+1, r-1, newNonZero, newLftTight, (d >= mx[r] and biggerRight) or d > mx[r]);
    }

    return ret;
}

int solve(long long x) {
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
    int t;
    long long a, b;
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lld%lld", &a, &b);
        if(a > b) swap(a, b);

        printf("Case %d: %d\n", Case, solve(b)-solve(a-1));
    }

    return 0;
}