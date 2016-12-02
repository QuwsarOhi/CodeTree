//UVa
//483 - Word Scramble
#include <bits/stdc++.h>

using namespace std;

int main()
{
	string x, y;
	stringstream ss;
	while(!getline(cin, x).eof())
	{
		ss.clear();
		ss << x;
		bool first = 1;
		while(ss >> x)
		{
			if(!first)
				printf(" ");
			reverse(x.begin(), x.end());
			cout << x ;
			first = 0;
		}
		printf("\n");
	}
	return 0;
}
