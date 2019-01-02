// LightOJ
// 1270 - Tiles (II)

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull dp[101][(1<<8)+2];
int vis[101][(1<<8)+2], visCnt = 0, n, m;
char G[101][101], tmp[101][9];

ull recur(int r, int c, int curRow, int nxtRow) {
    if(c == m) {
        if(r+1 == n)
            return 1;

        if(vis[r+1][nxtRow] == visCnt)
            return dp[r+1][nxtRow];
        
        vis[r+1][nxtRow] = visCnt;
        return dp[r+1][nxtRow] = recur(r+1, 0, nxtRow, 0);
    }

    bool cc = not (curRow & (1 << c));
    bool cnc = not (curRow & (1 << (c+1)));
    bool nc = not (nxtRow & (1 << c));
    bool nnc = not (nxtRow & (1 << (c+1)));
    bool npc = not (nxtRow & (1 << max(0, c-1)));

    if((not cc) or G[r][c] != '.')
        return recur(r, c+1, curRow, nxtRow);
    
    ull ret = 0;

    // first tile
    if(r+1 < n and G[r+1][c] == '.' and nc)
        ret += recur(r, c+1, curRow | (1 << c), nxtRow | (1 << c));

    // second tile
    if(c+1 < m and G[r][c+1] == '.' and cnc)
        ret += recur(r, c+1, curRow | (1 << c) | (1 << (c+1)), nxtRow);
    
    if(r+1 < n and c+1 < m and G[r+1][c+1] == '.' and nnc) {
        // third tile
        if(G[r+1][c] == '.' and nc)
                ret += recur(r, c+1, curRow | (1 << c), nxtRow | (1 << c) | (1 << (c+1)));
        // sixth tile
        if(G[r][c+1] == '.' and cnc)
            ret += recur(r, c+1, curRow | (1 << c) | (1 << (c+1)), nxtRow | (1 << (c+1)));


    }

    // fourth tile
    if(r+1 < n and c+1 < m and G[r][c+1] == '.' and G[r+1][c] == '.' and cnc and nc)
        ret += recur(r, c+1, curRow | (1 << c) | (1 << (c+1)), nxtRow | (1 << c));

    // fifth tile
    if(r+1 < n and c-1 >= 0 and G[r+1][c] == '.' and G[r+1][c-1] == '.' and nc and npc)
        ret += recur(r, c+1, curRow | (1 << c), nxtRow | (1 << c) | (1 << (c-1)));

    return ret;  
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t;
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &n, &m);

        for(int i = 0; i < n; ++i)
            scanf("%s", G[i]);

        if(n < m) {
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < m; ++j)
                    tmp[j][i] = G[i][j];
            swap(n, m);
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < m; ++j)
                    G[i][j] = tmp[i][j];
        }

        /*for(int i = 0; i < n; ++i, printf("\n"))
            for(int j = 0; j < m; ++j)
                printf("%c ", G[i][j]);*/
        
        ++visCnt;
        printf("Case %d: %llu\n", Case, recur(0, 0, 0, 0));
    }

    return 0;
}