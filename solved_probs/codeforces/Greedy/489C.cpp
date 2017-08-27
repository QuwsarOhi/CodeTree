// Codeforces
// C. Given Length and Sum of Digits...
// http://codeforces.com/problemset/problem/489/C

#include <bits/stdc++.h>
using namespace std;

int ReqLev, ReqSum;
vector<int>v;

void recurMin(int sum, int level) {
	if(level > ReqLev || sum == 0)
		return;
	for(int i = 9; i >= 0; --i) {
		if(sum == i && level != ReqLev) {
			continue;
		}
		if(sum == i && level == ReqLev) {
			v.push_back(i);
			return;
		}
		if(sum >= i) {
			v.push_back(i);
			recurMin(sum-i, level+1);
			return;
		}
	}
	return;
}

int main() {
	scanf("%d%d", &ReqLev, &ReqSum);
	
	if(ReqLev == 1 && ReqSum == 0) {
		printf("0 0\n");
		return 0;
	}
	
	if(((ReqLev*9) < ReqSum) || ReqSum == 0) {
		printf("-1 -1\n");
		return 0;
	}
	
	recurMin(ReqSum, 1);
	reverse(v.begin(), v.end());
	
	for(auto i : v)
		printf("%d", i);
	printf(" ");
	
	int lev = 1;
	while(ReqSum != 0) {
		for(int i = 9; i >= 0; --i) {
			if(ReqSum >= i) {
				printf("%d", i);
				ReqSum -= i;
				++lev;
				break;
			}
		}
	}
	
	while(ReqSum == 0 && lev <= ReqLev) {
		printf("0");
		++lev;
	}
	
	printf("\n");
	
	return 0;
}
	
