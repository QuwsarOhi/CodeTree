//Codeforces
//problem 682B
//http://codeforces.com/problemset/problem/682/B

#include <bits/stdc++.h>
using namespace std;


int main()
{
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int n;
	while(scanf("%d", &n)== 1) {
		unsigned arr[n+1];
		for(int i = 0; i < n; i++)
			scanf("%u", &arr[i]);
		sort(arr, arr+n);
		unsigned ans = 1;
		for(int i = 0; i < n; i++) {
			if(arr[i] >= ans)			//if the arr[i] is greater than ans, then we can decrease it, so the mex 
				ans++;					//for this position would be ans+1
		}
		printf("%u\n", ans);
	}
	return 0;
}

