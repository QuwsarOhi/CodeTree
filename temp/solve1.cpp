#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

vector<int>G[100010];

// {white, black} : 0, 1

ll dfs(int u, int color, int colorp) {
    if(G[u].size() == 1)
        return 1;

    ll &ret = dp[u][colorp][color];
    if(ret != -1)
        return ret;
    ret = 0;

    for(auto v : G[u]) {
        if(c == 0) {
            ret += dfs(u, 0);
            ret += dfs(u, 1);
        }
        else {
            ret += dfs(u, 0);
            if(colorp != 1)
                ret = += dfs(u, 1);
            ret %= MOD;
        }
    }

    return ret;
}

int main() {

}