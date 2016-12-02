//Codechef Biggener
//Url: https://www.codechef.com/problems/FLOW007
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	register int t;
	scanf("%d", &t);
	getchar();
	while(t--)
	{
		register int x,y = 0;
		scanf("%d", &x);
		while (x) {
			//cout << "x : " << x << endl;
	        y *= 10;
	        y += x%10;
	        x /= 10;
	        //cout << "y : " << y << endl;
	    }
		printf("%d\n", y);
	}
	
	return 0;
}
