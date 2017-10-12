// UVa
// 202 - Repeating Decimals

#include <bits/stdc++.h>
using namespace std;


int main() {
	int a, b, A;
	
	while(scanf("%d %d", &A, &b) != EOF) {
		unordered_map<int, int>mp;
		vector<int>dec1, dec2;
		int k = 0, point = -1;
		a = A;
		bool divisable = 0;
		if(a >= b) {
			dec1.push_back(a/b);
			a %= b;
		}
		
		while(1 && a != 0) {
			if(mp.find(a) != mp.end()) {
				//printf("map hit %d\n", a);
				point = mp[a];
				break;
			}
			
			if(a%b == 0) {
				dec2.push_back(a/b);
				break;
			}
			
			mp[a] = k++;
			
			int cnt = 0;
			while(a < b) {
				a *= 10;
				if(cnt != 0) {
					dec2.push_back(0);
					k++;
				}
				++cnt;
			}
			
			if(cnt != 0 && mp.find(a) != mp.end()) {
				point = mp[a];
				break;
			}
			
			if(cnt == 1)
				mp[a] = (k-1);
			
			dec2.push_back(a/b);
			a %= b;
			
			if(a == 0) {
				divisable = 1;
				break;
			}
		}
			
		
		printf("%d/%d = ", A, b);
		for(auto it : dec1)
			printf("%d", it);
		
		if(dec1.size() == 0) printf("0");
		printf(".");
		
		for(int i = 0; i < point; ++i)
			printf("%d", dec2[i]);
		
		if(!divisable)
			printf("(");
			
		for(int i = point; i < (int)dec2.size() && i < 50 && i != -1; ++i)
			printf("%d", dec2[i]);
		
		if(point == -1)
			for(auto it: dec2)
				printf("%d", it);
		
		if(dec2.size() >= 50)
			printf("...");
		
		if(divisable)
			printf("(");
		
		if(dec2.size() == 0 || divisable)
			printf("0");
			
		printf(")");
		
		printf("\n   %d = number of digits in repeating cycle\n\n", divisable == 1 ? 1:((int)dec2.size()-point));
	}
	
	return 0;
}	
