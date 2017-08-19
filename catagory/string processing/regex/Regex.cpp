#include <bits/stdc++.h>
using namespace std;

int main() {
	string a = "ThisIsALineThatIsALineWithoutSpaces";
	regex b("(Th)(.*)");
	
	if(regex_match(a, b))
		cout << "String a matches b" << endl;
	if(regex_match(a.begin(), a.end(), b))
		cout << "String a matches b" << endl;

	smatch m;
	
	regex_search(a, m, b);
	
	for(auto x : m)
		cout << x << endl;
		
	cout << regex_replace(a, b, "replaced") << endl;
	
		
	cout << "Exiting" << endl;
	return 0;
}
