//LightOJ
//1189 - Sum of Factorials
#include<bits/stdc++.h>
using namespace std;

long long fact[21];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    fact[0] = fact[1] = 1;
    for(long long i = 2; i < 21; i++) {
        fact[i] = fact[i-1] * i;
        //printf("%lld ", fact[i]);
    }
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        long long n;
        scanf("%lld", &n);
        vector<int>v;
        for(int i = 20; i >= 0 && n; i--)
            if(fact[i] <= n) {
                //printf("adding %d\n", i);
                n -= fact[i];
                v.push_back(i);
            }
        //printf("n : %ld\n", n);
        printf("Case %d: ", Case);
        if(n == 0) {
            if(v.size() != 1) {
                printf("%d!+", v[v.size()-1]);
                for(int i = v.size()-2; i > 0; i--)
                    printf("%d!+", v[i]);
                printf("%d!\n", v[0]);
            }
            else
                printf("%d!\n", v[0]);
        }
        else
            printf("impossible\n");
    }
    return 0;
}
