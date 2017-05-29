#include <iostream>

using namespace std;

/*
Binary Indexed Tree(BIT)

works something like this, 13 = 2pow(3) + 2pow(2) + 1

read function goes to the node that is called (exmpl: read(12)), then jumps to the upper 2 power nodes(if the number(here 12) is even)
if the number is odd then it jumps the parent even node then jumps to the 2 power nodes it works untill the idx is not 0

index	 	1		 2	 	3	 	4	 	5	 	6	 	7	 	8	 	9	 	10		 11		 12

array      1st	  1 to 2   3rd    1 to 4   5th 	  5 to 6   7th	  1 to 8   9th    9 to 10   11th   9 to 12  
sum 

the update function is used to create the binary index nodes(tree), also can be used to update the nodes while code is running
the function takes the value and position, and increments the value with the position of the bit and next goes to the other child
nodes(power of 2 and the last node if it is even) and increments it by the value


*/


//         1  2  3  4  5  6  7  8  9 10 11 12
int x[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
int tree[10];

int read(int idx)
{
	int sum = 0;
	
	while(idx > 0)
	{
		cout << idx << endl;
		sum += tree[idx];
		idx -= (idx & (-idx));
	}
	
	return sum;
}

void update(int idx, int val, int MaxVal)
{
	idx++; //As BIT can't work with 0 value, the 0 is avoided by incrementing 1
	while(idx <= MaxVal)
	{
		tree[idx] += val;
		cout << "value : " << val << " tree: " << idx << "--> " << tree[idx] << endl;
		idx += (idx & (-idx));
	}
	
	cout << "ending\n" << endl;
}

int main()
{
	for(int i = 0; i < 12; i++)
		update(i, x[i], 12);
		
	for(int i = 0; i < 13; i++)
		cout << tree[i] << endl;
		
	cout << "--------------" << endl;
	cout << read(11) << endl;
		
	return 0;
}
