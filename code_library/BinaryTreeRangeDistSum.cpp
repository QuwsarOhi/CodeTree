// http://mishadoff.com/blog/dfs-on-binary-tree-array/
// Complete Binary Tree
// Sum of distance from a node "n" such that every nodes distance from node "n" is less than or equal to k
// BinaryTreeRangeDistSum

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define INF 1e9+10
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define sf scanf
#define pf printf
#define SIZE(a) ((int)a.size())
#define Equal(a, b) (abs(a-b) < EPS)
#define Greater(a, b) (a >= (b+EPS))
#define GreaterEqual(a, b) (a > (b-EPS)) 
#define fr(i, a, b) for(register int i = (a); i < (int)(b); i++)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbug(vari) cerr << #vari << " = " << (vari) <<endl
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;

vector<ll>v[2000100], w, sum[2000100];
ll n, m;

void dfs(ll node) {
    if(node > n)
        return;
    
    ll lft = node<<1, rht = node<<1|1;
    dfs(lft), dfs(rht);
    
    ll lftSize = v[lft].size(), rhtSize = v[rht].size();
    ll nodeSize = lftSize+rhtSize+1;
    v[node].resize(nodeSize);
    v[node][0] = 0;                             // distance from this node to this node
    
    //printf("node : %d, nodeSize : %d, lftSize : %d, rhtSize : %d\n", node, nodeSize, lftSize, rhtSize);
    
    ll l = 0, r = 0;
    for(ll i = 1; i < nodeSize; ++i) {
        if(l == lftSize)
            v[node][i] = v[rht][r++] + w[rht];
        else if(r == rhtSize)
            v[node][i] = v[lft][l++] + w[lft];
        else {
            int lftW = v[lft][l] + w[lft], rhtW = v[rht][r] + w[rht];
            if(lftW < rhtW) {
                v[node][i] = lftW;
                l++;
            }
            else {
                v[node][i] = rhtW;
                r++;
            }
        }
    }
}


ll single(int node, ll d, ll delta) {
    if(d < 0) return 0;
    ll n = upper_bound(v[node].begin(), v[node].end(), d) - v[node].begin();
    return sum[node][n-1] + delta*n;                                    // delta is the common distance of all nodes
}

ll query(int node, ll k) {
    ll ans = single(node, k, 0);
    ll totlen = 0;
    while(node/2) {
        totlen += w[node];
        ll tmp = single(node/2, k-totlen, totlen);                      // distances from parent node
        tmp -= single(node, k-totlen-w[node], totlen + w[node]);        // common overlapped distance (of child node) from parent node
        ans += tmp;
        node /= 2;
    }
    return ans;
}

int main() {
    fastIO;
    cin >> n >> m;                   // n = total nodes, m = number of query
    w.resize(n+5);
    
    for(int i = 2; i <= n; ++i)     // Weight of tree w[x] contains distance from upper node to x (complete binary tree)
        cin >> w[i];
    
    dfs(1);
    
    /*for(int i = 1; i <= n; ++i) {
        cout << i << " ::  ";
        for(int j = 0; j < SIZE(v[i]); ++j)
            cout << v[i][j] << " ";
        cout <<  endl;
    }*/
    
    for(int i = 1; i <= n; ++i) {
        sum[i].resize(v[i].size());
        sum[i][0] = v[i][0];
        for(int j = 1; j < SIZE(v[i]); ++j)
            sum[i][j] = sum[i][j-1] + v[i][j];
    }
    
    while(m--) {
        ll node, k;
        cin >> node >> k;
        cout << query(node, k) << endl;
    }
    
    return 0;
}
