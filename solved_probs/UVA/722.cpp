//UVa
//722 - Lakes

#include<bits/stdc++.h>
using namespace std;

char G[100][110], water;
int r, c, cnt, R[] = {-1, 0, 0, 1}, C[] = {0, -1, 1, 0};
bool visited[101][101];

void dfs(int X, int Y)
{
    visited[X][Y] = 1;
    cnt++;
    for(int i = 0; i < 4; i++) {
        int x = X + R[i];
        int y = Y + C[i];
        if(x >= 0 && y >= 0 && x < r && y < c && G[x][y] == water && !visited[x][y])
            dfs(x, y);
    }
}



int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t, x, y;
    bool first = 1;
    scanf("%d", &t);
    while(t--) {
        scanf(" %d %d ", &x, &y);
        x--, y--;
        for(r = 0; ;r++) {
            if(fgets(G[r], 105, stdin) == NULL)
                break;
            if(G[r][0] == '\n')
                break;
        }
        memset(visited, 0, sizeof(visited));
        c = strlen(G[0]) - 1;
        water = G[x][y];
        cnt = 0;
        dfs(x, y);
        if(!first)
            printf("\n");
        first = 0;
        printf("%d\n", cnt);
    }
    return 0;
}
