// CodeChef
// Subarray GCD
// https://www.codechef.com/problems/SUBGCD

// Find the Largest Subarray where GCD(a1, a2, a3, ..... an) = 1
// If there is any element where GCD is 1, then the whole array is the answer!

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x, gc, t;
	
	cin >> t;
	
	while(t--) {
		cin >> n;
		bool ok = 0;
		for(int i = 0; i < n; ++i) {
			cin >> x;
			if(i == 0)
				gc = x;
			if(!ok) {
				gc = __gcd(gc, x);
				if(gc == 1)
					ok = 1;
			}
		}
		if(!ok)
			cout << "-1" << endl;
		else
			cout << n << endl;
	}
	return 0;
}
