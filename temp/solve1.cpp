// Codeforces
// http://codeforces.com/problemset/problem/813/E

// Presistant Segment Tree
// Count same value K times [Presistant Version of LOJ Fast Queries]

#include <bits/stdc++.h>
using namespace std;

#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;

struct node {
    ll val;
    node *lft, *rht;
    
    node(node *L = NULL, node *R = NULL, ll v = 0) {
        lft = L;
        rht = R;
        val = v;
    }
};

node *presis[100100];
vector<int>IDX[100100];
//int Count[100100];

node *nCopy(node *x) {
    node *tmp = new node();
    if(x) {
        tmp->val = x->val;
        tmp->lft = x->lft;
        tmp->rht = x->rht;
    }
    return tmp;
}

// Single Position update
void update(node *pos, ll l, ll r, ll idx, ll val) {
    if(l == r) {
        pos->val += val;
        return;
    }
    
    ll mid = (l+r)>>1;
    
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
}

// Range [L, R] Sum Query
ll query(node *pos, ll l, ll r, ll L, ll R) {
    if(r < L || R < l || pos == NULL)
        return 0;
    
    if(L <= l && r <= R)
        return pos->val;
    
    ll mid = (l+r)>>1;
    
    ll x = query(pos->lft, l, mid, L, R);
    ll y = query(pos->rht, mid+1, r, L, R);

    return x+y;
}



int main() {
    int n, m, k, l, r, x, y, val, MAX = 100001;
    FastRead;
    
    cin >> n >> k;
    
    for(int i = 1; i <= n; ++i) {
        cin >> val;
        IDX[val].push_back(i);                              // Storing index of all same values
        presis[i] = nCopy(presis[i-1]);                     // adding value in i'th presistant tree
        update(presis[i], 1, MAX, i, 1);
        if((int)IDX[val].size() > k) {                      // if the same value occures more than k, we delete the leftmost same value count
            int pos = IDX[val][(int)IDX[val].size()-k-1];
            update(presis[i], 1, MAX, pos, -1);             // so we have presistant segment tree for right bound 'r' which contains latest accurate updates
        }
    }
    
    cin >> m;
    int last = 0;
    while(m--) {
        cin >> x >> y;                      // We can't do offline processing (query sorting), as the range queries are dpenendent on previous answer
        l = (x+last)%n + 1;
        r = (y+last)%n + 1;
        if(l > r)
            swap(l, r);
        last = query(presis[r], 1, MAX, l, r);
        cout << last << "\n";
    }
    
    return 0;
}
