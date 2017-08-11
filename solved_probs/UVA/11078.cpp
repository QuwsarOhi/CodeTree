//UVa
//11078 - Open Credit System

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

int main()
{
	register int t;
	scanf(" %d", &t);
	while(t--)
	{
		register int n;
		scanf(" %d", &n);
		long long senior_max = -1, diff_max, a, b;
		scanf(" %lld %lld", &a, &b);
		senior_max = max(a, b);
		diff_max = a-b;
		n-=2;
		while(n--)
		{
			scanf("%lld", &a);
			diff_max = max(diff_max, senior_max-a);
			senior_max = max(senior_max, a);
		}
		printf("%lld\n", diff_max);
	}
	return 0;
}
