//Codeabbey
//Url: http://www.codeabbey.com/index/task_view/caesar-shift-cipher
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	register int t;
	int key;
	cin >> t >> key;
	//getchar();
	while(t--)
	{
		char in[100];
		fgets(in, 95, stdin);
		int len = strlen(in);
		for(register int i = 0; i < len ; i++)
		{
			if(in[i] >= 'A' && in[i] <= 'Z')
			{
				if((int)in[i] - key < 'A')
				{
					in[i] = 'Z' - ('A' - (in[i] - key)) + 1;
					//cout << "worked : " << (int)in[i] << endl;
				}
				else
					in[i] -= key;
			}
			if(in[i] == '.')
				in[i+1] = 0;
		}
		cout << in << " ";
	}
	return 0;
}
