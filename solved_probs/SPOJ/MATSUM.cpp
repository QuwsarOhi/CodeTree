// SPOJ MATSUM

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll tree[1030][1030], yMax, xMax;

void update(int x, int y, int val) {
    int y1;
    while(x <= xMax) {
        y1= y;
        while(y1 <= yMax) {
            tree[x][y1] += val;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}

ll read(int x, int y) {
    ll sum = 0;
    int y1;
    while(x > 0) {
        y1 =  y;
        while(y1 > 0) {
            sum += tree[x][y1];
            y1 -= (y1 & -y1);
        }
        x -= (x & -x);
    }
    return sum;
}


ll readSingle(int x, int y) {
    return read(x, y) + read(x-1, y-1) - read(x-1, y) - read(x, y-1);
}

int main() {
    //freopen("in.txt", "r", stdin);

    int n, t, x1, x2, y1, y2, val;
    char s[20];
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &n);
        yMax = n+3;
        xMax = n+3;
        memset(tree, 0, sizeof tree);

        while(1) {
            scanf("%s", s);
            if(strcmp(s, "SET") == 0) {
                scanf("%d %d %d", &x1, &y1, &val);
                x1+=2, y1+=2;
                ll tmp = readSingle(x1, y1);
                if(tmp != 0)
                    update(x1, y1, val-tmp);
                else
                    update(x1, y1, val);
            }
            else if(strcmp(s, "SUM") == 0) {
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                x1+=2, y1+=2, x2+=2, y2+=2;
                ll ans = read(x2, y2);
                ans += read(x1-1, y1-1);
                ans -= read(x1-1, y2);
                ans -= read(x2, y1-1);
                printf("%lld\n", read(x2, y2) + read(x1-1, y1-1) - read(x1-1, y2) - read(x2, y1-1));
            }
            else
                break;
        }
        printf("\n");
    }
    return 0;
}
