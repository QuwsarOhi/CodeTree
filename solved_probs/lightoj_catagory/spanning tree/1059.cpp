// LightOJ
// 1059 - Air Ports

#include <bits/stdc++.h>
using namespace std;

vector<int>u_list, u_set;
vector<pair<int, pair<int, int> > >Edge;
bitset<10010>found;

//u_list[x] contains the size of a set x
//u_set[x] contains the root of x

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

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, V, E, A, u, v, w;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d%d", &V, &E, &A);
        
        for(int i = 0; i < E; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            if(w < A)
                Edge.push_back(make_pair(w, make_pair(u, v)));
        }
        
        sort(Edge.begin(), Edge.end());
        int MST = 0, SelectedEdge = 0;
        unionInit(V+2);
        
        for(int i = 0; i < (int)Edge.size() && SelectedEdge < V; ++i) {
            u = Edge[i].second.first;
            v = Edge[i].second.second;
            w = Edge[i].first;
            if(!isSameSet(u, v)) {
                SelectedEdge++;
                MST += w;
                makeUnion(u, v);
            }
        }
        
        int TOT = 0;
        for(int i = 1; i <= V && TOT < V; ++i) {
            int u = unionRoot(i);
            if(!found[u]) {
                TOT += u_list[u];
                found[u] = 1;
            }
        }
        
        printf("Case %d: %d %d\n", Case, MST+(found.count()*A), found.count());
        
        Edge.clear();
        found.reset();
    }
    return 0;
}
