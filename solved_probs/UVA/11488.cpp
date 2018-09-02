// UVa
// 11488 - Hyper Prefix Sets
// Trie

#include <bits/stdc++.h>
using namespace std;
#define MAX                 2100
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
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

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


//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

struct node {
    node *v[2];
    int cnt;
    
    node() {
        v[0] = NULL;
        v[1] = NULL;
        cnt = 0;
    }
};

int ans;
char str[300];

void add(int pos, int len, node *cur) {
    /*if(cur == NULL) {
        cerr << "new node\n";
        cur = new node();
    }*/
    
    cur->cnt++;
    ans = max(ans, pos*cur->cnt);
    
    //cerr << (pos==0?'x':str[pos-1]) << " " << pos << " " << cur->cnt << endl;
    
    if(pos != len) {
        int idx = str[pos]-'0';
        if(cur->v[idx] == NULL)
            cur->v[idx] = new node();
        add(pos+1, len, cur->v[idx]);
    }
}

void del(node *cur) {
    if(cur->v[0] != NULL)
        del(cur->v[0]);
    if(cur->v[1] != NULL)
        del(cur->v[1]);
    delete cur;
}

int main() {
    //fileRead("in");
    //fileWrite("out");
    
    int n, t, len;
    sf("%d", &t);
    
    while(t--) {
        sf("%d", &n);
        node *root = new node();
        ans = 0;
        
        for(int i = 0; i < n; ++i) {
            sf("%s", str);
            len = strlen(str);
            add(0, len, root);
        }
        
        pf("%d\n", ans);
        del(root);
    }
    return 0;
}
