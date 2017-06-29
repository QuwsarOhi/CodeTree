/* Well-Commented code
 * This code is same as yours
 * only modified some lines which needed to
 */
 
#include <stdio.h>

struct table {			// Making a new data type named 'table'
	char name[20];
	char dept[20];
	char phone[15];
};


int main() {
	FILE *y;							// A file pointer
	y = fopen("pappu.txt", "w"); 		// Linking file pointer to a file with WRITE permission
	
	struct table a[10];					// An array of 'table' data type
	int i, j;
	char d;
	
	for(i = 0; i < 5; i++) {			// The input loop, this takes input and prompts user if he/she is done (takes five input), note: The loop will break when i == 5
		printf("Enter your nickname (within 10 characters): ");
		scanf(" %[^\n]", a[i].name);	// Now scanf can get input of space seperated name ex: "Bangla Desh"
		printf("Enter your department name in short: ");
		scanf(" %s", a[i].dept);
		printf("Enter your phone number: ");
		scanf(" %s", a[i].phone);
		
		// Main Break Points in input loop
	
		if(i != 4) {					// This loop will normally end when i == 4, no need to ask then
			printf("Are you done? (type y/n)\n");
			scanf(" %c", &d);
			if(d == 'Y' || d == 'y')	// Upper-case & lower-case support
				break;
		}
		else 							// If five inputs are done then i == 4, the loop will normally break, just warning the user
			printf("Five inputs given\nExiting.....");
	}
	
	// The user may not give five inputs
	// If the user gives 2 inputs then the last value of i would be 1,  {0 : first_input, 1 : second_input, break}
	// So, run a loop from 0 to i, this will avoid garbage values in file
	
	// Another problem
	// Suppose the user inputs five values, in the last moment, the value of i would be 5
	// and the input loop will break {0: first_input, ..... .. ., 4: fifth_input, 5 : break in for loop }
	
	// So, i need to handle two cases
	// If the user didn't inputs five data, then run a loop from 0 to j
	// if the user inputs five datas then run the loop from 0 to 4, i == 5 is the breaking point, no data is taken then (in input loop)
	// I think this was the last problem that u were facing in pappu.txt file, it was due to this issue
	
	// Now the file input loop
	
	for(j = 0; j <= i && j < 5; j++)		// Try to understand the condition, It might look tricky
		fprintf(y, "Name: %s Dept: %s Phone: %s\n", a[j].name, a[j].dept, a[j].phone);

	fclose(y);			// Close the file, otherwise it will cause data leaking
	
	return 0;
}
