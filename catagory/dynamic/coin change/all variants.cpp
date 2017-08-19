#include <bits/stdc++.h>
#define pb push_back
#define sp(b) if(!b){printf("\n"); b = false;}
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define f1(i, b) for(register int i = 1; i <= b; i++)
#define ss stringstream
#define mimx(a, b) if(a > b)swap(a, b);
#define msi map<string, int>
#define mii map<int, int>
#define vec vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define inf (1 << 28)

using namespace std;

// n is the amount we need to produce
// coin[] array contains the coins we can use


int coin[] = {1, 2, 3}, test[1000];

int main()
{
	while(1)
	{
	int n, coin_amount = 3;
	scanf("%d", &n);
	
	//	Solution for producing amount with coins. Without any co-occurance and 
	//	coins can be used more than once
	//  Bottom Up solution
	
	memset(test, 0, sizeof(test));
	test[0] = 1;	// Base case
	
	for(register int i = 0; i < coin_amount; i++)       	// this will NOT produce co-occurance
		for(register int j = 1; j<=n; j++)					// solution for 4 if there is present 1 & 2 coins would be 3
			if(j >= coin[i])								// 1+1+2, 2+2, 1+1+1+1
				test[j] += test[j - coin[i]];				//
	
	printf("Solution without co-occurance : %d\n", test[n]);
	
	//	Solution for producing amount with coins. With co-occurance and 
	//	coins can be used more than once
	//  Bottom Up solution
	
	memset(test, 0, sizeof(test));
	test[0] = 1;	// Base case
				
	for(register int j = 1; j <= n; j++)					// this will produce co-occurance
		for(register int i = 0; i < coin_amount; i++)		// solution for 4 if there is present 1 & 2 coins would be 5
			if(j >= coin[i])								// 1+1+2, 2+2, 1+1+1+1
				test[j] += test[j - coin[i]];				// and also 2+1+1, 1+2+1
			
	printf("Solution with co-occurance : %d\n", test[n]);
	
	
	//	Solution for producing amount with coins. With co-occurance and 
	//	coins can be used more than once
	//  Top Down solution
	fr(i, 0, 1000)test[i] = inf;
	//memset(test, inf, sizeof(test));
	test[0] = 0;	// Base case
	
	for(register int i = 0; i < coin_amount; i++)				// this will produce co-occurance
		for(register int j = n; j > 0; j--)						// solution for 4 if there is present 1, 2 & 3 coins would be 2
			if(j >= coin[i] && (test[j - coin[i]] + 1) < inf)	// 1+3, and 3+1
				test[j] = test[j-coin[i]] + 1;					//
			
	printf("Solution by using coins only once with co-occurance : %d\n", test[n]);
	
	//	Solution for producing amount with coins. With co-occurance and 
	//	coins can be used more than once
	//  Top Down solution
	
	
	fr(i, 0, 1000)test[i] = inf;
	//memset(test, inf, sizeof(test));
	test[0] = 0; // Base case
	printf("%d\n", test[20]);
	for(register int i = n; i > 0; i--)							// this will NOT produce co-occurance
		for(register int j = 0; j < coin_amount; j++)			// solution for 4 if there is present 1, 2 & 3 coins would be 1
			if(i >= coin[j] && (test[i - coin[j]] + 1) < inf)	// 1+3 only
				test[i] = test[i - coin[j]] + 1;				//
				
	printf("Solution by using coins only once without co-occurance : %d\n", test[n]);
	}
	return 0;
}
