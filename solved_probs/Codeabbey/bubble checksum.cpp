//codeabbay
//http://www.codeabbey.com/index/task_view/bubble-in-array

#include <iostream>

using namespace std;

int len = -1, count = 0, chksum = 0;
int mem[100];

void checksum()
{
	for(register int i = 0; i <= len; i++)
	{
		chksum = (chksum + mem[i])*113;
		if(chksum > 10000007)
			chksum %= 10000007;
	}
	
}

void bubble()
{
	for(register int i = 0; i < len; i++)
	{
		if(mem[i] > mem[i+1])
		{
			int temp = mem[i];
			mem[i] = mem[i+1];
			mem[i+1] = temp;
			count++;
		}
	}
}

int main()
{
	do{
		len++;
		cin >> mem[len];
	}while(mem[len] != -1);
	--len;
	bubble();
	checksum();
	cout << count << " " << chksum;
	return 0;
}
