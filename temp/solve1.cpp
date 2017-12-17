// codeforces.com/blog/entry/12239
#pragma comment(linker,"/STACK:100000000000,100000000000")
 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <iomanip>
#include <queue>
#include <map>
#include <functional>
#include <list>
#include <sstream>
#include <ctime>
#include <climits>
#include <bitset>
#include <list>
#include <cassert>
#include <complex>
 
using namespace std;
 
/* Constants begin */
const long long inf = 1e18+7;
const long long mod = 1e9+7;
const double eps = 1e-9;
const double PI = 2*acos(0.0);
const double E = 2.71828;
/* Constants end */
 
/* Defines begin */
#define pb push_back
#define mp make_pair
#define ll long long
#define double long double
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define forn(i,n) for (int (i)=0;(i)<(ll)(n);(i)++)
#define random (rand()<<16|rand())
#define sqr(x) (x)*(x)
#define base complex<double>
/* Defines end */
 
int n, m;
vector<int> g[100005];
int val[100005];
int nxt[100005], size[100005], p[100005], chain[100005], num[100005], csz[100005], top[100005], all, cnt = 1, depth[100005];
ll t[400005], mx[400005];
 
void upd(int v, int tl, int tr, int pos, int d){
  if(tl == tr){
    t[v] += d;
    return;
  }
  int tm = (tl + tr) >> 1;
  if(pos <= tm) upd(v + v, tl, tm, pos, d); else
    upd(v + v + 1, tm + 1, tr, pos, d);
  t[v] = max(t[v + v], t[v + v + 1]);
}
 
void dfs(int v, int pr = 0){
  p[v] = pr;
  size[v] = 1;
  forn(i, g[v].size()){
    int to = g[v][i];
    if(to == pr){
      continue;
    }
    depth[to] = depth[v] + 1;
    dfs(to, v);
    size[v] += size[to];
    if(nxt[v] == -1 || size[to] > size[nxt[v]]){
      nxt[v] = to;
    }
  }
}
 
void hld(int v, int pr = -1){
  chain[v] = cnt - 1;
  num[v] = all++;
  if(!csz[cnt - 1]){
    top[cnt - 1] = v;
  }
  ++csz[cnt - 1];
  if(nxt[v] != -1){
    hld(nxt[v], v);
  }
  forn(i, g[v].size()){
    int to = g[v][i];
    if(to == pr || to == nxt[v]){
      continue;
    }
    ++cnt;
    hld(to, v);
  }
}

ll go(int v, int tl, int tr, int l, int r){
  if(l > tr || r < tl){
    return 0;
  }
  if(l <= tl && r >= tr){
    return t[v];
  }
  int tm = (tl + tr) >> 1;
  return max(go(v + v, tl, tm, l, r), go(v + v + 1, tm + 1, tr, l, r));
}
 
ll go(int a, int b){
  ll res = 0;
  while(chain[a] != chain[b]){
    if(depth[top[chain[a]]] < depth[top[chain[b]]]) swap(a, b);
    int start = top[chain[a]];
    if(num[a] == num[start] + csz[chain[a]] - 1)
      res = max(res, mx[chain[a]]);
    else
      res = max(res, go(1, 0, n - 1, num[start], num[a]));
    a = p[start];
  }
  if(depth[a] > depth[b]) swap(a, b);
  res = max(res, go(1, 0, n - 1, num[a], num[b]));
  return res;
}
 
void modify(int a, int b){
  upd(1, 0, n - 1, num[a], b);
  int start = num[top[chain[a]]];
  int end = start + csz[chain[a]] - 1;
  mx[chain[a]] = go(1, 0, n - 1, start, end);
}
 
int main(void) {
  #ifdef nobik
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
  #endif
  scanf("%d", &n);
  forn(i, n - 1){
    int a, b; scanf("%d %d", &a, &b); --a; --b;
    g[a].pb(b); g[b].pb(a);
  }
  memset(nxt, -1, sizeof nxt);
  dfs(0);
  hld(0);
  scanf("%d", &m);
  forn(i, m){
    char c;
    scanf(" %c", &c);
    if(c == 'G'){
      int a, b; scanf("%d %d", &a, &b); --a; --b;
      printf("%lld\n", go(a, b));
    } else {
      int a, b; scanf("%d %d", &a, &b); --a;
      modify(a, b);
    }
  }
  return 0;
}