//UVa
//105 - the skyline problem
//Height map

#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("in", "r", stdin);

	int H[10010] = {0};
	int l, h, r;
	
	while(scanf("%d %d %d", &l, &h, &r) == 3)
		for(int i = l; i < r; ++i) 
			if(h > H[i])
				H[i] = h;
	
	int pastHeight = 0;
	bool notFirst = false;
	for(int i = 0; i != 10000; ++i) {
		if(H[i] != pastHeight) {
			if(notFirst)
				printf(" ");
			notFirst = true;
			printf("%d %d", i, H[i]);
			pastHeight = H[i];
		}
	}
	
	printf("\n");
	
	return 0;
}
