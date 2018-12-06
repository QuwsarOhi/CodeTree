// LightOJ
// 1377 - Blade and Sword

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;


char G[202][202];
int dist[202][202][2], n, m, dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
vector<pair<int, int> > teleport;

int BFS(int sx, int sy, int tx, int ty) {
    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(0, make_pair(sx, sy)));

    memset(dist, INF, sizeof dist);
    dist[sx][sy][0] = 0;

    int ux, uy, vx, vy, st, d;
    while(not q.empty()) {
        st = q.front().first;
        ux = q.front().second.first;
        uy = q.front().second.second;
        d = dist[ux][uy][st];
        q.pop();

        if(ux == tx and uy == ty)
            return dist[ux][uy][st];

        if(G[ux][uy] == '*') {
            int mark = -1;
            for(int i = 0; i < teleport.size(); ++i) {
                if(teleport[i].first == ux and teleport[i].second == uy) {
                    mark = i;
                    continue;
                }
                if(dist[teleport[i].first][teleport[i].second][1] != INF)
                    continue;

                dist[teleport[i].first][teleport[i].second][1] = d+1;
                q.push(make_pair(1, make_pair(teleport[i].first, teleport[i].second)));
            }
            if(mark != -1) {
                vx = teleport[mark].first, vy = teleport[mark].second;
                teleport.clear();
                teleport.push_back(make_pair(vx, vy));
            }
        }

        if((st == 1 and G[ux][uy] == '*') or G[ux][uy] != '*') {
            for(int i = 0; i < 4; ++i) {
                vx = ux + dx[i];
                vy = uy + dy[i];

                if(vx < 0 or vy < 0 or vx >= n or vy >= m or G[vx][vy] == '#')
                    continue;

                if(dist[vx][vy][0] != INF)
                    continue;

                dist[vx][vy][0] = d+1;
                q.push(make_pair(0, make_pair(vx, vy)));
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


/*

1
10 3

###
#D#
#*#
###
#*#
###
#*#
#P#
#.#
###

*/