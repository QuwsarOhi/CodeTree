//UVa
//11507 - Bender B. Rodríguez Problem

#include <bits/stdc++.h>

using namespace std;

void xaxis_p(string n, string *p)
{
	if(n.compare("+y"))
		*p = "+y";
	else if(n.compare("-y"))
		*p = "-y";
	else if(n.compare("NO"))
		return;
	else if(n.compare("+z"))
		*p = "+z";
	else if(n.compare("-z"))
		*p = "-z";
}

int main()
{
	int l;
	while(scanf(" %d", &l) && l)
	{
		getchar();
		//cout << "ok" << endl;
		stringstream s;
		string p = "+x", n;
		getline(cin, n);
		s << n;
		//cout << n << endl;
		while(s >> n)
		{
			//cout << n << endl;
			if(!n.compare("No"))
				continue;
			else if(!p.compare("+x"))
				p = n;
			else if(!p.compare("+y"))
			{
				if(!n.compare("-z"))
					p = "+y";
				else if(!n.compare("+z"))
					p = "+y";
				else if(!n.compare("-y"))
					p = "+x";
				else if(!n.compare("+y"))
					p = "-x";
			}
			else if(!p.compare("-y"))
			{
				if(!n.compare("+z") || !n.compare("-z"))
					continue;
				else if(!n.compare("-y"))
					p = "-x";
				else if(!n.compare("+y"))
					p = "+x";
			}
			else if(!p.compare("+z"))
			{
				if(!n.compare("-y") || !n.compare("+y"))
					continue;
				else if(!n.compare("+z"))
					p = "-x";
				else if(!n.compare("-z"))
					p = "+x";
			}
			else if(!p.compare("-z"))
			{
				if(!n.compare("+y") || !n.compare("-y"))
					continue;
				else if(!n.compare("-z"))
					p = "-x";
				else if(!n.compare("+z"))
					p = "+x";
			}
			else if(!p.compare("-x"))
			{
				if(!n.compare("+y"))
					p = "-y";
				else if(!n.compare("-y"))
					p = "+y";
				else if(!n.compare("-z"))
					p = "+z";
				else if(!n.compare("+z"))
					p = "-z";
			}
		}
		cout << p << endl;
	}
	return 0;
}
