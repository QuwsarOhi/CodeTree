//CodeChef
//https://www.codechef.com/problems/CSUB
//Math (Easy)

#include <bits/stdc++.h>
using namespace std;

long long binomialCoeff(long long n, long long k)
{
    long long res = 1;

    // Since C(n, k) = C(n, n-k)
    if ( k > n - k )
        k = n - k;

    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (long long i = 0; i < k; ++i)
    {
	//note: devide first then multiply to avoid overflow, decimal can be taken
	//after every calcualation round up the value
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	
	int t, n, cnt;
	char c;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		cnt = 0;
		while(n--) {
			scanf(" %c", &c);
			cnt = (c == '1') ? cnt+1 : cnt;
		}
		if(cnt == 1) {
			printf("1\n");
			continue;
		}
		else if(cnt == 0) {
			printf("0\n");
			continue;
		}
		unsigned long long ans = binomialCoeff(cnt, 2) + cnt;
		printf("%llu\n", ans);
	}
	return 0;
}
