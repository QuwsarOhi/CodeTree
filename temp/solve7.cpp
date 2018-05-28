#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;


int Len(ull n) {
    return floor(log10(n))+1;
}

/*ll Increase(ull v, int len, int j) {
    int t = 9-len;
    ull r = 0, tmp = v;
    
    for(int i = 0; i < t; ++i) {
        r *= 10;
        r += v%10;
        v /= 10;
    }
    
    for(int i = len; i+len <= 9; i += len) {
        v *= p[Len(v)]
*/

int main() {
    int j, c;
    long long t;
    double d;
    ull p[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 1000000000, 10000000000};
    
    while(scanf("%d", &j) and j != -1) {
        scanf("%d.%lld", &c, &t);
        int len = Len(t);
        d = t;
        d /= p[len];
        
        cout << t << " " << len << " : " << d << endl;
        
        long long a = round(p[len]*d - p[len-j]*d);
        long long b = p[len] - p[len-j];
        //cout << p[len]*d - p[len-j]*d << endl;
        t = __gcd(a, b);
        a /= t;
        b /= t;
        printf("%lld/%lld\n", a, b);
    }
    return 0;
}
