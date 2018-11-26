#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

char G[503][503];
int mem[503][503], n, m;
bool vis[503][503];
vector<pair<int, int> >p;

int dfs(int x, int y) {
    vis[x][y] = 1;
    p.push_back(make_pair(x, y));

    int ret = vis[x][y] == 'C';
    for(int i = 0; i < 4; ++i) {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if(xx >= 0 and yy >= 0 and xx < n and yy < m and not vis[xx][yy])
            ret += dfs(xx, yy);
    }
    return ret;
}

int main() {
    int t, q, tmp;
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d%d", &n, &m, &q);

        for(int i = 0; i < n; ++i)
            scanf(" %s", G[i]);

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(not vis[i][j]) {
                    tmp = dfs(i, j);

                    while(not p.empty()) {
                        mem[p.back().first][p.back().second] = tmp;
                        p.pop_back();
                    }
                }


    }
}