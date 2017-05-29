//UVa
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=38
//102 - Ecological Bin Packing
#include <bits/stdc++.h>

using namespace std;

int bin[3][3];

struct store
{
	char a, b, c;
	int val;
}str[6];

bool comp(const store &a, const store &b)
{
	return (a.val < b.val);
}


int gen(char x, int i)
{
	if(x == 'B')
		return bin[i][1] + bin[i][2];
	else if(x == 'G')
		return bin[i][0] + bin[i][2];
	else
		return bin[i][0] + bin[i][1];
}


int counter(char a, char b, char c)
{
	int sum = 0;
	
	sum += gen(a, 0);
	sum += gen(b, 1);
	sum += gen(c, 2);
	
	return sum;
}

int main()
{
	
	
	while(scanf("%d %d %d %d %d %d %d %d %d", &bin[0][0], &bin[0][1], &bin[0][2], &bin[1][0], &bin[1][1], &bin[1][2], &bin[2][0], &bin[2][1], &bin[2][2]) != EOF)
	{
		char dat[] = {'B', 'C', 'G'};
		int i = 0;
		//printf("done\n");
	
		do{
			//printf("%c %c %c\n", dat[0], dat[1], dat[2]);
			//printf("value : %d\n", counter(dat[0], dat[1], dat[2]));
			
			str[i].a = dat[0];
			str[i].b = dat[1];
			str[i].c = dat[2];
			str[i++].val = counter(dat[0], dat[1], dat[2]);
			
			
		}while(next_permutation(dat,dat+3));
		
		int min_val = (*min_element(str, str+6, comp)).val;
		
		for(i = 0; i < 6; i++)
			if(str[i].val == min_val)
			{
				printf("%c%c%c %d\n", str[i].a, str[i].b, str[i].c, str[i].val);
				break;
			}
		
		
	}
	return 0;
}
