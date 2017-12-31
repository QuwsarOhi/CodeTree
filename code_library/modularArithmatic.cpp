//Complexity : O(logN)
#include <bits/stdc++.h>
using namespace std;

// (2^10 % 5) = powMod(2, 10, 5)
long long powMod(long long N, long long P, long long M) {
	if(P==0)
		return 1;
	if(P%2==0) {
		long long ret = powMod(N, P/2, M)%M;
		return (ret * ret)%M;
	}
    return ((N%M) * (powMod(N, P-1, M)%M))%M;
}

// 2^100 = Pow(2, 100)
unsigned long long Pow(unsigned long long N, unsigned long long P) {
	if(P == 0)
		return 1;
	if(P % 2 == 0) {
		unsigned long long ret = Pow(N, P/2);
		return ret*ret;
	}
    return N * Pow(N, P-1);
}

// calculate A mod B, where A : 0<A<(10^100000) (or greater)
// take input as string and process with aftermod

// calculate A^B mod M, where B : 0<A<(10^100000) (or greater)
// take input as string and process with aftermod : afterMod(inputAsString, Mod-1)      due to fermat theorem

long long afterMod(string str, ll mod) {        // input as string, as it is big, mod is the Mod value (Mod-1 if modding an exponentiation)
	long long ans = 0;
	string :: iterator it;
    
	for(it = str.begin(); it != str.end(); it++)        // mod from first to last
		ans = (ans*10 + (*it -'0')) % mod;
	
    return ans;
}

int main() {
    return 0;
}
