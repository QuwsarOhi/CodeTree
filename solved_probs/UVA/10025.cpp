//UVa
//10025 - The ? 1 ? 2 ? ... ? n = k problem
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
#define wh while
#define inf std::numeric_limits<int>::max()
#define ll long long

using namespace std;

int main()
{
	register int t;
	sf("%d", &t);
	bool first = true;
	wh(t--)
	{
		if(!first) pf("\n");
		first = false;
		ll sum = 0, distance, total, i;
		sf(" %lld", &total);
		if(total < 0) total *= -1;
		/*if(total == 0) 
		{
			pf("1\n");
			continue;
		}*/
		for(i = 1; ;i++)
		{
			sum+=i;
			distance = sum - total;
			if(distance == 0)
			{
				//pf("broken\n");
				break;
			}
			else if((distance > 0) && (distance % 2 == 0) && (sum > total))
			{
				//pf("i is %lld, sum is %lld, distance is %lld\n", i , sum, distance);
				//pf("sum is %lld\n", sum - distance/2);
				if((sum - distance) == total)
					break;
			}
		}
		pf("%lld\n", i);
	}
	return 0;
}
