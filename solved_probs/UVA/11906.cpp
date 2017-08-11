//UVa
//11906 - Knight in a War Grid
#include<bits/stdc++.h>
using namespace std;

bool water[101][101];
bool visited[101][101];
int R, C, M, N, W, even, odd;

queue<pair<int, int> >q;

void dfs(int x, int y, int r[], int c[])
{
    bool mark[101][101];
    memset(mark, 0, sizeof(mark));
    int cnt = 0;
    for(int i = 0; i < 8; i++) {
            int X = x+r[i];
            int Y = y+c[i];
            if(X < R && Y < C && X >= 0 && Y >= 0 && !water[X][Y]) {
                if(!mark[X][Y]) {
                    cnt++;
                    mark[X][Y] = 1;
                    if(!visited[X][Y]) {
                        visited[X][Y] = 1;
                        q.push(make_pair(X, Y));
                    }
                }
            }
        }
    if(cnt % 2 == 0) {
        even++;
    }
    else {
        odd++;
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        scanf("%d %d %d %d %d", &R, &C, &M, &N, &W);
        memset(water, 0, sizeof(water));
        memset(visited, 0, sizeof(visited));
        even = odd = 0;
        int r[] = {M, M, -M, -M, N, N, -N, -N};
        int c[] = {N, -N, N, -N, M, -M, M, -M};
        while(W--) {
            int x, y;
            scanf("%d %d", &x, &y);
            water[x][y] = 1;
        }
        dfs(0, 0, r, c);
        visited[0][0] = 1;
        while(!q.empty()) {
            dfs(q.front().first, q.front().second, r, c);
            q.pop();
        }
        printf("Case %d: %d %d\n", Case, even, odd);
    }
    return 0;
}
