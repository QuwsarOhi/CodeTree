// LightOJ
// 1041 - Road Construction
// MST

#include <bits/stdc++.h>
using namespace std;

vector<int>u_set;
vector<pair<int, pair<int, int> > >Edge;
int Node;
map<string, int>mp;

int unionRoot(int n) {
    if(u_set[n] == n)
        return n;
    return u_set[n] = unionRoot(u_set[n]);
}

void makeUnion(int x, int y){
    u_set[unionRoot(y)] = unionRoot(x);
}

bool isSameSet(int x, int y) {
    return (unionRoot(x) == unionRoot(y));
}

void unionInit(int len) {
    u_set.resize(len+2);
    for(int i = 0; i <= len; ++i)
        u_set[i] = i;
}

int NodeNo(char s[]) {
    string S(s);
    if(mp.find(S) == mp.end()) {
        mp[S] = Node++;
        return Node-1;
    }
    return mp[S];
}

int main() {
    int t, n, selectedEdge, mstCost, w;
    char s1[60], s2[60];
    scanf("%d", &t);
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &n);
        Node = selectedEdge = mstCost = 0;
        unionInit(300);
        for(int i = 0; i < n; ++i) {
            scanf("%s %s %d", s1, s2, &w);
            Edge.push_back(make_pair(w, make_pair(NodeNo(s1), NodeNo(s2))));
        }
        sort(Edge.begin(), Edge.end());
        for(size_t i = 0; i < Edge.size(); ++i) {
            int u = Edge[i].second.first;
            int v = Edge[i].second.second;
            w = Edge[i].first;
            if(!isSameSet(u, v)) {
                selectedEdge++;
                makeUnion(u, v);
                mstCost += w;
            }
        }
        printf("Case %d: ", Case);
        if(selectedEdge == Node-1)
            printf("%d\n", mstCost);
        else
            printf("Impossible\n");
        Edge.clear();
        mp.clear();
    }
}
