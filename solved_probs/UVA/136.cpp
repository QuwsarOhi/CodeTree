//UVa
//136 - Ugly Numbers
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

ll mem[8000];

inline void gen()
{
	priority_queue<ll, vector<ll>, greater<ll> > pq;
	priority_queue<ll, vector<ll>, greater<ll> >q;
	ll qa[6];
	pq.push(1);
	pq.push(2);
	pq.push(3);
	pq.push(5);
	q.push(2);
	q.push(3);
	q.push(5);
	map<ll, int> mc;
	register int i = 1, r, l;
	ll tmp;
	for(; i < 5840; i++)
	{
		l = 0;
		if(mc[tmp = 2*q.top()] == 0)
		{
			pq.push(tmp);
			mc[tmp]++;
			qa[l++] = tmp;
		}
		if(mc[tmp = 3*q.top()] == 0)
		{
			pq.push(tmp);
			mc[tmp]++;
			qa[l++] = tmp;
		}
		if(mc[tmp = 5*q.top()] == 0)
		{
			pq.push(tmp);
			mc[tmp]++;
			qa[l++] = tmp;
		}
		q.pop();
		for(r = 0; r < l; r++)
			q.push(qa[r]);
	}
	i = 1;
	mc.clear();
	while(!pq.empty())
	{
		mem[i++] = pq.top();
		pq.pop();
	}
}


int main()
{
	gen();
	pf("The 1500'th ugly number is %lld.\n", mem[1500]);
	return 0;
}
