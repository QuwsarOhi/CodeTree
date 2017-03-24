//TLE
#include<bits/stdc++.h>
using namespace std;

bool visited[110], found;
vector<int>G[110], ans;
vector<string>name;
map<string, int>to_int;
map<int, string>to_str;


bool can_be_used(int node)
{
    for(int i = 0; i < G[node].size(); i++) {
        if(visited[G[node][i]])
            return 0;
    }
    return 1;
}


void dfs()
{
    //printf("started\n");
    for(int i = 0; i < name.size() && !found; i++) {
        if(ans.size() == name.size()) {
            found = 1;
            for(int j = 0; j < ans.size(); j++)
                printf(" %s", to_str[ans[j]].c_str());
            printf(".\n");
            return;
        }
        int node = to_int[name[i]];
        if(!visited[node] && can_be_used(node)) {
            ans.push_back(node);
            visited[node] = 1;
            dfs();
            visited[node] = 0;
            ans.pop_back();
        }
    }
}

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int n, r, indx, Case = 1;
    bool first = 1;
    char S1[60], S2[60];
    while(scanf("%d", &n) != EOF) {
        indx = 0;
        for(int i = 0; i < n; i++) {
            scanf(" %s ", S1);
            //printf("%s\n", S1);
            to_int[S1] = indx;
            to_str[indx++] = S1;
            name.push_back(S1);
        }
        scanf("%d", &r);
        for(int i = 0; i < r; i++) {
            scanf("%s %s", S1, S2);
            //printf("%s  %s\n",S1, S2);
            G[to_int[S1]].push_back(to_int[S2]);
        }
        //if(!first)
        //    printf("\n");
        first = 0;
        found = 0;
        printf("Case #%d: Dilbert should drink beverages in this order:", Case++);
        memset(visited, 0, sizeof(visited));
        dfs();
        ans.clear();
        name.clear();
        to_int.clear();
        to_str.clear();
        for(int i = 0; i < 101; i++)
            G[i].clear();
        printf("\n");
    }
    return 0;
}
