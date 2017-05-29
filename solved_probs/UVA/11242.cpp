//UVa
//11242 - Tour de France

#include <bits/stdc++.h>
#define pb push_back
#define sp(b) if(!b)printf("\n"); b = false;
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define f1(i, b) for(register int i = 1; i <= b; i++)
#define ss stringstream
#define mimx(a, b) if(a > b)swap(a, b);
#define msi map<string, int>
#define mii map<int, int>
#define vec vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;
int front[20], rear[20];
float dr[150];

int main()
{
	int f, r;
	while(scanf(" %d", &f) && f)
	{
		scanf(" %d", &r);
		fr(i, 0, f)
			scanf(" %d", &front[i]);
		fr(i, 0, r)
			scanf(" %d", &rear[i]);
		register int l = 0;
		fr(i, 0, f)
			fr(j, 0, r)
				dr[l++] = ((float)rear[j]) / ((float)front[i]);
		sort(dr, dr+l);
		float maxim = 0;
		fr(i, 0, l-1)
			maxim = max(dr[i+1]/ dr[i], maxim);
		printf("%.2f\n", (roundf(maxim*100.0))/100);
	}
	return 0;
}

