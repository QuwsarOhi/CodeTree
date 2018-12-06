// LightOJ
// 1337 - The Crystal Maze

#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

char G[503][503];
int mem[503][503], n, m;
int vis[503][503], cnt;
vector<pair<int, int> >p;

int dfs(int x, int y) {
    vis[x][y] = cnt;
    p.push_back(make_pair(x, y));

    int ret = G[x][y] == 'C';
    for(int i = 0; i < 4; ++i) {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if(xx >= 0 and yy >= 0 and xx < n and yy < m and vis[xx][yy] != cnt and G[xx][yy] != '#')
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

        ++cnt;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(vis[i][j] != cnt) {
                    tmp = dfs(i, j);
                    //cerr << i << " " << j << " :: " << tmp << endl;
                    while(not p.empty()) {
                        mem[p.back().first][p.back().second] = tmp;
                        p.pop_back();
                    }
                }

        printf("Case %d:\n", Case);
        while(q--) {
            scanf("%d%d", &n, &m);
            printf("%d\n", mem[n-1][m-1]);
        }
    }

    return 0;
}