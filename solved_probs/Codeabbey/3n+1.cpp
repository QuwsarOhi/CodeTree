//Codeabbey
// Url : http://www.codeabbey.com/index/task_view/collatz-sequence
//Collatz Sequence (3n+1)

#include <iostream>

using namespace std;

int coll(register int x, register int count = 0)
{
	if(x%2 == 0)
		x /= 2;
	else
		x = (3*x) + 1;
	count ++;
	if(x == 1)
		return count;
	coll(x, count);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	register int t;
	int n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		cout << coll(n) << " ";
	}
	return 0;
}
