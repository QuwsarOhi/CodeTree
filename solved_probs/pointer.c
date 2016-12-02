# include <stdio.h>

int main()
{
	int var = 20;
	int *ip;
	int *ptr = NULL;
	
	ip = &var;
	
	printf("Address of var variable: %x\n", &var);
	
	printf("Address stored in ip variable: %x\n", ip);
	
	printf("value of *ip variable: %d\n", *ip);
	
	printf("the value of ptr is: %x\n", ptr);
	
	if(ptr)
	    printf("ptr is null");
	if(!ptr)
	    printf("ptr is NOT null ");
	
	return 0;
}
