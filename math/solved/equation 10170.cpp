//UVa
//10170 - The Hotel with Infinite Rooms
//Math (Equation), also solveable with binary search
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
	ll man, total, upper, lower, t1, t2;
	wh(sf("%lld %lld", &man, &total) != EOF)
	{
		total += ((man-1)*man)/2;
		//pf("total : %lld\n", total);
		upper = round((sqrt(1+ (8.0*total)) + 1.0)/2.0);
		lower = round((sqrt(1+ (8.0*total)) - 1.0)/2.0);
		//pf("lower: %lld\nupper: %lld\n", lower, upper);
		t1 = (upper*(upper+1))/2;
		t2 = (lower*(lower+1))/2;
		if((total - t1 < 0 && total - t2 < 0) || (total -t1 > 0 && total-t2 > 0))
		{
			if(abs(total-t1) < abs(total-t2))
				pf("%lld\n", upper);
			else
				pf("%lld\n", lower);
		}
		else if(total - t1 < 0 && total - t2 > 0)
			pf("%lld\n", upper);
		else
			pf("%lld\n", lower);
	}
	return 0;
}
