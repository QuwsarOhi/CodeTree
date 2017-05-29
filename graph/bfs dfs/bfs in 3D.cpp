//UVa
//532 - Dungeon Master
//BFS in 3D


#include<bits/stdc++.h>
#define MAX 31
using namespace std;

struct point {
    int x, y, z, time;
    point() {
        x = y = z = time = 0;
    }
    //point(int _x, int _y, int _z, int _time) : x(_x), y(_y), z(_z), time(_time) {}
    point(int _x, int _y, int _z, int _time) {
        x = _x;
        y = _y;
        z = _z;
        time = _time;
    }
};

bool visited[MAX][MAX][MAX];
char obstacle[MAX][MAX][MAX];
int start_x, start_y, start_z, end_x, end_y, end_z, L, R, C;

//north, south, east, west, up, down
int r[] = {-1, 1, 0, 0, 0 , 0}, c[] = {0, 0, 1, -1, 0, 0}, l[] = {0, 0, 0, 0, 1, -1};

int BFS()
{
    memset(visited, 0, sizeof visited);
    queue<point> q;
    q.push(point(start_x, start_y, start_z, 0));
    visited[start_x][start_y][start_z] = 1;

    while(!q.empty()) {
        point u = q.front();
        q.pop();

        //printf("popped %d %d %d || %d\n", u.x, u.y, u.z, u.time);

        for(int i = 0; i < 6; i++) {
            point v;
            v.x = u.x + r[i];
            v.y = u.y + c[i];
            v.z = u.z + l[i];
            v.time = u.time + 1;

            if(obstacle[v.x][v.y][v.z] == 'E')
                return v.time;

            if(v.x > -1 && v.x < R && v.y > -1 && v.y < C && v.z > -1 && v.z < L)
                if(!visited[v.x][v.y][v.z] && obstacle[v.x][v.y][v.z] == '.') {
                    visited[v.x][v.y][v.z] = 1;
                    q.push(v);
                }
        }
    }
    return -1;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    while(scanf("%d %d %d", &L, &R, &C) && (L || R || C)) {
        for(int k = 0; k < L; k++)
            for(int i = 0; i < R; i++)
                for(int j = 0; j < C; j++) {
                    scanf(" %c ", &obstacle[i][j][k]);

                    //Finding the starting point
                    if(obstacle[i][j][k] == 'S') {
                        start_x = i;
                        start_y = j;
                        start_z = k;
                    }
                }

        int ans = BFS();
        if(ans == -1)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n", ans);
    }
    return 0;
}
