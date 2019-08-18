#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

vector<ll> v, on[70];

ll solve(ll mxLen) {
	for(int i = 0; i < 64; ++i) {
		queue<ll> q;
		lvl.clear();

		for(auto it : on[i]) {
			q.push(it);
			lvl[it] = 1;
		}

		while()
	}
}

int main() {
	ll n;
	cin >> n;

	v.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> v[i];

		for(int j = 0; j < 64; ++j) {
			if(v[i] & (1ULL << j)) {
				on[j].push_back(v[i]);
			}
		}
	}

	for(int i = 0; i < 64; ++i) {
		if(on[i].size()) {
			cout << i << ": ";
			for(auto it : on[i])
				cout << it << " ";
			cout << endl;
		}
	}



	return 0;
}