//UVa
//489 - Hangman Judge
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
#define inf std::numeric_limits<int>::max()
#define ll long long
#define N 27;

using namespace std;

int main()
{
	int ch[27], n, life, point, var, len;
	bool dead;
	char r[1000], a[1000];
	wh(sf("%d", &n) && n >= 0)
	{
		map<char, int>track;
		map<char, int>wrong;
		pf("Round %d\n", n);
		life = 7;
		dead = 0;
		point = 0;
		memset(ch, 0, sizeof(ch));
		memset(r, 0, sizeof(r));
		memset(a, 0, sizeof(a));
		sf(" %s", r);
		sf(" %s", a);
		len = strlen(r) - 1;
		set<char>st (r, r+len+1);
		var = st.size();
		st.clear();
		//pf("len = %d\n", len);
		//pf("var = %d\n", var);
		for(int i = 0; i <= len; i++)
		{
			//pf("%c", r[i]);
			ch[(int)r[i] - 'a']++;
		}
		//pf("\n");
		len = strlen(a) - 1;
		for(int i = 0; i <= len; i++)
		{
			if(ch[(int)a[i]- 'a'] > 0)
			{
				if(track[a[i]]++ == 0)
					++point;
				ch[(int)a[i]] = 0;
			}
			else
			{
				if(wrong[a[i]]++ == 0)
					--life;
			}
			if(point == var)
				break;
			if(life == 0)
			{
				dead = 1;
				break;
			}
		}
		//pf("point : %d\nlife : %d\n", point, life);
		if(dead)
			pf("You lose.\n");
		else if(point == var)
			pf("You win.\n");
		else
			pf("You chickened out.\n");
	}
	return 0;
}
	
