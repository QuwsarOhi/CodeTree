// TOPH
// LIDS
// Double Boundary Digit DP

#include <bits/stdc++.h>
using namespace std;

vector<int> mn, mx;
int LIM, target;
long long dp[12][2][2][2][10][11];

long long recur(int pos, bool lower, bool higher, bool nonZero, int pst, int tot) {
    if(pos == LIM)
        return tot == target;

    long long &ret = dp[pos][lower][higher][nonZero][pst][tot];
    if(ret != -1)
        return ret;

    int lo = lower ? mn[pos]:0;
    int hi = higher ? mx[pos]:9;
    ret = 0;

    for(int d = lo; d <= hi; ++d) {
        bool newLower = (d == mn[pos]) ? lower:0;
        bool newHigher = (d == mx[pos]) ? higher:0;
        bool newnonZero = (d > 0) or nonZero;

        if(d > pst and newnonZero)
            ret += recur(pos+1, newLower, newHigher, newnonZero, d, tot+1);
        ret += recur(pos+1, newLower, newHigher, newnonZero, pst, tot);
    }

    return ret;
}

void genVal(int a, int b) {
    mx.clear();
    mn.clear();

    while(b) {
        mx.push_back(b%10);
        b /= 10;
    }

    LIM = mx.size();
    while(a) {
        mn.push_back(a%10);
        a /= 10;
    }
    while(mn.size() < LIM)
        mn.push_back(0);

    reverse(mn.begin(), mn.end());
    reverse(mx.begin(), mx.end());
}

int main() {
    int t, a, b;
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &a, &b);
        if(a > b) swap(a, b);

        genVal(a, b);

        for(int i = LIM; i >= 1; --i) {
            memset(dp, -1, sizeof dp);
            target = i;
            long long ans = recur(0, 1, 1, 0, -1, 0);
            if(ans > 0) {
                printf("Case %d: %d %lld\n", Case, i, ans);
                break;
            }
        }
    }

    return 0;
}