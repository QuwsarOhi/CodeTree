// ICPCLive
// 4872 - Underground Cables
#include <bits/stdc++.h>
using namespace std;

double dist(int x1, int y1, int x2, int y2) {
    double dx = x1-x2, dy = y1-y2;
    return sqrt(dx*dx + dy*dy);
}

priority_queue<pair<double, int> >pq;
vector<pair<int, int> > p;
bitset<1009>taken;
int n;

void process(int u) {
    taken[u] = 1;
    for(int v = 0; v < n; ++v) {
        if(taken[v]) continue;
        pq.push({-dist(p[u].first, p[u].second, p[v].first, p[v].second), -v});
    }
}

int main() {
    int x, y;
    while(cin >> n) {
        if(n == 0) break;

        p.clear();
        taken.reset();

        for(int i = 0; i < n; ++i) {
            cin >> x >> y;
            p.push_back({x, y});
        }

        double ans = 0;
        process(0);
        while(not pq.empty()) {
            double w = -pq.top().first;
            int v = -pq.top().second;
            pq.pop();

            if(not taken[v])
                process(v), ans += w;
        }

        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}