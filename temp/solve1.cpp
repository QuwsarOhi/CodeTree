#include <bits/stdc++.h>
using namespace std;

bool recur(int a, int b, int c, bool p) {
    if(p == 0) {
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
    return p;
}

int main() {
    int t, a, b, n, aCnt, bCnt, cCnt, x;
    scanf("%d", &t);

    while(t--) {
        scanf("%d%d%d", &n, &a, &b);
        aCnt = bCnt = cCnt = 0;

        for(int i = 0; i < n; ++i) {
            scanf("%d", &x);
            if(x%a == 0)
                ++aCnt;
            if(x%b == 0)
                ++bCnt;
            if(x%a == 0 and x%b == 0)
                --aCnt, --bCnt, ++cCnt;
        }

        //aCnt %= 2, bCnt %= 2, cCnt %= 2;

        int t = min(aCnt, min(bCnt, cCnt));
        aCnt -= t, bCnt -= t, cCnt -= t;

        if(recur(aCnt, bCnt, cCnt, 1))
            printf("ALICE\n");
        else
            printf("BOB\n");
    }

    /*cout << recur(3, 3, 3, 1) << endl;
    cout << recur(3, 3, 2, 1) << endl;
    cout << recur(3, 2, 3, 1) << endl;
    cout << recur(3, 3, 3) << endl;*/
    return 0;
}