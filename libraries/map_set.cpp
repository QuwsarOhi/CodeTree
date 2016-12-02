#include <iostream>
#include <set>
#include <map>
#include <string>


using namespace std;

int main()
{
	cout << "Using Map" << endl;
	
	map <string, int> m;
	string input;
	
	while(cin >> input)
	{
		if(input == "end")
			break;
		m[input] ++;
		cout << input << " is " << m[input] << endl;
	}
	
	cout << "Using Set" << endl;
	
	set <int> s;
	s.insert(10);
	s.insert(23);
	set<int>::iterator it;
	for(it = s.begin(); it!=s.end(); it++)
		cout << *it << endl;
	
	return 0;
	
}
