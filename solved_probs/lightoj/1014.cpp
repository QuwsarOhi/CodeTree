//LightOJ
//1014 - Ifter Party
//Divisors

#include <bits/stdc++.h>
using namespace std;


// Returns the divisors
vector<unsigned long long>divisor;
void divisors(unsigned long long n) {
    unsigned long long lim = sqrt(n);

    //deal with 1 and n manually
    for(unsigned long long i = 2; i <= lim; i++) {
        if(n % i == 0) {
            unsigned long long tmp = n/i;
            divisor.push_back(tmp);
            if(i != tmp)
                divisor.push_back(i);
        }
    }
}


int main() {
	int t;
	scanf("%d", &t);
	unsigned long long a, b;
	for(int Case = 1; Case <= t; Case++) {
		scanf("%llu %llu", &a, &b);
		printf("Case %d:", Case);
		bool found = 0;
		if(b == 0) {
			printf(" 1");
			found = 1;
		}
        divisors(a-b);
        sort(divisor.begin(), divisor.end());
        for(int i = 0; i < (int)divisor.size(); i++)
            if(divisor[i] > b) {
                printf(" %llu",divisor[i]);
                found = 1;
            }
        if(a-b > b && a != 1) {   //a-b != a, this is only for case 1 0
            printf(" %llu", a-b);
            found = 1;
        }
        if(!found)
            printf(" impossible");
        printf("\n");
        divisor.clear();
	}
	return 0;
}
