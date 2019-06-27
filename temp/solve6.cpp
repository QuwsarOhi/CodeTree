<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	int t;
	cin >> t;

	for(int Case = 1; Case <= t; ++Case) {
		cin >> s;

		int B = 0, n = s.size();
		for(int i = 1; i < n; ++i)
			if(s[i] == 'B')
				++B;

		cout << "Case #" << Case << ": ";
		if(B == 1 and n == 3)
			cout << "Y" << endl;
		else if(B == n-1)
			cout << "N" << endl;
		else if(B >= 2)
			cout << "Y" << endl;
		else
			cout << "N" << endl;
	}

	return 0;
}
=======
>>>>>>> 70a5491588d00ec98f196356c1f76d863f3bdd71
