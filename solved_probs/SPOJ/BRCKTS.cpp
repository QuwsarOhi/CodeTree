// SPOJ
// BRCKTS - Brackets

#include <bits/stdc++.h>
using namespace std;


struct node{
    int BrcStart, BrcEnd;
    bool isOk = 0;
    
    node(int a = 0, int b = 0) {
        BrcStart = a;
        BrcEnd = b;
        isOk = BrcStart == 0 && BrcEnd == 0;
    }
    
    node(char c) {
        if(c == '(') {
            BrcStart = 1;
            BrcEnd = 0;
        }
        else {
            BrcStart = 0;
            BrcEnd = 1;
        }
    }
    
    void mergeNode(node lft, node rht) {
        if(lft.isOk && rht.isOk) {
            BrcStart = BrcEnd = 0;
            isOk = 1;
        }
        else {
            int match = min(lft.BrcStart, rht.BrcEnd);
            BrcStart = lft.BrcStart - match + rht.BrcStart;
            BrcEnd = lft.BrcEnd + rht.BrcEnd - match;
            (BrcStart == 0 && BrcEnd == 0) ? isOk = 1: isOk = 0;
        }
    }
};

node tree[120010];
char s[30100];

void init(int L, int R, int pos) {
    if(L == R) {
        tree[pos] = node(s[L]);
        return;
    }
    
    int mid = (L+R)>>1;
    
    init(L, mid, pos<<1);
    init(mid+1, R, pos<<1|1);
    
    tree[pos].mergeNode(tree[pos<<1], tree[pos<<1|1]);
}

void update(int L, int R, int idx, char val, int pos) {
    if(idx < L || R < idx)
        return;
    
    if(L == R && L == idx) {
        tree[pos] = node(val);
        return;
    }
        
    //printf("%d :: %d\n", L, R);
    
    int mid = (L+R)>>1;
    
    update(L, mid, idx, val, pos<<1);
    update(mid+1, R, idx, val, pos<<1|1);
    
    tree[pos].mergeNode(tree[pos<<1], tree[pos<<1|1]);
}

int main() {
    //freopen("in", "r", stdin);
    
    int n, q, x, Test = 1;
    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i)
            scanf(" %c ", &s[i]);
            
        init(1, n, 1);
        scanf("%d", &q);
        printf("Test %d:\n", Test++);
        
        while(q--) {
            scanf("%d", &x);
            if(x == 0)
                printf("%s\n", tree[1].isOk ? "YES" : "NO");
            else {
                s[x] = s[x] == '(' ? ')' : '(';
                update(1, n, x, s[x], 1);
            }
        }
    }
    return 0;
}
