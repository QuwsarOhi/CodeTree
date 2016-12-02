//UVA
//11559 - Event Planning
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=2595&mosmsg=Submission+received+with+ID+17963135

#include <bits/stdc++.h>

using namespace std;

bool cmp(int x, int y)
{
	return x < y;
}

int main()
{
	int p, m, h, w, dat[20], j = 0;
	while(cin >> p >> m >> h >> w)
	{
		j = 0;
		while(h--)
		{
			bool ok = false;
			int wk[15], c;
			cin >> c;
			for(register int i = 0; i < w; i++)
			{
				cin >> wk[i];
				if(wk[i] >= p)
					ok = true;
			}
			if(ok)
				dat[j++] = c;
		}
		if(j == 0)
		{
			//cout << "------------" << endl;
			cout << "stay home" << endl;
			continue;
		}
		//for(register int i = 0; i <= j; i++)
			//cout << dat[i] << "  ";
		sort(dat, dat+j, cmp);
		if(dat[0] * p <= m)
			cout << dat[0] * p << endl;
		else
			cout << "stay home" << endl;
		memset(dat, 0, 20);
		if(cin.eof())
			break;
	}
	return 0;
}
