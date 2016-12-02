//Codeabbey
//Url: http://www.codeabbey.com/index/task_view/weighted-sum-of-digits
#include <iostream>
using namespace std;

int cal(register int x)
{
	register int mem = 0;
	register int len;
	mem = x;
	for(len = 0; mem; len++)
		mem /= 10;
		
	for( ; x; len--)
	{
		mem += (x%10) * len;
		x /= 10;
	}
	return mem;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	register int t, in;
	cin >> t;
	while(t--)
	{
		cin >> in;
		cout << cal(in) << " ";
	}
	return 0;
}
