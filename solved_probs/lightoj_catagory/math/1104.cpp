// LigthOJ
// 1104 - Birthday Paradox

#include <bits/stdc++.h>
using namespace std;

int BirthdayParadox(int days, int targetPercent = 50) {         // Returns Number of people required so that probability is >= target
    int people = 0;                                             // Formula : 1 - (365/365) * (364/365) * (363/365) * .....
    double percent = targetPercent/100.0, gotPercent = 1;
    for( ; gotPercent > percent; ++people)
        gotPercent *= (days-people-1)/(double)days;
    return people;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, d;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &d);
        printf("Case %d: %d\n", Case, BirthdayParadox(d));
    }
    return 0;
}
