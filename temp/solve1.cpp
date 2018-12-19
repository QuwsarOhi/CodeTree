#include <bits/stdc++.h>
using namespace std;


bool valid(pii x) {
    if(x.first < 0 or x.first >= 8)
        return 0;
    if(x.second < 0 or x.second >= 8)
        return 0;
    return 1;
}

int dist[8][8], mem[8][8][8][8];

int bfs(pii s, pii t) {
    if(mem[u.first][u.second] != -1)
        return mem[u.first][u.second];

    queue<pii>q;
    q.push(s);
    dist[s.first][s.second] = 0;

    pii u, v;
    while(not q.empty()) {
        u = q.front();
        q.pop();

        if(u == t)
            return mem[u.first][u.second] = dist[u.first][u.second];

        for(int i = 0; i < 8; ++i) {
            v.first = u.first + dx[i];
            v.second = u.second + dy[i];

            if(not valid(v)) 
                continue;
            if(G[v.first][v.second] != '.' and G[v.first][v.second] != 'P')
                continue;

            dist[v.first][v.second] = dist[u.first][u.second] + 1;
            q.push(v);
        }
    }

    return -1;
}


int recur(int placed, int x, int y, int mask) {
    if(placed == )
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &step);

        for(int i = 0; i < 8; ++i)
            scanf("%s", &G[i]);


    }
}

/*
3

...pP...
..P..k.K
p.....p.
...p....
...p....
........
.p......
........