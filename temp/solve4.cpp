// CodeForces
// B. A Lot of Games
// http://codeforces.com/contest/455/problem/B

#include <bits/stdc++.h>
using namespace std;
#define MAX                 110000
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define All(S)              S.begin(), S.end()              
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())
#define error(args...)      { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)

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

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {                                                  // Debugger error(a, b, ....)
	cerr << *it << " = " << a << "\n";
	err(++it, args...);
}

//const int dx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};                                                      // Four side 
//const int dxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};                     // Eight side
//----------------------------------------------------------------------------------------------------------

struct node {
    bool win, lose;
    node *nxt[26];
    node() {
        win = lose = 0;
        for(int i = 0; i < 26; ++i)
            nxt[i] = NULL;
    }
};

char str[110000];

void insert(node *root, int pos, int len) {
    if(pos == len)
        return;
    
    int idx = str[pos]-'a';
    if(!root->nxt[idx])
        root->nxt[idx] = new node();
    
    insert(root->nxt[idx], pos+1, len);
}


void dfs(node *root) {
    bool isLeaf = 1;
    for(int i = 0; i < 26; ++i)
        if(root->nxt[i]) {
            isLeaf = 0;
            dfs(root->nxt[i]);
        }
    
    if(isLeaf) {
        root->lose = 1;
        return;
    }
    
    for(int i = 0; i < 26; ++i)
        if(root->nxt[i]) {
            root->win |= (not root->nxt[i]->win);
            root->lose |= (not root->nxt[i]->lose);
        }
}
 
void winner(bool state) {
    printf("%s\n", state ? "First":"Second");
    return;
}

int main() {
    int n, k;
    node *root = new node();
    scanf("%d%d", &n, &k);
    
    for(int i = 0; i < n; ++i) {
        scanf("%s", str);
        insert(root, 0, strlen(str));
    }
    
    dfs(root);
    
    // First : player who gave first move
    // Second: player who gave second move
    
    if(!root->win)                              // First player can't win by any means
        winner(0);
    else if(root->lose)                         // First player does have a winning state
        winner(root->win);
    else if(k%2)                                // if there is odd number of plays, the first player can win if there exists a winning state
        winner(root->win);
    else
        winner(!root->win);
    
    return 0;
}
