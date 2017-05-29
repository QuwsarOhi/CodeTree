//Codechef Biggener
//Link: https://www.codechef.com/problems/MUFFINS3

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int t, n, a;
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		
		if(n == 2)
			a = 2;
		else if(n == 1)
			a = 1;
		else
		{
			//cout << "*" << endl;
			//cout << ceil(n/2) << endl;
			a = ceil(n/2) + 1;
		}
			
		cout << a << endl;
	}
	
	return 0;
}
