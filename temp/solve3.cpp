// Timus
// 1671. Anansi's Cobweb

// Graph Component edge deletion

// Offline 
// As the edges are undirected, we can use union distjoint to count components

#include <bits/stdc++.h>
using namespace std;

vector<int>u_list, u_set;

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

    for(int i = 0; i <= len; i++)
        u_set[i] = i;
}

bool isSameSet(int a, int b) {
    if(unionRoot(a) == unionRoot(b))
        return 1;
    return 0;
}

vector<pair<int, int> >Edge;
vector<int>Query;
int ans[100100];
bool Break[100100];

int main() {
    int n, m, u, v, q, e;
    
    scanf("%d%d", &n, &m);
    
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        Edge.push_back({u, v});
    }
    
    scanf("%d", &q);
    for(int i = 0; i < q; ++i) {
        scanf("%d", &e);
        Query.push_back(e);
        Break[e] = 1;
    }
    
    int comp = n;
    unionInit(n);
    
    for(int i = 0; i < m; ++i)
        if(!Break[i+1]) {
            if(unionRoot(Edge[i].first) != unionRoot(Edge[i].second))
                --comp;
            makeUnion(Edge[i].first, Edge[i].second);
        }
        
    for(int i = q-1; i >= 0; --i) {
        ans[i] = comp;
        int j = Query[i]-1;
        if(unionRoot(Edge[j].first) != unionRoot(Edge[j].second))
            --comp;
        makeUnion(Edge[j].first, Edge[j].second);
    }
    
    printf("%d", ans[0]);
    for(int i = 1; i < q; ++i)
        printf(" %d", ans[i]);
    
    return 0;
}

