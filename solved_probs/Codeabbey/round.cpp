//Codeabbey
//Url: http://www.codeabbey.com/index/task_view/fahrenheit-celsius
//refer: https://en.wikipedia.org/wiki/Rounding#Round_half_up
// https://en.wikipedia.org/wiki/Absolute_value

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(register int i = 0; i < n; i++)
	{
		float a, b;
		cin >> a >> b;
		float r = a/b;
		//cout << r << " - " << (int)r << endl;
		if(r >= 0)
		{
			if(r - (int)r >= 0.5)
				r = ceil(r);
			else if(r - (int)r < 0.5)
				r = floor(r);
		}
		else
		{
			if(r - (int)r >= (-0.5)) //Tricky
				r = ceil(r);
			else
				r = floor(r);
		}
		if(r == -0) //Cause ceil sets -0.01 to -0 (test case -5587354 -1107185)
			r = 0;
		cout << r << " ";
		//can be used nearbyint();
	}
	return 0;
}

/*Tese case:
16
19099 628
4420170 391
1490659 868
8574379 783
4360962 864
1499565 823
-5722499 2717942
8756413 206
14669 470
191478 -4342618
2702436 10
-5587354 -1107185
12057 1110
5864617 -2146031
-8128739 1588371
2599884 714
*/
