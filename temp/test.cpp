#include <bits/stdc++.h>
using namespace std;


int main() {
	int t, x;
	char s[20];
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d %s", &x, s);
		printf("Case %d: ", Case);
		if(strcmp(s, "Bob") == 0) {
			if(x%3 == 0)
				printf("Alice\n");
			else
				printf("Bob\n");
		}
		else {
			//printf("Here\n");
			if((x-1)%3 == 0)
				printf("Bob\n");
			else
				printf("Alice\n");
		}
	}
	return 0;
}
