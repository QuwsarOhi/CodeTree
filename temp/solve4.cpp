#include <bits/stdc++.h>
using namespace std;

map<int, int>lft, rht;
set<int>tree;

int main() {
    int n, x, par;
    cin >> n;

    cin >> x;
    tree.insert(x);

    for(int i = 1; i < n; ++i) {
        cin >> x;
        auto p = tree.upper_bound(x);

        if(p != tree.end() and lft[*p] == 0) {
            //cerr << "lft" << endl;
            lft[*p] = x;
            par = *p;
        }
        else {
            //cerr << "rht" << endl;
            p--;
            rht[*p] = x;
            par = *p;
        }

        tree.insert(x);
        cout << par << " ";
    }

    cout << endl;
    return 0;
}