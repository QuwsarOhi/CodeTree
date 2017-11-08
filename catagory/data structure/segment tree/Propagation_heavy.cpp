// UVa
// 11402 - Ahoy, Pirates!
// Segment Tree (Propagation)

#include <bits/stdc++.h>
using namespace std;

// propataion tags:
// 0 - no change
// 1 - all set to one
// 2 - all set to zero
// 3 - all need to be flipped

vector<pair<int, int> >tree;
string s;

void init(int L, int R, int pos) {
    if(L == R) {
        tree[pos].first = (s[L] == '1');
        tree[pos].second = 0;
        return;
    }
    
    int mid = (L+R)>>1;
    init(L, mid, pos<<1);
    init(mid+1, R, pos<<1|1);
    
    tree[pos].first = tree[pos<<1].first + tree[pos<<1|1].first;
    tree[pos].second = 0;
}

int Convert(int tag) {  // This function generates output tag of child node if the parent node is set to 3 (fipped)
    if(tag == 1)
        return 2;
    if(tag == 2)
        return 1;
    if(tag == 3)
        return 0;
    return 3;
}

// On every layer of update or query, this Propagation func should be called to pre-process previous left off operations
void Propagate(int L, int R, int parent) {      // Propagate parent node to child nodes (left and right)
    if(tree[parent].second == 0)                // and sets parent node's propagation tag to 0
        return;
    
    int mid = (L+R)>>1;
    int lft = parent<<1, rht = parent<<1|1;

    if(tree[parent].second == 1) {
        tree[lft].first = mid-L+1;
        tree[rht].first = R-mid;
    }
    else if(tree[parent].second == 2) {
        tree[lft].first = tree[rht].first = 0;
    }
    else if(tree[parent].second == 3) {
        tree[lft].first = (mid-L+1) - tree[lft].first;
        tree[rht].first = (R-mid) - tree[rht].first;
    }
    
    if(L != R) {                                // If the child nodes also contain propagate tag (and the childs are not leaf node)
        if(tree[parent].second == 1 || tree[parent].second == 2)
            tree[lft].second = tree[rht].second = tree[parent].second;
        else {
            tree[lft].second = Convert(tree[lft].second);
            tree[rht].second = Convert(tree[rht].second);
        }
    }
    
    tree[parent].second = 0;                    // Parent node's prop tag set to zero
    if(L!=R)                                    // If this is not the leaf node, calculate child node's sum
        tree[parent].first = tree[lft].first + tree[rht].first;
}

void updateOn(int L, int R, int l, int r, int pos) {
    if(r < L || R < l || L > R)
        return;
        
    Propagate(L, R, pos);
    
    if(l <= L && R <= r) {
        tree[pos].first = (R-L+1);
        tree[pos].second = 1;
        return;
    }
    
    int mid = (L+R)>>1;
    updateOn(L, mid, l, r, pos<<1);
    updateOn(mid+1, R, l, r, pos<<1|1);
    
    tree[pos].first = tree[pos<<1].first + tree[pos<<1|1].first;
}

void updateOff(int L, int R, int l, int r, int pos) {
    if(r < L || R < l || L > R)
        return;

    Propagate(L, R, pos);
    
    if(l <= L && R <= r) {
        tree[pos].first = 0;
        tree[pos].second = 2;
        return;
    }
    
    int mid = (L+R)>>1;
    updateOff(L, mid, l, r, pos<<1);
    updateOff(mid+1, R, l, r, pos<<1|1);
    
    tree[pos].first = tree[pos<<1].first + tree[pos<<1|1].first;
}

void updateFlip(int L, int R, int l, int r, int pos) {
    if(r < L || R < l || L > R)
        return;

    Propagate(L, R, pos);
    
    if(l <= L && R <= r) {
        tree[pos].first = abs(R-L+1 - tree[pos].first);
        tree[pos].second = 3;
        return;
    }
    
    int mid = (L+R)>>1;
    updateFlip(L, mid, l, r, pos<<1);
    updateFlip(mid+1, R, l, r, pos<<1|1);
    
    tree[pos].first = tree[pos<<1].first + tree[pos<<1|1].first;
}

int querySum(int L, int R, int l, int r, int pos) {
    if(r < L || R < l || L > R)
        return 0;
    
    Propagate(L, R, pos);
    
    if(l <= L && R <= r)
        return tree[pos].first;
    
    int mid = (L+R)>>1;
    int lft = querySum(L, mid, l, r, pos<<1);
    int rht = querySum(mid+1, R, l, r, pos<<1|1);
    
    return lft+rht;
}

int main() {
    int t, l, r, x, y, q;
    char s1[100], c;
    tree.resize(1024000*4 +1000, {0, 0});
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &x);
        s.clear();
        s = " ";
        while(x--) {
            scanf("%d", &y);
            scanf(" %s", s1);
            while(y--)
                s += string(s1);
        }
        
        init(1, (int)s.size()-1, 1);
        printf("Case %d:\n", Case);
        scanf("%d", &q);
        int Query = 1;
        while(q--) {
            scanf(" %c %d %d", &c, &l, &r);
            ++l, ++r;
            if(c == 'F')
                updateOn(1, (int)s.size()-1, l, r, 1);
            else if(c == 'E')
                updateOff(1, (int)s.size()-1, l, r, 1);
            else if(c == 'I')
               updateFlip(1, (int)s.size()-1, l, r, 1);
            else {
                printf("Q%d: ", Query++);
                printf("%d\n", querySum(1, (int)s.size()-1, l, r, 1));
            }
        }
    }
    
    return 0;
}
