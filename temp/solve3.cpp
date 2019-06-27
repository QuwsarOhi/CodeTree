<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

vector<string> v = {
	"BUBT", "bubt", "Bubt",
	"~", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "-", "+", "\\", "/", ".", ",",
	"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
	"department", "Department", "DEPARTMENT", "DEPT", "dept",
	"EEE", "eee",
	"CSE", "cse",
	//"Economics", "ECONOMICS", "eco", "ECO",
	//"BBA", "bba",
	"Cafeteria", "cafeteria", "cafe", "Cafe", "CAFE",
	"student", "students", "std", "Students", "Student"
};


void gen(string s) {
	if(s.size() >= 8) {
		printf("%s", s.c_str());
		return;
	}

	for(int i = 0; i < v.size(); ++i)
		gen(s+v[i]);
}

int main() {
	gen("");
	return 0;
}
=======
>>>>>>> 70a5491588d00ec98f196356c1f76d863f3bdd71
