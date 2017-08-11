//Codeabbay
//url: http://www.codeabbey.com/index/task_view/modulo-and-time-difference

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
		int d1, d2, h1, h2, m1, m2, s1, s2, sum1, sum2;
		cin >> d1 >> h1 >> m1 >> s1 >> d2 >> h2 >> m2 >> s2;
		sum1 = (d1*3600*24) + (h1*3600) + (m1*60) + s1;
		sum2 = (d2*3600*24) + (h2*3600) + (m2*60) + s2;
		sum2 = sum2 - sum1;
		d1 = sum2 / (3600*24);
		h1 = (sum2 / (3600))%24;
		m1 = (sum2 / 60)%60;
		s1 = sum2%60;
		
		cout << "(" <<d1 << " " << h1 << " " <<m1 << " " << s1 << ") ";
	}
	return 0;
}
