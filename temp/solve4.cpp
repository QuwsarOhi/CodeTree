#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MOD 1000000007
#define ll long long

ll modexp(ll a, ll b){
	ll res = 1;
	while(b > 0){
		if(b%2 == 1){
			res = (res*a)%mod;
		}
		a = (a*a)%mod;
		b = b/2;
	}
	return res%mod;
}

// calculate A mod B, where A : 0<A<(10^100000) (or greater)
// take input as string and process with aftermod

// calculate A^B mod M, where B : 0<A<(10^100000) (or greater)
// take input as string and process with aftermod : afterMod(inputAsString, Mod-1)      due to fermat theorem

long long afterMod(string str, ll mod) {
	long long ans = 0;
	string :: iterator it;
    
	for(it = str.begin(); it != str.end(); it++)        // mod from first to last
		ans = (ans*10 + (*it -'0')) % mod;
	
    return ans;
}

int main() {
	ll a;
	string b;
	cin >> a >> b;
//	cout <<  b << endl;
	cout << modexp(a,mo(b,mod-1))<<endl;
	return 0;
}
