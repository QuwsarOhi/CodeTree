#include <bits/stdc++.h>
using namespace std;


int main() {
	cout << 1 << endl;
	int seed;
	cin >> seed;
	srand(seed);
	int a = rand()%50;
	int b = rand()%50;
	cout << a << " " << b << " " << a+b << endl;
	return 0;
}