//Codeabbey
//url : http://www.codeabbey.com/index/task_view/fools-day-2014

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int ints[50];

int ctoint(char mem[])
{
	int len = strlen(mem), j = 0, num;
	char temp[10];
	long long sum = 0;
	//cout << len;
	for(register int i = 0; i < len; i++)	
	{
		if(mem[i] == ' ')
		{
			//cout << "i : " << i << endl;
			num = atoi(temp);
			//cout << "temp : "<< temp[j-1] << endl;
			//cout << num << " ||" << endl;
			sum = sum + (num*num);
			//cout << sum << " : sum" << endl;
			j = 0;
			int tlen = strlen(temp);
			for(register int p = 0; p <= tlen; p++)
				temp[p] = 0;
			continue;
		}
		if(len-1 == i)
		{
			temp[j++] = mem[i];
			num = atoi(temp);
			//cout << num << " ||" << endl;
			sum = sum + (num*num);
			//cout << sum << " : sum" << endl;
			continue;
		}
		temp[j++] = mem[i];
	}
	return sum;
}

int main()
{
	register int t = 0;
	cin >> t;
	cin.ignore();
	while(t--)
	{
		char mem[50];
		cin.getline(mem, 45);
		cout << ctoint(mem) << " ";
	}
	return 0;
}
