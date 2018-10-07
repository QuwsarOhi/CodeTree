#include <bits/stdc++.h>
using namespace std;

int main() {
	/*freopen("in", "w", stdout);
	for(int i = 1; i <= 19; ++i)
		for(int j = i+1; j <= 19; ++j)
			cout << i << " " << j << endl;
	return 0;*/
	int t = 010101, k, cnt = 0;
	cout << t << endl;
	for(k = t&(-t);k; k>>=1)++cnt;
	cout << cnt << endl;
	cnt = 0;
	for(k = t; k; k = k&(k-1))++cnt;
	cout << cnt << endl;
	return 0;
}