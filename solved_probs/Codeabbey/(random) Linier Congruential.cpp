//Codeabbey
//Url : http://www.codeabbey.com/index/task_view/linear-congruential-generator
//refer : http://www.codeabbey.com/index/wiki/random-numbers

#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	register int t;
	cin >> t;
	while(t--)
	{
		int a, c, m, x, n;
		cin >> a >> c >> m >> x >> n;
		while(n--)
			x = ((a * x) + c)% m;
		cout << x << " ";
	}
	return 0;
}
