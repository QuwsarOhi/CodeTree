//UVa
//10360 - Rat Attack
#include<bits/stdc++.h>
using namespace std;

int kills[1030][1030], _x, _y, min_x, min_y, max_kill, population, x, y, d;

inline void update()
{
    max_kill = kills[_x][_y];
    min_x = _x;
    min_y = _y;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    register int t, kill;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &d, &population);
        max_kill = -1;                      //assigning a minimum value
        min_x = min_y = 2000;               //assigning a big value
        memset(kills, 0, sizeof(kills));
        while(population--) {
            scanf("%d %d %d", &x, &y, &kill);
            int lim_x = x+d, lim_y = y+d;
            for(_x = x-d; _x <= lim_x; _x++) { if(_x < 0 || _x > 1024) continue;            //setting kill value in all (x, y) + d range point
                for(_y = y-d; _y <= lim_y; _y++) { if(_y < 0 || _y > 1024) continue;
                        kills[_x][_y] += kill;
                        if(kills[_x][_y] == max_kill) {
                            if(_x < min_x) update();
                            else if(x == min_x && _y < min_y) update();
                        }
                        else if(kills[_x][_y] > max_kill) update();
                }
            }

        }
        printf("%d %d %d\n", min_x, min_y, max_kill);
    }
    return 0;
}
