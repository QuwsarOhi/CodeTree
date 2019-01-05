#include <bits/stdc++.h>
using namespace std;

bool recur(int a, int b, int c, bool p) {
    if(p == 1) {
        if(a > 0 and recur(a-1, b, c, not p) == p)
            return p;
        if(c > 0 and recur(a, b, c-1, not p) == p)
            return p;

        return not p;
    }
    else {
        if(b > 0 and recur(a, b-1, c, not p) == p)
            return p;
        if(c > 0 and recur(a, b, c-1, not p) == p)
            return p;

        return not p;
    }
    return not p;
}

int main() {
    int t, a, b, n, aCnt, bCnt, cCnt;
    long long x;
    scanf("%d", &t);

    while(t--) {
        scanf("%d%d%d", &n, &a, &b);
        aCnt = bCnt = cCnt = 0;

        for(int i = 0; i < n; ++i) {
            scanf("%lld", &x);
            if(x%a == 0)
                ++aCnt;
            if(x%b == 0)
                ++bCnt;
            if(x%a == 0 and x%b == 0)
                --aCnt, --bCnt, ++cCnt;
        }

        if(recur(aCnt, bCnt, cCnt, 1))
            printf("BOB\n");
        else
            printf("ALICE\n");
    }

    return 0;
}