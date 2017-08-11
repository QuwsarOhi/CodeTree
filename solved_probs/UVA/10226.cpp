//UVa
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1167
//10226 - Hardwood Species

#include <bits/stdc++.h>

using namespace std;

int main()
{
	register int t;
	scanf("%d", &t);
	getchar();
	getchar();
	register int count;
	while(t--)
	{
		map<string, int> store;
		char input[40];
		count = 0;
		while(fgets(input, 39, stdin))
		{
			if(input[0] == '\n')
			{
				//cout << "break" << endl;
				break;
			}
			input[strlen(input)-1] = 0;
			if(store.find(string(input)) == store.end())
			{
				store[string(input)] = 1;
			}
			else
				store[string(input)] += 1;
			count++;
		}
		
		for(map<string, int>::iterator it = store.begin(); it != store.end(); it++)
		{
			printf("%s %.4lf\n", (*it).first.data(), (((double)(*it).second/(double)count)*100));
		}
		if(t != 0)
			cout << "\n";
	}
	return 0;
}
