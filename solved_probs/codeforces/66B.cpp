//Codeforces
//problem 66B
//http://codeforces.com/problemset/problem/66/B
//Bruteforce

#include <bits/stdc++.h>
using namespace std;

int cnt, n, arr[1010];

void leftSegment(int pos) {
	if(pos >= n || pos < 0)
		return;
	if(arr[pos] <= arr[pos+1])
		cnt++;
	else
		return;
	leftSegment(pos-1);
}

void rightSegment(int pos) {
	if(pos >= n || pos < 0)
		return;
	if(arr[pos] <= arr[pos-1])
		cnt++;
	else
		return;
	rightSegment(pos+1);
}

int main()
{
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	while(scanf("%d", &n) == 1) {
		for(int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		int maxcnt = 0;
		for(int i = 0; i < n; i++) {
			cnt = 1;
			leftSegment(i-1);
			rightSegment(i+1);
			if(maxcnt < cnt)
				maxcnt = cnt;
		}
		printf("%d\n", maxcnt);
	}
	return 0;
}
