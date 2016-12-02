//UVa
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1130
//10189 - Minesweeper

#include <bits/stdc++.h>

using namespace std;

int n, m;

char push(char x)
{
	if(x == '*')
		return '*';
	if(x == '.')
		return '0';
	else
	{
		int y = x - '0';
		y++;
		return ((char)(y+'0'));
	}
}

void change(char mat[][302], int i, int j)
{
	if(j-1 >= 0)
		mat[i][j-1] = push(mat[i][j-1]);
	if(j+1 < m)
		mat[i][j+1] = push(mat[i][j+1]);
	if(i-1 >= 0)
		mat[i-1][j] = push(mat[i-1][j]);
	if(i+1 < n)
		mat[i+1][j] = push(mat[i+1][j]);
	if(i-1 >=0 && j-1 >= 0)
		mat[i-1][j-1] = push(mat[i-1][j-1]);
	if(i-1 >= 0 && j+1 < m)
		mat[i-1][j+1] = push(mat[i-1][j+1]);
	if(i+1 < n && j-1 >= 0)
		mat[i+1][j-1] = push(mat[i+1][j-1]);
	if(i+1 < n && j+1 < m)
		mat[i+1][j+1] = push(mat[i+1][j+1]);
}


int main()
{
	int c = 1;
	while(1)
	{
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0)
			break;
			
		if(c != 1)
			printf("\n");
		char mat[n][302];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
			{
				char x;
				scanf(" %c", &x);
				mat[i][j] = x;
			}
			
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
			{
				if(mat[i][j] == '.')
					mat[i][j] = '0';
			}
			
			
			
			
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
			{
				if(mat[i][j] == '*')
					change(mat, i, j);
			}
					
		printf("Field #%d:\n", c++);
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				printf("%c", mat[i][j]);
			}
			printf("\n");
		}
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
			{
				mat[i][j] = 0;
			}
	}
	return 0;
}
