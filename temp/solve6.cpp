#include <bits/stdc++.h>
using namespace std;

void GEN(int n) {
    cout << n << endl;
    srand(420);
    
    for(int i = 0; i < n; ++i, cout << endl)
        for(int j = 0; j < n; ++j)
            cout << "E";
            //cout << (rand()%2 ? 'E':'.');
}

int main() {
    freopen("in", "w", stdout);
    GEN(100);
    return 0;
}
