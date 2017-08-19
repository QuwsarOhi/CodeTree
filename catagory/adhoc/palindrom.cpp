//UVa
//401 - Palindromes
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
#define N 1000000

using namespace std;

bool palin(char x, char y)
{
	if(x == y)
		return 1;
	return 0;
}

bool mirror_palin(char x, char y = '*')
{
	if(y == '*') y = x;
	if(x == y && x == 'A')
		return 1;
	else if(x == y && x == 'H')
		return 1;
	else if(x == y && x == 'I')
		return 1;
	else if(x == y && x == 'M')
		return 1;
	else if(x == y && x == 'O')
		return 1;
	else if(x == y && x == 'T')
		return 1;
	else if(x == y && x == 'U')
		return 1;
	else if(x == y && x == 'V')
		return 1;
	else if(x == y && x == 'W')
		return 1;
	else if(x == y && x == 'X')
		return 1;
	else if(x == y && x == 'Y')
		return 1;
	else if(x == y && x == '8')
		return 1;
	else if(x == y && x == '1')
		return 1;
	else
		return 0;
}

bool mirror_str(char x, char y) //changed
{
	//if(y == '*') y = x;
	if((x == '3' && y == 'E') || (x == 'E' && y == '3'))
		return 1;
	else if((x == 'J' && y == 'L') || (x == 'L' && y == 'J'))
		return 1;
	else if((x == 'S' && y == '2') || (x == '2' && y == 'S'))
		return 1;
	else if((x == 'Z' && y == '5') || (x == '5' && y == 'Z'))
		return 1;
	else if((x == 'J' && y == 'L') || (x == 'L' && y == 'J'))
		return 1;
	else if(mirror_palin(x, y))
		return 1;
	return 0;
}

int main()
{
	char a[10000];
	register int len, i, j, lim;
	wh(sf(" %s", a) != EOF) {
		bool pal = 1, mir_palin = 1, mir_str = 1, flag = 0;
		len = strlen(a) - 1;
		if((len+1)%2 != 0) flag = 1;
		lim = (len+1)/2;//(lim % 2 == 0) ? (lim/2) - 1 : lim/2;
		//pf("lim : %d\n", lim);
		for(i = 0, j = len; i < lim ; i++, j--) {
			//pf("%d %d\n", i, j);
			if(!palin(a[i], a[j])) //regular
				pal = 0;
			if(!mirror_palin(a[i], a[j])) //mirror palin
				mir_palin = 0;
			if(!mirror_str(a[i], a[j])) //mirror str
				mir_str = 0;
			}
		if(flag)
			if(!mirror_palin(a[len/2]))
				mir_palin = 0;
		if(mir_str && !pal)
			pf("%s -- is a mirrored string.\n\n", a);
		else if(mir_palin)
			pf("%s -- is a mirrored palindrome.\n\n", a);
		else if(pal)
			pf("%s -- is a regular palindrome.\n\n", a);
		else
			pf("%s -- is not a palindrome.\n\n", a);
	}
	return 0;
}
