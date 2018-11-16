#include <bits/stdc++.h>
using namespace std;

int tt[20], dp[18][18][2][2][2];
vector<int>mx;

int recur(int l, int r, bool nonZero, bool lftTight, bool rhtTight) {
    if(l > r) {
        // fuck this shit
        for(int i = 0; i < mx.size(); ++i)
            printf("%d", tt[i]);
        //printf("\n");

        if(lftTight == 1 && rightGreater == 1) {
            printf(" NO\n");
            return 0;
        }

        printf(" YES %d %d\n", lftTight, rightGreater);
        return 1;
    }

    //int &ret = dp[l][r][nonZero][lftTight][rightGreater];
    //if(ret != -1) {
    //    cerr << "HIT mother fucker" << endl;
    //    return ret;
    //}

    int ret = 0;
    int lftlim = lftTight ? mx[l]:9;
    int rhtlim = rhtTight ? mx[r]:9;

    //cerr << "Range :: " << l << " " << r << " :: " << lim << endl;
    for(int d = 0; d <= lftlim; ++d) {
        bool newTight = d == lftlim ? lftTight:0;
        bool rhtTight = d == rhtlim ? rhtTight:0;
        
        if(l == r)
            newRightGreater = rightGreater;

        if(nonZero == 0 && d == 0) {
            tt[l] = 0;
            //cerr << "Place " << "0" << " range " << l << " " << r << endl;
            ret += recur(l+1, r, nonZero, newTight, newRightGreater);
            continue;
        }

        //cerr << "Place " << d << " range " << l << " " << r <<endl;
        tt[l] = tt[r] = d;
        ret += recur(l+1, r-1, 1, newTight, newRightGreater);
    }

    return ret;
}


int solve(long long x) {
    if(x < 0) return 0;
    if(x == 0) return 1;

    cerr << "VAL " << x << endl;

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

        printf("%d %d\n", solve(a-1), solve(b));
    }

    return 0;
}