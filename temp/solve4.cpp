// LightOJ
// 1123 - Trail Maintenance

#include <bits/stdc++.h>
using namespace std;

vector<int>u_list, u_set;               // u_list[x] contains the size of a set x
                                        // u_set[x] contains the root of x
set<pair<int, pair<int, int> > >Edge;
int E[201][201];

int unionRoot(int n) {
    if(u_set[n] == n)
        return n;
    else
        return u_set[n] = unionRoot(u_set[n]);
}

int makeUnion(int a, int b) {
    int x = unionRoot(a);
    int y = unionRoot(b);
    if(x == y)
        return x;
    else if(u_list[x] > u_list[y]) {
        u_set[y] = x;
        u_list[x] += u_list[y];
        return x;
    }
    else {
        u_set[x] = y;
        u_list[y] += u_list[x];
        return y;
    }
}

void unionInit(int len) {
    u_list.resize(len+5, 1);
    u_set.resize(len+5);
    for(int i = 0; i <= len+3; i++)
        u_set[i] = i, u_list[i] = 0;
}

bool isSameSet(int a, int b) {
    if(unionRoot(a) == unionRoot(b))
        return 1;
    return 0;
}

int MST(int V) {
    int mstCost = 0, edge = 0;
    unionInit(V+10);
    set<pair<int, pair<int, int> > > :: iterator it = Edge.begin();
    
    for( ; it != Edge.end() && edge < V; ++it) {
        int u = (*it).second.first;
        int v = (*it).second.second;
        int w = (*it).first;
        
        if(!isSameSet(u, v)) {
            E[u][v] = E[v][u] = w;
            ++edge, mstCost += w, makeUnion(u, v);
        }
    }
    
    if(edge != V-1)
        return -1;
    
    for(it = Edge.begin(); it != Edge.end(); ++it) {
        int u = (*it).second.first;
        int v = (*it).second.second;
        int w = (*it).first;
        
        if(E[u][v] != w) {
            Edge.erase(it);
            if(it == Edge.end())
                break;
        }
    }
    
    return mstCost;
}
    
int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    
    int t, u, v, V, W, w;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &V, &W);
        printf("Case %d:\n", Case);
        int ans = -1;
        memset(E, -1, sizeof E);
        
        for(int i = 1; i <= W; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            Edge.insert(make_pair(w, make_pair(u, v)));
            
            if(i >= V-1)
                ans = MST(V);
            
            printf("%d\n", ans);
        }
        Edge.clear();
    }
    
    return 0;
}
