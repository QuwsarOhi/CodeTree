// LightOJ
// 1276 - Very Lucky Numbers

#include <bits/stdc++.h>
#define LIM 1e12+10
using namespace std;

typedef long long ll;

vector<ll> lucky;

void gen(ll val) {
    if(val > LIM)
        return;

    if(val > 0)
        lucky.push_back(val);

    gen(val*10 + 4);
    gen(val*10 + 7);
}

set<ll>vis;
void bfs() {
    queue<ll> q;

    for(int i = 0; i < lucky.size(); ++i)
        q.push(lucky[i]);

    ll u, v;
    while(not q.empty()) {
        u = q.front();
        q.pop();

        for(int i = 0; i < lucky.size(); ++i) {
            v = u*lucky[i];
            if(v < 0 or v > LIM)
                break;
            if(vis.count(v))
                continue;
            vis.insert(v);
            q.push(v);
        }
    }
}

int main() {
    gen(0);
        
    sort(lucky.begin(), lucky.end());
    bfs();

    for(set<ll> :: iterator it = vis.begin(); it != vis.end(); ++it)
        lucky.push_back(*it);
    sort(lucky.begin(), lucky.end());
    lucky.erase(unique(lucky.begin(), lucky.end()), lucky.end());

    //cout << "DONE\n";
    int t;
    ll a, b;
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lld%lld", &a, &b);
        if(a > b) swap(a, b);
        printf("Case %d: %d\n", Case, int(upper_bound(lucky.begin(), lucky.end(), b) - lower_bound(lucky.begin(), lucky.end(), a)));
    }

    return 0;
}