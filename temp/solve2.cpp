#include <bits/stdc++.h>
#define MAX 100009
#define MOD 1000000009
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

ll cum[20], p[20];

void powCal() {
	p[0] = 1;
	for(int i = 1; i <= 13; ++i)
		p[i] = p[i-1]*10;
}

ll findPal(ll d, ll n) {
	vector<int>v;
	ll first = 1;

	int tot = (d / 2) + (d % 2);

	for(int i = 1; i < tot; i++) first *= 10;
	//cout<<"F  "<<first<<endl;

   ll now = first + n - 1;
   ll temp = now;

   while(temp){
   	v.push_back(temp % 10);
   	temp /= 10;
   }
   for(int i = 1; i < v.size(); i++){
   	now = (now * 10) + v[i];
   }
   return now;

}

int main() {
	ll t, n;
	
	powCal();
	for(int i = 0; i <= 10; ++i)
		cum[i] = 9 * p[i];

 	cin >> t;
 	for(int Case = 1; Case <= t; ++Case) {
 		cin >> n;

 		if(n <= 9) {
 			cout << "Case " << Case << ": " << n << endl;
 			continue;
 		}

 		int len = 0, d = 1;
 		for( ; n-cum[len] >= 0; ++len, d += 2)
 			n -= cum[len];

 		//cout<<"N  "<<n<<"  "<<len<<endl;
 		cout << "Case " << Case << ": " << findPal(d, n) << endl;
 	}

	return 0;
}