#include<bits/stdc++.h>
using namespace std;

#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define PI acos(-1.0)

#define MOD 1000000007
#define MX 100010

bool vis[MX];
vector<int>adj[MX], topSort;

void dfs(int u)
{
    vis[u]=true;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(!vis[v])    dfs(v);
    }
    topSort.push_back(u);
    return;
}

int connectedComponent(int n)
{
    CLR(vis);
    for(int i=1; i<=n; i++)
        if(!vis[i])     dfs(i);

    CLR(vis);
    int cnt=0;
    for(int i=topSort.size()-1; i>=0; i--) //as topSort contains the reverse of topological order
        if(!vis[topSort[i]])
        {
            cnt++;
            dfs(topSort[i]);
        }
 return cnt;
}


int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc, kk=1, n, m, u, v;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        for(int i=0; i<m; i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }

        cout<<connectedComponent(n)<<"\n";

        topSort.clear();
        for(int i=1; i<=n; i++)    adj[i].clear();
    }
    return 0;
}
