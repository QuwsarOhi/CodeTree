// LightOJ
// 1166 - Old Sorting
// Greedy

// This is a pure greedy problem
// For any permutation (of course, every number is used only once in the array) we'll try to put every number in its initial position
// Steps:
// for all values from 1 to n (let this be i)
// First Check for i value in the array (Suppose we found it in j'th index)
// swap (i,th index value, j'th index value)

// EX:
// 4 3 2 1
// ^	 ^	(swap, 1 found on 4'th index (index is from base 1))
// 1 3 2 4
//   ^ ^	(swap, 2 found on 3rd index swap(3rd index, 2nd index))
// 1 2 3 4  total swaps : 2


#include <bits/stdc++.h>
using namespace std;

/*
void printer(int v[1110], int n) {
	for(int i = 1; i <=n; ++i)
		printf("%d ", v[i]);
		
	printf("\n");
}*/

int main() {
	
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, cnt, v[110], n;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &n);
		cnt= 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &v[i]);
		}
		
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				if(v[j] == i) {
					if(i != j) {
						swap(v[i], v[j]), ++cnt;
						//printer(v, n);
						break;
					}
				}
			}
		}
		
		printf("Case %d: %d\n", Case, cnt);
	}
	
	return 0;
}
		 
