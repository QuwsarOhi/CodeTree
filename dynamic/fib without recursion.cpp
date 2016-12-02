#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	long long int mem[100], n;
	
	memset(mem, 0, 100);
	
	mem[0] = 0;
	mem[1] = 1;
	
	cin >> n;
	
	//cout << " = "<<mem[-1] << endl;
	//mem[-1] (mem[i-2] i== 1) returns 1
	//but mem[-2] returns random number
	
	for(int i = 2; i <= n; i++)
	{
		mem[i] = mem[i-1] + mem[i - 2];
		cout << i << " --> " << mem[i] << " = " << mem[i - 1] << "("<< i-1 << ")" << " + " << mem[i - 2] << "(" << i-2 << ")" << endl;
	}
	
	return 0;
}
