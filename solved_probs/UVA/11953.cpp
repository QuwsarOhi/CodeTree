//UVa
//11953 - Battleships

#include<bits/stdc++.h>
using namespace std;

int r[] = {-1, 0, 0, 1}, c[] = {0, -1, 1, 0}, n;
char G[110][110];
bool visited[110][110];

bool dfs(int X, int Y)
{
    bool found = 0;
    visited[X][Y] = 1;
    if(G[X][Y] == 'x')
        found = 1;
    for(int i = 0; i < 4; i++) {
        int x = X + r[i];
        int y = Y + c[i];
        if(x >= 0 && y >= 0 && x < n && y < n)
            if(!visited[x][y] && G[x][y] != '.')
                found = dfs(x, y) || found;         //NOTE: found  = found || dfs(x, y) wouldn't work
                                                    //in this case c++ wont go to the function if found is true,
                                                    //c++ is built in that way, but, it is optimal also
    }
    return found;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf(" %s", G[i]);
        memset(visited, 0, sizeof(visited));
        int alive = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(G[i][j] != '.' && !visited[i][j])
                    if(dfs(i, j))
                        alive++;
        printf("Case %d: %d\n", Case, alive);
    }
    return 0;
}
