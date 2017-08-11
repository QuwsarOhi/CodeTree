//Codeabbey
//Url: http://www.codeabbey.com/index/task_view/arithmetic-progression
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
		int a, d, n;
		cin >> a >> d >> n;
		cout << (n*(2*a + (n-1) * d))/2 << " ";
	}
	return 0;
}
