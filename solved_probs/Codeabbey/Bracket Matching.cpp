//Codeabbey
//Url : http://www.codeabbey.com/index/task_view/matching-brackets
//Stack implementation
#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

stack <char> stk;

int check(char in)
{
	if(stk.empty())
		return 0;
	//cout << in << " ";
	if(in == ']')
		in = '[';
	else if(in == ')')
		in = '(';
	else if(in == '>')
		in = '<';
	else if(in == '}')
		in = '{';
	if((stk.top()) == in)
	{
		//cout << "*" << endl;
		stk.pop();
		return 1;
	}
	else
	{
		//cout << "**" << endl;
		return 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	register int t;
	cin >> t;
	cin.ignore(1);
	while(t--)
	{
		char mem[200];
		cin.getline(mem, 195);
		int len = strlen(mem), flag = 1;
		//cout << "len : " << len << " : " << mem << endl;
		for(register int i = 0; i < len; i++)
		{
			if((mem[i] == '{') || (mem[i] == '(') || (mem[i] == '<'))
				stk.push(mem[i]);
			if(mem[i] == '[')
				stk.push(mem[i]);
			if(mem[i] == '}' || mem[i] == ')' || mem[i] == '>' )
				if(!check(mem[i]))
				{
					//cout << "1 : " << stk.top() << endl;
					flag = 0;
					//cout << stk.empty() << endl;
				}
			if(mem[i] == ']')
				if(!check(mem[i]))
				{
					//cout << "2 : " << stk.top() << endl;
					flag = 0;
				}
		}
		if(!stk.empty())
			flag = 0;
		cout << flag << " ";
		while(!stk.empty())
			stk.pop();
	}
	return 0;
}
