// Codeforces
// A. Double Cola
// http://codeforces.com/problemset/problem/82/A

#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, t;
	
	cin >> n;
	
	t = 1;
	
	while(n - t*5 >= 0) {
		n -= t*5;
		t *= 2;
	}

	int cnt = 0;
	
	while(n-t > 0) {
		n -= t;
		++cnt;
	}
	
	if(cnt == 0 && n != 0)
		cout << "Sheldon" << endl;
	else if(cnt == 1)
		cout << "Leonard" << endl;
	else if(cnt == 2)
		cout << "Penny" << endl;
	else if(cnt == 3)
		cout << "Rajesh" << endl;
	else
		cout << "Howard" << endl;
	
	return 0;
}
