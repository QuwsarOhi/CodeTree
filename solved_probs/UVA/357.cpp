//UVa
//357 - Let Me Count The Ways
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define f1(i, b) for(register int i = 1; i <= b; i++)
#define ss stringstream
#define mimx(a, b) if(a > b)swap(a, b)
#define msi map<string, int>
#define mii map<int, int>
#define vec vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define inf (1 << 30)
using namespace std;

int coin[] = {1, 5, 10, 25, 50};
long long test[30010];

int main()
{
	int n;
	while(scanf(" %d", &n) != EOF)
	{
		fr(i, 0, n+1)
			test[i] = 0;
		test[0] = 1;
		
		for(register int i = 0; i < 5; i++)
			for(register int j = 1; j <= n; j++)
				if(j >= coin[i])
					test[j] += test[j - coin[i]];
		if(test[n] == 1)
			printf("There is only %lld way to produce %d cents change.\n", test[n], n);
		else
			printf("There are %lld ways to produce %d cents change.\n", test[n], n);
	}
	return 0;
}
