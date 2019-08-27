// UVa
// 10865 - Brownie Points

#include <bits/stdc++.h>
#define MAX 200009
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;

ll x[MAX], y[MAX];

int main() {
	ll n;

	while(1) {
		cin >> n;

		if(n == 0)
			break;

		for(int i = 0; i < n; ++i)
			cin >> x[i] >> y[i];

		int mid = n/2;
		ll a = 0, b = 0;
		for(int i = 0; i < n; ++i) {
			if(i == mid)
				continue;
			x[i] -= x[mid];
			y[i] -= y[mid];

			if(x[i] > 0 and y[i] > 0)
				++a;
			else if(x[i] < 0 and y[i] < 0)
				++a;
			else if(x[i] != 0 and y[i] != 0)
				++b;
		}

		cout << a << " " << b << endl;
	}

	return 0;
}