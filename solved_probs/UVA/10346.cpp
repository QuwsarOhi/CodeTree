//UVa
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=1287&mosmsg=Submission+received+with+ID+18012551
//10346 - Peter's Smokes
#include <bits/stdc++.h>

using namespace std;

int smoked;

void counter(int new_cig, int make, int buds)
{
	//cout << new_cig << " " << make << " " << buds << endl;
	if(buds / make)
		new_cig += (buds/make);
	
	if(new_cig)
	{
		smoked += new_cig;
		
		if(new_cig == 0)
			return;
		counter(new_cig/make, make, (new_cig%make)+(buds%make));
	}
}

int main()
{
	int x, y;
	while(scanf("%d%d", &x, &y) != EOF)
	{
		smoked = 0;
		counter(x, y, 0);	
		printf("%d\n", smoked);
	}
	return 0;
}
