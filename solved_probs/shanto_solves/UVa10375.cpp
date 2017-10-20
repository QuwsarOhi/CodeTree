// UVa
// 10375 - Choose and divide

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n1, n2, r1, r2;
	while(scanf("%d %d %d %d", &n1, &r1, &n2, &r2) == 4) {
		
		if(n1-r1 < r1)
			r1 = n1-r1;
		if(n2-r2 < r2)
			r2 = n2-r2;
			
		vector<int>vp, vd;
		
		for(int i = 1; i <= max(r1, r2); ++i) {
			if(i <= r1) {
				vp.push_back(n1);
				vd.push_back(i);
			}
			if(i <= r2) {
				vp.push_back(i);
				vd.push_back(n2);
			}
			--n1;
			--n2;
		}
		
		long long upper = 1e12;
		int i = 0, j = 0;
		double ans = 1;
		
		sort(vp.begin(), vp.end());
		sort(vd.begin(), vd.end());
		
		while(i < vp.size() && j < vd.size()) {
			while(ans >= upper && j < vd.size())
				ans /= vd[j++];
			ans *= vp[i++];
		}
		
		while(i < vp.size())
			ans *= vp[i++];
			
		while(j < vd.size())
			ans /= vd[j++];
		
		printf("%.5lf\n", ans);
	}
	
	return 0;
}
