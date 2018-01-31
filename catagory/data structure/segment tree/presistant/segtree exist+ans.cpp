// Codeforces
// http://codeforces.com/contest/916/problem/D

// Presistant Segment Tree

#include <bits/stdc++.h>
using namespace std;
#define MAX                 501000
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000003
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


struct node {
    ll val;
    node *lft, *rht;
    
    node(node *L = NULL, node *R = NULL, ll v = 0) {
        lft = L;
        rht = R;
        val = v;
    }
};

node *presis[101000] = {}, *exist[101000];
ll lim = 1073741824LL;

node *nCopy(node *x) {
    node *tmp = new node();
    if(x) {
        tmp->val = x->val;
        tmp->lft = x->lft;
        tmp->rht = x->rht;
    }
    return tmp;
}


void init(node *pos, ll l, ll r) {
    if(l == r) {
        pos->val = v[l];
        return;
    }
    
    ll mid = (l+r)>>1;
    
    pos->lft = new node();
    pos->rht = new node();
    
    init(pos->lft, l, mid);
    init(pos->rht, mid+1, r);
    
    pos->val = 0;
    if(pos->lft)
        pos->val += pos->lft->val;
    if(pos->rht)
        pos->val += pos->rht->val;
}

void update(node *pos, ll l, ll r, ll idx, ll val) {
    if(l == r) {
        pos->val += val;
        return;
    }
    
    ll mid = (l+r)/2LL;
    
    if(idx <= mid) {
        pos->lft = nCopy(pos->lft);
        update(pos->lft, l, mid, idx, val);
    }
    else {
        pos->rht = nCopy(pos->rht);
        update(pos->rht, mid+1, r, idx, val);
    }
    
    pos->val = 0;
    if(pos->lft)
        pos->val += pos->lft->val;
    if(pos->rht)
        pos->val += pos->rht->val;
        
    //pos->val = pos->lft->val + pos->rht->val;
}

ll query(node *pos, ll l, ll r, ll L, ll R) {
    if(r < L || R < l || pos == NULL)
        return 0;
    
    if(L <= l && r <= R)
        return pos->val;
    
    ll mid = (l+r)/2LL;
    
    ll x = query(pos->lft, l, mid, L, R);
    ll y = query(pos->rht, mid+1, r, L, R);

    return x+y;
}


map<string, ll>Map;
ll Mapper(string str) {
    if(Map.find(str) == Map.end())
        Map[str] = Map.size();
    return Map[str];
}

// two segment tree
// presis : contains the values ( sum <= priority)
// exist : contains if the string id exists in this presistant tree

// query will go throuth 1 to 



int main() {
    //fileRead("in");
    FastRead;
    ll q, prio;
    string op, str;
    cin >> q;
    
    for(int i = 1; i <= q; ++i) {
        cin >> op;
        
        if(op == string("undo")) {
            ll day;
            cin >> day;
            
            exist[i] = nCopy(exist[i-day-1]);               // note: creating a new copy of pointer, not assigning to pointer
            presis[i] = nCopy(presis[i-day-1]);
            continue;
        }
        
        cin >> str;
        ll id = Mapper(str);
        exist[i] = nCopy(exist[i-1]);
        presis[i] = nCopy(presis[i-1]);
        
        //cout << id << " -> " << str << endl;
        
        ll pastPrio = query(exist[i], 1, q, id, id);
        
        if(op == string("set")) {
            cin >> prio;
            
            if(pastPrio)                                              // exists
                update(presis[i], 0, lim, pastPrio, -1);              // remove presis past value
            
            update(exist[i], 1, q, id, prio-pastPrio);          //  re-assign new priority in exist
            update(presis[i], 0, lim, prio, 1);                 // update in presis 
        }
        
        else if(op == string("query")) {
            if(pastPrio)
                cout << query(presis[i], 0, lim, 1, pastPrio-1) << "\n";
            else
                cout << "-1\n";
        }
        
        else if(op == string("remove")) {
            if(pastPrio) {
                update(presis[i], 0, lim, pastPrio, -1);
                update(exist[i], 1, q, id, -pastPrio);
            }
        }

        cout << flush;
    }
    
    return 0;
}
            
