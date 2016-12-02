//UVa
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=3644&mosmsg=Submission+received+with+ID+18038632
//1203 - Argus

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pr;

class compare
{
	public:
	bool operator() (const pr& a, const pr& b)
	{
		if(a.second != b.second)
		{
			//cout << a.second << "  " << b.second << endl;
			return(a.second > b.second);
		}
		else
		{
			return(a.first > b.first);
		}
	}
};

int main()
{
		char input[12];
		register int a, b, counter = 0;
		
		char x[9];
		strcpy(x, "Register");
		char y[2];
		strcpy(y, "#");
		vector<pr> reg;
		while(scanf("%s", input) != EOF)
		{
			//printf("running\n");
			//printf("running\n");
			//printf("%s\n", x);
			if(strcmp(input, x) == 0)
			{
				//printf("pairing\n");
				scanf(" %d %d", &a, &b);
				reg.push_back(make_pair(a, b));
				counter++;
			}
			else if(strcmp(input, y) == 0)
			{
				//printf("getting k\n");
				scanf(" %d", &a);
				priority_queue<pr, vector<pr>, compare > store;
				for(b = 1; b <= a; b++)
					for(vector<pr>::iterator it = reg.begin(); it != reg.end(); it++)
					{
						store.push(make_pair(it->first, ((it->second)*b)));
						//cout << it->first << "  " << (it->second)*b << endl;
					}
				
				while(a--)
				{
					printf("%d\n", (store.top()).first);
					store.pop();
				}
			}
		}
		
		return 0;
}
