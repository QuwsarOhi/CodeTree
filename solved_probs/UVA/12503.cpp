//UVA
//12503 - Robot Instructions

#include <bits/stdc++.h>

using namespace std;

int main()
{
	register int t;
	scanf(" %d", &t);
	getchar();
	while(t--)
	{
		int n, p = 0;
		vector<string>vec;
		scanf(" %d", &n);
		getchar();
		while(n--)
		{
			string x, y;
			stringstream s;
			getline(cin, x);
			vec.push_back(x);
			s << x;
			while(s >> y)
			{
				if(y.compare("LEFT") == 0)
					p--;
				else if(y.compare("RIGHT") == 0)
					p++;
				else if(isdigit(y[0]))
				{
					s.clear();
					int a = stoi(y);
					s << vec[a-1];
				}
				else
					y.clear();
			}
		}	
		printf("%d\n", p);
	}
	return 0;
}
