//Codeabbey
//Url: http://www.codeabbey.com/index/task_view/palindromes
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char mem[100];
char ans[50];
int len;

bool rev()
{
	int flag = 1;
	for(register int i = 0; i <= len; )
	{
		if(mem[i] >= 'A' && mem[i] <= 'Z')
			mem[i] = ((int)mem[i] - 'A') + 'a';
		if(mem[len] >= 'A' && mem[len] <= 'Z')
			mem[len] = ((int)mem[len] - 'A') + 'a';
		if(mem[i] > 'z' || mem[i] < 'a')
		{
			++i;
			continue;
		}
		if(mem[len] > 'z' || mem[len] < 'a')
		{
			--len;
			continue;
		}
		if(mem[i] == mem[len])
		{
			len--;
			i++;
		}
		else
		{
			//cout << i << " " << len << endl; 
			flag = 0;
			break;
		}
	}
	return flag;
}
		
		


int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	register int t, i=0;
	cin >> t;
	getchar();
	while(t--)
	{
		fgets(mem, 90, stdin);
		len = strlen(mem);
		//cout << len << endl;;
		if(rev())
			ans[i++] = 'Y';
		else
			ans[i++] = 'N';
	}
	
	for(register int j = 0; j <= i; j++)
		cout << ans[j] << " ";
	return 0;
}
		
