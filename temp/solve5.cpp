#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll v[101000], GCD = 0, ANS = 0, n;

int main() {
    
    scanf("%lld", &n);
    for(int i = 0; i < n; ++i)
        scanf("%lld", &v[i]);
    
    sort(v, v+n);
    
    for(int i = 0; i < n; ++i) {
        if(i) {
            ll dist = abs(v[i] - v[i-1]);
            //cout <<  "DIST " << dist << endl;
            if(GCD == 0)
                GCD = dist;
            else
                GCD = __gcd(dist, GCD);
            //cout << "GCD " << GCD << endl;
        }
    }
    
    for(int i = 1; i < n; ++i) {
        ll dist = abs(v[i-1] - v[i]);
        if(dist == GCD)
            continue;
        else
            dist = abs(v[i-1] - (v[i]-1));
        //cout << "CAL DIST " << dist << " " << v[i]-1 << " " << v[i-1] << endl;
        //dist -= 2;
        ANS += (dist / GCD);
    }
    
    printf("%lld", ANS);
    
    return 0;
}
