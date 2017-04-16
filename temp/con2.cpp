#include <bits/stdc++.h>
using namespace std;


bitset<10000010>isPrime;
vector<long long>primes;

//Generates a number is prime or not, and also makes an array of prime numbers

void sieveGen(unsigned long long N)
{
    isPrime.set();
    //0 and 1 are not prime
	isPrime[0] = isPrime[1] = 0;
	//Note, N isn't square rooted!
	for(unsigned long long i = 2; i <= N; i++) {
		if(isPrime[i]) {
            unsigned long long skip = 2*i;
			for(unsigned long long j = i*i; j <= N; j+= skip)
                isPrime[j] = 0;
			primes.push_back(i);
		}
	}
}

vector<int> primeFactor(unsigned long long n)    //returns vector of co-efficient of prime factor
{
    /*if(isPrime[n]) {
        vector<int>factor(n+1, 0);
        factor[n] = factor[1] = 1;
        return factor;
    }*/
    printf("started\n");
    vector<int>factor(n+1, 0);

	for(unsigned long long i = 0; i < primes.size() && primes[i] <= n; i++) {
		while(n%primes[i] == 0) {       //divide 1 - n with primes 1 - n
			factor[primes[i]]++;        //counts how many prime in the number
			n/=primes[i];               //cuts out the prime
		}
	}
	if(n > 1)
        factor[n]++;
    for(int i = 0; i < factor.size(); i++)
        if(factor[i])
            printf("%d^%d ", i, factor[i]);
    printf("\n");
	return factor;
}

/*unsigned long long numberOfDivisors(unsigned long long n)
{
    printf("input taken\n");
    if(isPrime[n])          //if the number is prime, there is two divisors: 1, n
        return 2;

    vector<int>primefactor = primeFactor(n);            //first factorize the number
    unsigned long long numDiv = 1;                               //the number itself is a divisor
    printf("done\n");
    for(unsigned long long i = 0; i < primefactor.size(); i++) {
        if(primefactor[i] != 0)
            numDiv *= (primefactor[i] + 1);
    }
    return numDiv;
} */


unsigned long long cal(unsigned long long n)
{
    vector<int>factor = primeFactor(n);
    printf("factor done\n");
    unsigned long long mul = 1;
    priority_queue<pair<unsigned long long, unsigned long long> >pq;
    for(unsigned long long i = 0; i < factor.size(); i++) {
        if(factor[i] != 0) {
            pq.push({factor[i]+1, factor[i]+1});
            printf("pb %d %d\n", factor[i]+1, factor[i]+1);
            mul *= (factor[i]+1);
        }
    }
    printf("mul %llu\n", mul);
    unsigned long long ans = mul-1;
    while(!pq.empty()) {
        unsigned long long div = pq.top().second;
        unsigned long long sub = pq.top().first-1;
        pq.pop();
        printf("%llu %llu\n", sub, div);
        if(sub < 1)
            continue;
        if(pq.size() == 1 && sub == 1)
            continue;
        ans += (mul/div) * sub;
        printf("adding %llu\n", (mul/div) * sub);
        pq.push({sub, div});
    }
    printf("ans : %llu\n", ans);
    return ans;
}

int main()
{
    freopen("in", "r", stdin);

    sieveGen(1000000);
    unsigned long long a, b, ans;
    scanf("%llu %llu", &a, &b);
    if(a == b) {
        ans = cal(a);
        printf("%llu\n", ans+ans);
    }
    else {
        unsigned long long ans = cal(a);
        ans += cal(b);
        printf("%llu\n", ans);
    }
    return 0;
}
