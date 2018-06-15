// LightOJ
// 1115 - Filling the Regions

#include <bits/stdc++.h>
using namespace std;

int r, c;
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
char G[60][60];

bool valid(int x, int y) {
    if(x < 0 || y < 0 || x >= r || y >= c)
        return 0;
    return 1;
}

bool vis[60][60];
void Fill(int x, int y, char T) {
    vis[x][y] = 1;
    for(int i = 0; i < 4; ++i) {
        int _x = x+dx[i];
        int _y = y+dy[i];
        
        if(!valid(_x, _y))
            continue;
        if(G[_x][_y] != T && !vis[_x][_y])
            Fill(_x, _y, T);
}}

void FillSurroundedBy(char T) {
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < c; ++i) {
        if(!vis[0][i] && G[0][i] != T)
            Fill(0, i, T);
        if(!vis[r-1][i] && G[r-1][i] != T)
            Fill(r-1, i, T);
    }
    
    for(int i = 0; i < r; ++i) {
        if(!vis[i][0] && G[i][0] != T)
            Fill(i, 0, T);
        if(!vis[i][c-1] && G[i][c-1] != T)
            Fill(i, c-1, T);
    }
    
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j) 
            if(!vis[i][j])
                G[i][j] = T;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t;
    scanf("%d", &t);
    bool Checked[30];
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &r, &c);
        memset(G, '.', sizeof G);
        memset(Checked, 0, sizeof Checked);
        
        for(int i = 0; i < r; ++i)
            scanf("%s", G[i]);
        
        for(int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j)
                if(G[i][j] != '.' && !Checked[G[i][j]-'A']) {
                    FillSurroundedBy(G[i][j]);
                    Checked[G[i][j]-'A'] = 1;
                }

        printf("Case %d:\n", Case);
        for(int i = 0; i < r; ++i)
            printf("%s\n", G[i]);
    }
    return 0;
}


/*

1
10 9
.........
.BBBBBBB.
.BTTTTTB.
.BT...TB.
.BT.R.TB.
.BT...TB.
.BT...TB.
.BTTTTTB.
.BBBBBBB.
.........

3 3
B.B
B.B
B.B

*/

