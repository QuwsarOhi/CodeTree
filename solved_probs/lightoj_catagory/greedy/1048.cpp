// LightOJ
// 1048 - Conquering Keokradong
// Greedy, Bisection, Binary Search

// Pure greedy solution will not work for this problem
// In this problem there are two targets:
// 1. Finding Minimum walking distance with k stopage
// 2. Printing the solution

// For the first target, we need to use bisection, to check if the bisection value works possible function is used (this function is greedy)
// The printing solution is also greedy


#include <bits/stdc++.h>
using namespace std;

int v[1010], N, M;

bool possible(int range) {
	int walked = 0, stop = 0;
	for(int i = 0; i < N; ++i) {
		if(walked + v[i] > range) {
			if(v[i] > range)
				return 0;
			walked = v[i];
			++stop;
		}
		else
			walked += v[i];
		if(stop > M)
			return 0;
	}
	if(walked > range)
		return 0;
	return 1;
}

int bisection(int lo, int hi) {
	int ans = 0, mid;
	for(int i = 0; i < 50; ++i) {
		mid = (hi+lo)/2;
		if(possible(mid)) {
			ans = mid;
			hi = mid;
		}
		else
			lo = mid;
	}
	return ans;
}
	

int main() {
	
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, Min, Max, sum;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d%d", &N, &M);
		++N;
		sum = 0;
		for(int i = 0; i < N; ++i) {
			scanf("%d", &v[i]);
			Min = min(v[i], Min);
			sum += v[i];
		}
		
		Max = bisection(Min, 100010);
		
		printf("Case %d: %d\n", Case, Max);
		int walked = 0, stop = 0;
		for(int i = 0; i < N; ++i) {
			if(N-i < M+1-stop) {					// If the number of next camps are equal to the nights to stay, take all!
				if(walked)
					printf("%d\n", walked);
				walked = 0;
				printf("%d\n", v[i]);
				++stop;
				continue;
			}
			if(walked + v[i] > Max) {
				printf("%d\n", walked);
				walked = v[i];
				++stop;
			}
			else
				walked += v[i];
		}
		if(walked && stop == M)
			printf("%d\n", walked);
	}
	
	return 0;
}
