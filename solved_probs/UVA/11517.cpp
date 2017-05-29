//UVa
//11517 - Exact Change
//Count the minimum possible coin without any occurance
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
#define inf (1 << 29)

int main()
{
	register int t, total, n;
	int test[10001], coin[101];
	scanf(" %d", &t);
	while(t--)
	{
		scanf(" %d %d", &total, &n);
		fr(i, 0, n)
			scanf(" %d", &coin[i]);
		fr(i, 1, 10001)
			test[i] = inf;
		test[0] = 0; //base case
		
		for(register int i = 0; i < n; i++)
			for(register int j = 10000;j > 0; j--)
				if(j >= coin[i] && (test[j - coin[i]] + 1) < test[j])
					test[j] = test[j - coin[i]] + 1;
		// here 1 is the main fact, it is used as, coin[i] is added
		// in the sequence, example: if the total = 1500 and coin 500, 1000, 2000
		//then for test[1000 - 500] + 1  = test[500] + 1(as im giving 500 coin) = 0 (as we'r running from high to low) + 1
		for(register int i = total; ; i++)
			if(test[i] != inf)
			{
				printf("%d %d\n", i, test[i]);
				break;
			}
	}
	return 0;
}
