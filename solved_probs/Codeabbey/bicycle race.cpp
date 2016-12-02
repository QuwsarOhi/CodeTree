//Codeabbey
//url: http://www.codeabbey.com/index/task_view/bicycle-race
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	register int t;
	cin >> t;
	while(t--)
	{
		double d, a, b, t;
		cin >> d >> a >> b;
		t = d/(a+b);
		cout << setprecision(12) << a*t << " ";
	}
	return 0;
} 
