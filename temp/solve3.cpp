#include <bits/stdc++.h>
using namespace std;

string g[102];
int cnt = 0, n, TOT;
bool p[102][102], vis[102][102];

vector<pair<int, int> > Ans, V;

void SET(int x, int y, bool v) {
    vis[x][y] = v;
    for(int i = 0; i < n; ++i) {
        if(p[x][i] != v) {
            if(v) cnt += 1; //cout << "ADD " << x << " " << i << endl; }
            else cnt -= 1;
            p[x][i] = v;
        }
        if(p[i][y] != v) {
            if(v) cnt += 1; //cout << "ADD " << i << " " << y << endl; }
            else cnt -= 1;
            p[i][y] = v;
        }
    }
}


void recur(int x, int y) {
    cout << x+1 << " " << y+1 << " " << cnt << endl;
    
    V.push_back({x, y});
    SET(x, y, 1);
     
    if(cnt == TOT) {
        cout << "ANS SIZE " << V.size() << endl;
        if(Ans.empty() or Ans.size() > V.size())
            Ans = V;
        return;
    }
    
    if(not Ans.empty() and Ans.size() < V.size())
        return;
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(not vis[i][j] and g[i][j] != 'E')
                recur(i, j);
    
    V.pop_back();
    SET(x, y, 0);
    
    cout << "Fall\n";
    //getchar();
}

int main() {
    cin >> n;
    TOT = n*n;
    
    for(int i = 0; i < n; ++i)
        cin >> g[i];
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(g[i][j] != 'E') {
                //cout << "NEW START " << i << " " << j << endl;
                recur(i, j);
            }
    
    if(Ans.empty())
        return !puts("-1");
    
    for(auto it : Ans)
        cout << it.first+1 << " " << it.second+1 << endl;
    return 0;
}
