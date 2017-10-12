// UVa
// 455 - Periodic Strings

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	char s[120];
	bool first = 1;
	scanf("%d", &t);
	while(t--) {
		if(!first) printf("\n");
		first = 0;
		scanf(" %s", s);
		string x(s);
		int l = x.size();
		
		for(int i = 1; i <= l; ++i) {
			if(l%i != 0)
				continue;
			string p = x.substr(0, i);
			bool found = 1;
			
			for(int j = i; j < l; j+=i) {
				if(x.substr(j, i) != p) {
					found = 0;
					break;
				}
			}
			if(found) {
				printf("%d\n", i);
				break;
			}
		}
		
	}
	return 0;
}
