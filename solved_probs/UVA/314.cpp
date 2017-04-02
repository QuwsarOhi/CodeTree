//UVa
//314 - Robot
//BFS in Grid (3D or 2D)


#include<bits/stdc++.h>
#define INF 1e6
using namespace std;

bool input[51][51], changed[55][55];
int N, M, q, start_x, start_y, end_x, end_y, dir, visited[55][55][4];

//r and c is sorted according to direction
//north east south west
int r[] = {-1, 0, 1, 0}, c[] ={0, 1, 0, -1};

//BFS in 3D grid
//the 3D parameters are, row, column, direction

int bfs()
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            for(int k = 0; k < 4; k++)
                visited[i][j][k] = INF;

    queue<pair<pair<int, int>, pair<int, int> > >q;
    q.push(make_pair(make_pair(dir, 0), (make_pair(start_x, start_y))));
    visited[start_x][start_y][dir] = 0;

    while(!q.empty()) {
        int _x = q.front().second.first;
        int _y = q.front().second.second;
        int _w = q.front().first.second;
        int _dir = q.front().first.first;

        q.pop();

        //if answer is found, exit
        if(_x == end_x && _y == end_y)
                return _w;

        //first visiting towards the direction
        //r[dir] and c[dir] contains the row and column according to the direction
        //the robot can go 1, 2 or 3 units, so the loop runs for 1, 2 & 3
        for(int i = 1; i < 4; i++) {
            int x = _x + (i * r[_dir]);
            int y = _y + (i * c[_dir]);

            //if no obstacle is found, we can traverse, if obstacle is found, we cant go for big units
            //so breaking the loop will work
            if(x > 0 && y > 0 && x < N && y < M && !input[x-1][y-1] && !input[x-1][y] && !input[x][y-1] && !input[x][y]) {
                if(visited[x][y][_dir] == INF) {
                    visited[x][y][_dir] = _w + 1;
                    q.push(make_pair(make_pair(_dir, _w+1), make_pair(x, y)));
                }
            }
            else
                break;
        }

        //if the robot moves right
        if(visited[_x][_y][(_dir+1)%4] == INF) {
            visited[_x][_y][(_dir+1)%4] = _w + 1;
            q.push(make_pair(make_pair((_dir+1)%4, _w+1), make_pair(_x, _y)));
        }

        //if the robot moves left
        if(visited[_x][_y][(_dir+3)%4] == INF) {
            visited[_x][_y][(_dir+3)%4] = _w + 1;
            q.push(make_pair(make_pair((_dir+3)%4, _w+1), make_pair(_x, _y)));
        }
    }
    return -1;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    char S[10];

    while(scanf("%d %d", &N, &M) && (N || M)) {

        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++) {
                scanf(" %d ", &q);
                input[i][j] = (bool)q;
            }
        scanf("%d %d %d %d %s", &start_x, &start_y, &end_x, &end_y, S);

        if(S[0] ==  'e')
            dir = 1;
        else if(S[0] == 'n')
            dir = 0;
        else if(S[0] == 'w')
            dir = 3;
        else
            dir = 2;

        printf("%d\n", bfs());
    }
    return 0;
}
