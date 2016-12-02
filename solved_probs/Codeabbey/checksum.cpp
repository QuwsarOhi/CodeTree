//Codeabbey
// Url: http://www.codeabbey.com/index/task_view/array-checksum
#include <iostream>
using namespace std;

int main()
{
	int l;
	long long mem, result = 0;
	cin >> l;
	for(register int i = 0; i < l; i++)
	{
		cin >> mem;
		result += mem;
		result *= 113;
		if(result>10000007)
			result %= 10000007;
	}
	cout << result << " ";
	return 0;
}
