//UVa
//11173 - Grey Codes
//Pattern finding of bitwise terms
#include<bits/stdc++.h>
using namespace std;

int main()
{
    register int t, n, k;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &k);
        printf("%d\n", k ^ (k >> 1));
    }
    return 0;
}
