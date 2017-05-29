
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
	register int i, j, tmp;
	register int d[6][6] = { {0, 1, 2, 3, 4, 5}, {1, 5, 2, 3, 0, 4}, {2, 1, 5, 0, 4, 3}, {3, 1, 0, 5, 4, 2},
    {4, 0, 2, 3, 5, 1}, {5, 4, 2, 3, 1, 0} };
	char t[10], m[10];
	bool found;
	wh(sf(" %c%c%c%c%c%c%c%c%c%c%c%c", &t[0], &t[1], &t[2], &t[3], &t[4], &t[5], &m[0], &m[1], &m[2], &m[3], &m[4], &m[5]) != EOF) {
		found = 0;
	for(i = 0; i < 6; i++) {
		for(j = 0; j < 4; j++) {
			tmp = d[i][1];
			d[i][1] = d[i][2];
			d[i][2] = d[i][4];
			d[i][4] = d[i][3];
			d[i][3] = tmp;
			if(t[0] == m[d[i][0]] && t[1] == m[d[i][1]] && t[2] == m[d[i][2]] && t[3] == m[d[i][3]] && t[4] == m[d[i][4]] && t[5] == m[d[i][5]]) {
				found = 1;
				break;
			}
		}
		if(found) break;
	}
	if(found) pf("TRUE\n");
	else pf("FALSE\n");
	}
	return 0;
}
