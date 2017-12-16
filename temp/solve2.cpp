// Codeforces
// E. Propagating tree
// http://codeforces.com/contest/384/problem/E

#include <bits/stdc++.h>
using namespace std;
#define MAX                 200100
#define EPS                 1e-9
#define INF                 1e9+10
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS)) 
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbug(vari)          cerr << #vari << " = " << (vari) <<endl
#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<ll, ll>mll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<long long>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;

vi G[MAX];
int sTime[MAX], eTime[MAX], level[MAX], cst[MAX], timer;
ll treeE[MAX], treeO[MAX];
int MaxVal = MAX-3;

void updateE(int idx, int val) {
	while(idx <= MaxVal) {
		treeE[idx] += val;
		idx += (idx & -idx);
	}
}

void updateO(int idx, int val) {
	while(idx <= MaxVal) {
		treeO[idx] += val;
		idx += (idx & -idx);
	}
}

long long readE(int idx) {
	long long sum = 0;
	while(idx > 0) {
		sum += treeE[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

long long readO(int idx) {
	long long sum = 0;
	while(idx > 0) {
		sum += treeO[idx];
		idx -= (idx & -idx);
	}
	return sum;
}


void dfs(int u, int lvl) {
    sTime[u] = ++timer;
    level[u] = lvl;
    for(int i = 0; i < SIZE(G[u]); ++i) {
        if(sTime[G[u][i]] == 0)
            dfs(G[u][i], lvl+1);
        eTime[u] = timer;
    }
}

    
int main() {
    //fileRead("in");
    
    int n, q, u, v, x, t;
    sf("%d %d", &n, &q);
    
    for(int i = 1; i <= n; ++i)
        sf("%d", &cst[i]);
    
    for(int i = 1; i < n; ++i) {
        sf("%d %d", &u, &v);
        G[u].pb(v);
        G[v].pb(u);
    }
    
    memset(sTime, 0, sizeof sTime);
    memset(treeE, 0, sizeof treeE);
    memset(treeO, 0, sizeof treeO);
    
    timer = 0;
    dfs(1, 1);
    
    if(n == 1) {
        level[1] = 1;
        sTime[1] = eTime[1] = 1;
    }
    
    while(q--) {
        sf("%d", &t);
        
        if(t == 1) {
            sf("%d %d", &u, &x);
            if(level[u]%2 == 0) {
                //pf("Eve node %d : %d %d val %d\n", u, sTime[u], eTime[u], x);
                updateE(sTime[u], x);
                updateE(eTime[u]+1, -x);
                updateO(sTime[u], -x);
                updateO(eTime[u]+1, x);
            }
            else {
                //pf("Odd node %d : %d %d val %d\n", u, sTime[u], eTime[u], x);
                updateE(sTime[u], -x);
                updateE(eTime[u]+1, x);
                updateO(sTime[u], x);
                updateO(eTime[u]+1, -x);
            }
        }
        else {
            sf("%d", &u);
            //pf("sTime[%d] = %d\n", u, sTime[u]);
            if(level[u]%2 == 0) {
                //cout << "E* " << readSingleE(sTime[u]) << endl;
                pf("%lld\n", cst[u]+readE(sTime[u]));
            }
            else {
                //cout << "O* " << readSingleO(sTime[u]) << endl;
                pf("%lld\n", cst[u]+readO(sTime[u]));
            }
        }
    }

    return 0;
}
