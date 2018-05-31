// UVa
// 408 - Uniform Generator

#include <bits/stdc++.h>
using namespace std;

bitset<100010>found;

int seed(int s, int step, int m) {
    return (s+step)%m;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int s, m;
    while(scanf("%d%d", &s, &m) == 2) {
        //printf("0");
        found.reset();
        for(int x = 0; ; ) {
            x = seed(x, s, m);
           // printf(" %d", x);
            if(found[x]) {
                printf("%10d%10d    ", s, m);
                if((int)found.count() == m)
                    printf("Good Choice\n");
                else
                    printf("Bad Choice\n");
                break;
            }
            found[x] = 1;
        }
        printf("\n");
    }
    return 0;
}
