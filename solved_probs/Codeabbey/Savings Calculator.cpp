//Codeabbey
//Url : http://www.codeabbey.com/index/task_view/savings-calculator

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	register int t;
	cin  >> t;
	while(t--)
	{
		double s, r, p, y = 0;
		cin >> s >> p >> r;
		r /= 100;
		while(s < p)
		{
			s += (s*r);
			y++;
			//cout << setprecision(12) <<s << endl;
			s = ceil(s*100)/100;
			//cout << setprecision(12) <<s << endl;
		}
		cout << y << " ";
	}
	return 0;
}

/*
 * 19
50 750 35
1000 20000 4
1000 5000 3
1000 13000 45
500 9000 3
250 3000 5
2500 10000 5
2500 50000 1
2500 30000 5
100 1300 25
2500 17500 10
50 800 10
1000 14000 50
2500 20000 15
500 8500 5
10000 200000 6
1000 7000 15
5000 90000 15
50 500 15
* */

//Answers
//10 77 55 7 98 51 29 302 51 12 21 30 7 15 59 52 14 21 17
//
