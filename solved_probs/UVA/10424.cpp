//UVa
//UVa 10424 - Love Calculator

#include <bits/stdc++.h>

using namespace std;

int turn(int x)
{
	int sum = 0;
	while(1)
	{
		sum += x%10;
		x /= 10;
		if(x == 0 && to_string(sum).size() == 1)
			break;
		else if(x == 0 && to_string(sum).size() > 1)
		{
			x = sum;
			sum = 0;
		}
	}
	
	return sum;
}

int main()
{
	string x, y;
	while(!getline(cin, x).eof())
	{
		getline(cin, y);
		int l1 = x.size(), l2 = y.size(), sum1=0, sum2=0;
		//cout << l1 << " " << l2 << endl;
		for(register int i = 0; i < l1; i++)
			if(isalpha(x[i]))
			{
				if(isupper(x[i]))
					sum1 += (int)x[i] - 'A' + 1;
				else
					sum1 += (int)x[i] - 'a' + 1;
			}
		for(register int i = 0; i < l2; i++)
			if(isalpha(y[i]))
			{
				if(isupper(y[i]))
					sum2 += y[i] - 'A' + 1;
				else
					sum2 += y[i] - 'a' + 1;
			}
		double o1 = turn(sum1), o2 = turn(sum2);
		//cout << o1 << " " << o2 << endl;
		if(o1 > o2)swap(o1, o2);
		printf("%.2f %%\n", (o1/o2)*100.0);
	}
	return 0;
}
