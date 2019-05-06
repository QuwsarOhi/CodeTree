#include <bits/stdc++.h>
#define MAX 105
#define INF 0x3f3f3f3f
using namespace std;

bool g[MAX][MAX];
int n;


vector<pair<pair<int, int>, char> > ans, v;

void go(int x, int y) {
    if(x > n) {
        if(v.size() < ans.size() or ans.empty()) 
            ans = v;
        return;
    }
    if(y > n) {
        go(x+1, 1);
        return;
    }

    if(g[x][y]) {
        if(g[x-1][y-1]) {
            v.push_back({{x, y}, 'L'});
            go(x, y+1);
            v.pop_back();
        }
        else if(g[x-1][y+1]) {
            v.push_back({{x, y}, 'R'});
            go(x, y+1);
            v.pop_back();
        }
        else
            go(x, y+1);
    }
    else
        go(x, y+1);
}


int main() {
    int t;
    char c;
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);
        memset(g, 0, sizeof g);

        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j) {
                scanf(" %c", &c);
                if(c == 'O') g[i][j] = 1;
            }

        ans.clear(), v.clear();
        go(1, 1);
        printf("%d\n", (int)ans.size());
        sort(ans.begin(), ans.end());
        for(auto it : ans)
            printf("%d %d %c\n", it.first.first, it.first.second, it.second);
    }

    return 0;
}