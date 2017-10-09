// UVa
// 253 - Cube painting

#include <bits/stdc++.h>
using namespace std;

bool check(string x, string y, int a[]) {
	string z;
	for(int i = 0; i < 6; ++i)
		z += y[a[i]-1];
	if(x == z)
		return 1;
	return 0;
}

int main() {
	string s;
	int d[3][6] = {{1, 3, 2, 4, 5, 6}, {2, 6, 4, 1, 3, 5}, {3, 6, 2, 1, 5, 4}}, tmp;
	
	while(cin >> s) {
		string x = {s[0], s[2], s[1], s[3], s[4], s[5]};
		string y = s.substr(6, 6);
		bool ok = 0;
		int k = 0;
		for(int i = 0; i < 3 && !ok; ++i) {
			for(int j = 0; j < 4 && !ok; ++j) {
				if(check(x, y, d[i])) {
					cout << "TRUE" << endl;
					ok = 1;
				}
				tmp = d[i][4];
				d[i][4] = d[i][3];
				d[i][3] = d[i][2];
				d[i][2] = d[i][1];
				d[i][1] = tmp;
			}
			swap(d[i][0], d[i][5]);
			swap(d[i][1], d[i][2]);
			swap(d[i][3], d[i][4]);
			if(k == i)
				--i, ++k;
		}
		
		if(!ok)
			cout << "FALSE" << endl;
	}
	
	return 0;
}
