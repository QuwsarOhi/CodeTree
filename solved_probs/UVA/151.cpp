// UVa
// 151 - Power Crisis

#include <bits/stdc++.h>
using namespace std;

bitset<104>off;
bool check(int n, int m) {
    off.reset();
    int cnt = m-1;
    for(int i = 1; !off[13] and off.count() != n-1; ++i) {            
        if(i > n) {
            i %= n;
            if(!i) ++i;
        }
        
        if(!off[i])
            ++cnt;
        
        if(cnt == m) {
            cnt = 0;
            //cout << i << endl;
            off[i] = 1;
            continue;
        }
    }
    return !off[13];
}
int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int n;
    while(scanf("%d", &n) and n) {
        for(int i = 1; i < 1000000; ++i)
            if(check(n, i)) {
                printf("%d\n", i);
                break;
            }
    }
    
    return 0;
}
