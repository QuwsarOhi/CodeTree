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
#define N 27;

using namespace std;

/*Leap Year Pseudo code
 * if (year is not divisible by 4) then (it is a common year)
 * else if (year is not divisible by 100) then (it is a leap year)
 * else if (year is not divisible by 400) then (it is a common year)
 * else (it is a leap year)
*/

bool leapyear(ll n)
{
	if(n % 4 != 0)
		return 0;
	else if(n % 100 != 0)
		return 1;
	else if(n % 400 != 0)
		return 0;
	else
		return 1;
}

int main()
{
	ll n;
	wh(sf(" %lld", &n) != EOF) {
		if(leapyear(n))
			pf("Leap Year.\n");
	}
	return 0;
}
