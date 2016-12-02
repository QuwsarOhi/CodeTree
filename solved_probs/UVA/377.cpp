//UVa
//377 - Cowculations
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define f1(i, b) for(register int i = 1; i <= b; i++)
#define ss stringstream
#define mimx(a, b) if(a > b)swap(a, b)
#define msi map<string, int>
#define mii map<int, int>
#define vec vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sf scanf
#define pf printf
#define wh while
#define ll long long

using namespace std;

int main()
{
	map<char, int>m;
	char a1[10], a2[15], w;
	int i, p, num, con, t, c;
	bool first = true;
	m['V'] = 0, m['U'] = 1, m['C'] = 2, m['D'] = 3;
	sf("%d", &t);
	wh(t--)
	{
		sf(" %s", a1);
		sf(" %s", a2);
		p = num = con = 0;
		c = 3;
		for(i = 4; i >= 0; i--)
		{
			num+= m[a1[i]] * (pow(4, p));
			con+= m[a2[i]] * (pow(4, p++));
		}
		wh(c--)
		{
			sf(" %c", &w);
			if(w == 'A')
				con+=num;
			else if(w == 'L')
				con *= 4;
			else if(w == 'R')
				con /= 4;
		}
		p = 0;
		sf(" %s", a2);
		num = 0;
		for(i = 7; i >= 0; i--)
			num += m[a2[i]] * (pow(4, p++));
		if(first)
		{
			pf("COWCULATIONS OUTPUT\n");
			first = false;
		}
		if(num == con)
			pf("YES\n");
		else
			pf("NO\n");
		if(t==0)
			pf("END OF OUTPUT\n");
	}
	return 0;
}

