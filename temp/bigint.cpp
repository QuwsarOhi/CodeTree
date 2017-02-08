#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int c, s, lim, speciment[20], t = 1;
    float avg, imbalance;
    map<int, int>position;
    while(scanf("%d %d", &c, &s) != EOF) {
        avg = 0;
        for(register int i = 0; i < s; i++) {
            scanf("%d", &speciment[i]);
            position[speciment[i]] = i;
            avg += speciment[i];
        }
        avg /= s;
        lim = c*2;
        for(register int i = s; i <lim; i++)
            speciment[i] = 0;
        sort(speciment, speciment+lim);
        printf("Set #%d\n", t++);
        imbalance = 0;
        for(register int i = 0; i < c; i++) {
            printf("%2d: ", i);
            lim--;
            if(speciment[i] != 0)
                printf("%d %d\n", speciment[i], speciment[lim]);
            else
                printf("%d\n", speciment[lim]);
            imbalance += abs(speciment[i] + speciment[lim] - avg);
        }
        printf("IMBALANCE = %.5f\n", imbalance);
    }
    return 0;
}
