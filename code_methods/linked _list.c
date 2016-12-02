#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;	
};

struct node *start = NULL;

void add_first(int x)
{
	struct node *t;
	
	t = (struct node*)malloc(sizeof(struct node));
	
	if(start == NULL)
	{
		start = t;
		start->data = x;
		start->next = NULL;
		return;
	}
	
	t->data = x;
	t->next = start;
	start = t;
}

void printlist()
{
	if(start == NULL)
	{
		printf("The list is empty!");
		return;
	}
	
	struct node *t;
	t = start;
	
	while(t->next != NULL)
	{
		printf("%d\n", t->data);
		t = t->next;
	}
	printf("%d\n", t->data);
	
}

void add_last(int x)
{
	struct node *t;
	struct node *temp;
	
	t = (struct node *)malloc(sizeof(struct node));
	
	if(start == NULL)
	{
		start = t;
		start->data = x;
		start->next = NULL;
		return;
	}
	
	temp = start;
	
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	
	temp->next = t;
	t->data = x;
	t->next = NULL;

}

void append(int n, int x)
{
	int i = 1;
	int mem, mem2;
	struct node *t;
	struct node *temp;
	
	t = (struct node *)malloc(sizeof(struct node));
	
	if(start == NULL)
	{
		start = t;
		start->data = x;
		start->next = NULL;
		return;
	}
	
	temp = start;
	
	while(i<n && temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	
	mem = temp->data;
	temp->data = x;
	
	do
	{
		temp = temp->next;
		mem2 = temp->data;
		temp->data = mem;
		mem = mem2;
	}while(temp->next != NULL);
	
	temp->next = t;
	t->data = mem;
	t->next = NULL;
	
}

void delete(int x)
{
	struct node *present;
	struct node *previous;
	struct node *temp;
	
	present = start;
	
	while(present->data!= x)
	{
		previous = present;
		present = present->next;
	}
	
	temp = present;
	present = present->next;
	free(temp);
	previous->next = present;
	
}


int main()
{
	int x, n, i;
	
	printf("This is a test linked list.\n\n");
	
	while(1)
	{
		printf("press 1 to add first\npress 2 to view\npress 3 to add last\npress 4 to append\npress 5 to delete\n\n");
		scanf("%d", &n);
		if(n == 1)
		{
			printf("Enter integer data : ");
			scanf("%d", &x);
			add_first(x);
		}
		else if(n == 2)
		{
			printf("Viewing the list :\n\n");
			printlist();
		}
		else if(n == 3)
		{
			printf("Enter integer data : ");
			scanf("%d", &x);
			add_last(x);
		}
		else if(n == 4)
		{
			printf("Enter position and value :");
			scanf("%d %d", &i, &x);
			append(i, x);
		}
		else if(n == 5)
		{
			printf("Enter value to delete :");
			scanf("%d", &x);
			delete(x);
		}
		else
			continue;
	}
	
	return 0;
}
