// A. Lucky Division
// http://codeforces.com/problemset/problem/122/A

#include <bits/stdc++.h>
using namespace std;

vector<int>lucky;

bool ok(int x) {
	while(x) {
		int t = x%10;
		if(t != 4 && t != 7)
			return 0;
		x /= 10;
	}
	return 1;
}

void bruteforce() {
	for(int i = 4; i <= 1000; ++i) {
		if(ok(i)) {
			lucky.push_back(i);
			//cout << i << endl;
		}
	}
}


int main() {
	int n;
	bruteforce();
	scanf("%d", &n);
	
	for(auto i : lucky) {
		if(n%i == 0) {
			printf("YES\n");
			return 0;
		}
	}
	
	printf("NO\n");
	return 0;
}
