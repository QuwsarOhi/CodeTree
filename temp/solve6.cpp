// LightOJ
// 1424 - New Land

#include <bits/stdc++.h>
using namespace std;

int g[2010][2010];

int maxHistogram(int idx, int n) {
    stack<int>s;
    int area = 0;

    int i = 0;
    while(i < n) {
        if(s.empty() or g[s.top()][idx] <= g[i][idx])
            s.push(i++);
        else {
            int r = s.top(), d = i;
            s.pop();
            if(not s.empty())
                d -= s.top() + 1;

            area = max(area, g[r][idx] * d);
    }}

    while(not s.empty()) {
        int r = s.top(), d = i;
        s.pop();
        if(not s.empty())
            d -= s.top() + 1;
        area = max(area, g[r][idx] * d);
    }

    return area;
}


int main() {
    int t, n, m;
    char c;
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &n, &m);

        memset(g, 0, sizeof g);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) {
                scanf(" %c", &c);
                if(c == '0')
                    g[i][j] = 1 + (j-1 >= 0 ? g[i][j-1]:0);
                else
                    g[i][j] = 0;
            }

        int ans = 0;
        for(int i = 0; i < m; ++i)
            ans = max(ans, maxHistogram(i, n));

        printf("Case %d: %d\n", Case, ans);
    }

    return 0;
}

