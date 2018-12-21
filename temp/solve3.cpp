#include <bits/stdc++.h>
using namespace std;

map<int, int> lft, rht, par;

int process(int root, int x) {
    if(root == 0) {
        root = x;
    }
    else if(root < x) {
        if(rht[root] == 0) {
            rht[root] = x;
            par[x] = root;
        }
        else
            process(rht[root], x);
    }
    else {
        if(lft[root] == 0) {
            lft[root] = x;
            par[x] = root;
        }
        else
            process(lft[root], x);
    }
    return root;
}

int v[100100];

int main() {
    int n, root = 0;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        root = process(root, v[i]);
    }

    for(int i = 1; i < n; ++i)
        cout << par[v[i]] << " ";

    return 0;
}