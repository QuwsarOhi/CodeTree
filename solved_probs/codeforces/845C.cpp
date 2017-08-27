// CodeForces
// C. Two TVs
// http://codeforces.com/problemset/problem/845/C

#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n,x,y;
	
	vector<pair<int, int> >v, tv;
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &x, &y);
		v.push_back({x, y});
	}
		
	sort(v.begin(), v.end());

	for(int i = 0; i < n; ++i) {
		for(auto j = tv.begin(); j < tv.end(); ++j) {
			if(v[i].first > (*j).second) {
				tv.erase(j);
			}
		}
		tv.push_back(v[i]);
		if(tv.size() > 2)
			break;
	}
	
	if(tv.size() > 2)
		printf("NO\n");
	
	else
		printf("YES\n");
	
	return 0;
}
