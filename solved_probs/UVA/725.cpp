//UVa
//725 - Division

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	bool first = true;
	while(scanf(" %d", &n) && n)
	{
		if(!first)
			printf("\n");
		first = false;
		bool found = false;
		int lim = 98765/n;
		for(register int i = 1234; i <= lim; i++)
		{
			int num = n * i;
			bitset<10>bit;
			if(i < 10000)
				bit.set(0);
			int tmp = num;
			while(tmp)
			{
				bit.flip(tmp%10);
				tmp/=10;
			}
			tmp = i;
			while(tmp)
			{
				bit.flip(tmp%10);
				tmp/=10;
			}
			//cout << num << "  " << i << endl;
			//cout << bit << endl;
			if(bit.all())
			{
				found = true;
				printf("%.5d / %.5d = %d\n", num, i, n);
			}
		}
		if(!found)
			printf("There are no solutions for %d.\n", n);
	}
	return 0;
}
