// UVa
// 125 - Numbering Paths

// Nice problem for cycle detection

#include <bits/stdc++.h>
#define MAX 40
using namespace std;

vector<int>G[MAX];
bitset<MAX>vis;

int dfs1(int u, int target, bool first = 1) {       // Counts number of path
    if(not first and u == target)
        return 1;
    
    if(first)
        vis.reset();
    vis[u] = 1;
    int ret = 0;
    
    for(auto v : G[u])
        if(!vis[v] or v == target)
            ret += dfs1(v, target, 0);
    
    vis[u] = 0;
    return ret;
}

bool canGo(int u, int to, bool first = 1) {         // If there is a path between u -> to 
    if(u == to)
        return 1;
        
    if(first)
        vis.reset();
        
    vis[u] = 1;
    for(auto v : G[u])
        if(!vis[v] and canGo(v, to, 0))
            return 1;
    return 0;
}
    

int color[MAX];
bool dfs2(int u, int from, int to) {                // Checks for cycle in path u -> v
    color[u] = 2;
    
    for(auto v : G[u]) {
        if(color[v] == 2) {
            if(canGo(from, v) and canGo(v, to))     // if the cycle is in middle of some way from 'from' to 'to' (u to v)
                return 1;
        }
        else if(color[v] != 1)
            if(dfs2(v, from, to))
                return 1;
    }
    
    color[u] = 1;
    return 0;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int n, u, v, Case = 0;
    
    while(scanf("%d", &n) == 1) {
        printf("matrix for city %d\n", Case++);
        
        int V = -1;
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
            V = max(V, max(u, v));
        }
        
        if(V == -1) continue;
        
        for(int i = 0; i <= V; ++i, printf("\n"))
            for(int j = 0; j <= V; ++j) {
                if(j) printf(" ");
                
                int ans = dfs1(i, j);
                
                if(ans == 0)
                    printf("0");
                else {
                    memset(color, 0, sizeof color);
                    if(dfs2(i, i, j))
                        printf("-1");
                    else
                        printf("%d", ans);
                }
            }
        
        for(int i = 0; i <= V; ++i)
            G[i].clear();
    }
    
    return 0;
}


/*
4
0 1
1 2
2 0
0 3

4
0 4
0 1
1 2
2 3

5
0 4
0 1
1 2
2 3
1 0

5
0 1
1 2
2 3
3 1
1 4

6
0 1
0 2
1 3
3 4
4 5
5 3

7
0 1
0 2
1 3
3 4
4 5
5 3
3 1

4
0 1
1 2
2 3
3 0

6
0 1
1 4
4 2
2 1
2 3
1 2

2
1 2
2 1

1
0 0
*/
