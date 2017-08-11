#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int main()
{
	string x, y;
	stack <char> stk; 
	int flag, n;
	
	cin >> n;
	
	getline(cin, y);
	
	while(n--)
	{
		flag = 0;
		
		getline(cin, x);
	
		for(int i = 0; i < x.size(); i++)
		{
			if(x[i] == '1')
				stk.push(x[i]);
			else
			{
				if(stk.empty())
					flag = 1;
				else
					stk.pop();

			}
		}
		
		if(flag == 1)
			cout << "MAGIC" << endl;
		else
			cout << "NORMAL" << endl;
			
		while(!stk.empty())
			stk.pop();
	}

	
	return 0;
}
