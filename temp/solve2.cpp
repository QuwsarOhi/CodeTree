// LightOJ
// 1434 - Patch Quilt

#include <bits/stdc++.h>
using namespace std;
 
int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
vector<string>p;
int n, m, len;
char s[50], G[50][50];
bool ok[30];

void printer(int x, int y, int pos, int dir) {
    if(pos == 0) {
        string ss = "(";
        ss += to_string(x+1);
        ss += ",";
        ss += to_string(y+1);
        ss += ")";
        p.push_back(ss);
        return;
    }
 
    if(dir == 0)
        p.push_back("UL");
    else if(dir == 1)
        p.push_back("U");
    else if(dir == 2)
        p.push_back("UR");
    else if(dir == 3)
        p.push_back("L");
    else if(dir == 4)
        p.push_back("*");
    else if(dir == 5)
        p.push_back("R");
    else if(dir == 6)
        p.push_back("DL");
    else if(dir == 7)
        p.push_back("D");
    else
        p.push_back("DR");
}
 
bool dfs(int x, int y, int pos) {
    if(pos == len)
        return 1;
 
    for(int i = 0; i < 9; ++i) {
        int xx = x+dx[i];
        int yy = y+dy[i];
 
        if(xx < 0 or xx >= n or yy < 0 or yy >= m or G[xx][yy] != s[pos])
            continue;
 
        if(dfs(xx, yy, pos+1)) {
            printer(xx, yy, pos, i);
            return 1;
        }
    }
    return 0;
}
 
int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
 
    int t, q;
    scanf("%d", &t);
 
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &n, &m);
    
        memset(ok, 0, sizeof ok);
        for(int i = 0; i < n; ++i) {
            scanf("%s", G[i]);
            for(int j = 0; j < m; ++j)
                ok[G[i][j]-'A'] = 1;
        }
 
        printf("Case %d:\n", Case);
        scanf("%d", &q);
 
        while(q--) {
            scanf("%s", s);
            len = strlen(s);
            bool found = 0;
            
            for(int i = 0; i < len; ++i)
                if(not ok[s[i]-'A'])
                    goto pass;

            for(int i = 0; i < n and not found; ++i)
                for(int j = 0; j < m and not found; ++j)
                    if(dfs(i, j, 0))
                        found = 1;

            pass:;
            if(not found)
                printf("%s not found\n", s);
            else {
                printf("%s found:", s);
                for(int i = (int)p.size()-1; i >= 0; --i) {
                    if(i != (int)p.size()-1)
                        printf(",");
                    printf(" %s", p[i].c_str());
                }
                printf("\n");
            }
            p.clear();
        }
    }
 
    return 0;
}