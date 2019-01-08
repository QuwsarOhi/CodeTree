#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
int main() {
    freopen("in", "w", stdout);
    int n = 50;
    cout << n*n << endl;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cout << i << " " << j << endl;

    return 0;
}*/

int n, m, g[60][60];

bool check(int x, int y) {
    vector<int>v;

    if(x-1 >= 0)
        v.push_back(g[x-1][y]);
    if(y-1 >= 0)
        v.push_back(g[x][y-1]);
    if(x+1 < n)
        v.push_back(g[x+1][y]);
    if(y+1 < m)
        v.push_back(g[x][y+1]);

    sort(v.begin(), v.end());
    for(int i = 1; i < v.size(); ++i)
        if(v[i-1] == v[i])
            return 0;
    return 1;
}

int main() {
    int x;
    freopen("out", "r", stdin);

    //for(int i = 1; i <= 50; ++i)
        //for(int j = 1; j <= 50; ++j) {
            scanf("%d", &x);
            n = 50, m = 50;

            for(int k = 0; k < n; ++k)
                for(int l = 0; l < m; ++l)
                    scanf("%d", &g[k][l]);

            for(int k = 0; k < n; ++k)
                for(int l = 0; l < m; ++l)
                    if(not check(k, l)) {
                        cout << "ERROR for " << n << " " << m << endl;
                        return 0;
                    }
        //}

    cout << "OK\n";
    return 0;
}
