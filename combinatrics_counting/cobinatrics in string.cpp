//Codechef
//April Cook-Off 2017
//Bear and AB
//https://www.codechef.com/COOK81/problems/ABREPEAT
//Combinatrics, Counting

#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t;
	unsigned long long n, k, sum, cnt;
	queue<unsigned long long>q;
	scanf("%d", &t);
	while(t--) {
		scanf("%llu %llu", &n, &k);
		char s[n+5];
		
		scanf(" %s", s);
		cnt = 0;
		for(unsigned int i = 0; i < n; i++) {
			if(s[i] == 'a')
				cnt++;
			if(s[i] == 'b')
				q.push(cnt);
		}
		sum = 0;
		while(!q.empty()) {
			sum += (k*(2*q.front() + ((k-1)*cnt)))/2;
			q.pop();
		}
		printf("%llu\n", sum);
	}
	return 0;
}
