// LightOJ
// 1275 - Internet Service Providers
// Basic Math



// I just ran the loop, found a pattern and tried to make an equation from it

//for(T = 0; C - N*T >= 0; ++T)
//printf("T : %d  : %d : %d : %d\n", T, C - N*T, N*T, T * (C- N*T));

// for the float answer, took the best profitable one



#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, C, N;
	
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d %d", &N, &C);
		
		printf("Case %d: ", Case);
		
		if(N == 0)
			printf("0\n");
		else {
			int upper = ceil(C / (2.0*N)), lower = floor(C / (2.0 * N));
			
			if(lower * (C - lower*N) >= upper * (C - upper*N))
				printf("%d\n", lower);
			else
				printf("%d\n", upper);
		}
	}
	
	return 0;
}
