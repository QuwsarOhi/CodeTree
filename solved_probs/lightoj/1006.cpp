//LightOJ
//1006 - Hex-a-bonacci
#include<bits/stdc++.h>
using namespace std;

long a, b, c, d, e, f;
long memo[10100];

inline long fn( long n ) {
    if( n == 0 ) return memo[n] = a;
    if( n == 1 ) return memo[n] = b;
    if( n == 2 ) return memo[n] = c;
    if( n == 3 ) return memo[n] = d;
    if( n == 4 ) return memo[n] = e;
    if( n == 5 ) return memo[n] = f;
    if(memo[n] != -1) return memo[n];

    long long ans = 0;
    for(register int i = 1; i < 7; i++) {
        if(memo[n-i] == -1)
            ans += fn(n-i);
        else
            ans += memo[n-i];
        //if(ans >= 10000007)
        ans %= 10000007;
    }
    return memo[n] = (long)ans;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    long n, caseno = 0, cases;
    scanf("%ld", &cases);
    while( cases-- ) {
        memset(memo, -1, sizeof(memo));
        scanf("%ld %ld %ld %ld %ld %ld %ld", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %ld: %ld\n", ++caseno, fn(n)%10000007);
    }
    return 0;
}
