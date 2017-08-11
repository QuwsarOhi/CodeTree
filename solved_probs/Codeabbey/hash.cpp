//Codeabbey
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	register int t;
	double x;
	cin >> t;
	while(t--)
	{
		cin >> x;
		x *= 6;
		x = floor(x);
		x += 1;
		cout << (int)x << " ";
	}
	return 0;
}
