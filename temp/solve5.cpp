// SPOJ
// SUBXOR - SubXor

#include <bits/stdc++.h>
#define isON(x, pos)        (x & (1 << pos)) 
using namespace std;

const int LIM = 20;

struct node {
    int cnt;
    node *nxt[2];

    node() {
        cnt = 0;
        nxt[0] = NULL;
        nxt[1] = NULL;
}};

void Insert(const int val, node *cur, int pos = LIM) {
    //cout << "at " << pos << endl;
    if(pos < 0)
        return;
    /*if(cur == NULL) {
        cerr << "NEW NODE\n"; 
        cur = new node();
    }*/

    cur->cnt++;
    int nxtIdx = (val & (1 << pos)) > 0;
    //cerr << "nxt IDX " << nxtIdx << endl;
    if(cur->nxt[nxtIdx] == NULL)
        cur->nxt[nxtIdx] = new node();
    Insert(val, cur->nxt[nxtIdx], pos-1);
}

void Traverse(node *cur, int pos = LIM) {
    if(cur == NULL) {
        cerr << "END\n";
        return;
    }
    if(cur->nxt[0] != NULL) {
        //cerr << "got " << 0 << " at " << pos << endl;
        Traverse(cur->nxt[0], pos-1);
    }
    if(cur->nxt[1] != NULL) {
        //cerr << "got " << 1 << " at " << pos << endl;
        Traverse(cur->nxt[1], pos-1);
    }
}

void Erase(node *cur, int pos = LIM) {
    //cerr << "AT " << pos << endl;
    if(cur->nxt[0] != NULL)
        Erase(cur->nxt[0], pos+1);
    if(cur->nxt[1] != NULL)
        Erase(cur->nxt[1], pos+1);
    delete cur;
}

int CalMin(const int val, const int lim, node *cur, int pos = LIM) {
    if(pos < 0 or not cur)
        return 0;
    int ret = 0;

    if(isON(lim, pos)) {      // Bit is on
        if(isON(val, pos)) {
            // take the 0 position, as it is smaller, and go through the 1 position
            // pos 1 is for 1 ^ 0
            ret += CalMin(val, lim, cur->nxt[0], pos-1);
            if(pos > 0 and cur->nxt[1])
                ret += cur->nxt[1]->cnt;
        }
        else {
            ret += CalMin(val, lim, cur->nxt[1], pos-1);
            if(pos > 0 and cur->nxt[0])
                ret += cur->nxt[0]->cnt;
        }
    }
    else {
        if(isON(val, pos))
            ret += CalMin(val, lim, cur->nxt[1], pos-1);
        else
            ret += CalMin(val, lim, cur->nxt[0], pos-1);
    }

    return ret;
}

int main() {
    int t, n, x, k, CUMxor;
    long long ans;
    scanf("%d", &t);
    node *root;

    while(t--) {
        scanf("%d%d", &n, &k);
        CUMxor = 0;
        ans = 0;
        root = new node();
        Insert(CUMxor, root);

        for(int i = 0; i < n; ++i) {
            scanf("%d", &x);
            CUMxor ^= x;

            ans += CalMin(CUMxor, k, root);
            //cerr << i << " CalMIN done\n";
            Insert(CUMxor, root);
            //cerr << i << " Insert done\n";
            //Traverse(root);
            //cerr << "ANS " << ans << endl;
        }

        printf("%lld\n", ans);
        //Erase(root);
    }

    return 0;
}