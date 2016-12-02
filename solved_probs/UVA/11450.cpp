//UVa
//11450 - Wedding shopping
//Sample Input
/*
1 //test case
100 4 //total, //garment items
3 8 6 4 //number of catagories in garment items, // values
2 5 10  //number of catagories in garment items, // values
4 1 3 3 7  //number of catagories in garment items, // values
4 50 14 23 8  //number of catagories in garment items, // values
*/
#include <bits/stdc++.h>
#define pb push_back
#define sp(b) if(!b)printf("\n"); b = false;
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


using namespace std;

int price[30][30], total, g, item;
bool test[21][210];

int main()
{
	register int t;
	scanf(" %d", &t);
	while(t--)
	{
		memset(test, false, sizeof(test));
		scanf(" %d %d", &total, &g);
		for(register int i = 0; i < g; i++)
		{
			scanf(" %d", &price[i][0]);
			for(register int j = 1; j <= price[i][0]; j++)
				scanf(" %d", &price[i][j]);
		}
		//printf("got price\n");
		for(register int i = 1; i <= price[0][0]; i++)
		{
			if(total - price[0][i] >= 0)
				test[0][total - price[0][i]] = true;
			//printf("%d ", i);
		}
		for(register int i = 1; i < g; i++)
			for(register int money = 0; money < total; money++)
				if(test[i-1][money])
					for(register int j = 1; j <= price[i][0]; j++)
						if(money - price[i][j] >= 0)
							test[i][money - price[i][j]] = true;
		bool found = false;
		for(register int money = 0; money <= total; money++)
			if(test[g-1][money])
			{
				printf("%d\n", total - money);
				found = true;
				break;
			}
		if(!found)
			printf("no solution\n");
	}
	return 0;
}
