#include <stdio.h>

int main()
{
    int input, out, in;
    unsigned int copy;
    
    out = 1;
    
    while(scanf("%d", &input) != EOF)
    {
		copy = 1;
		in = 0;
		
		if(input < 0)
		    break;
		    
		while(input > copy)
		{
			copy = copy * 2;
			in++;
		}
		
		printf("Case %d: %d\n", out, in);
		out++;
	}
	
	return 0;
}
