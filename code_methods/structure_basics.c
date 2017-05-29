#include <stdio.h>
struct Distance{
    int feet;
    float inch;
}d1,d2,sum;

typedef struct Complex
{
	char name[80];
	int age;
	struct Distance dis;
}comp;



int main(){
	
	comp person[2] = {
		{"Test", 12}
		};
	
    printf("1st distance\n");
    printf("Enter feet: ");
    scanf("%d",&d1.feet);  /* input of feet for structure variable d1 */
    printf("Enter inch: ");
    scanf("%f",&d1.inch);  /* input of inch for structure variable d1 */
    printf("2nd distance\n");
    printf("Enter feet: ");
    scanf("%d",&d2.feet);  /* input of feet for structure variable d2 */
    printf("Enter inch: ");
    scanf("%f",&d2.inch);  /* input of inch for structure variable d2 */
    sum.feet=d1.feet+d2.feet;
    sum.inch=d1.inch+d2.inch;
    if (sum.inch>12){  //If inch is greater than 12, changing it to feet.
        ++sum.feet;
        sum.inch=sum.inch-12;
    }
    printf("Sum of distances=%d\'-%.1f\"",sum.feet,sum.inch);
    printf("\n");
    
    printf("Enter name and age :\n");
    scanf("%s %d", person[1].name, &person[1].age);
    printf("%s %d\n", person[0].name, person[0].age);
    printf("%s %d\n", person[1].name, person[1].age);
/* printing sum of distance d1 and d2 */
    return 0;
}
