#include <bits/stdc++.h>
using namespace std;

char a[100010], b[100010];
long long powMod(long long N, long long P, long long M) {
	if(P==0)
		return 1;
	if(P%2==0) {
		long long ret = powMod(N, P/2, M)%M;
		return (ret * ret)%M;
	}
    return ((N%M) * (powMod(N, P-1, M)%M))%M;
}

long long bigExpo(char *N, char *P, long long M) {
    long long base = 0, ans = 1;
    for(int i = 0; N[i] != '\0'; ++i)
        base = (base*10LL + N[i] - '0')%M;
    
    for(int j = 0; P[j] != '\0'; ++j)
        ans = (powMod(ans, 10, M) * powMod(base, P[j]-'0', M))%M;
    
    return ans;
}

int main() {
    scanf("%s %s", a, b);
    printf("%lld\n", bigExpo(a, b, 1000000007));
}
