//UVa
//665 - False coin

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf(" %d", &t);
	while(t--)
	{
		int c, n;
		scanf(" %d %d", &c, &n);
		bool original[c+2] = {};
		//cout << "c is " << c << " n is " << n << endl;
		while(n--)
		{
			int l;
			scanf(" %d", &l);
			//cout << "got l" << endl;
			int arr[2*l];
			for(register int i = 0; i < 2*l; i++)
				scanf(" %d", &arr[i]);
			char x;
			scanf(" %c", &x);
			if(x == '=')
				for(register int i = 0; i < 2*l; i++)
					original[arr[i]] = true;
		}
		//cout << "got all value" << endl;
		int place = 0;
		//cout << "c is " << c << endl;
		for(register int i = 1; i < c+1; i++)
		{
			//cout << i << "  " << original[i] << endl;
			if(!original[i] && !place)
				place = i;
			else if(!original[i] && place)
			{
				//cout << "* " << i << endl;
				place = 0;
				break;
			}
			//cout << "place : " << place << endl;
		}
		if(place)
			printf("%d\n", place);
		else
			printf("0\n");
		if(t != 0)
			printf("\n");
	}
	return 0;
}
