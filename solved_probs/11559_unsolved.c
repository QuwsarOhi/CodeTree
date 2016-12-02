#include <stdio.h>

int main()
{
	int hotel_number, weeks, people, budget, i, j;
	int hotel_weeks[15], hotel_flag = 0, weekend_price[20], cost_memory, cost;
	
	scanf("%d %d %d %d", &people, &budget, &hotel_number, &weeks);
	
	for(i=0; i < hotel_number; i++)
	{
		scanf("%d", &weekend_price[i]);
		
		for(j=0; j<weeks; j++)
		{
			scanf("%d", &hotel_weeks[j]);
			if(hotel_weeks[j] >= people)
			{
				
				cost = people * weekend_price[i];
				
				if(cost < cost_memory && hotel_flag == 1)
					cost_memory = cost;
					
				else if(hotel_flag == 0)
					cost_memory = cost;
				
				hotel_flag = 1;
			}
		}	
	}
	
	if(hotel_flag == 1 && cost_memory <= budget)
		printf("%d\n", cost_memory);
	else
		printf("stay home\n");
		
	return 0;
}
