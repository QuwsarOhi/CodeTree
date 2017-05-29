//UVa
//872 - Ordering
//Topological sort, All combinations

#include<bits/stdc++.h>
using namespace std;

map<char, int>to_int;
map<int, char>to_chr;
vector<int>ans, G[35];
bool visited[35], found;

bool can_be_used(int n)
{
    for(int i = 0; i < G[n].size(); i++)
        if(visited[G[n][i]]) {
            return 0;
    return 1;
}


void dfs()
{
    for(map<char, int> :: iterator it = to_int.begin(); it != to_int.end(); it++) {
        if(ans.size() == to_int.size()) {
            found = 1;
            printf("%c", to_chr[ans[0]]);
            for(int i = 1; i < ans.size(); i++)
                printf(" %c", to_chr[ans[i]]);
            printf("\n");
            return;
        }
        int node = it->second;
        if(can_be_used(node) && !visited[node]) {
            visited[node] = 1;
            ans.push_back(node);
            dfs();
            visited[node] = 0;
            ans.pop_back();
        }
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    bool first = 1;
    char x, y, z, S[200];
    scanf("%d", &t);
    memset(visited, 0, sizeof(visited));
    while(t--) {
        to_chr.clear();
        to_int.clear();
        ans.clear();
        for(int i = 0; i < 35; i++)
            G[i].clear();
        scanf(" %[^\n] ", S);
        stringstream ss;
        ss << S;
        int indx = 0;
        while(ss >> x) {
            to_int[x] = indx;
            to_chr[indx] = x;
            indx++;
        }
        scanf(" %[^\n] ", S);
        ss.clear();
        ss << S;
        while(ss >> x >> y >> z)
            G[to_int[x]].push_back(to_int[z]);
        if(!first)
            printf("\n");
        first = 0;
        found = 0;
        dfs();
        if(!found)
            printf("NO\n");
    }
}
