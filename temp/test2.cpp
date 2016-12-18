
#include <bits/stdc++.h>
#define pb push_back
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

//(a+b)%m = ((a%m) + (b%m))%m
//(a*b)%m = ((a%m) * (b%m))%m

inline ull odd(ull n)
{
	return (n & 1);
}

inline ull powmod(ull n, ull p, ull m)
{
	if(p == 0) return 1;
	if(!odd(p)) {
		ull tmp = powmod(n, p/2, m)%m;
		return (tmp*tmp)%m;
	}
	else return ((n%m)*(powmod(n, p-1, m)%m))%m;
}

inline ull plusmod(ull x, ull y, ull m)
{
	return ((x%m)+(y%m))%m;
}

