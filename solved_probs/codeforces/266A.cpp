// Codeforces
// A. Stones on the Table
// http://codeforces.com/problemset/problem/266/A

#include <bits/stdc++.h>
using namespace std;


int main() {
	string x;
	int n, cnt = 0;
	cin >> n;
	cin >> x;

	for(int i = 0; i < x.size()-1; ++i) {
		if(x[i] == x[i+1])
			++cnt;
	}
	
	cout << cnt << endl;
	return 0;
}
