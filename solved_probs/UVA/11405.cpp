// UVa
// 11405 - Can U Win?

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef pair<int, int> pii;

int dx[] = {-2, -2, -1, 1, 2, 2, 1, -1}, dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};
char G[10][10];

bool valid(pii x) {
    if(x.first < 0 or x.first >= 8)
        return 0;
    if(x.second < 0 or x.second >= 8)
        return 0;
    if(G[x.first][x.second] == 'K' or G[x.first][x.second] == 'p')
        return 0;
    return 1;
}

int dist[8][8];

int bfs(pii s, pii t) {
    queue<pii>q;
    q.push(s);

    memset(dist, INF, sizeof dist);
    dist[s.first][s.second] = 0;

    pii u, v;
    while(not q.empty()) {
        u = q.front();
        q.pop();

        if(u == t)
            return dist[u.first][u.second];
        if(G[u.first][u.second] == 'P')
            continue;

        for(int i = 0; i < 8; ++i) {
            v.first = u.first + dx[i];
            v.second = u.second + dy[i];

            if(not valid(v)) 
                continue;
            if(dist[v.first][v.second] != INF)
                continue;
            dist[v.first][v.second] = dist[u.first][u.second] + 1;
            q.push(v);
        }
    }

    return -1;
}

vector<pii>P;
bool dp[65][8][8][(1<<8)+10];
int vis[65][8][8][(1<<8)+10], visCnt;

int recur(int step, int x, int y, int mask) {
    if(mask == (1 << P.size())-1)
        return 1;

    bool &ret = dp[step][x][y][mask];
    if(vis[step][x][y][mask] == visCnt)
        return ret;
    ret = 0;
    vis[step][x][y][mask] = visCnt;

    for(int i = 0; i < P.size(); ++i) {
        if(mask & (1 << i)) continue;

        int d = bfs({x, y}, P[i]);
        if(d != -1 and d <= step) {
            G[P[i].first][P[i].second] = '.';
            if(recur(step-d, P[i].first, P[i].second, mask | (1 << i)))
                return ret = 1;
            G[P[i].first][P[i].second] = 'P';
        }
    }

    return ret;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t, kx, ky, step;
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &step);

        for(int i = 0; i < 8; ++i)
            scanf("%s", &G[i]);

        P.clear();
        for(int i = 0; i < 8; ++i)
            for(int j = 0; j < 8; ++j) {
                if(G[i][j] == 'k')
                    kx = i, ky = j;
                else if(G[i][j] == 'P')
                    P.push_back({i, j});
            }

        ++visCnt;

        if(recur(step, kx, ky, 0))
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}

/*
3

...pP...
..P..k.K
p.....p.
...p....
...p....
........
.p......
........

*/