#include <bits/stdc++.h>
#define MAX 103
#define INF 0x3f3f3f3f
using namespace std;

bool g[MAX][MAX];
int n, dp[MAX][MAX][2][2];

int recur(int x, int y) {
    int &ret = dp[x][y][g[x-1][y-1]][g[x-1][y+1]];

    if(ret != -1)
        return ret;
    if(x > n)
        return ret = 0;
    if(y > n)
        return ret = recur(x+1, 1);

    ret = INF;
    if(g[x][y]) {
        //g[x][y] = 0;
        if(g[x-1][y-1]) {
            //cerr << x << " " << y << " LFT\n";
            ret = min(ret, recur(x, y+1)+1);
        }
        else if(g[x-1][y+1]) {
            //cerr << x << " " << y << " RHT\n";
            ret = min(ret, recur(x, y+1)+1);
        }
        
        //g[x][y] = 1;
        if(not g[x-1][y-1] and not g[x-1][y+1])
            ret = recur(x, y+1);
    }
    else
        ret = recur(x, y+1);

    //cerr << "AT " << x << " " << y << " :: " << ret << endl;
    return ret;
}

int get(int x, int y) {
    return dp[x][y][g[x-1][y-1]][g[x-1][y+1]];
}

void dfs(int x, int y) {
    int ret = get(x, y);
    if(x > n)
        return;
    if(y > n) {
        dfs(x+1, 1);
        return;
    }

    if(g[x][y]) {
        //g[x][y] = 0;
        //cerr << "AT " << x << " " << y << " " << ret << " == " << get(x, y+1)+1 << endl;
        if(g[x-1][y-1] and ret == get(x, y+1)+1) {
            printf("%d %d L\n", x, y);
            dfs(x, y+1);
        }
        else if(g[x-1][y+1] and ret == get(x, y+1)+1) {
            printf("%d %d R\n", x, y);
            dfs(x, y+1);
        }
        else {
            //g[x][y] = 1;
            dfs(x, y+1);
        }
    }
    else
        dfs(x, y+1);
}

vector<pair<pair<int, int>, char> > ans, v;

void go(int x, int y) {
    //cout << x << " " << y << endl;
    if(x > n) {
        if(v.size() < ans.size() or ans.empty())
            ans = v;
        return;
    }
    if(y > n) {
        go(x+1, 1);
        return;
    }

    if(g[x][y]) {
        g[x][y] = 0;
        if(g[x-1][y-1]) {
            v.push_back({{x, y}, 'L'});
            go(x, y+1);
            v.pop_back();
        }
        if(g[x-1][y+1]) {
            v.push_back({{x, y}, 'R'});
            go(x, y+1);
            v.pop_back();
        }
        g[x][y] = 1;
        if(not g[x-1][y-1] and not g[x-1][y+1])
            go(x, y+1);
    }
    else
        go(x, y+1);
}


int main() {
    int t;
    char c;
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);
        memset(g, 0, sizeof g);

        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j) {
                scanf(" %c", &c);
                if(c == 'O') g[i][j] = 1;
            }

        /*memset(dp, -1, sizeof dp);
        int ret = recur(1, 1);
        printf("%d\n", ret);
        dfs(1, 1);*/

        ans.clear(), v.clear();
        go(1, 1);
        printf("%d\n", (int)ans.size());
        for(auto it : ans)
            printf("%d %d %c\n", it.first.first, it.first.second, it.second);
    }

    return 0;
}