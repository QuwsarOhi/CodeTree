#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, v1, v2, t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d", &n, &v1, &v2);
		if((sqrt(2)*(double)n)/(double)(v1)  < (2.0*(double)n)/(double)v2)
			printf("Stairs\n");
		else
			printf("Elevator\n");
	}	
	return 0;
}
