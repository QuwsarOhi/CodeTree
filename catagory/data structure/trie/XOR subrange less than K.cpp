// SPOJ - SUBXOR
// http://www.spoj.com/problems/SUBXOR/

// TRIE
// Find number of subarray which's XOR is less that K

#include <bits/stdc++.h>
using namespace std;

struct node {
    int count[2];
    node *next[2];

    node() {
        count[0] = count[1] = 0;
        for(int i = 0; i < 2; i++)
            next[i] = NULL;
    }
};

void del(node *current) {
    for(int i = 0; i < 2; i++)
        if(current->next[i] != NULL)
            del(current->next[i]);
    delete current;
}

void insert(node *root, int val, int pos) {
    if(pos == -1)
        return;
    
    bool newPos = val&(1<<pos);                 // inserting bits from most significant bit to least significant bit
    if(!root->next[newPos])
        root->next[newPos] = new node();
    
    root->count[newPos]++;                      // counting number of nodes which goes through this node to 0 and 1
    insert(root->next[newPos], val, pos-1);
}


int query(node *root, int val, int k, int pos) {
    if(pos == -1 || !root)
        return 0;
    
    if(k & (1<<pos)) {                                                      // if the pos'th bit of k is on
        if(val & (1<<pos))                                                  // if the pos'th bit of val is on
            return query(root->next[0], val, k, pos-1) + root->count[1];
        else                                                                // if the pos'th bit of val is off
            return query(root->next[1], val, k, pos-1) + root->count[0];
    }
    else {                                                                  // if the pos'th bit of k is off
        if(val & (1<<pos))
            return query(root->next[1], val, k, pos-1);
        else
            return query(root->next[0], val, k, pos-1);
    }
}

int main() {
    int t, n, k, val;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        node *root = new node();
        
        scanf("%d%d", &n, &k);
        insert(root, 0, 20);
        
        int prefXOR = 0;
        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &val);
            
            prefXOR ^= val;
            ans += query(root, prefXOR, k, 20);
            insert(root, prefXOR, 20);
        }
        
        del(root);
        
        printf("%lld\n", ans);
    }
    
    return 0;
}
    
