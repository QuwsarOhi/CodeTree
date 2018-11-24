// LightOJ
// 1238 - Power Puff Girls

#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

char G[22][22];
bool vis[22][22];
int n, m;

int bfs(int sx, int sy, int tx, int ty) {
    memset(vis, 0, sizeof vis);
    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(0, make_pair(sx, sy)));

    int ux, uy, vx, vy, w;
    while(not q.empty()) {
        w = q.front().first;
        ux = q.front().second.first;
        uy = q.front().second.second;
        q.pop();

        if(tx == ux and ty == uy)
            return w;

        for(int i = 0; i < 4; ++i) {
            vx = dx[i] + ux;
            vy = dy[i] + uy;

            if(vx >= n or vx < 0 or vy >= m or vy < 0 or vis[vx][vy])
                continue;

            if(G[vx][vy] == '#' or G[vx][vy] == 'm')
                continue;

            vis[vx][vy] = 1;
            q.push(make_pair(w+1, make_pair(vx, vy)));
        }
    }
    return -1;
}

int main() {
    int t, tX, tY;
    vector<pair<int, int> >p;
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &n, &m);

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) {
                scanf(" %c", &G[i][j]);

                if(G[i][j] >= 'a' and G[i][j] <= 'c')
                    p.push_back(make_pair(i, j));
                if(G[i][j] == 'h')
                    tX = i, tY = j;
            }


        int ans = 0;
        for(int i = 0; i < p.size(); ++i) {
            //cerr << p[i].first << " " << p[i].second << " :: " << tX << " " << tY << " = " << bfs(p[i].first, p[i].second, tX, tY) << endl;
            ans = max(ans, bfs(p[i].first, p[i].second, tX, tY));
        }

        printf("Case %d: %d\n", Case, ans);
        p.clear();
    }
}