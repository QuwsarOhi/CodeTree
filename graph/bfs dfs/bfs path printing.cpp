//UVa
//11049 - Basic wall maze
//Breadth First Search (Path Printing)

#include<bits/stdc++.h>
using namespace std;

map<pair<pair<int, int>, pair<int, int> >, bool>not_visitable;
int path[8][8], r[] = {-1, 0, 1, 0}, c[] = {0, 1, 0, -1};
bool visited[8][8];
char dir[5] = "NESW";

void horizontal(int start_x, int start_y, int end_x, int end_y)
{
    for(int i = start_y+1; i <= end_y; i++) {
        //printf("h %d %d | %d %d\n", start_x, i, start_x+1, i);
        not_visitable[make_pair(make_pair(start_x, i), make_pair(start_x+1, i))] = 1;
        not_visitable[make_pair(make_pair(start_x+1, i), make_pair(start_x, i))] = 1;
    }
}

void vertical(int start_x, int start_y, int end_x, int end_y)
{
    for(int i = start_x+1; i <= end_x; i++) {
        //printf("v %d %d | %d %d\n", i, start_y, i, start_y+1);
        not_visitable[make_pair(make_pair(i, start_y), make_pair(i, start_y+1))] = 1;
        not_visitable[make_pair(make_pair(i, start_y+1), make_pair(i, start_y))] = 1;
    }
}

void BFS(int start_x, int start_y, int end_x, int end_y)
{
    memset(visited, 0, sizeof visited);
    queue<pair<int, int> >q;
    q.push(make_pair(start_x, start_y));
    visited[start_x][start_y] = 1;

    while(!q.empty()) {
        int _x = q.front().first;
        int _y = q.front().second;

        q.pop();

        //printf("BFS %d %d\n", _x, _y);

        if(_x == end_x && _y == end_y)
            return;

        for(int i = 0; i < 4; i++) {
            int x = _x + r[i];
            int y = _y + c[i];

            if(x > 0 && y > 0 && x <= 6 && y <= 6) {
                if(!visited[x][y] && !not_visitable[make_pair(make_pair(_x, _y), make_pair(x, y))]) {
                    //printf("%d %d\n", x, y);
                    visited[x][y] = 1;
                    path[x][y] = i;
                    q.push(make_pair(x, y));
                }
            }
        }
    }
}

void pathPrinter(int start_x, int start_y, int end_x, int end_y)
{
    if(end_y == start_y && end_x == start_x) {
        //printf("%c", dir[path[end_x][end_y]]);
        return;
    }
    if(path[end_x][end_y] == 0)
        pathPrinter(start_x, start_y, end_x+1, end_y);
    else if(path[end_x][end_y] == 1)
        pathPrinter(start_x, start_y, end_x, end_y-1);
    else if(path[end_x][end_y] == 2)
        pathPrinter(start_x, start_y, end_x-1, end_y);
    else if(path[end_x][end_y] == 3)
        pathPrinter(start_x, start_y, end_x, end_y+1);

    printf("%c", dir[path[end_x][end_y]]);
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int start_x, start_y, end_x, end_y;
    while(scanf("%d %d", &start_y, &start_x) && (start_x || start_y)) {
        scanf("%d %d", &end_y, &end_x);
        for(int i = 0; i < 3; i++) {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
            if(x1 == x2)
                horizontal(x1, y1, x2, y2);
            else
                vertical(x1, y1, x2, y2);
        }
        BFS(start_x, start_y, end_x, end_y);
        pathPrinter(start_x, start_y, end_x, end_y);
        printf("\n");
        not_visitable.clear();
    }
    return 0;
}
