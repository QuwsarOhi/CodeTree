// LightOJ
// 1158 - Anagram Division

#include <bits/stdc++.h>
using namespace std;

int dp[1003][(1<<10)+2], vis[1003][(1<<10)+2], visCnt, len, d;
char v[20];

int recur(int modVal, int mask) {
    if(mask == (1 << len)-1)
        return modVal == 0;

    int &ret = dp[modVal][mask], vv;
    if(vis[modVal][mask] == visCnt)
        return ret;

    vis[modVal][mask] = visCnt;
    ret = 0;
    bool placed[10] = {0};


    for(int i = 0; i < len; ++i) {
        vv = v[i] - '0';
        if(mask & (1 << i) or placed[vv]) continue;
        placed[vv] = 1;
        ret += recur((modVal*10 + vv)%d, mask | (1 << i));
    }

    return ret;
}

int main() {
    int t;
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%s %d", v, &d);
        len = strlen(v);

        ++visCnt;
        printf("Case %d: %d\n", Case, recur(0, 0));
    }

    return 0;
}