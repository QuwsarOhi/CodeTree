//Codeabbey
//url: http://www.codeabbey.com/index/task_view/average-of-array
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int arr[100];
	register int t;
	cin >> t;
	while(t--)
	{
		float sum = 0, len;
		register int i;
		for(i = 1; ; i++)
		{
			cin >> arr[i];
			if(arr[i] == 0)
				break;
		}
		len = --i;
		for(; i != 0; i--)
			sum += arr[i];
		cout << (int)round(sum/len) << " ";
	}
	return 0;
}
