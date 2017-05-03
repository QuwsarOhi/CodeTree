//LightOJ
//1245 - Harmonic Number (II)
//http://www.lightoj.com/volume_showproblem.php?problem=1245

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main()
{
	int t;
	scanf("%d", &t);
	for(int Case = 1; Case <= t; Case++) {
		long long n, past_division, lim, sum;
		scanf("%lld", &n);
		sum = past_division = lim = n;
		for(long long i = 2; i <= lim; i++) {
			long long tmp = n/i;
			//printf("tmp : %lld\n", tmp);
			sum += abs(past_division - tmp) * (i-1);
			//printf("%lld\n", sum);
			if(i-1 != tmp)
				sum += tmp;
			//printf("sum (%lld) = (%lld - %lld) *  %lld + %lld\n", sum, past_division, tmp, i-1, tmp);
			past_division = tmp;
			lim = tmp;
		}
		printf("Case %d: %lld\n", Case, sum);
	}
	return 0;
}
