//Codechef Biggener
//Url : https://www.codechef.com/problems/CIELRCPT
//Fractional Knapsack
//Ciel and Receipt

#include <iostream>
#include <iostream>

using namespace std;

int mem[] = {2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};

int main()
{
	int t, n;
	cin >> t;
	while(t--)
	{
		int counter = 0, i = 0;
		cin >> n;
		while(n)
		{
			if(mem[i] <= n)
			{
				counter++;
				n -= mem[i];
			}
			else
				i++;
		}
		cout << counter << endl;
	}
	
	return 0;
}
		
