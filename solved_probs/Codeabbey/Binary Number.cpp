//Codeabbey
//http://www.codeabbey.com/index/task_view/binary-search

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

long double hi, low, mid, a, b, c, d;

long double func(double x)
{
	return ((a * x) + (b * sqrt(pow(x, 3))) - (c * exp((-x) / 50)) - d);
}

long double binary()
{
	while(hi - low > 0.0000000000000001)
	{
		mid = (hi + low)/2;
		if(func(hi) == 0)
			return hi;
		else if(func(low) == 0)
			return low;
		else if(func(mid) > 0)
			hi = mid;
		else
			low = mid;
	}
	return mid;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	register int t;
	cin >> t;
	while(t--)
	{
		cin >> a >> b >> c >> d;
		low = 0;
		hi = 100;
		cout << setprecision(12) <<binary() << " ";
	}
	return 0;
}

