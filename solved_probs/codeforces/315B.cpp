//Codeforces
//Problem - 315B
//http://codeforces.com/problemset/problem/315/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int n, m, pos, k;
	while(scanf("%d %d", &n, &m) == 2) {
		unsigned long long arr[n+2];
		for(int i = 0; i < n; i++)
			scanf("%llu", &arr[i]);
		unsigned long long sumup = 0, x;
		while(m--) {
			scanf("%d", &k);
			
			if(k == 1) {
				scanf("%d %llu", &pos, &x);
				arr[pos-1] = x - sumup;		//if the value is changed after the entire array value is summed up
			}								//then we can save a negative value in the position so that arr[pos]+sumup = new set value
			else if(k == 2) {
				scanf("%llu", &x);
				sumup+= x;
			}
			else {
				scanf("%d", &pos);
				printf("%llu\n", arr[pos-1]+sumup);
			}
		}
	}
	return 0;
}
			
