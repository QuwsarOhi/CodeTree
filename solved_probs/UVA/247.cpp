//UVa
//247 - Calling Circles
//Strongly Connected Component (Tarjan)

#include<bits/stdc++.h>
using namespace std;

vector<int>G[30], SCC;
int dfs_num[30], dfs_low[30], dfsCounter;
map<int, string>to_str;
map<string, int>to_int;
map<pair<int, int>, bool>is_used;
bitset<30>visited;

void tarjanSSC(int u)
{
	//Stack, here, it is implemented as vector instead
    SCC.push_back(u);
    //Marking node u as visited
    //visited[u] marks if the node u is usable in a SCC and not used on other SCC
    //if visited[u] is false, then it is used in other SCC
    visited[u] = 1;
    dfs_num[u] = dfs_low[u] = ++dfsCounter;
    //for all Strongly Connected Component (directed graph), dfs_low[u] is same
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        //if it is not visited yet, backtrack it
        if(dfs_num[v] == 0) {
            tarjanSSC(v);
        }
        //if node v (visited[v]) is not visited, we can use it to minimize the dfs_low[u] value from dfs_low[v]
        if(visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    //in a SCC the first node of the SCC, node u is the first node in a SCC if dfs_low[u] == dfs_low[v]
    //as we implementing stack like data structure, the nodes from top to u are on the same SCC
    if(dfs_low[u] == dfs_num[u]) {
        bool first = 1;
        while(1) {
            int v = SCC.back();
            SCC.pop_back();
            //node v is used, so marking it as false, so that the ancestor nodes
            //doesn't use this node to update it's value
            visited[v] = 0;
            if(first) {
                printf("%s", to_str[v].c_str());
                first = 0;
            }
            else
                printf(", %s", to_str[v].c_str());
            if(u == v)
                break;
        }
        printf("\n");
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int E, V, Case = 1;
    char S1[30], S2[30];
    bool first = 1;
    while(scanf("%d %d", &V, &E) && (V || E)) {
        int indx = 1;
        if(!first)
            printf("\n");
        first = 0;
        printf("Calling circles for data set %d:\n", Case++);
        while(E--) {
            scanf("%s %s", S1, S2);
            if(!to_int[S1]) {
                to_int[S1] = indx;
                to_str[indx++] = S1;
            }
            if(!to_int[S2]) {
                to_int[S2] = indx;
                to_str[indx++] = S2;
            }
            int u = to_int[S1];
            int v = to_int[S2];
            if(!is_used[make_pair(u, v)]) {
                is_used[make_pair(u, v)] = 1;
                G[u].push_back(v);
            }
        }
        memset(dfs_num, 0, sizeof(dfs_num));
        dfsCounter = 0;
        visited.reset();
        for(int i = 1; i < indx; i++) {
            if(dfs_num[i] == 0)
                tarjanSSC(i);
        }
        to_str.clear();
        to_int.clear();
        is_used.clear();
        for(int i = 0; i < 30; i++)
            G[i].clear();
    }
}
