#include <iostream>
#include <vector>
#include <limits>

using namespace std;
	
vector< int >chimps;
vector< int >lunchs;
int det;

int least_tall(int lunch, int last)
{
	int first=0, mid, hi_mem = -1;
	--last;
	
	while(first<=last)
	{
		mid = (last+first)/2;
	
		if(chimps[mid] < lunch && chimps[mid] > hi_mem)
			hi_mem = chimps[mid];
		
		if(chimps[mid]>=lunch)
			last = mid-1;
		
		else
			first = mid+1;
			
	}
	
	return hi_mem;	
	
}

int high_tall(int lunch, int last)
{
	int first = 0, mid;
	--last;
	
	int low_mem = numeric_limits< int >::max();
	det = low_mem;
	
	while(first<=last)
	{
		mid = (first+last)/2;
		
		if(chimps[mid] > lunch && chimps[mid] < low_mem)
			low_mem = chimps[mid];
		
		if(chimps[mid] > lunch)
			last = mid - 1;
			
		else
			first = mid + 1;
	}
	
	return low_mem;
}

void printer(int x, int y)
{
	if(x == -1 && y == det)
		cout << "X" << " " << "X" << endl;
	else if(x == -1)
		cout << "X" << " " << y << endl;
	else if(y == det)
		cout << x << " " << "X" << endl;
	else
		cout << x << " " << y << endl;
	
}


int main()
{
	int chimp_inpt, chimp;
	int lunch_inpt, lunch;
	int x, y;
	
	cin >> chimp;
	
	for(int i = 0; i<chimp; i++)
	{
		cin >> chimp_inpt;
		chimps.push_back(chimp_inpt);
	}

	cin >> lunch;
	
	for(int i = 0; i < lunch; i++)
	{
		cin >> lunch_inpt;
		lunchs.push_back(lunch_inpt);
	}
	
	for(int i = 0; i < lunch; i++)
	{
		x = least_tall(lunchs[i], chimp);
		y = high_tall(lunchs[i], chimp);
		
		printer(x, y);
	}
	
	return 0;
	
}
