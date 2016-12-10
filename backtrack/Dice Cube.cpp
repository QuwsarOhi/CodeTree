
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
#define N 9876543210
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;

int main()
{
	register int i, k, cnt = 0, tmp;
	register int d[6][6] = { {0, 1, 2, 3, 4, 5}, {1, 2, 0, 5, 3, 4}, {2, 0, 1, 4, 5, 3}, {5, 4, 3, 1, 2, 0}, {4, 3, 0, 2, 5, 1}, {3, 5, 1, 0, 4, 2}};
	for(i = 0; i < 6; i++) {
			for(k = 0; k < 4; k++) {
				tmp = d[i][1];
				d[i][1] = d[i][2];
				d[i][2] = d[i][4];
				d[i][4] = d[i][3];
				d[i][3] = tmp;
				pf("%d %d %d %d %d %d\n", d[i][0], d[i][1], d[i][2], d[i][3], d[i][4], d[i][5]);
				cnt++;
			}
	}
	pf("%d iterations done.\n", cnt);
	return 0;
}
