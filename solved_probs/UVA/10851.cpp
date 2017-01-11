//UVa
//10851 - 2D Hieroglyphs decoder

#include<bits/stdc++.h>
using namespace std;

int a[100];
char x[100];

int main()
{
    register int t, len;
    bool first;
    scanf("%d", &t);
    while(t--) {
        first = 0;
        memset(a, 0, sizeof(a));
         for(register int n = 0; ; n++) {
            scanf(" %s", x);
            if(!first) { len = strlen(x); first = 1; continue;}
            if(n == 9) break;
            for(int i = 0; i < len; i++)
                if(x[i] == '\\')
                    a[i] += 1<<(n-1);
        }
        for(register int i = 1; i < len-1; i++)
            printf("%c", a[i]);
        printf("\n");
    }
    return 0;
}
