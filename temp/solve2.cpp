// LightOJ
// 1090 - Trailing Zeroes (II)

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int>pii;

int FactorialCount(int n, int p = 5) {      // Returns how many value of p is present in n!
    int ret = 0, r = p;                     // returns number of trailing zero of n! if p = 5
    while(n/r != 0) {
        ret += n/r;
        r *= p;
    }
    return ret;
}


pii C(int n, int k) {
    pii cnt(0, 0);          // count_2_as_prime_factor, count_5_as_prime_factor
    cnt.first += FactorialCount(n, 2);
    cnt.second += FactorialCount(n, 5);
    cnt.first -= FactorialCount(k, 2) + FactorialCount(n-k, 2);
    cnt.second -= FactorialCount(k, 5) + FactorialCount(n-k, 5);
    return cnt;
}

pii P(int n, int p) {
    pii cnt(0, 0);
    while(n%2 == 0) n/=2, ++cnt.first;
    while(n%5 == 0) n/=5, ++cnt.second;
    cnt.first *= p, cnt.second *= p;
    return cnt;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, n, r, p, q;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d%d%d", &n, &r, &p, &q);
        pii a = C(n, r);
        pii b = P(p, q);
        a.first += b.first, a.second += b.second;
        printf("Case %d: %d\n", Case, min(a.first, a.second));
    }
    return 0;
}
