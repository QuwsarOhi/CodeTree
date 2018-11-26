#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	cin >> s;

	bitset<3>b(s);
	cout << b << endl;

	int v = 0;
	for(int i = 0; i < s.size(); ++i)
		v = v*2 + (s[i] - '0');

	cout << v << endl;
	int n = s.size();
	for(int i = 0; i < 1<<n; ++i) {
		cout << i << ", " << (v^i) << endl;
	}

	return 0;
}