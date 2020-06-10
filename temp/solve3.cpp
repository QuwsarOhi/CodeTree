#include <iostream>
using namespace std;

class A{
	int a, b, c;
	
public:
	A(int x, int y, int z) {
		a = x;
		b = y;
		c = z;
	}
};

void printValue(A val) {
	int *p = (int*) &val;
	cout << "a = " << *p << endl;
	p++;
	cout << "b = " << *p << endl;
	p++;
	cout << "c = " << *p << endl;
}

int main() {
	A y = A(1, 2, 3);
	printValue(y);
	return 0;
}