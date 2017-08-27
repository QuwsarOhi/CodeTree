// Codeforces
// A. Way Too Long Words
// http://codeforces.com/problemset/problem/71/A
#include <bits/stdc++.h>
using namespace std;



int main() {
	int t;
	string x;
	scanf("%d", &t);
	while(t--) {
		cin >> x;
	
		if(x.size() > 10) {
			cout << x[0];
			cout << x.size()-2;
			cout << x[x.size()-1] << endl;
		}
		else
			cout << x << endl;
	}
	return 0;
}
