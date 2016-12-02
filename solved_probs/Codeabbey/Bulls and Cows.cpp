//Codeabbey
//url : http://www.codeabbey.com/index/task_view/bulls-and-cows
//Bulls and Cows

#include <iostream>

using namespace std;

void flush(int mem[], int len)
{
	for(register int i = 0; i < len; i++)
		mem[i] = -1;
}
/*inplace is used to know the value from the integer place (for the first input)
 * inval is used to know the place from the integer(for the first input)
 * tplace tval is for the test inputs
*/


int main()
{
	int inplace[5], inval[10], tplace[5], tval[10];
	register int t, temp;
	int x;
	flush(inplace, 5);
	flush(inval, 10);
	cin >> x >> t;
	for(register int i = 4; i > 0; i--)
	{
		temp =  x%10;
		inplace[i] = temp;
		inval[temp] = i;
		x /= 10;
	}
	
	while(t--)
	{
		register int a = 0, b = 0;
		cin >> x;
		flush(tplace, 5);
		flush(tval, 10);
		for(register int i = 4; i > 0; i--)
		{
			temp = x%10;
			tplace[i] = temp;
			tval[temp] = i;
			x /= 10;
		}
		for(register int i = 4; i > 0; i--)
		{
			//cout << "ip: " << inplace[i] << " tp: " << tplace[i] << endl;
			if(inplace[i] == tplace[i])//checking if the place and value are same
				a++;
			//cout << inval[inplace[i]] << "---" << tval[tplace[i]] << endl;
			temp = tplace[i];//getting the value from the place(for the test integer)
			if(inval[temp] != -1)//checking if the value is present in the first input (if its -1 then it doesn't exist)
				if(inval[temp] != tval[temp])//counting only if the positions are not same for the temp value
					b++;
		}
		cout << a << "-" << b << " ";
	}
	return 0;
}
