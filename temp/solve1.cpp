#include <bits/stdc++.h>
using namespace std;


struct node {
    int lftBracket, rhtBracket, Max;
    bool err;

    node(int lft=0, int rht=0, int Max=0, int err = 0) {
        this->lftBracket = lft;
        this->rhtBracket = rht;
        this->Max = Max;
        this->err = err;
    }
};

node Merge(node lft, node rht, int range) {
        node tmp = node(0, 0, max(lft.Max, rht.Max), lft.err || rht.err);

        if(tmp.err || lft.rhtBracket > lft.lftBracket || rht.rhtBracket > lft.lftBracket) {      // )(  or ()))
            tmp.err = 1;
            return tmp;         // (FIXED) ERROR this values must flow upwards
        }

        // Another problem arose : while error found on a node, it will never merge with the left sides right node
        // )()

        // What to do when
        // left has error right is ok
        // if right side has problem and left is ok
        // if both is ok
        // if both has problem

        if(lft.lftBracket == 0 && lft.rhtBracket == 0 && rht.lftBracket == 0 && rht.rhtBracket == 0)
            tmp.Max = lft.Max + rht.Max;

        tmp.lftBracket = lft.lftBracket + rht.lftBracket;
        tmp.rhtBracket = lft.rhtBracket + rht.rhtBracket;

        if(tmp.lftBracket == tmp.rhtBracket) {
            tmp.lftBracket = tmp.rhtBracket = 0;
            tmp.Max = max(tmp.Max, range);
        }
        return tmp;
    }

char str[] = ")()";
node tree[100];

void init(int pos, int l, int r) {
    if(l == r) {
        if(str[l-1] == '(')
            tree[pos] = node(1, 0, 0);
        else
            tree[pos] = node(0, 1, 0);
        printf("At Leaf %d [%d, %d] : %d %d %d %d\n", pos, l, r, tree[pos].lftBracket, tree[pos].rhtBracket, tree[pos].Max, tree[pos].err);
        return;
    }

    int mid = (l+r)>>1;
    init(pos<<1, l, mid);
    init(pos<<1|1, mid+1, r);

    tree[pos] = Merge(tree[pos<<1], tree[pos<<1|1], r-l+1);

    printf("At %d [%d, %d]: %d %d %d %d\n", pos, l, r, tree[pos].lftBracket, tree[pos].rhtBracket, tree[pos].Max, tree[pos].err);
}



int main() {
    init(1, 1, 3);
    return 0;
}
