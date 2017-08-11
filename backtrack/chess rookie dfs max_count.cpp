//UVa
//639 - Don't Get Rooked
#include<bits/stdc++.h>
using namespace std;

int row[] = {-1, -1, -1, 0, 0, 1, 1, 1}, col[] = {-1, 0, 1, -1, 1, -1, 0, 1}, max_rookie, placed_rookie, n;
bool rookie[6][6];
char wall[8][8];

inline bool place(int r, int c)
{
    if(rookie[r][c] || wall[r][c] == 'X') return 0;
    for(int i = r-1; i >= 0; i--) {
        if(wall[i][c] == 'X')
            break;
        if(rookie[i][c])
            return 0;
    }
    for(int i = r+1; i < n; i++) {
        if(wall[i][c] == 'X')
            break;
        if(rookie[i][c])
            return 0;
    }
    for(int i = c-1; i >= 0; i--) {
        if(wall[r][i] == 'X')
            break;
        if(rookie[r][i])
            return 0;
    }
    for(int i = c+1; i < n; i++) {
        if(wall[r][i] == 'X')
            break;
        if(rookie[r][i])
            return 0;
    }
    return 1;
}

inline int dfs(int r, int c)
{
    for(int _r = 0; _r < n; _r++)
        for(int _c = 0; _c < n; _c++) {
            if(place(_r, _c)) {
                rookie[_r][_c] = 1;
                placed_rookie++;
                max_rookie = max(placed_rookie, max_rookie);
                dfs(_r, _c);
                placed_rookie--;
                rookie[_r][_c] = 0;
            }
        }
}

int main()
{
    while(scanf("%d", &n) && n) {
        for(int i = 0; i < n; i++) {
            scanf(" %s", wall[i]);
        }
        max_rookie = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                memset(rookie, 0, sizeof(rookie));
                if(wall[i][j] == '.') {
                    placed_rookie = 1;
                    max_rookie = max(placed_rookie, max_rookie);
                    rookie[i][j] = 1;
                    dfs(i, j);
                }
            }
        printf("%d\n", max_rookie);
    }
    return 0;
}
