#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, x, y, mx = -1e7;
    vector<pair<int, int> >v;
    cin >> n;
    while(n--) {
        cin >> x >> y;
        v.push_back({y, x});
        mx = max(x, mx);
    }

    sort(v.begin(), v.end());

    int sum = 0, cards = 0;
    bool first = 1;
    for(auto it = v.rbegin(); it != v.rend(); ++it) {
        if(first && it->first != 0) {
            sum += it->second;
            cards += it->first;
            first = 0;
        }
        else if(cards > 0){
            sum += it->second;
            cards += it->first - 1;
        }
        else
            break;
    }

    if(first)
        sum += mx;

    cout << sum << endl;
    return 0;
}
