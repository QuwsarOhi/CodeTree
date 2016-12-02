#include <iostream>
#include <utility>
#include <vector>
#include <cstdio>
#include <algorithm>

//5
//10 20
//5 20
//1 40
//100 200
//20 90
//20
//Max cost : 1750

using namespace std;

typedef pair<int, int>PII;

vector<PII>V;

bool cmp(PII A, PII B)
{
	//N = number of test cases
	//First == Weight
	//Second == Price
	//W == Total weight of bag
	// Actual ratio is price/weight
	//So return A.second/A.first > B.second/B.first
	//Simplified to A.second * B.first > B.second * A.first
	return A.second * B.first > A.first * B.second;
}

void fractional_knapsack()
{
	int n, W;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int weight, price;
		scanf("%d %d", &weight, &price);
		V.push_back(PII(weight, price));
	}
	
	sort(V.begin(), V.end(), cmp);
	cout << "-----------" << endl; //Optional
	for(int i = 0; i <= V.size(); i++) //Optional
	{
		cout << V[i].first << " " << V[i].second << endl;//Optional
	}
	cout << "-----------" << endl;//Optional
	
	scanf("%d", &W);
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		cout << "W = " << W << endl;//Optional
		int z = min(W, V[i].first);
		W -= z;
		ans += z * V[i].second;
	}
	
	printf("Max cost : %d\n", ans);
}

int main()
{
	fractional_knapsack();
	
	return 0;
}
		
