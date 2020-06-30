#include <bits/stdc++.h>
using namespace std;


int main() {
	long long a, b, sum = 0;
	// 1
	cin >> a >> b;

	//2 3
	if(a%2 == 0) {
		cout << a << " is even\n";
		sum += a;
	}
	else {
		cout << a << " is odd\n";
		sum -= a;
	}


	// 4 5 6
	if(b > 0) {
		cout << b << " is greater than zero\n";
		sum += b;
	}
	else if(b < 0) {
		cout << b << " is less than zero\n";
		sum -= b;
	}
	else {
		cout << b << " is equal to zero\n";
		sum *= b;
	}

	// 7
	cout << "after adding,a+b is equal to " << a+b << "\n";


	// 8 9
	if((a+b)%2 == 0) {
		sum += a;
		sum += b;
		cout << "after adding " << a << " " << b << " sum is equal to " << sum << "\n";
	}
	else {
		sum -= a;
		sum -= b;
		cout << "after removing " << a << " " << b << " b sum is equal to " << sum << "\n";
	}

	// 10
	if(a+b == 0) {
		sum *= 10;
		cout << "the result after multiplying sum = " << sum << "\n";
	}

	// 11
	sum *= 5;

	// 12
	cout << "THE ULTIMATE RESULT = " << sum << "\n";
	// 13
	cout << "I wanna be a national contestant and I can write long code\n";

	return 0;
}