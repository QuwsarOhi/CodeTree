#include <iostream>
#include <queue>

//myqueue.top() for maximum element

using namespace std;

int main()
{
	queue <int> myqueue;
	int myint;
	
	do{
		cin.get() >> myint;
		myqueue.push(myint);
	}while(myint+1 && cin.get() != '\n');
	
	cout << "Size of queue " << myqueue.size() << endl;
	
	while(!myqueue.empty())
	{
		cout << myqueue.front() << endl;
		myqueue.pop();
	}
	
	return 0;
}
