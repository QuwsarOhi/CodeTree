// UVa
// 412 - PI

#include <bits/stdc++.h>
using namespace std;

vector<int>v;

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int n, x, cnt;
    while(scanf("%d", &n) and n) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &x);
            v.push_back(x);
        }
        
        cnt = 0;
        for(int i = 0; i < (int)v.size(); ++i)
            for(int j = i+1; j < (int)v.size(); ++j)
                cnt += (__gcd(v[i], v[j]) == 1);
        
        //cout << "COUNT " << cnt << endl;
        double PI = 6*(n*(n-1))/2;
        PI /= cnt;
        
        //cout << PI << endl;
        if(cnt == 0) printf("No estimate for this data set.\n");
        else        printf("%.6lf\n", sqrt(PI));
        v.clear();
    }
    return 0;
}
