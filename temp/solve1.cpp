#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    ++n;

    int cnt = 0;
    for(int i = 1; i <= 5; ++i) {
        int x = m+i;
        if(x > n) {
            if(x%n == 0)
                x = n;
            else
                x = x%n;
        }
        if(x != 1) 
            ++cnt;
    }
    cout << cnt << endl;
    return 0;
}