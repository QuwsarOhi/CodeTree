//UVa
//10258 - Contest Scoreboard

#include <bits/stdc++.h>

using namespace std;

typedef struct tst
{
	int solved = 0;
	int time = 0;
	int position;
	bool tried[10] = {};
	bool solv[10] = {};
	bool part = false;
}dat;

bool comp(const dat &a, const dat &b)
{
	if(a.solved != b.solved)
		return a.solved > b.solved;
	else if(a.time != b.time)
		return a.time < b.time;
	else
		return a.position < b.position;
}

int main()
{
	register int t;
	scanf("%d\n", &t);
	while(t--)
	{
		dat ctnt[101];
		for(register int i = 1; i < 101; i++)
			ctnt[i].position = i;
		string x;
		getline(cin, x);
		while(isdigit(x[0]))
		{
			stringstream ss;
			ss << x;
			ss >> x;
			int c = stoi(x);
			ss >> x;
			int p = stoi(x);
			ss >> x;
			int t = stoi(x);
			ss >> x;
			ctnt[c].part = true;
			if(x[0] == 'I')
				ctnt[c].tried[p] = true;
			else if(x[0] == 'C')
			{
				if(ctnt[c].tried[p] && !ctnt[c].solv[p])
				{
					ctnt[c].time += t + 20;
					ctnt[c].solved++;
				}
				else if(ctnt[c].tried && !ctnt[c].solv[p])
				{
					ctnt[c].tried[p] = true;
					ctnt[c].time += t;
					ctnt[c].solved++;
				}
				
				ctnt[c].solv[p] = true;
				//cout << c << " solved " << ctnt[c].solved << endl;
			}
			getline(cin, x);
		}
		sort(ctnt+1, ctnt+101, comp);
		for(register int i = 1; i <= 100; i++)
		{
			if(ctnt[i].part)
				printf("%d %d %d\n", ctnt[i].position, ctnt[i].solved, ctnt[i].time);
		}
		if(t != 0)
			printf("\n");
		
	}
	return 0;
}
