// CS Academy
// Limited Swaps
// https://csacademy.com/contest/archive/task/limited-swaps/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>    // rb_Tree_tag
#include <ext/pb_ds/tree_policy.hpp>        // Tree_order_statistics_node_update

#define MAX 110000

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct node {
    ll val;
    int idx;

    void Merge(node lft, node rht) {
        if(lft.val > rht.val) {
            val = lft.val;
            idx = lft.idx;
        }
        else if(rht.val > lft.val) {
            val = rht.val;
            idx = rht.idx;
        }
        else {
            val = lft.val;
            idx = min(lft.idx, rht.idx);
        }
    }
};

ll val[MAX];
node Tree[5*MAX];
vector<ll>ans;

void init(int pos, int l, int r) {
    if(l == r) {
        Tree[pos].val = val[l];
        Tree[pos].idx = l;
        return;
    }

    int mid = (l+r)>>1;

    init(pos<<1, l, mid);
    init(pos<<1|1, mid+1, r);

    Tree[pos].Merge(Tree[pos<<1], Tree[pos<<1|1]);
}


node query(int pos, int l, int r, int L, int R) {
    if(r < L || R < l) {
        node tmp;
        tmp.val = -1, tmp.idx = -1;
        return tmp;
    }

    if(L <= l && r <= R)
        return Tree[pos];

    int mid = (l+r)>>1;

    node x = query(pos<<1, l, mid, L, R);
    node y = query(pos<<1|1, mid+1, r, L, R);

    node mrg;
    mrg.Merge(x, y);
    return mrg;
}

void update(int pos, int l, int r, int idx) {
    if(l == r) {
        Tree[pos].val = -1;
        return;
    }

    int mid = (l+r)>>1;

    if(idx <= mid)
        update(pos<<1, l, mid, idx);
    else
        update(pos<<1|1, mid+1, r, idx);
    Tree[pos].Merge(Tree[pos<<1], Tree[pos<<1|1]);
}



int main() {
    ll n, k;
    ordered_set<ll>Set;

    scanf("%lld%lld", &n, &k);

    // Inserting index
    for(int i = 1; i <= n; ++i)
        Set.insert(i);

    for(int i = 1; i <= n; ++i)
        scanf("%lld", &val[i]);

    init(1, 1, n);
    
    ll r = k+1, rmvCnt = 1;
    
    
    while(k > 0 && Set.size() > 1) {
        r = *Set.find_by_order(min(k, n-rmvCnt));

        node mx = query(1, 1, n, 1, r);
        
        ll actualPos = Set.order_of_key(mx.idx);
        
        Set.erase(Set.find_by_order(actualPos));

        update(1, 1, n, mx.idx);

        k -= actualPos;
        rmvCnt++;
        
        ans.push_back(mx.val);
    }
    
    
    // Insert rest of the value
    for(auto it : Set)
        ans.push_back(val[it]);
    
    
    for(int i = 0; i < (int)ans.size(); ++i) {
        if(i)
            printf(" %lld", ans[i]);
        else
            printf("%lld", ans[i]);
    }
    
    printf("\n");    
    
    return 0;
}
