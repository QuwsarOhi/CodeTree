//UVa
//467 - Synching Signals

#include <bits/stdc++.h>

using namespace std;

struct light
{
	int time;
	int g_time = 0;
	int run = 0;
	bool green = true;
};

int main()
{
	int set = 1;
	string x;
	while(!getline(cin, x).eof())
	{
		stringstream s;
		light l[10];
		register int c= 0;
		s << x;
		while(s >> x)
		{
			l[c].g_time = stoi(x) - 5;
			l[c].time = stoi(x) + l[c].g_time + 5;
			l[c].run = l[c].g_time;
			c++;
		}
		register int t = 1;
		bool got, first = true;
		for(; t <= 3600; t++)
		{
			got = true;
			for(register int i = 0; i < c; i++)
			{
				if(l[i].run)
					--l[i].run;
				if(t % l[i].time == 0 && !l[i].run)
				{
					l[i].green = true;
					l[i].run = l[i].g_time;
				}
				else if(!l[i].run)
					l[i].green = false;
			}
			for(register int i = 0; i < c; i++)
			{
				if(!l[i].green)
				{
					first = false;
					got = false;
				}
			}
			if(got && !first)
				break;
		}
		if(got)
			printf("Set %d synchs again at %d minute(s) and %d second(s) after all turning green.\n", set, t/60, t%60);
		else
			printf("Set %d is unable to synch after one hour.\n", set);
		set++;
	}
	return 0;
}
