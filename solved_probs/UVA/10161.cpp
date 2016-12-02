//UVa
//10161 - Ant on a Chessboard
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
#define ll long long

using namespace std;

int main()
{
	ll n, big_val, max_pos, x, y;
	wh(sf("%lld", &n) && n)
	{
		big_val = ceil(sqrt((float)n));
		max_pos = (big_val * big_val) - big_val + 1;
	//	if(n%2 == 0)
	//	
		if(big_val % 2 == 0)
		{
			if(n < max_pos)
			{
				y = big_val; //- (max_pos-n);
				x = big_val - (max_pos-n);
			}
			else if(n == max_pos)
				x = y = big_val;
			else
			{
				x = big_val;
				y = big_val - (n- max_pos);
			}
		}
		else
		{
			if(n < max_pos)
			{
				y = big_val - (max_pos-n);
				x = big_val;
			}
			else if(n == max_pos)
				x = y = big_val;
			else
			{
				y = big_val;
				x = big_val - (n- max_pos);
			}
		}
	//	}
	//	else
	//	{
			
		//	else if(n < max_pos)
				
	//	}
	pf("%lld %lld\n", x, y);
	}
	return 0;
}

