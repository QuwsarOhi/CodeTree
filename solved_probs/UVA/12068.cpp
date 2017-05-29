//UVa
//12068 - Harmonic Mean

#include<bits/stdc++.h>
using namespace std;

struct fraction {
    unsigned long long a, b;
    fraction() {
        a = 1;
        b = 1;
    }
    fraction(int x, int y) : a(x), b(y) {}
    void flip() {swap(a, b);}
    fraction operator + (fraction other) {
        fraction temp;
        temp.b = ((b)*(other.b))/(__gcd(b, other.b));
        temp.a = (temp.b/b)*a + (temp.b/other.b)*other.a;
        unsigned long long x = __gcd(temp.a, temp.b);
        if(x != 1) {temp.a/=x; temp.b/=x;}
        return temp;
    }
    fraction operator - (fraction other) {
        fraction temp;
        temp.b = (b*other.b)/__gcd(b, other.b);
        temp.a = (temp.b/b)*a - (temp.b/other.b)*other.a;
        unsigned long long x = __gcd(temp.a, temp.b);
        if(x != 1) {temp.a/=x; temp.b/=x;}
        return temp;
    }
    fraction operator / (fraction other) {
        fraction temp;
        temp.a = a*other.b;
        temp.b = b*other.a;
        unsigned long long x = __gcd(temp.a, temp.b);
        if(x != 1) {temp.a/=x; temp.b/=x;}
        return temp;
    }
    fraction operator * (fraction other) {
        fraction temp;
        temp.a = a*other.a;
        temp.b = b*other.b;
        unsigned long long x = __gcd(temp.a, temp.b);
        if(x != 1) {temp.a/=x; temp.b/=x;}
        return temp;
    }
};

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n;
    scanf("%d", &n);
    for(int Case = 1; Case <= n; Case++) {
        int f, b;
        fraction sum;
        scanf("%d", &f);
        for(int i = 0; i < f; i++) {
            scanf("%d", &b);
            if(i == 0) {
                sum.b = b;
                continue;
            }
            fraction a(1, b);
            sum = sum + a;
        }
        sum.flip();
        fraction a(f, 1);
        sum = sum * a;
        printf("Case %d: %llu/%llu\n", Case, sum.a, sum.b);
    }
    return 0;
}
