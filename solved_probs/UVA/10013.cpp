//UVa
//10013 - Super long sums

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

char arr1[2000000], arr2[2000000], arr3[2000000];

int main()
{
	register int len1, t, len3, tmp;
	scanf(" %d", &t);
	while(t--)
	{
		for(register int i = 0; i <= 1000200; i++)
		{
			arr1[i] = 'a';
			arr2[i] = 'b';
			arr3[i] = 'c';
		}
		tmp = 0;
		scanf(" %d", &len1);
		--len1;
		
		for(register int i = len1; i >= 0; i--)
		{
			int a, b;
			scanf(" %d %d", &a, &b);
			arr1[i] = '0' + a;
			arr2[i] = '0' + b;
		}
		
		for(len3 = 0; (len3 <= len1) || tmp; len3++)
		{
			if(isdigit(arr1[len3]) && isdigit(arr2[len3]))
				tmp = arr1[len3] + arr2[len3] - '0' - '0' + tmp;
			//printf("first value %d\n", tmp);
			if(tmp > 9)
			{
				arr3[len3] = (tmp%10) + '0';
				tmp/=10;
			}
			else
			{
				arr3[len3] = tmp + '0';
				tmp = 0;
			}
			//printf("Changed value : %d\n", tmp);
		}
		
		for(register int i = (len3-1); i >= 0; i--)
			printf("%d", (arr3[i] - '0'));
		printf("\n");
		if(t)
			printf("\n");
	}
	return 0;
}
