// LightOJ
// 1055 - Going Together

#include <bits/stdc++.h>
using namespace std;

char G[15][15];
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0}, n;
bool vis[11][11][11][11][11][11];

bool Check(vector<int> &x, vector<int> &y) {
    return vis[x[0]][y[0]][x[1]][y[1]][x[2]][y[2]];
}

void Set(vector<int> &x, vector<int> &y) {
    vis[x[0]][y[0]][x[1]][y[1]][x[2]][y[2]] = 1;
}
    
int bfs(vector<int> x, vector<int> y) {
    queue<pair<int, pair<vector<int>, vector<int> > > >q;
    q.push(make_pair(0, make_pair(x, y)));
    memset(vis, 0, sizeof vis);
    Set(x, y);
    vector<int> _x(3), _y(3);
    
    while(!q.empty()) {
        x = q.front().second.first;
        y = q.front().second.second;
        int w = q.front().first;
        q.pop();
        
        bool ok = 1;
        for(int i = 0; i < 3; ++i)
            if(G[x[i]][y[i]] != 'X')
                ok = 0;
        if(ok)
            return w;
        
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 3; ++j) {
                _x[j] = x[j]+dx[i];
                _y[j] = y[j]+dy[i];
                
                if(_x[j] < 0 || _x[j] >= n || _y[j] < 0 || _y[j] >= n || G[_x[j]][_y[j]] == '#')
                    _x[j] = x[j], _y[j] = y[j];
            }
            
            for(int j = 0; j < 3; ++j)
                for(int k = j+1; k < 3; ++k)
                    if(_x[j] == _x[k] && _y[j] == _y[k]) {
                        if(_x[j] != x[j] || _y[j] != y[j])
                            _x[j] = x[j], _y[j] = y[j];
                        else
                            _x[k] = x[k], _y[k] = y[k];
                    }
            
            ok = 1;
            for(int j = 0; j < 3; ++j)
                for(int k = j+1; k < 3; ++k)
                    if(_x[j] == _x[k] && _y[j] == _y[k])
                        ok = 0;
            
            if(!ok || Check(_x, _y))
                continue;
            Set(_x, _y);
            q.push(make_pair((w+1), make_pair(_x, _y)));
        }
    }
    return -1;
}


int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t;
    scanf("%d", &t);
    vector<int>x, y;
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &n);
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) {
                scanf(" %c", &G[i][j]);
                if(G[i][j] >= 'A' && G[i][j] <= 'C')
                    x.push_back(i), y.push_back(j);
            }
        
        int ans = bfs(x, y);
        if(ans != -1)
            printf("Case %d: %d\n", Case, ans);
        else
            printf("Case %d: trapped\n", Case);
        x.clear(), y.clear();
    }
        
    return 0;
}
        
