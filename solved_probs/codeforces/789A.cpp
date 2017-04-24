//Codeforces
//problem - 789A
//http://codeforces.com/contest/798/problem/A
#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	char s[30];
	
	while(scanf(" %s", s) == 1) {
		int len = strlen(s), missmatch = 0;
		for(int i = 0, j =  len-1; i < j; i++, j--) {
			if(s[i] != s[j])
				missmatch++;
		}
		if((missmatch == 1 && (len%2) == 0) || (missmatch == 0 && (len%2) == 1) || (missmatch == 1 && (len%2) == 1))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
