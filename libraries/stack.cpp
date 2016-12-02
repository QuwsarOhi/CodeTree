#include <iostream>
#include <stack>

using namespace std;


int main()
{
	stack <int> st;
	stack <int> st2;
	
	st.push(1);
	st.push(3);
	st.push(6);
	
	st2.push(34);
	st2.push(657);
	
	cout << "stack size " << st.size() << endl;
	
	st.pop();
	
	while(!st2.empty())
	{
		cout << st2.top() << endl;
		st2.pop();
	}
	
	cout << "stack 1 size " << st.size() << endl;
	cout << "stack 2 size " << st2.size() << endl;
	
	return 0;
}
