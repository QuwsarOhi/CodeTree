//Codeabbey
//url: http://www.codeabbey.com/index/task_view/sort-with-indexes
#include <iostream>
#include <algorithm>

using namespace std;

struct indx
{
	int val;
	int pos;
}mem[50];

bool cmp(indx a, indx b)
{
	return a.val<b.val;
}


int main()
{
	int n;
	register int i;
	cin >> n;
	for(i = 1; i <= n; i++)
	{
		cin >> mem[i].val;
		mem[i].pos = i;
	}
	sort(mem+1, mem+(n+1), cmp);
	for(i = 1; i <= n; i++)
		cout << mem[i].pos << " ";
	return 0;
}
