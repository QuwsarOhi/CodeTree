// LightOJ
// 1105 - Fi Binary Number

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//
// 1, 10, 100, 101, 1000, 1001, 1010, 10000, 10001, 10010, 10100, 10101
// 1   2    3    4     5     6     7      8      9     10     11     12
// 

ll f[60];
void GenFib() {
    f[1] = 1;
    f[2] = 2;
    //cerr << "1 : 1\n2 : 2\n";
    for(int i = 3; ; ++i) {
        f[i] = f[i-1] + f[i-2];
        //cerr << i << " : " << f[i] << endl;
        if(f[i] > 1e9)
            break;
    }
}

int getLen(int Nth) {
    for(int i = 1; i < 60; ++i)
        if(Nth < f[i])
            return i-1;
    return -1;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    GenFib();
    int n, t;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &n);
        int idx = getLen(n);
        string ans;
    
        for(int i = idx; i >= 1; --i) {
            if(n >= f[i]) {
                n -= f[i];
                ans.push_back('1');
            }
            else
                ans.push_back('0');
        }
        printf("Case %d: %s\n", Case, ans.c_str());
    }
    return 0;
}
