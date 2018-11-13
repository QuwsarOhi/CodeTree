// UVa
// 437 - The Tower of Babylon
// Dynamic Programming

#include <bits/stdc++.h>
using namespace std;

int dp[400][400];
vector<tuple<int, int, int> >cube;

bool canPlace(int Past, int New) {
    if(get<0>(cube[Past]) > get<0>(cube[New]) and get<1>(cube[Past]) > get<1>(cube[New]))
        return 1;
    return 0;
}

int recur(int taken, int lastTaken) {
    int &ret = dp[taken][lastTaken];
    if(ret != -1)
        return ret;
    ret = 0;
    for(int i = 0; i < cube.size(); ++i)
        if(taken == 0 or canPlace(lastTaken, i))
            ret = max(ret, recur(taken+1, i)+get<2>(cube[i]));
    return ret;
}

set<tuple<int, int, int> >SET;

int main() {
    int n, d[3], Case = 1;
    while(true) {
        cin >> n;
        if(n == 0)
            return 0;

        cube.clear();
        SET.clear();

        for(int i = 0; i < n; ++i) {
            cin >> d[0] >> d[1] >> d[2];
            sort(d, d+3);
            if(SET.count(make_tuple(d[0], d[1], d[2])))
                continue;
            do {
                cube.push_back(make_tuple(d[0], d[1], d[2]));
            } while(next_permutation(d, d+3));
        }

        memset(dp, -1, sizeof dp);
        cout << "Case " << Case++ << ": maximum height = " << recur(0, 0) << endl;
    }
    return 0;
}

/*

1
10 20 30
2
6 8 10
5 5 5

*/

