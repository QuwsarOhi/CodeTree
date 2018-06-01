#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--) {
        string a, b, op;
        cin >> a >> op >> b;
        long long x = stoll(a, 0, 16);
        long long y = stoll(b, 0, 16);
        bitset<13>X(x);
        bitset<13>Y(y);
    
        if(op[0] == '+')
            cout << X << " + " << Y << " = " << x+y << "\n";
        else
            cout << X << " - " << Y << " = " << x-y << "\n";
    }
    return 0;
}
