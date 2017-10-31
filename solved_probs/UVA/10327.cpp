// UVa
// 10327 - Flip Sort

#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n, v[1500];
    while(scanf("%d", &n) == 1) {
        for(int i = 0; i < n; ++i)
            scanf("%d", &v[i]);
        int cnt = 0;
        for(int i = 0; i < n; ++i)
            for(int j = n-1; j > 0; --j)
                if(v[j-1] > v[j]) {
                    cnt++;
                    swap(v[j-1], v[j]);
                }
        printf("Minimum exchange operations : %d\n", cnt);
    }
    return 0;
}

