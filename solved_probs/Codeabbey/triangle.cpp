//Codeabbey
//Url: http://www.codeabbey.com/index/task_view/triangles
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	register int t;
	cin >> t;
	while(t--)
	{
		float a, b, c, v, s;
		cin >> a >> b >> c;
		s = (a+b+c)/2;
		v = sqrt(s*(s-a)*(s-b)*(s-c));
		if(v > 0)
			cout << "1 ";
		else
			cout << "0 ";
		
	}
	return 0;
}
