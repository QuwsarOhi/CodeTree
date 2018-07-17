// LightOJ
// 1165 - Digit Dancing

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

//                0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
bool isPrime[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1};


int GETWEIGHT(vi &VV) {
    int ret = 0;
    for(int i = 0; i < 8; ++i) ret = ret*10 + abs(VV[i]);
    return ret;
}

vi v;
void GETVEC(vi &u, int p1, int p2, bool kk) {
    v = u;
    for( ; max(0, p1+kk) < p2; --p2)
        swap(v[p2], v[p2-1]);
    for( ; p2 < max(p1-kk, 0); ++p2)
        swap(v[p2], v[p2+1]);
}

map<int, int>vis;
vi pos, neg;

void TRY(queue<vi> &q, vi &u, int i, int j, int w, bool s) {
    GETVEC(u, i, j, s);
    int ss = GETWEIGHT(v);
    if(vis.find(ss) == vis.end()) {
        vis[ss] = w+1;
        q.push(v);
    }
}

int BFS(vi u) {
    vis.clear();
    queue<vi>q;
    q.push(u);
    int ss = GETWEIGHT(u);
    vis[ss] = 0;
    
    while(!q.empty()) {
        u = q.front();
        ss = GETWEIGHT(u);
        int w = vis[ss];
        q.pop();
        
        bool ok = 1;
        pos.clear(), neg.clear();
        for(int i = 0; i < (int)u.size(); ++i) {
            if(i > 0 && (abs(u[i-1]) > abs(u[i]))) ok = 0;
            if(u[i] > 0) pos.push_back(i);
            else neg.push_back(i);
        }
        if(ok) return w;
        
        for(int i = 0; i < (int)pos.size(); ++i) {
            for(int j = 0; j < (int)neg.size(); ++j) {
                if(!isPrime[abs(u[pos[i]]) + abs(u[neg[j]])])
                    continue;

                TRY(q, u, pos[i], neg[j], w, 0);
                TRY(q, u, pos[i], neg[j], w, 1);
                TRY(q, u, neg[j], pos[i], w, 0);
                TRY(q, u, neg[j], pos[i], w, 1);
            }
        }
    }
    
    return -1;
}


int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, x;
    scanf("%d", &t);
    
    
    for(int Case = 1; Case <= t; ++Case) {
        v.clear();
        for(int i = 0; i < 8; ++i) {
            scanf("%d", &x);
            v.push_back(x);
        }
        
        int ans = BFS(v);
        printf("Case %d: %d\n", Case, ans);
    }
    return 0;
}
