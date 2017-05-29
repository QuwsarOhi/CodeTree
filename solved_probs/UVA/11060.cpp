//UVa
//11060 - Beverages
//Khan's algorithm for Topological order (modified)

#include<bits/stdc++.h>
using namespace std;

map<string, int>to_int;
map<int, string>to_str;
vector<int>G[110];
vector<string>name;


void topsort()
{
    int indegree[110];
    memset(indegree, 0, sizeof(indegree));
    for(int i = 0; i < name.size(); i++) {
        int node = to_int[name[i]];
        for(int i = 0; i < G[node].size(); i++)
            indegree[G[node][i]]++;
    }

    priority_queue<int, vector<int>, greater<int> >pq;      //Normally queue can be used
                                                            //priority queue is used to avoid special formating cases
    for(int i = name.size()-1; i >= 0; i--) {
        int node = to_int[name[i]];
        if(indegree[node] == 0)
            pq.push(node);
    }

    //int cnt = 0;                  //to detect if the graph is Acyclic, check below
    vector<string>ans;

    while(!pq.empty()) {
        int u = pq.top();
        pq.pop();
        ans.push_back(to_str[u]);

        for(int i = 0; i < G[u].size(); i++)
            if(--indegree[G[u][i]] == 0)
                pq.push(G[u][i]);
        //cnt++;
    }
    //if(cnt != to_int.size())      //it has no topological order (Acyclic)

    for(int i = 0; i < ans.size(); i++)
        printf(" %s", ans[i].c_str());
    printf(".\n\n");
}


int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int n, t, Case = 1;
    char S1[60], S2[60];
    while(scanf("%d", &n) != EOF) {
        int indx = 0;
        for(int i = 0; i < n; i++) {
            scanf(" %s ", S1);
            to_int[S1] = indx;
            to_str[indx++] = S1;
            name.push_back(S1);
        }
        sort(name.begin(), name.end());
        scanf("%d", &t);
        for(int i = 0; i < t; i++) {
            scanf(" %s %s ", S1, S2);
            G[to_int[S1]].push_back(to_int[S2]);
        }
        for(int i = 0; i < n; i++) {
            sort(G[i].begin(), G[i].end());
        }
        printf("Case #%d: Dilbert should drink beverages in this order:", Case++);
        topsort();
        to_str.clear();
        to_int.clear();
        name.clear();
        for(int i = 0; i < 101; i++)
            G[i].clear();
    }
    return 0;
}
