/*
Title: STRLCP
Data: 2011-4-21
*/

#include <bits/stdc++.h>

#define InputFileName		"STRLCP.in"
#define OutputFileName		"STRLCP.out"
#define Max(a, b)			(a > b ? a : b)

using namespace std;

const int MaxN = 260000;
long long HashMod = 110118553, HashMul = 131;

int n, q, Son[MaxN][2], Father[MaxN], Size[MaxN], Total;
char a[MaxN], cmd, Data[MaxN];
long long Hash[MaxN], Power[MaxN];

inline void Update(const int t)
{
	Size[t] = Size[Son[t][0]]+Size[Son[t][1]]+1;
	Hash[t] = (Hash[Son[t][0]]+Power[Size[Son[t][0]]]*(long long)Data[t]+Power[Size[Son[t][0]]+1]*Hash[Son[t][1]]) % HashMod;
}

void Build(int &t, const int f, const int l, const int r)
{
	const int mid = l+r >> 1;
	Data[t = ++Total] = a[mid];
	Father[t] = f;
	if (l < mid)
		Build(Son[t][0], t, l, mid-1);
	else
		Son[t][0] = 0;
	if (mid < r)
		Build(Son[t][1], t, mid+1, r);
	else
		Son[t][1] = 0;
	Update(t);
}

void Rotate(const int t, const int p)
{
	const int f = Father[t];
	Father[t] = Father[f];
	Son[Father[t]][Son[Father[f]][1] == f] = t;
	Father[Son[t][! p]] = f;
	Son[f][p] = Son[t][! p];
	Father[f] = t;
	Son[t][! p] = f;
	Update(f);
	Update(t);
}

void Splay(const int t, const int Root)
{
	for (int f, p, q; (f = Father[t]) != Root;)
	{
		p = Son[f][1] == t;
		q = Father[f] == Root ? -1 : (Son[Father[f]][1] == f);
		Rotate(p == q ? f : t, p);
		if (q >> 1)
			break;
		Rotate(t, q);
	}
}

int Query(int t, int k)
{
	while (1)
		if (Size[Son[t][0]]+1 == k)
			return t;
		else if (k <= Size[Son[t][0]])
			t = Son[t][0];
		else
		{
			k -= Size[Son[t][0]]+1;
			t = Son[t][1];
		}
}

void GetSeg(const int x, const int y)
{
	Splay(Query(Son[1][0], x), 1);
	Splay(Query(Son[1][0], y+2), Son[1][0]);
}

int main()
{
	//#ifndef ONLINE_JUDGE
	//freopen(InputFileName, "r", stdin);
	//freopen(OutputFileName, "w", stdout);
	//#endif
    //freopen("out", "w", stdout);
	Power[0] = 1;
	for (int i = 1; i < MaxN; ++i)
		Power[i] = Power[i-1]*HashMul % HashMod;
	int TestCase;
    scanf("%d\n", &TestCase);
	while(TestCase--)
	{
		Total = 1;
		scanf("%s", (a+1));
		for (n = 1; a[n]; ++n);
		scanf("%d\n", &q);
		Build(Son[1][0], 1, 0, n);
		for (int x, y; q; --q)
		{
			scanf("%c", &cmd);
			if (cmd == 'Q')
			{
				scanf("%d%d\n", &x, &y);
				int Ans = 0;
				long long p, q;
				for (int l = 1, r = Size[Son[1][0]]-Max(x, y)-1, mid = l+r >> 1; l <= r; mid = l+r >> 1)
				{
					GetSeg(x, x+mid-1);
					p = Hash[Son[Son[Son[1][0]][1]][0]];
					GetSeg(y, y+mid-1);
					q = Hash[Son[Son[Son[1][0]][1]][0]];
					p == q ? l = (Ans = mid)+1 : r = mid-1;
				}
				printf("%d\n", Ans);
			}
			else if (cmd == 'R')
			{
				scanf("%d ", &x);
				GetSeg(x, x);
				scanf("%c\n", &Data[Son[Son[Son[1][0]][1]][0]]);
				Hash[Son[Son[Son[1][0]][1]][0]] = Data[Son[Son[Son[1][0]][1]][0]];
			}
			else if (cmd == 'I')
			{
				scanf("%d %c\n", &x, &a[0]);
				GetSeg(x, x-1);
				Build(Son[Son[Son[1][0]][1]][0], Son[Son[1][0]][1], 0, 0);
			}
			if (cmd != 'Q')
			{
				Update(Son[Son[1][0]][1]);
				Update(Son[1][0]);
			}
		}
        //cerr << "DONE\n";
	}
	return 0;
}
