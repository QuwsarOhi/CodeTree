#include <iostream>
#include <string>
using namespace std;

class CSE42 {
	public:
		string name = "";
		int id = 0;
		int section = 0;
		int intake = 42;

	CSE42() {}

	CSE42(string name, int id, int section) {
		this->name = name;
		this->id = id;
		this->section = section;
	}
};


int main() {
	CSE42 array[5];

	for(int i = 0; i < 5; ++i) {
		string name = "Student_";
		name.push_back('1'+i);
		array[i] = CSE42(name, i+1, i+1);
	}

	for(int i = 0; i < 5; ++i) {
		cout << "Name: " << array[i].name << endl;
		cout << "Intake: " << array[i].intake << endl;
		cout << "Section: " << array[i].section << endl; 
		cout << "ID: " << array[i].id << endl;
		cout <<"\n";
	}

	return 0;
}