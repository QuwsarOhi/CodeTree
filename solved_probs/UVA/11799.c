#include <stdio.h>

int finder(int x)
{
	int static mem = 0;
	
	if(x > mem)
	mem = x;
	
	if(x == -1)
	return mem;
	
	if(x == 0)
	mem = 0;
}



int main()
{
	int i, j, students, Case, speed;
	int mem_value[51];
	
	scanf("%d", &Case);
	
	for(i = 1; i <= Case; i++)
	{
		scanf("%d", &students);
		for(j = 0; j < students; j++)
		{
			scanf("%d", &speed);
			finder(speed);
		}
		
		mem_value[i] = finder(-1);
		finder(0);
	}
	
	for(i = 1; i <= Case; i++)
		printf("Case %d: %d\n", i, mem_value[i]);
	
	
	
	return 0;
	
	
}
