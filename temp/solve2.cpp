#include <bits/stdc++.h>
using namespace std;


int main() {
    int vcnt = 0, hcnt = 0;
    vector<pair<int, int> > v;
    string s;
    cin >> s;

    for(auto it : s) {
        if(it == '0') {        // vertical
            if(vcnt == 4)
                vcnt = 0;
            if(vcnt == 0)
                v.push_back({1, 1});
            else if(vcnt == 1)
                v.push_back({1, 2});
            else if(vcnt == 2)
                v.push_back({1, 3});
            else
                v.push_back({1, 4});
            ++vcnt;
        }
        else {
            if(hcnt == 2)
                hcnt = 0;
            if(hcnt == 0)
                v.push_back({4, 1});
            else
                v.push_back({4, 3});
            hcnt++;
        }
    }

    for(auto it : v)
        cout << it.first << " " << it.second << endl;
    return 0;
}