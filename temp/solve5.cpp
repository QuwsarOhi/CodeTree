#include <bits/stdc++.h>
using namespace std;

int r, c;
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
char G[60][60];

bool valid(int x, int y) {
    if(x < 0 || y < 0 || x >= r || y >= c)
        return 0;
    return 1;
}

// Boundary Fill

bool b[60][60];
void BoundaryFill(int x, int y) {
    b[x][y] = 1;
    for(int i = 0; i < 4; ++i) {
        int _x = x+dx[i];
        int _y = y+dy[i];
        
        if(valid(_x, _y) && !b[_x][_y] && G[_x][_y] == '.')
            BoundaryFill(_x, _y);
}}


void Boundary() {
    memset(b, 0, sizeof b);
    for(int i = 0; i < c; ++i) {
        if(G[0][i] == '.' && !b[0][i])
            BoundaryFill(0, i);
        if(G[r-1][i] == '.' && !b[r-1][i])
            BoundaryFill(r-1, i);
    }
    
    for(int i = 0; i < r; ++i) {
        if(G[i][0] == '.' && !b[i][0])
            BoundaryFill(i, 0);
        if(G[i][c-1] == '.' && !b[i][c-1])
            BoundaryFill(i, c-1);
}}

bool vis[60][60];
char SurroundedBy(int x, int y) {
    memset(vis, 0, sizeof vis);
    
    queue<pair<int, int> >q;
    q.push(make_pair(x, y));
    vis[x][y] = 1;
    vector<char>v;
    
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int _x = x+dx[i];
            int _y = y+dy[i];
            
            if(!valid(_x, _y) || b[_x][_y]) {
                v.push_back(G[x][y]);
                continue;
            }
            
            if(vis[_x][_y])
                continue;
                
            vis[_x][_y] = 1;
            q.push(make_pair(_x, _y));
    }}
    
    for(int i = 0; i < (int)v.size()-1; ++i)
        if(v[i] != v[i+1]) return 0;
    return v[0];
}

void Fill(int x, int y, char c, bool dot = 0) {
    vis[x][y] = 1;
    for(int i = 0; i < 4; ++i) {
        int _x = x+dx[i];
        int _y = y+dy[i];
        
        if(!valid(_x, _y) || b[_x][_y])
            continue;
        if(dot) {
            if(G[_x][_y] == '.' && !vis[_x][_y])
                Fill(_x, _y, c, dot);
        }
        else if(!vis[_x][_y] && G[x][y] == G[_x][_y])
            Fill(_x, _y, c, dot);
    }
    G[x][y] = c;
}
        
void CenterFill() {
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j) {
            if(b[i][j] || ((i == 0 || i == r-1 || j == 0 || j == c-1)))
                for(int k = 0; k < 4; ++k) {
                    int x = i+dx[k];
                    int y = j+dy[k];
                
                    if(valid(x, y) && !b[x][y]) {
                        memset(vis, 0, sizeof vis);
                        Fill(x, y, G[x][y], 1);
}}}}


void MarkSurrounded(int x, int y) {
    int cnt[60][60] = {0};
    queue<pair<int, int> >q;
    q.push(make_pair(x, y));
    vis[x][y] = cnt[x][y] = 1;
    char T = G[x][y];
    
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int _x = x+dx[i];
            int _y = y+dy[i];
            
            if(!valid(_x, _y))
                continue;
            
            if(G[_x][_y] == T && vis[_x][_y] == 1)
                continue;
            
            if(G[_x][_y] != T)
                ++cnt[_x][_y];
            
            
            

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t;
    scanf("%d", &t);
    vector<pair<int, int> >v;
    bool found[26];
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &r, &c);
        memset(found, 0, sizeof found);
        v.clear();
        
        for(int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j) {
                scanf(" %c", &G[i][j]);
                if(G[i][j] != '.' && !found[G[i][j]-'A'])
                    v.push_back(make_pair(i, j)), found[G[i][j]-'A'] = 1;
            }
        
        Boundary();
        CenterFill();
        
        cout << endl;
        for(int i = 0; i < r; ++i, printf("\n"))
            for(int j = 0; j < c; ++j)
                printf("%c", b[i][j]?'x':G[i][j]);
        
        
        
        //cout << endl;
        printf("Case %d:\n", Case);
        for(int i = 0; i < r; ++i, printf("\n"))
            for(int j = 0; j < c; ++j)
                printf("%c", G[i][j]);
        
    }
    return 0;
}


/*

1
5 5
.BBB.
.B.B.
.B.B.
.BBB.
.....

3 3
B.B
B.B
B.B

*/

