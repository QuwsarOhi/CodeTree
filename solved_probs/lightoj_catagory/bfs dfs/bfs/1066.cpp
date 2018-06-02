// LightOJ
// 1066 - Gathering Food

#include <bits/stdc++.h>
using namespace std;

int lstX, lstY, n;
char G[20][20];
bool vis[20][20];
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

int bfs(int x, int y, char to) {
    queue<pair<int, pair<int, int> > >q;
    q.push(make_pair(0, make_pair(x, y)));
    memset(vis, 0, sizeof vis);
    vis[x][y] = 1;

    while(!q.empty()) {
        x = q.front().second.first;
        y = q.front().second.second;
        int w = q.front().first;
        q.pop();

        if(G[x][y] == to) {
            lstX = x, lstY = y;
            G[x][y] = '.';
            return w;
        }

        for(int i = 0; i < 4; ++i) {
            int _x = x+dx[i];
            int _y = y+dy[i];

            if(_x < 0 || _x >= n || _y < 0 || _y >= n)
                continue;

            if(G[_x][_y] != '.' && G[_x][_y] != to)
                continue;

            if(vis[_x][_y])
                continue;
            vis[_x][_y] = 1;
            q.push(make_pair(w+1, make_pair(_x, _y)));
        }
    }
    return -1;
}


int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &n);
        int k = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) {
                scanf(" %c", &G[i][j]);
                if(G[i][j] == 'A')
                    lstX = i, lstY = j;
                if(isalpha(G[i][j]))
                    ++k;
            }

        int dst = 0, t;
        char T = 'A';
        for(int i = 0; i < k; ++i) {
            t = bfs(lstX, lstY, T);
            if(t == -1)
                break;
            dst += t;
            T += 1;
        }

        if(t != -1)
            printf("Case %d: %d\n", Case, dst);
        else
            printf("Case %d: Impossible\n", Case);
    }
    return 0;
}
