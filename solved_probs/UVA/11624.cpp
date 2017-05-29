//UVa
//11624 - Fire!
//Multi Source Shortest Paths
//BFS

#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int fire[MAX][MAX], joe_x, joe_y, R, C;
int r[] = {-1, 1, 0, 0}, c[] = {0, 0, 1, -1};
char mat[MAX][MAX];
vector<pair<int, int> >fire_points;


void BFS_fire(int fire_x, int fire_y)
{
    queue<pair<int, pair<int, int> > >q;
    q.push(make_pair(0, make_pair(fire_x, fire_y)));

    //fire[x][y] contains the time when point (x, y) is on fire

    fire[fire_x][fire_y] = 0;

    while(!q.empty()) {
        int _x = q.front().second.first;
        int _y = q.front().second.second;
        int fire_time = q.front().first;
        q.pop();

        fire_time++;

        for(int i = 0; i < 4; i++) {
            int x = _x + r[i];
            int y = _y + c[i];

            //the point is in fire if it is not fired yet,
            //if it is fired earlier then skip it
            if(x > -1 & x < R && y > -1 && y < C && (fire[x][y] == -1 || fire[x][y] > fire_time) && mat[x][y] == '.') {
                fire[x][y] = fire_time;
                q.push(make_pair(fire_time, make_pair(x, y)));
            }
        }
    }
}

int Bfs_joe()
{
    bool visited[R+1][C+1];
    memset(visited, 0, sizeof visited);
    queue<pair<int, pair<int, int> > >q;
    q.push(make_pair(0, make_pair(joe_x, joe_y)));
    visited[joe_x][joe_y] = 1;

    while(!q.empty()) {
        int _x = q.front().second.first;
        int _y = q.front().second.second;
        int joe_time = q.front().first;

        q.pop();
        joe_time++;

        if(_x == 0 || _y == 0 || _x == R-1 || _y == C-1)
            return joe_time;

        for(int i = 0; i < 4; i++) {
            int x = _x + r[i];
            int y = _y + c[i];

            //joe can visit point (x, y) if the point is not in fire at that time
            if(x > -1 && y > -1 && x < R && y < C) {
                if(!visited[x][y] && (fire[x][y] > joe_time || fire[x][y] == -1)&& mat[x][y] == '.') {
                    visited[x][y] = 1;
                    q.push(make_pair(joe_time, make_pair(x, y)));
                }
            }
        }
    }
    return -1;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &R, &C);
        joe_x = joe_y = -1;
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++) {
                scanf(" %c ", &mat[i][j]);
                if(mat[i][j] == 'J') {
                    joe_x = i;
                    joe_y = j;
                }
                //fire points may be more than one
                //it is not defined in the problem

                if(mat[i][j] == 'F') {
                    fire_points.push_back(make_pair(i, j));
                }
            }
        memset(fire, -1, sizeof fire);
        for(int i = 0; i < fire_points.size(); i++)
            BFS_fire(fire_points[i].first, fire_points[i].second);
        if(joe_x != -1 && joe_y != -1) {
            int ans = Bfs_joe();
            if(ans != -1)
                printf("%d\n", ans);
            else
                printf("IMPOSSIBLE\n");
        }
        else
            printf("IMPOSSIBLE\n");
        fire_points.clear();
    }
    return 0;
}
