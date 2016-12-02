//UVa
//414 - Machined Surfaces

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	while(scanf(" %d", &n) && n)
	{
		getchar_unlocked();
		register int i = 0, sum = 0, mx = 0;
		int arr[n];
		while(n--)
		{
			string x, y;
			getline(cin, x);
			stringstream s;
			s << x;
			s >> x;
			s >> y;
			arr[i] = (x.size() + y.size());
			mx = max(arr[i++], mx);
		}
		for(register int j = 0; j < i; j++)
			sum += mx - arr[j];
		printf("%d\n", sum);
	}
	return 0;
}
