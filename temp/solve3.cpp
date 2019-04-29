#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000000
using namespace std;
typedef long long ll;

ll dp[2][1000002], n;
vector<int>v;

int cal() {
    int prev = 0, curr = 1;
    for(int i = 0; i < v.size(); ++i) {
        dp[curr][0] = 1;
        for(int tot = 1; tot <= n; ++tot) {
            int tmp = tot-v[i];
            dp[curr][tot] = (tmp >= 0 ? dp[curr][tmp]:0) + (i > 0 ? dp[prev][tot]:0);
            if(dp[curr][tot] >= MOD)
                dp[curr][tot] %= MOD;
        }
        prev ^= 1, curr ^= 1;
    }
    return dp[prev][n];
}


int main() {
    for(int i = 0; (1<<i) <= 1000000; ++i) {
        //scerr << i << " :: " << (1<<i) << endl;
        v.push_back(1<<i);
    }
    cin >> n;
    cout << cal() << endl;
    return 0;
}