//Codeabbey
//Url: http://www.codeabbey.com/index/task_view/vowel-count
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	register int t, a, e, i, o, u, y;
	char mem[100];
	cin >> t;
	//getchar(); is not needed because of sync_with_stdio;
	while(t--)
	{
		fgets(mem, 90, stdin);
		puts(mem);
		int len = strlen(mem)+1;
		a = count(mem, mem+len, 'a');
		e = count(mem, mem+len, 'e');
		i = count(mem, mem+len, 'i');
		o = count(mem, mem+len, 'o');
		u = count(mem, mem+len, 'u');
		y = count(mem, mem+len, 'y');
		cout << a+e+i+o+u+y << " ";
	}
	return 0;
}
