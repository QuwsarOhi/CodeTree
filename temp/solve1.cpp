#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, Min = 1e10, gcd, x;
    
    scanf("%lld", &n);
    
    for(int i = 0; i < n; ++i) {
        scanf("%lld", &x);
        if(i) gcd = __gcd(x, gcd);
        else  gcd = x;
        Min = min(x, Min);
    }
    
    printf("%lld", gcd);
    gcd += gcd;
    
    while(gcd < Min) {
        printf(" ");
        printf("%lld", gcd);
        gcd += gcd;
    }
    
    printf("\n");
    return 0;
}
        
