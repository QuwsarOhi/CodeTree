#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int scale(int n, int x, int y) {
	if(n < x)
		n = x;
	if(n > y) {
		n %= y;
		n+1;
	}
	return max(n, x);
}

void gen(int n, int tar=-1) {
	vector<int> v, u;
	for(int i = 1; i <= n; ++i)
		u.push_back(i), v.push_back(i);

	int idx = 0;
	do {
		do {
			//if(idx <= 0) {
			++idx;
				cout << n << endl;
				for(int i = 0; i < n; ++i)
					cout << v[i] << " ";
				cout << endl;
				for(int j = 0; j < n; ++j)
					cout << u[j] << " ";
				cout << endl;
			//--idx;
			if(idx == tar) {
				cerr << n << endl;
				for(int i = 0; i < n; ++i)
					cerr << v[i] << " ";
				cerr << endl;
				for(int j = 0; j < n; ++j)
					cerr << u[j] << " ";
				cerr << endl;
			}
		} while(next_permutation(v.begin(), v.end()));
		//--idx
	} while(next_permutation(u.begin(), u.end()));
}

int main() {
	//ll seed;
	//cout << 10 << endl;
	//cin >> seed;
	//srand(seed);

	//for(int i= 0; i < n; ++i) {
	//	gen(n, rand())
	//}

	cout << 14400 << endl;
	gen(5, 45);

	return 0;
}