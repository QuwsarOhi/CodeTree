//Codechef Beginner
//Finding the ratio
//Url: 
#include <iostream>
#include <vector>

using namespace std;

int gcd(int x, int y)
{
	if(y == 0)
		return x;
	int z = x%y;
	return gcd(y, z);
}



int main()
{
	int mem[200];
	register int t, i;
	int x;
	
	cin >> t;
	
	while(t--)
	{
		int p;
		cin >> p;
		if(p == 1)
		{
			cin >> mem[0];
			cout << mem[0] << endl;
			continue;
		}
		cin >> mem[0];
		cin >> mem[1];
		x = gcd(mem[0], mem[1]);
		if(p == 2)
		{
			cout << mem[0]/x << " " << mem[1]/x << endl;
			continue;
		}
		
		for(i = 2; i < p; i++)
		{
			cin >> mem[i];
			x = gcd(mem[i], x);
		}
		for(i = 0; i < p; i++)
			cout << mem[i]/x << " ";
		
		cout << "\n";
	}
	return 0;
}
