//UVa
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=208&mosmsg=Submission+received+with+ID+17968094
//Tex Quotes (272)
#include <bits/stdc++.h>

using namespace std;

int main()
{
	char temp[10000];
	char mem[10000];
	register int flag = 1;
	while(fgets(mem, 9998, stdin))
	{
		//printf("new loop\n");
		int len = strlen(mem);
		register int j = 0;
		for(register int i = 0; i < len; i++)
		{
			if((mem[i] == '"') && (flag == 1))
			{
				//printf("char : %c ; %d %d \n", mem[i], i, j);
				temp[j++] = '`';
				temp[j++] = '`';
				flag = 2;
				continue;
			}
			
			else if((mem[i] == '"') && (flag == 2))
			{
				//printf("char : %c ; %d %d \n ", mem[i], i, j);
				temp[j++] = '\'';
				temp[j++] = '\'';
				flag = 1;
				continue;
			}
			
			//printf("char : %c ; %d %d \n", mem[i], i, j);
			temp[j++] = mem[i];
		}
		printf("%s", temp);
		memset(temp, 0, 10000);
	}
	return 0;
}
