//UVa
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=435&mosmsg=Submission+received+with+ID+17974149
//Kindergarten Counting Game (494)

#include <bits/stdc++.h>

using namespace std;

int main()
{
	string x;
	while(getline(cin, x))
	{
		int len = x.size();
		bool alpha = false;
		register int counter = 0;
		for(register int i = 0; i <= len; i++)
		{
			if((x[i] >= 'A' && x[i] <= 'Z') || (x[i] >= 'a' && x[i] <= 'z'))
				alpha = true;
			else
				if(alpha)
				{
					alpha = false;
					counter++;
				}
		}
		cout << counter << endl;
	}
	return 0;
}
