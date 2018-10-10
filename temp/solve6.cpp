#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("in", "w", stdout);
	srand(111);

	cout << 1000 << " " << 500000 << endl;

	for(int i = 0; i < 1000; ++i)
		cout << ((rand()%200000) * (rand()&1?-1:1)) << " " << ((rand()%200000) * (rand()&1?-1:1)) << " " << (rand()%200000+1) << endl;

	for(int i = 0; i < 500000; ++i)
		cout << (rand()%1000000) << endl;
	return 0;
}