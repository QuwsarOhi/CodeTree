#include <bits/stdc++.h>
using namespace std;

long long area(long long a, long long b, long long c) {
    long long s = (a+b+c)/2;
    return s*(s-a)*(s-b)*(s-c);
}

int main() {
    int n;
    cin >> n;

    int ans = 0;
    for(int c = 1; c <= n; ++c) {
        for(int b = 1; b <= c; ++b) {
            int a = c^b;
            if(a <= b and area(a, b, c) > 0)
                ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}