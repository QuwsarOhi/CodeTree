#include <bits/stdc++.h>
#define MAX 200011
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;
typedef long long int ll;

struct BIT {
    int tree[MAX];
    int MaxVal;
    void init(int sz) {
        for(int i = 0; i <= sz+3; ++i)
            tree[i] = 0;
        MaxVal = sz+1;
    }
    void update(int idx, int val) {
        for( ; idx <= MaxVal; idx += (idx & -idx))
            tree[idx] += val;
    }
    int read(int idx) {
        int ret = 0;
        for( ; idx > 0; idx -= (idx & -idx))
            ret += tree[idx];
        return ret;
    }
};

BIT d;
int v[2][MAX], idx[2][MAX];

int check(int x, int y, int n) {
    int ret = 0;
    d.init(n);

    int cst = 0;
    for(int i = 1; i <= n; ++i) {
        int val = v[x][i];

        int p = d.read(idx[y][val]) + idx[y][val];
        int q = i+cst;

        if(p != q) {
            --cst, ++ret;
            d.update(idx[y][val], -1);
        }
    }

    return ret;
}

int main() {
    int t, n;
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &n);

        for(int i = 0; i < 2; ++i) {
            for(int j = 1; j <= n; ++j) {
                scanf("%d", &v[i][j]);
                idx[i][v[i][j]] = j;
            }
        }

        printf("Case %d: %d\n", Case, min(check(0, 1, n), check(1, 0, n))*2);
    }

    return 0;
}


/*

1
4
2 3 4 1
1 2 3 4


2
5
1 3 5 4 2
1 5 4 3 2
4
1 2 4 3
3 4 2 1

1
4
3 1 4 2
2 1 3 4

1
5
5 4 3 2 1
3 2 5 1 4

*/