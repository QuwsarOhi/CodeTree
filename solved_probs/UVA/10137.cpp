//UVa
//10137 - The Trip
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

using namespace std;

int main()
{
	int t, ct;
	double arr[1010], sum, avg, n, p;
	wh(sf("%d", &t) && t)
	{
		sum = ct = p = n = 0;
		fr(c, 0, t)
		{
			sf(" %lf", &arr[c]);
			if(((int)(arr[c]*100))%10 > 0)
				ct++;
			sum+=arr[c];
		}
		avg = sum / t;
		fr(c, 0, t)
		{
			double d = arr[c] - avg;
			d = ((long)(d*100))/100.0;
			if(d > 0)
				p+= d;
			else
				n+= d;
		}
		n *= -1;
		//pf("%.2lf  %.2lf\n", n, p);
		if(n > p)
			pf("$%.2lf\n", n);
		else
			pf("$%.2lf\n", p);
	}
	return 0;
}
