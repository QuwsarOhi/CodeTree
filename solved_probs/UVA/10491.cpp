//UVa
//10491 - Cows and Cars

#include<bits/stdc++.h>
using namespace std;

int main()
{
    double ncow, nshow, ncar;
    while(scanf("%lf %lf %lf", &ncow, &ncar, &nshow) != EOF) {
        //if player first takes cow, then switches to car
        //player can take ncow from total (ncow + ncar)
        //then player can take ncar from total-showed - door that he took, ncow+ncar-nshow-1
        double ans = (ncow/(ncow+ncar)) * (ncar/(ncow+ncar-nshow-1));
        //if player first takes car then again switches to car
        ans += (ncar/(ncow+ncar)) * ((ncar-1)/(ncow+ncar-nshow-1));
        printf("%.5lf\n", ans);
    }
    return 0;
}
