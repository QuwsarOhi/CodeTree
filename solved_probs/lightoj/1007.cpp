//LightOJ
//1007 - Mathematically Hard 

#include <bits/stdc++.h>
#define MAX 5000005
using namespace std;
 
unsigned long long phi[MAX];

// Computes phi or Euler Phi 1 to n
void computeTotient(int n) {
    for (int i=1; i<=n; i++)	// Initialize
        phi[i] = i;
 
    for (int p=2; p<=n; p++) {	// Computation
        if (phi[p] == p) {		//if phi is not computed
            phi[p] = p-1;		//p is prime and phi(prime) = prime-1;
 
            for (int i = 2*p; i<=n; i += p) {	// Sieve like implementation
    // Add contribution of p to its multiple i by multiplying with (1 - 1/p)
               phi[i] = (phi[i]/p) * (p-1);
            }
        }
        phi[p] *= phi[p];		//score
        phi[p] += phi[p-1];		//cumulative sum
    }
}
 
int main()
{
    computeTotient(MAX-2);
	int t, a, b;
	scanf("%d", &t);
	for(int Case = 1; Case <= t; Case++) {
		scanf("%d %d", &a, &b);
		printf("Case %d: %llu\n", Case, phi[b]-phi[a-1]);
	}
    return 0;
}
