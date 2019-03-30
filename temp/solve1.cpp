//satyaki3794
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define ff first
#define ss second
#define pb push_back
#define MOD (1000000007LL)
#define LEFT(n) (2*(n))
#define RIGHT(n) (2*(n)+1)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;


const int N = 500005;
int n, h, par[N], cnt[N], depth[N], arr[N], subsize[N];
vector<int> adj[N];
bool big[N];
int valid = 0;
ll ans = 0;

void dfs0(int v, int d){
    depth[v] = d;
    subsize[v] = 1;
    for(auto vv : adj[v]){
        dfs0(vv, d+1);
        subsize[v] += subsize[vv];
    }
}

void add(int v){
    cnt[depth[v]]++;
    if(cnt[depth[v]] == arr[depth[v]])
        valid++;
    for(auto vv: adj[v])
        if(!big[vv])
            add(vv);
}

void remove(int v){
    cnt[depth[v]]--;
    if(cnt[depth[v]] == arr[depth[v]]-1)
        valid--;
    for(auto vv: adj[v])
        remove(vv);
}


void dfs(int v, bool keep){

    int mx = -1, bigChild = -1;
    for(auto vv : adj[v])
       if(subsize[vv] > mx)
          mx = subsize[vv], bigChild = vv;
    
    for(auto vv : adj[v])
        if(vv != bigChild)
            dfs(vv, false);  // run a dfs on small childs and clear them from cnt

    if(bigChild != -1){
        dfs(bigChild, true), big[bigChild] = 1;  // bigChild marked as big and not cleared from cnt
    }

    add(v);
    //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.

    ans += valid;
    if(bigChild != -1)
        big[bigChild] = 0;
    if(keep == false)
        remove(v);
}



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>h;
    for(int i=1;i<n;i++){
        cin>>par[i];
        adj[par[i]].pb(i);
    }

    for(int i=0;i<=h;i++)   cin>>arr[i];

    dfs0(0, 0);

    for(int i=0;i<=h;i++)
        if(arr[i] == 0)
            valid++;

    dfs(0, true);
    cout<<ans;
    return 0;
}






