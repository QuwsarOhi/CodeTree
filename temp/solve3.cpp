#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


bool Get(int x, int y, const ll &v) {
    int idx = x*8+y;
    return v & (1LL << idx);
}

void Set(int x, int y, ll &v) {
    int idx = x*8+y;
    v |= (1LL << idx);
}

void Reset(int x, int y, ll &v) {
    int idx = x*8+y;
    v &= ~(1LL << idx);
}

void Toggle(int x, int y, ll &v) {
    int idx = x*8+y;
    v ^= (1LL << idx);
}

int n, m;

bool OK(const ll &v) {
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(not Get(i, j, v))
                return 0;
    return 1;
}

ll turnOn(int x, int y, ll v) {
    // horizontal 
    for(int i = 0; i < m; ++i)
        Toggle(x, i, v);
    
    // vertical
    for(int i = 0; i < n; ++i)
        Toggle(i, y, v);
    
    // diagonals
    int xx = x, yy = y;
    while(xx >= 0 and yy >= 0)
        Toggle(xx--, yy--, v);
    xx = x, yy = y;
    while(xx < n and yy < m)
        Toggle(xx++, yy++, v);

    //

    xx = x, yy = y;
    while(xx < n and yy >= 0)
        Toggle(xx++, yy--, v);

    xx = x, yy = y;
    while(xx >= 0 and yy < m)
        Toggle(xx--, yy++, v);

    Toggle(x, y, v);
    return v;
}


void printer(ll vv) {
    for(int i = 0; i < n; ++i, printf("\n"))
        for(int j = 0; j < m; ++j)
            printf("%c ", Get(i, j, vv) ? '*':'.');
}

map<ll, int>dist;

int bfs(ll u) {
    queue<ll> q;
    q.push(u);
    dist[u] = 0;

    ll v;
    while(not q.empty()) {
        u = q.front();
        q.pop();

        if(OK(u))
            return dist[u];

        int tmp = dist[u] + 1;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                v = turnOn(i, j, u);

                if(i == 2 and j == 2) {
                    cerr << "NEW " << tmp << endl;
                    printer(v);
                    getchar();
                }

                if(dist.find(v) != dist.end()) continue;
                dist[v] = tmp;

                q.push(v);
            }
        }
    }

    return -1;
}


int main() {
    int t;
    char cc;
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &n, &m);

        ll gg = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) {
                scanf(" %c", &cc);
                if(cc == '*') {
                    cerr << i << " " << j << endl;
                    Set(i, j, gg);
                }
            }


        printer(gg);

        dist.clear();
        int ans = bfs(gg);

        printf("Case %d: ", Case);
        if(ans == -1)
            printf("impossible\n");
        else
            printf("%d\n", ans);
    }

    return 0;
}