// UVa
// 855 - Lunch in Grid City

#include <bits/stdc++.h>
using namespace std;


int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t, x, y, n;
    vector<int> X, Y;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d %d %d", &x, &y, &n);
        int SumX = 0, SumY = 0;
        //cout << "Done " << n << endl;
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &x, &y);
            X.push_back(x);
            Y.push_back(y);
            SumX += x;
            SumY += y;
        }
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());

        if(n&1) {
            x = X[n/2];
            y = Y[n/2];
        }
        else {
           x = X[(n-1)/2];
           y = Y[(n-1)/2];
        }
        printf("(Street: %d, Avenue: %d)\n", x, y);
        X.clear();
        Y.clear();
    }
    return 0;
}
