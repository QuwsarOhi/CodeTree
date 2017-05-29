//UVa
//10041 - Vito's Family
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
#define sf scanf
#define pf printf
#define inf std::numeric_limits<int>::max()

using namespace std;

int arr[550];

int main()
{
	register int t, n;
	long long int sum, msum;
	scanf(" %d", &t);
	while(t--)
	{
		msum = inf;
		//pf("%lld", msum);
		sf("%d", &n);
		fr(i, 0, n) sf(" %d", &arr[i]);
		/*sort(arr, arr+n);
		if(n%2) mid = (n/2);
		else mid = (n/2)-1;
		for(int i = mid-1; i >= 0; i--)
			sum += abs(arr[mid] - arr[i]);
		for(int i = mid+1; i < n; i++)
			sum += abs(arr[mid] - arr[i]);
		printf("%lld\n", sum);*/

		for(int i = 0; i < n; i++)
		{
			sum = 0;
			for(int j = i-1; j >= 0; j--)
				sum += abs(arr[i] - arr[j]);
			for(int j = i+1; j < n; j++)
				sum += abs(arr[i] - arr[j]);
			//printf("%d ", sum);
			msum = min(msum, sum);
		}
		pf("%lld\n", msum);
	}
	return 0;
}
