#include <bits/stdc++.h>
using namespace std;



int main()
{
    char S[20];

    scanf(" %s", S);

    int len = strlen(S), cnt = 0;

    for(int i = 0, j = len-1; i != j && i < j; i++, j--) {
        if(S[i] != S[j]) {
            //printf("%d %d\n", i, j);
            cnt++;
        }
    }

    if(cnt <= 1)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
