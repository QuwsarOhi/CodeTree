#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll v[109], n;

bool TRY(int x) {
    ll T = v[0]%x;
    for(int i = 1; i < n; ++i)
        if(T != v[i]%x)
            return 0;
    return 1;
}

int main() {
    ll gcd;
    scanf("%lld", &n);
    for(int i = 0; i < n; ++i) {
        //if(i) 
        //    gcd = __gcd(gcd, v[i]);
        //else
        //    gcd = v[i];
            
        scanf("%lld", &v[i]);
    }
    
    sort(v, v+n);
    ll dst = 1e10;
    
    for(int i = 0; i+1 < n; ++i)
        dst = min(dst, v[i+1] - v[i]);
    
    //cerr << "GCD " << gcd << endl;
    
    ll lim = 2+dst;
    bool first = 1;
    for(ll k = 2; k <= lim; ++k)
        if(TRY(k)) {
            if(!first) printf(" ");
            first = 0;
            printf("%lld", k);
        }
    printf("\n");
    return 0;
}
