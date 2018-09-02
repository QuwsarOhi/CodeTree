// SOPJ
// https://www.spoj.com/problems/DICT/


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
    node *nxt[26];
    bool isEnd;
    node() {
        for(int i = 0; i < 26; ++i)
            nxt[i] = NULL;
        isEnd = 0;
    }
};

char str[100];
string RetStr;

void add(int pos, int len, node *cur) {
    if(pos == len) {
        cur->isEnd = 1;
        return;
    }
    int idx = str[pos]-'a';
    
    //cerr << "at " << str[pos] << endl;
    if(cur->nxt[idx] == NULL) {
        //cerr << "new node\n";
        cur->nxt[idx] = new node();
    }
        
    add(pos+1, len, cur->nxt[idx]);
}

node *tmp;
bool findLast(int pos, int len, node *cur) {
    if(pos == len) {
        tmp = cur;
        return 1;
    }
    
    int idx = str[pos]-'a';
    
    //cerr << "at " << str[pos] << endl;
    
    if(cur->nxt[idx] == NULL) {
        //cerr << "NOT FOUND" << endl;
        return 0;
    }
    
    return findLast(pos+1, len, cur->nxt[idx]);
}


void goALL(node *cur, bool isFirst = 0) {
    if(cur->isEnd and not isFirst)
        pf("%s\n", RetStr.c_str());
        
    for(int i = 0; i < 26; ++i)
        if(cur->nxt[i] != NULL) {
            RetStr.push_back('a'+i);
            goALL(cur->nxt[i]);
            RetStr.pop_back();
        }
}

void del(node *cur) {
    for(int i = 0; i < 26; ++i)
        if(cur->nxt[i] != NULL)
            del(cur->nxt[i]);
    delete cur;
}

int main() {
    int n, len;
    sf("%d", &n);
    node *root = new node();
    
    for(int i = 0; i < n; ++i) {
        sf("%s", str);
        add(0, strlen(str), root);
    }
    
    //cerr << "DONE\n";
    
    sf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        sf("%s", str);
        RetStr.clear();
        len = strlen(str);
        
        //cerr << "LEN " << len << endl;
        pf("Case #%d:\n", i);
        
        for(int i = 0; i < len; ++i)
            RetStr.pb(str[i]);
        if(not findLast(0, len, root))
            pf("No match.\n");
        else
            goALL(tmp, 1);
    }
    
    del(root);
    return 0;
}
