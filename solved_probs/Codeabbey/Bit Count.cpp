//Codeabbey
//Url : http://www.codeabbey.com/index/task_view/bit-count

#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	register int t;
	cin >> t;
	while(t--)
	{
		bitset <32> input;
		int p;
		cin >> p;
		input = p;
		cout << input.count() << " ";
	}
	return 0;
}
