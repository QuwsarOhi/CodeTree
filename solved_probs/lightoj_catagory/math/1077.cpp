// LightOJ
// 1077 - How Many Points?

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* Equation: y = x *(y1-y2)/(x1-x2) + x1*(y1-y2)*(x1-x2)
 * So, find the number of values in range [y1, y2] which can be divided by (x1-x2)
 */

ll Compute(ll x1, ll y1, ll x2, ll y2) {
    ll b = abs(x1-x2);
    ll a = abs(y1-y2);
    ll gcd = __gcd(a, b);
    return 1 + gcd;
}
    
int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t;
    ll x1, x2, y1, y2, cnt;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
        cnt = 0;
        
        if(x1 == x2)
            cnt = abs(y1-y2)+1;
        else if(y1 == y2)
            cnt = abs(x1-x2)+1;
        else if(abs(x1-x2) == abs(y1-y2)) {
            //cerr << "DIAGONAL " << endl;
            cnt = abs(x1-x2)+1;
        }
        else {
            //cerr << "Exceptional \n";
            cnt = Compute(x1, y1, x2, y2);
        }
        
        printf("Case %d: %lld\n", Case, cnt);
    }
    return 0;
}
