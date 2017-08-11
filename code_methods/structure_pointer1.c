#include <stdio.h>

struct Test_name
{
	char name[80];
	int age;	
};

int main()
{
	struct Test_name *ptr, p;
	
	ptr = &p;
	
	printf("Enter name : ");
	scanf("%s", (*ptr).name); //or use ptr->name//
	printf("Enter age : "); 
	scanf("%d", &(*ptr).age);  //or use ptr->age//
	printf("Displaying Using Pointer: \n");
	printf("name : %s \nage : %d\n", (*ptr).name, (*ptr).age);
	printf("Displaying Without Pointer: \n");
	printf("name : %s \nage : %d\n", p.name, p.age);
	
	return 0;	
}
