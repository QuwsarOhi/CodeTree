//Codechef Biggener
//Url: https://www.codechef.com/problems/FCTRL2

#include <iostream>
#include <cstring>

using namespace std;

int mem[200];

int mul(int fac)
{
	int index, temp;
	
	for(int i = 199; i >= 0; i--)
		mem[i] = -1;
	
	mem[199] = 1;
	temp = 0;
	while(fac > 1)
	{
		index = 199;
		while(mem[index] >= 0)
		{
			temp = ((mem[index] * fac) + temp);
			mem[index] = temp%10;
			temp = temp/10;
			index--;
		}
	
		while(temp)
		{
			mem[index] = temp%10;
			temp = temp/10;
			index--;
		}
		
		fac--;
	}
	return index;
}

int main()
{
	int x, n, t;
	
	cin >> t;
	
	while(t--)
	{
		cin >> x;
		if(x == 1)
		{
			cout << "1" << endl;
			continue;
		}
		
		n = mul(x) + 1;
		while(n <= 199)
		{
			cout << mem[n];
			n++;
		}
		cout << "\n";
	}
	return 0;
}
