// UVa
// 352 - The Seasonal War

#include <bits/stdc++.h>
using namespace std;

char G[30][30];
bool vis[30][30];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1}, n;

void dfs(int x, int y) {
    vis[x][y] = 1;
    for(int i = 0; i < 8; ++i) {
        int _x = x+dx[i];
        int _y = y+dy[i];
        
        if(_x < 0 or _x >= n or _y < 0 or _y >= n)
            continue;
        if(vis[_x][_y] or G[_x][_y] == '0')
            continue;        
        dfs(_x, _y);
    }
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int Case = 1;
    while(scanf("%d", &n) == 1) {
        for(int i = 0; i < n; ++i)
            scanf("%s", G[i]);
            
        int ans = 0;
        memset(vis, 0, sizeof vis);
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(not vis[i][j] and G[i][j] == '1')
                    dfs(i, j), ++ans;
        printf("Image number %d contains %d war eagles.\n", Case++, ans);
    }
    return 0;
}
