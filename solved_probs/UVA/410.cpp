//UVa
//410 - Station Balance
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int c, s, lim, speciment[20], t = 1, l, r;
    double avg, imbalance;
    while(scanf("%d %d", &c, &s) != EOF) {
        avg = 0;
        for(register int i = 0; i < s; i++) {
            scanf("%d", &speciment[i]);
            avg += speciment[i];
        }
        speciment[s] = 0;
        avg /= (double)c;
        lim = c*2;
        for(register int i = s; i <lim; i++)
            speciment[i] = 0;
        sort(speciment, speciment+lim);
        printf("Set #%d\n", t++);
        imbalance = 0;
        for(register int i = 0; i < c; i++) {
            printf("%2d:", i);
            l = speciment[i];
            r = speciment[lim-i-1];
            if(l == 0 && r == 0)
                printf("\n");
            else if(l == 0)
                printf(" %d\n", r);
            else if(r == 0)
                printf(" %d\n", l);
            else
                printf(" %d %d\n", l, r);
            imbalance += abs(r + l - avg);
        }
        printf("IMBALANCE = %.5f\n\n", imbalance);
    }
    return 0;
}
