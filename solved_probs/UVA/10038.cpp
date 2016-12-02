//UVa
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=979&mosmsg=Submission+received+with+ID+17968831
//Jolly Jumper 10038

#include <bits/stdc++.h>

using namespace std;

int main()
{
	register int n;
	while(scanf("%d", &n) != EOF)
	{
		set <int> con;
		register int i;
		bool tru = true;
		int x, y;
		for(i = 0; i < n; i++)
		{
			scanf("%d", &x);
			if(i == 0)
				y = x;
			else
			{
				con.insert(abs(x-y));
				y = x;
			}	
		}
		
		if(con.count(0) != 0)
			tru = false;
		if(con.size() != (n-1))
			tru = false;
		if(con.upper_bound(n-1) != con.end())
			tru = false;
		if(tru)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}
	return 0;
}
