//UVa
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1895
//10954 - Add All

#include <bits/stdc++.h>

using namespace std;

int main()
{
	while(1)
	{
		register int t;
		register int x;
		scanf("%d", &t);
		priority_queue<int, vector<int>, greater<int> >pq;
		if(t == 0)
			break;
		while(t--)
		{
			scanf("%d", &x);
			pq.push(x);
		}
		register int sum = 0;
		int cost = 0;
		while(!pq.empty())
		{
			if(pq.size() == 1)
			{
				//cout << pq.size() << endl;
				//cost += pq.top();
				pq.pop();
				break;
			}
			//cout << pq.top() << " ";
			sum += pq.top();
			pq.pop();
			sum += pq.top();
			//cout << pq.top() << "\n";
			pq.pop();
			pq.push(sum);
			cost += sum;
			sum = 0;
		}
		printf("%d\n", cost);
	}
	return 0;
}
