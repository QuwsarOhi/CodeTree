//UVa
//10130 - SuperSale
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
#define inf (2^32) - 1
using namespace std;

int price[2000], weight[2000], cost[2000][40];
// price of i'th element price[i]
// weight of i'th element weight[i]
// max profit of i'th element if the weight of bag is w, cost[i][w]

int main()
{
	register int t;
	scanf(" %d", &t);
	while(t--)
	{
		int number_object, query, sum = 0, knapsack_weight;
		scanf(" %d", &number_object);
		fr(i, 1, number_object+1)
			scanf(" %d %d", &price[i], &weight[i]);
		scanf(" %d", &query);
		while(query--)
		{
			scanf(" %d", &knapsack_weight);
			fr(i, 0, number_object)cost[i][0] = 0;
			fr(i, 0, knapsack_weight)cost[0][i] = 0;
			for(register int i = 1; i <= number_object; i++)
				for(register int w = 1; w <= knapsack_weight; w++)
				{
					if(w < weight[i])
						cost[i][w] = cost[i-1][w];
					else
						cost[i][w] = max(cost[i-1][w], cost[i-1][w - weight[i]] + price[i]);
				}
			sum += cost[number_object][knapsack_weight];
		}
		printf("%d\n", sum);
	}
	return 0;
}
