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

long long mo(string str, ll mode) {
	long long ans = 0;
	string :: iterator it;
	for(it = str.begin();it != str.end();it++){
		ans = (ans*10 + (*it -'0'))%mode;
	}
//	cout << ans << endl;
	return ans;
}
int main()
{
	ll a;
	string b;
	cin >> a >> b;
//	cout <<  b << endl;
	cout << modexp(a,mo(b,mod-1))<<endl;
	return 0;
}
