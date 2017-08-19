//UVa
//11955 - Binomial Theorem

#include<bits/stdc++.h>
using namespace std;

long long p[55][54];

//Building Pascle of 50 rows
void buildPascle()
{
    p[0][0] = 1;
    p[1][0] = p[1][1] = 1;
    for(int i = 2; i <= 50; i++)
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i)
                p[i][j] = 1;
            else
                p[i][j] = p[i-1][j-1] + p[i-1][j];
        }

    /* Uncomment this if you want to see the full triangle
    for(int i = 0; i <= 50; i++) {
        for(int j = 0; j <=i; j++)
            printf("%lld ", p[i][j]);
        printf("\n");
    }
    */

    return;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    buildPascle();
    int t;
    scanf("%d", &t);
    char in[120];
    for(int Case = 1; Case <= t; Case++) {
        char a[100], b[100], n[20];
        int pw;
        //%* is used for skipping
        scanf(" %*[(] %[^+] %*[+] %[^)] %s", a, b, n);
        //%*[(] skipping (
        //%[^+] take input until +
        //%*[+] skipping +
        //%*[^)] skipping ^ and )
        pw = atoi(n+2);
        printf("Case %d: ", Case);
        if(pw == 1) {
            printf("%s+%s\n", a, b);
            continue;
        }
        for(int i = 0; i <= pw; i++) {
            //printing the first number
            if(p[pw][i] != 1)
                printf("+%lld*", p[pw][i]);

            //the first variable
            if(pw-i == 1)
                printf("%s", a);
            else if(pw-i > 0)
                printf("%s^%d", a, pw-i);

            //the second variable
            if(i == 1)
                printf("*%s", b);
            else if(i == pw)
                printf("+%s^%d\n", b, i);
            else if(i != 0)
                printf("*%s^%d", b, i);
        }
    }
    return 0;
}
