// LightOJ
// 1140 - How Many Zeroes?

#include <stdio.h>
#include <string>
using namespace std;
typedef long long ll;

long long CountZerosInRangeZeroTo(string n) {
    ll x = 0, fx = 0, gx = 0;
    for(int i = 0; i < (int)n.size(); ++i){
        ll y = n[i] - '0';
        fx = 10LL * fx + x - gx * (9LL - y);        // Our formula
        //fx += MOD;                                // If ans is to be returned in moded value
        //fx %= MOD;
        x = 10LL * x + y;                           // Now calculate the new x and g(x)
        //x %= MOD;
        if(y == 0LL) gx++;
    }
    return fx+1;
}


string TOSTRING(long long n) {
    string ret;
    if(n == 0) return string("0");
    while(n) {
        ret.push_back(n%10 + '0');
        n /= 10;
    }
    
    for(int l = 0, r = (int)ret.size()-1; l < r; ++l, --r) {
        ret[l] = ret[l] ^ ret[r];
        ret[r] = ret[l] ^ ret[r];
        ret[l] = ret[l] ^ ret[r];
    }
    
    return ret;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t;
    scanf("%d", &t);
    long long a, b;
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lld%lld", &a, &b);
        long long ans = CountZerosInRangeZeroTo(TOSTRING(b));
        if(a != 0)
            ans -= CountZerosInRangeZeroTo(TOSTRING(a-1));
        
        printf("Case %d: %lld\n", Case, ans);
    }
    return 0;
}

