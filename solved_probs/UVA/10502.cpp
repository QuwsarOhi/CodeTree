//UVa
//10502 - Counting Rectangles
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
#define inf std::numeric_limits<int>::max()

using namespace std;

int main()
{
	register int n, m, cnt, num;
	int A[110][110];
	while(sf(" %d", &n) && n)
	{
		sf(" %d", &m);
		cnt = 0;
		fr(i, 0, n)
			fr(j, 0, m)
			{
				sf(" %1d", &A[i][j]);
				if(i > 0) A[i][j] += A[i-1][j];
				if(j > 0) A[i][j] += A[i][j-1];
				if(i > 0 && j > 0) A[i][j] -= A[i-1][j-1];
				//pf("%d %d\n", i, j);
			}
		fr(i, 0, n)
			fr(j, 0, m)
			{
				//pf("*");
				if(A[i][j])
				fr(k, i, n)
					fr(l, j, m)
					{
						num = A[k][l];
						if(i > 0) num -= A[i-1][l];
						if(j > 0) num -= A[k][j-1];
						if(i> 0 && j > 0) num += A[i-1][j-1];
						if(num == ((abs(i-k)+1) * (abs(j-l)+1)))
							cnt++;
					}
			}
		pf("%d\n", cnt);
	}
	return 0;
}
