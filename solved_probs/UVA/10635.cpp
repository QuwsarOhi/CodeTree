// UVa
// 10635 - Prince and Princess


// Dynamic Programmig and LCS will cause runtime error / memory limit exceed
// This problem can be transformed from LCS to LIS
// Mark the common points that prince and princess visit
// Then run LIS use any order (prince's visiting order / princess's visiting order) of the common points
// This is possible because the ORDERS/ point's INDEX is the sequence (which is increasing) which has to be maintained by both
// So highest increasing INDEX of the common points is the answer!

#include <bits/stdc++.h>
using namespace std;


int LIS(vector<int> &val) {
	vector<int>lis;
	for(int i = 0; i < (int)val.size(); i++) {			// Use upper_bound for longest non decreasing subsequence
		vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), val[i]);
		if(lis.end() == it)								// 'it' points to the end, val[i] is bigger
			lis.push_back(val[i]);
		else
			lis[it - lis.begin()] = val[i];
	}
	return lis.size();
}

int mapper[250*250+10];
int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	vector<int>v;
	int t, x, p, q, n;
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case) {
		v.clear();
		memset(mapper, -1, sizeof(mapper));
		scanf("%d %d %d", &n, &p, &q);
		for(int i = 0; i <= p; ++i) {
			scanf("%d", &x);
			mapper[x] = i;
		}
		for(int i = 0; i <= q; ++i) {
			scanf("%d", &x);
			if(mapper[x] != -1)
				v.push_back(mapper[x]);
		}
		printf("Case %d: %d\n", Case, LIS(v));
	}
	return 0;
}
