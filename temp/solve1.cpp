#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k, s;
map<ll, ll> st;

void recur(ll val, ll step) {
	if(step >= k) {
		st[val]+=1;
		return;
	}

	for(int i = 0; i <= n; ++i)
		recur(val^i, step+1);
}

int main() {
	ll t;
	cin >> t;

	while(t--) {
		cin >> n >> k >> s;

		st.clear();
		recur(s, 0);

		for(auto it : st)
			cout << it.first << " : " << it.second << endl;
		cout << endl;
	}

	return 0;
}