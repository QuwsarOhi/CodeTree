#include <bits/stdc++.h>
using namespace std;


bitset<30>dead;
bool Try(int n, int m, int k) {
    dead.reset();
    int bad = n/2, cnt = 0;
    for(int i = 0; ; ++i) {
        if(i >= n)
            i %= n;
        if(!dead[i])
            ++cnt;
        
        if(cnt == m) {
            if((int)dead.count() < bad and i < k)
                return 0;
            else if((int)dead.count() == bad)
                return 1;
            dead[i] = 1;
            cnt = 0;
        }
    }
    return 1;
}


int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int k, n;
    
    while(scanf("%d", &k) and k) {
        n = k*2;
        bool ok = 0;
        for(int i = 1; i < 100000; ++i)
            if(Try(n, i, k)) {
                cout << i << endl;
                ok = 1;
                //break;
            }
            //else
            //    cerr << i << "Failed\n";
        
        if(!ok) cout << k << " ERROR\n";
    }
    return 0;
}
