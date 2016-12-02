#include <iostream>
#include <cstdio>

inline void fastRead(int *a)

{
 register char c=0;
 while (c<33)
 {
	 printf("in c<33\n");
	 c=getchar_unlocked();
 }
 *a=0;
 while (c>33)
 {
	 printf("in c>33\n");
     *a=*a * 10 + c-'0';
     c=getchar_unlocked();
 }
 
 printf("breaking\n");
}

int main()
{
	int x, i = 5;
	
	while(i--)
	{
		fastRead(&x);
		printf("value %d\n", x);
	}
	
	return 0;

}
