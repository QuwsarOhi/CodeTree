//Codechef Biggener
//Url: https://www.codechef.com/problems/COMM3

#include <cstdio>

int r, x[3], y[3];

int check(int i, int j)
{
	return ((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) <= r*r);
}


int main()
{
	register int t;
	for(scanf("%d", &T); T--; )
	{
		scanf("%d %d %d %d %d %d %d", &r, x, y, x+1, y+1, x+2, y+2);
		int p = check(0, 1) + check(1, 2) + check(0, 2);
		puts(p >= 2 ? "yes":"no");
	}
	return 0;
}
