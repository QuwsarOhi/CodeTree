//UVa
//443 - Humble Numbers
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
	pq.push(7);
	q.push(2);
	q.push(3);
	q.push(5);
	q.push(7);
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
		if(mc[tmp = 7*q.top()] == 0)
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
	//pf("size : %d\n", (int)pq.size());
	mc.clear();
	while(!pq.empty())
	{
		mem[i++] = pq.top();
		//if(i == 101) pf("%lld\n", pq.top());
		//pf("%d\n", pq.top());
		pq.pop();
	}
}


int main()
{
	gen();
	int n;
	wh(sf(" %d", &n) && n)
	{
		if(n%10 == 1 && (n % 100) / 10 != 1)
			pf("The %dst humble number is %lld.\n", n, mem[n]);
		else if(n%10 == 2 && (n % 100) / 10 != 1)
			pf("The %dnd humble number is %lld.\n", n, mem[n]);
		else if(n%10 == 3 && (n % 100) / 10 != 1)
			pf("The %drd humble number is %lld.\n", n, mem[n]);
		else
			pf("The %dth humble number is %lld.\n", n, mem[n]);
	}
	return 0;
}
