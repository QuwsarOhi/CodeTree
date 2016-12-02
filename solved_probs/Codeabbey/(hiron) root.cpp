//Codeabbey
//Url : http://www.codeabbey.com/index/task_view/square-root
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

long double heron(register double val, int step)
{
	register double r = 1, d;
	while(step--)
	{
		d = val/r;
		//cout << "r : " <<r << " d : " << val<< endl;
		if(abs(r-d) > 1)
			r = (d+r)/2;
		else
		{
			r = (d+r)/2;
			//cout << "done" << endl;
		}
		//cout << r << endl;
	}
	return r;
}

int main()
{
	register int t;
	long double ans;
	scanf("%d", &t);
	while(t--)
	{
		int val, step;
		scanf("%d %d", &val, &step);
		ans = heron(val, step);
		cout << setprecision(12) << ans << " ";
	}
	return 0;
}
