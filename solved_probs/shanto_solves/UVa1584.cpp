// UVa
// 1584 - Circular Sequence

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	string x, y;
	cin >> t;
	while(t--) {
		cin >> x;
		int len = x.size();
		x += x;
		y = x;
		for(int i = 0; i < len; ++i) {
			string t = x.substr(i, len);
			if(t < y)
				y = t;
		}
		cout << y << endl;
	}
	return 0;
}
	
		
