#include <bits/stdc++.h>
#define MAX 100011
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;
typedef long long int ll;

int u[MAX], v[MAX];

int lcs(int m, int n)   {  
    if (m == 0 || n == 0)  
        return 0;  
    if(u[m] == v[n])  
        return 1 + lcs(m-1, n-1);  
    else
        return max(lcs(m, n-1), lcs(m-1, n));  
} 

int main() {
	int t, n;
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &n);

		for(int i = 1; i <= n; ++i)
			scanf("%d", &v[i]);
		for(int i = 1; i <= n; ++i)
			scanf("%d", &u[i]);

		int ret = lcs(n, n);
		printf("Case %d: %d\n", Case, (n-ret)*2);
	}

	return 0;
}