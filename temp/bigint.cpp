#include<bits/stdc++.h>
using namespace std;

int kills[1030][1030], _x, _y, max_x, max_y, max_kill, population, x, y, d,
r[9] = {-1, -1, -1, 0, 0, 1, 1, 1}, c[9] = {-1, 0, 1, -1, 1, -1, 0, 1};

void update()
{
    max_kill = kills[_x][_y];
    max_x = _x;
    max_y = _y;
}

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    register int t, kill;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &d, &population);
        max_x = max_y = max_kill = -1;
        memset(kills, 0, sizeof(kills));
        while(population--) {
            scanf("%d %d %d", &x, &y, &kill);
            kills[x][y] += kill;
            for(int i = 0; i < 8; i++) {
                //for(int j = 1; j <=d; j++) {
                _x = x+(r[i]*d);
                _y = y+(c[i]*d);
                if(_x >= 0 && _x <= 1026 && _y >= 0 && _y <= 1026) {
                    kills[_x][_y] += kill;
                    //printf(":%d %d:\n", r[i], c[i]);
                    //printf("| %d %d : %d|\n", _x, _y, kills[_x][_y]);
                    if(kills[_x][_y] == max_kill) {
                        if(_x < max_x) update();
                        else if(_y < max_y) update();
                    }
                    else if(kills[_x][_y] > max_kill) update();
                }
            }
        }
        printf("%d %d %d\n", max_x, max_y, max_kill);
    }
    return 0;
}
