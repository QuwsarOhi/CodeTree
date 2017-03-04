#include<bits/stdc++.h>
using namespace std;

//const int lim = ;

bitset<46350>isPrime;
vector<int>prime;
bitset<1000001>segment_prime;

void sieve()
{
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    //printf("%lld\n", lim);
    prime.push_back(2);
    for(int i = 4; i < 46350; i+=2)
        isPrime[i] = 0;
    for(unsigned int i = 3; i <= 46350; i += 2)
        if(isPrime[i]) {
            prime.push_back(i);
            unsigned inc = i+i;
            for(unsigned int j = i*i; j < 46350; j+= inc)
                isPrime[j] = 0;
        }
}

void segment_sieve(long long a, long long b)
{
    int lim = sqrt(b) + 1;
    segment_prime.set();
    for(int i = 0; i < prime.size() && prime[i] < lim; i++) {
        long long j = (long long)ceil(a/(double)prime[i]);
        //printf("\nstarting from %d * %lld : %d -> ", prime[i], j , prime[i]*j);
        j = prime[i] * j;
        for(long long k = j - a; j <= b; j+= prime[i], k += prime[i]) {
            segment_prime[k] = 0;
            //printf("%lld (%lld) ", j, k);
        }
        //printf("\n");
    }
    printf("\n\nsegment prime : %d\n", segment_prime.size());
    //for(int i = 0; i < b-a+1; i++)
        //if(segment_prime[i])
            //printf("%d ", a+i);
}

int main()
{
    unsigned z;
    sieve();
    printf("sieve done\n");
    for(int i = 0; i < 100; i++)
        if(isPrime[i])
            printf("%d ", i);
    segment_sieve(1000, 2e29);
    return 0;
}
