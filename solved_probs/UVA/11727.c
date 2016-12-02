#include <stdio.h>

int survivor(int x, int y, int z)
{
	if(x > y)
	{
		if(x > z)
		{
			if(y > z)
			return y;
			
			else
			return z;
		}
		
		else
		{
			if(x > y)
			return x;
			
			else
			return y;
		}
	}
	
	else
	{
		if(y > z)
		{
			if(x > z)
			return x;
			
			else
			return z;
		}
		
		else
		{
			if(x > y)
			return x;
			
			else
			return y;
			
		}	
	}
}

int main()
{
	int i, j, x, y, z, ans;
	
	scanf("%d", &j);
	
	for(i=1; i <= j; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		ans = survivor(x, y, z);
		printf("Case %d: %d\n", i, ans);
	}
	
	return 0;
	
}
