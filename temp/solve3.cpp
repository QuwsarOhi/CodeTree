// UVa
// 160 - Factors and Factorials


#include <bits/stdc++.h>
using namespace std;

int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
vector<int>F;

void factorialFactorization(int n) {	//prime factorization of factorials (n!)
	F.clear();
    int sz = sizeof(primes)/sizeof(int);
    
	for(int i = 0; i < sz and primes[i] <= n; i++) {
		int tmp = n, power = 0;
		while(tmp/primes[i]) {
			power += tmp/primes[i];
			tmp /= primes[i];
		}
		if(power != 0)
			F.push_back(power);
	}
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int n;
    while(scanf("%d", &n) and n) {
        factorialFactorization(n);
        printf("%3d! =", n);
        
        int cnt = 0;
        for(auto it : F) {
            if(cnt == 15) {
                printf("\n      ");
                cnt = 0;
            }
            printf("%3d", it);
            ++cnt;
        }
        printf("\n");
    }
    return 0;
}
