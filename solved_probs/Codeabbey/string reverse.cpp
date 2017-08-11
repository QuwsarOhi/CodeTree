//Codeabbey
#include <iostream>
#include <cstdio>

using namespace std;

void rev()
{
	char x = getchar();
	if(x == 10)
		return;
	rev();
	cout << x;
}

int main()
{
	rev();
	return 0;
}
