// Toph
// Left and Right
// https://toph.co/p/left-and-right

#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

int val[MAX+100], sVal[MAX+100];
map<int, int>idx;

// Merge Sort Tree
struct MergeSortTree {
    vector<int>tree[5*MAX];

    void init(int pos, int l, int r) {
        if(l == r) {
            tree[pos].push_back(val[l]);
            return;
        }
    
        int mid = (l+r)>>1;
        init(pos<<1, l, mid);
        init(pos<<1|1, mid+1, r);
        merge(tree[pos<<1].begin(), tree[pos<<1].end(), tree[pos<<1|1].begin(), tree[pos<<1|1].end(), back_inserter(tree[pos]));
    }

    int query(int pos, int l, int r, int L, int R, int k) {
        if(r < L || R < l)
            return 0;
    
        if(L <= l && r <= R)
            return (int)tree[pos].size() - (upper_bound(tree[pos].begin(), tree[pos].end(), k) - tree[pos].begin());
        
        int mid = (l+r)>>1;
        return query(pos<<1, l, mid, L, R, k) + query(pos<<1|1, mid+1, r, L, R, k);
    }
};

MergeSortTree mst;

int main() {
    //freopen("in", "r", stdin);
    //freopen("out2", "w", stdout);
    
    int n, k, q;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &val[i]);
        sVal[i] = val[i];
        idx[val[i]] = i;
    }
    
    mst.init(1, 1, n);
    sort(sVal+1, sVal+n+1);
    
    scanf("%d", &q);
    
    while(q--) {
        scanf("%d", &k);
        int swap = (sVal[k] != val[k]);
        if(k != 1) {
            swap += mst.query(1, 1, n, 1, k-1, sVal[k]);
            if(idx[sVal[k]] < k and val[k] > sVal[k])
                swap++;
        }
        printf("%d\n", swap);
    }
    return 0;
}
