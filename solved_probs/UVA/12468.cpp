//UVa
//12468 - Zapping

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int j, i, mx, mn;
	while(scanf(" %d %d", &i, &j) && i != -1 && j != -1)
	{
		mx = max(i, j);
		mn = min(i, j);
		mn = min((mn - mx) + 100, mx-mn);
		printf("%d\n", mn);
	}
	return 0;
}
