//UVa
//147 - Dollars

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

long test[30100];
int coin[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};


int main()
{
	long x, y;
	memset(test, 0, sizeof(test));
	test[0] = 1;
	for(register int i = 0; i < 11; i++)
		for(register int j = coin[i]; j <= 30050; j++)
				test[j] += test[j - coin[i]];
	
	while(scanf("%ld.%ld", &x, &y) && (x || y))
	{
		long num = (x * 100)+ y;
		//printf(" %ld\n", num);		
		printf("%3ld.%.2ld%17ld\n", x, y, test[num]);
	}
	return 0;
}
