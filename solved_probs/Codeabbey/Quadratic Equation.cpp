//Codeabbey
//url: http://www.codeabbey.com/index/task_view/quadratic-equation

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	register int t;
	cin >> t;
	while(t--)
	{
		int a, b, c, r;
		cin >> a >> b >> c;
		r = (b*b) - (4*a*c);
		if(r >= 0)
		{
			cout << (sqrt(r) - b)/(2*a) << " ";
			cout << (-(sqrt(r) + b))/(2*a);	
		}
		else
		{
			r *= (-1);
			b = (-b)/(2*a);
			r = sqrt(r)/(2*a);
			cout << b << "+" << r << "i" << " ";
			cout << b << "-" << r << "i";
		}
		if(t != 0)
			cout << "; ";
	}
	return 0;
}
