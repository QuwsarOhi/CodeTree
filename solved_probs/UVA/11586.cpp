//UVa
//11586 - Train Tracks

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf(" %d", &t);
	getchar();
	while(t--)
	{
		bool loop = true;
		map<string, int>mp;
		stringstream s;
		string x;
		getline(cin, x);
		s << x;
		while(s >> x)
			mp[x]++;
		if(abs(mp["MM"] - mp["FF"]) != 0)
			loop = false;
		else if(mp["MF"] && mp["FM"] && !mp["MM"] && !mp["FF"])
			loop = false;
		else if(mp["MF"] == 1 && mp["FM"] == 0 && mp["FF"] == 0 && mp["MM"] == 0)
			loop = false;
		else if(mp["MD"] == 0 && mp["FM"] == 1 && mp["FF"] == 0 && mp["MM"] == 0)
			loop = false;
		if(loop)
			printf("LOOP\n");
		else
			printf("NO LOOP\n");
	}
	return 0;
}
