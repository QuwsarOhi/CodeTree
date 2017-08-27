// CodeForces
// A. Diversity
// http://codeforces.com/problemset/problem/844/A

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	string x;
	
	cin >> x;
	cin >> n;
	
	map<char, int>mp;
	
	for(auto i : x) {
		mp[i]++;
	}
	
	if(n > (int)x.size()) {
		cout << "impossible" << endl;
		return 0;
	}
	
	
	cout << max(n-(int)mp.size(), 0) << endl;
	
	return 0;
}
