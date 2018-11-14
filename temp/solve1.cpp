#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> mn, mx, tt;
int LIM;

int getMirrorIndex(int nonZero, int pos, int lim) {
    int len = lim - nonZero;
    if(len&1 and (len+1)/2 >= pos-nonZero+1)
        return -1;
    if(not (len&1) and len/2 >= pos-nonZero+1)
        return -1;
    return nonZero+(lim-pos-1);
}

ll dp[19][2][2][2][10];

ll recur(int pos, bool lower, bool higher, int nonZero, int pstPlaced) {
    if(pos == LIM) {
        /*for(auto it : tt)
            cout << it;
        cout << " " << nonZero << endl;*/
        return 1;
    }

    ll &ret = dp[pos][lower][higher][nonZero][pstPlaced];
    /*if(ret != -1) {
        cerr << "HIT\n";
        return ret;
    }*/

    ret = 0;
    //ll ret = 0;
    int lo = lower ? mn[pos]:0;
    int hi = higher ? mx[pos]:9;
    int mirrorPos = getMirrorIndex(nonZero, pos, LIM);

    if(mirrorPos != -1 and nonZero != -1) {
        int d = tt[mirrorPos];
        if(not(lo <= d and d <= hi))
            return 0;

        bool newLower = (d == mn[pos]) ? lower:0;
        bool newHigher = (d == mx[pos]) ? higher:0;

        if(dp[pos][newLower][newHigher][nonZero][d] != -1)
            return dp[pos][newLower][newHigher][nonZero][d];

        tt.push_back(d);
        ret = recur(pos+1, newLower, newHigher, nonZero, d);
        tt.pop_back();
        return ret;
    }

    for(int d = lo; d <= hi; ++d) {
        bool newLower = (d == mn[pos]) ? lower:0;
        bool newHigher = (d == mx[pos]) ? higher:0;
        int newNonZero = nonZero >= 0 ? nonZero: (d > 0 ? pos:-1);

        tt.push_back(d);
        ret += recur(pos+1, newLower, newHigher, newNonZero, -1);
        tt.pop_back();
    }
    return ret;
}


void genVal(ll a, ll b) {
    mn.clear(), mx.clear();

    while(b) {
        mx.push_back(b%10);
        b/=10;
    }
    while(a) {
        mn.push_back(a%10);
        a/=10;
    }

    LIM = mx.size();
    while(mn.size() < LIM)
        mn.push_back(0);

    reverse(mn.begin(), mn.end());
    reverse(mx.begin(), mx.end());
}


int main() {
    int t;
    ll a, b;
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lld%lld", &a, &b);

        if(a > b) swap(a, b);
        genVal(a, b);

        memset(dp, -1, sizeof dp);
        printf("Case %d: %lld\n", Case, recur(0, 1, 1, -1, -1));
    }

    return 0;
}


/*

5
1 10
100 1
1 1000
1 10000
1 100000000000000000

*/