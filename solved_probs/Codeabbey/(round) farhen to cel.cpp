//Codeabbey
//Url: http://www.codeabbey.com/index/task_view/fahrenheit-celsius
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	register int t;
	float in, out;
	cin >> t;
	while(t--)
	{
		cin >> in;
		out = (5*in - 160)/9;
		cout << nearbyint(out) << " ";
	}
	return 0;
}
