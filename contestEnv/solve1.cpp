#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int main() {
    int a, b, x;
    string input;
    getline(cin, input);
    istringstream iss(input);
    iss >> a;
    iss >> b;
    iss >> x;
    string output = "";
    if(x == 1){
        for(int i=0; i<a; i++){
            output += "0";
        }
        for (int i=0; i<b; i++){
            output += "1";
        }
    } else if (x == 2) {
        if(a >= b){
            output += "0";
            for (int i=0; i<b; i++){
                output += "1";
            }
            for (int i=1; i<a; i++){
                output += "0";
            }
        } else {
            output += "1";
            for (int i=0; i<a; i++){
                output += "0";
            }
            for (int i=1; i<b; i++){
                output += "1";
            }
        }
    } else {
        string toAdd = a >= b ? "01" : "10";
        bool more0 = a >= b ? true : false;
        output = toAdd;
        int num0 = 1;
        int num1 = 1;
        if (x == 1) {
            for (int i = 0; i < a; i++) {
                output += "0";
            }
            for (int i = 0; i < b; i++) {
                output += "1";
            }
        }
        if (x % 2 == 1) {
            for (int i = 1; i < (x - 2); i += 2) {
                output += toAdd;
                num0++;
                num1++;
            }
            if (a >= b) {
                for (int i = num0; i < a; i++) {
                    output += "0";
                }
                for (int i = num1; i < b; i++) {
                    output += "1";
                }
            } else {
                for (int i = num1; i < b; i++) {
                    output += "1";
                }
                for (int i = num0; i < a; i++) {
                    output += "0";
                }
            }
        } else {
            for (int i = 1; i < x - 1; i += 2) {
                output += toAdd;
                num0++;
                num1++;
            }
            if (a >= b) {
                for (int i = num1; i < b; i++) {
                    output += "1";
                }
                for (int i = num0; i < a; i++) {
                    output += "0";
                }
            } else {
                for (int i = num0; i < a; i++) {
                    output += "0";
                }
                for (int i = num1; i < b; i++) {
                    output += "1";
                }
            }
        }
    }

    cout << output;
}
