//Codeabbey Modular Calculator
//url : http://www.codeabbey.com/index/task_view/modular-calculator
// (a%b + c%b)%b = (a+c)%b
// (a%b * c%b)%b = (a*c)%b

#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	char sign[10000];
	int value[10000];
	register int i = -1, mem;
	cin >> mem;
	do
	{
		++i;
		cin >> sign[i] >> value[i];
	}while(sign[i] != '%');
	
	for(register int j = 0; j < i; j++)
	{
		if(sign[j] == '+')
			mem = (mem%value[i] + value[j]%value[i])%value[i];
		else
			mem = (mem%value[i] * value[j]%value[i])%value[i];
	}
	cout << mem;
	
	return 0;
}
