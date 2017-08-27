// Codeforces
// A. Twins
// http://codeforces.com/problemset/problem/160/A

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x, sum = 0, cnt = 0, tmp = 0;
	scanf("%d", &n);
	vector<int>v;
	
	for(int i = 0 ; i < n; ++i) {
		scanf("%d", &x);
		sum += x;
		v.push_back(x);
	}
	
	sort(v.begin(), v.end());
	sum /= 2;
	
	for(int i = v.size()-1; i >= 0; --i) {
		tmp += v[i];
		cnt++;
		if(tmp > sum)
			break;
	}
	
	printf("%d\n", cnt);
	
	return 0;
}
	
