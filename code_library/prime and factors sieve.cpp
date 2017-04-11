#include<bits/stdc++.h>
#define MAX 1e5
using namespace std;

bitset<10000000>isPrime;
vector<long long>primes;

//Only generates a number is prime or not
void sieve(long long N)
{
    isPrime.set();
    //0 and 1 are not prime
    isPrime[0] = isPrime[1] = 0;

    long long lim = sqrt(N) + 5;

    for(long long i = 2; i <= lim; i++) {
        if(isPrime[i])
            for(long long j = i*i; j <= N; j+=i)
                isPrime[j] = 0;
    }
}

//Generates a number is prime or not, and also makes an array of prime numbers

void sieveGen(long long N)
{
    isPrime.set();
    //0 and 1 are not prime
	isPrime[0] = isPrime[1] = 0;
	//Note, N isn't square rooted!
	for(long long i = 2; i <= N; i++) {
		if(isPrime[i]) {
			for(long long j = i*i; j <= N; j+=i)
                isPrime[j] = 0;
			primes.push_back(i);
		}
	}
}

//generates the prime factors of N
//outputs in an array


long long primefactor[10000];

void primeFactor(long long n)
{
	memset(primefactor, 0, sizeof(primefactor));
	long long tmp;
	for(long long i = 0; i < primes.size() && primes[i] <= n; i++)
	{
		tmp = n;
		while(tmp)      //divide 1 - n with primes 1 - n
		{
			primefactor[primes[i]] += tmp/primes[i];    //counts how many prime in the number
			tmp/=primes[i];         //cuts out the prime
		}
	}
}

vector<int> primeFactors(long long N) //returns a vector of primeFactors of n
{
	vector<int>factors;
	long long PF_idx = 0, PF = primes[PF_idx];

	while(PF*PF <= N)
	{
		while(N % PF == 0)
		{
			N /= PF;
			factors.push_back(PF);
		}
		PF = primes[++PF_idx];
	}
	if(N != 1)
		factors.push_back(N);
	return factors;
}

long long numPF(long long n) //returns number of prime factors
{
	long long num = 0;
	for(long long i = 0; primes[i] * primes[i] <= n; i++)
	{
		while(n % primes[i] == 0)
		{
			n /= primes[i];
			num++;
		}
	}
	//there might left a prime number which is bigger than primes[i]
	if(n > 1)
		num++;

	return num;
}

long long numDIFPF(long long n) // returns number of different prime factors
{
	long long diff_num = 0;
	for(long long i = 0; primes[i] * primes[i] <= n; i++)
	{
		bool ok = 0;
		while(n % primes[i] == 0)
		{
			n /= primes[i];
			ok = 1;
		}
		if(ok)
            diff_num++;
	}
	if(n > 1)
		diff_num++;

	return diff_num;
}

unsigned long long sumPF(long long n) //returns sum of prime factors
{
	unsigned long long sum = 0;
	for(long long i = 0; primes[i] * primes[i] <= n; i++)
		while(n % primes[i] == 0)
		{
			n /= primes[i];
			sum+=primes[i];
		}
	if(n > 1)
		sum+= n;
	return sum;
}


int main()
{
    return 0;
}
