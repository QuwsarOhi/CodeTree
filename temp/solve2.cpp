#include <iostream>
using namespace std;


bool greatest(int a, int b) {
    return a > b;
}

bool greatest(char a, char b) {
    return a > b;
}

bool greatest(float a, float b) {
    return a > b;
}


int main() {
    cout << "2 is greater than 1: " << (greatest(2, 1)?"True":"False") << endl;
    cout << "2.3 is greater than 3: " << (greatest(2.3, 3)?"True":"False") << endl;
    cout << "A is greater than B: " << (greatest('A', 'B')?"True":"False") << endl;
    return 0;
}