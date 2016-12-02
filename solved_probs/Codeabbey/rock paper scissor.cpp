//Codeabbey
//Url: http://www.codeabbey.com/index/task_view/rock-paper-scissors
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char spdat[3][60];

int splitter(char mem[])
{
	int len = strlen(mem);
	int j = 0, k = 0;
	for(register int i = 0; i < len; i++)
	{
		if(mem[i] == ' ')
		{
			//cout << "* " << mem[i] << endl;
			j = 0;
			k++;
			continue;
		}
		spdat[j++][k] = mem[i];
	}
	/*for(register int i=0; i <= k; i++)
	{
		cout << spdat[0][i] << " " << spdat[1][i] << " |"<< endl;
	}*/
	return k;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	register int t;
	cin >> t;
	getchar();
	while(t--)
	{
		char mem[100];
		int len, lp = 0, rp = 0;
		fgets(mem, 98, stdin);
		len = splitter(mem);
		for(register int i = 0; i <= len; i++)
		{
			//cout << spdat[0][i] << " " << spdat[1][i] << " ||" << endl;
			if(spdat[0][i] == spdat[1][i])
				continue;
			if((spdat[0][i] == 'R' && spdat[1][i] == 'S') || (spdat[0][i] == 'S' && spdat[1][i] == 'P') || (spdat[0][i] == 'P' && spdat[1][i] == 'R'))
			{
				//cout << "*" << endl;
				lp++;
			}
			if((spdat[0][i] == 'S' && spdat[1][i] == 'R') || (spdat[0][i] == 'P' && spdat[1][i] == 'S') || (spdat[0][i] == 'R' && spdat[1][i] == 'P'))
			{
				//cout << "**" << endl;
				rp++;
			}
		}
		if(lp > rp)
			cout << "1 ";
		else
			cout << "2 ";
	}
	return 0;
}
