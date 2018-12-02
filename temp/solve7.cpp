#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;


char G[202][202];
int dist[202][202], n, m, dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
vector<pair<int, int> > teleport;
bool vis[202][202];

int BFS(int sx, int sy, int tx, int ty) {
    queue<pair<int, int> > q;
    q.push(make_pair(sx, sy));

    memset(vis, 0, sizeof vis);
    memset(dist, INF, sizeof dist);
    dist[sx][sy] = 0;

    int ux, uy, vx, vy;
    bool first = true;
    while(not q.empty()) {
        ux = q.front().first;
        uy = q.front().second;
        q.pop();

        if(ux == tx and uy == ty)
            return dist[ux][uy];

        for(int i = 0; i < 4; ++i) {
            vx = ux + dx[i];
            vy = uy + dy[i];

            if(vx >= n or vy >= m or vx < 0 or vy < 0 or G[vx][vy] == '#')
                continue;

            if(dist[vx][vy] != INF)
                continue;

            if(G[vx][vy] != '*') {
                q.push(make_pair(vx, vy));
                dist[vx][vy] = dist[ux][uy] + 1;
            }
            else if(not vis[vx][vy]) {
                vis[vx][vy] = 1;
                for(int i = 0; i < teleport.size(); ++i) {
                    if(vx == teleport[i].first and vy == teleport[i].second)
                        continue;

                    if(dist[teleport[i].first][teleport[i].second] != INF)
                        continue;

                    q.push(make_pair(teleport[i].first, teleport[i].second));
                    dist[teleport[i].first][teleport[i].second] = dist[ux][uy] + 2;
                }
            }
        }
    }

    return -1;
}

int main() {
    int t, eX, eY, sX, sY;
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &n, &m);

        teleport.clear();
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) {
                scanf(" %c", &G[i][j]);

                if(G[i][j] == 'P')
                    sX = i, sY = j;
                else if(G[i][j] == 'D')
                    eX = i, eY = j;
                else if(G[i][j] == '*')
                    teleport.push_back(make_pair(i, j));
            }

        int ans = BFS(sX, sY, eX, eY);
        printf("Case %d: ", Case);

        if(ans == -1)
            printf("impossible\n");
        else
            printf("%d\n", ans);
    }

    return 0;
}