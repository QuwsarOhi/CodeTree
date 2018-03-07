#include <bits/stdc++.h>
#define MAX 200000
using namespace std;
typedef long long ll;

struct node {
    ll val;
    node *lft, *rht;
    
    node(node *L = NULL, node *R = NULL, ll v = 0) {
        lft = L;
        rht = R;
        val = v;
    }
};

node *persis[MAX], *null = new node();
ll val[MAX];

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
        pos->lft = pos->rht = null;
        return;
    }
    
    ll mid = (l+r)>>1;
    
    if(idx <= mid) {
        pos->lft = nCopy(pos->lft);
        if(!pos->rht)
            pos->rht = null;
        update(pos->lft, l, mid, idx, val);
    }
    else {
        pos->rht = nCopy(pos->rht);
        if(!pos->lft)
            pos->lft = null;
        update(pos->rht, mid+1, r, idx, val);
    }
    
    pos->val++;
}


ll Count;
ll query(node *lftNode, node *rhtNode, node *track, int l, int r, ll val) {
    ll cnt = rhtNode->val-lftNode->val-track->val;
    
    //printf("At range %d %d : %lld %lld %lld %lld\n", l, r, cnt, rhtNode->val, lftNode->val, track->val);
    if(val < l || cnt <= 0) {
        Count = 0;
        return -1;
    }
    
    if(l == r) {
        track->val += cnt;
        Count = cnt;
        return l;
    }
    
    if(!track->lft)
        track->lft = new node();
    if(!track->rht)
        track->rht = new node();
    
    //cout << (rhtNode->lft == NULL) << (lftNode->lft == NULL) << (track->lft == NULL) << endl;
    
    //cout << "OKA\n";
    int mid = (l+r)>>1, ret = -1;
    int lftCnt = rhtNode->lft->val - lftNode->lft->val - track->lft->val;
    //int rhtCnt = rhtNode->rht->val - lftNode->rht->val - track->rht->val;
    //printf("lftCnt %d\n", lftCnt);
    
    if(val <= mid && lftCnt > 0)
        ret = query(lftNode->lft, rhtNode->lft, track->lft, l, mid, val);
    else
        ret = query(lftNode->rht, rhtNode->rht, track->rht, mid+1, r, val);
        
    track->val += Count;
    return ret;
}


void ClearTree(node *pos) {
    if(pos == NULL) {
        delete pos;
        return;
    }

    ClearTree(pos->lft);
    ClearTree(pos->rht);
    
    delete pos;
}

int main() {
    ll n, q, l, r, lim=-1;
    
    
    // MODIFY N before submit
    
    null->lft = null->rht = null;
    persis[0] = null;
    
    scanf("%lld", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%lld", &val[i]);
        lim = max(val[i], lim);
    }
    
    for(int i = 1; i <= n; ++i) {
        persis[i] = nCopy(persis[i-1]);
        update(persis[i], 1, lim, val[i], 1);
    }
    
    // Query Starts
    
    scanf("%lld", &q);
    
    while(q--) {
        scanf("%lld%lld", &l, &r);
        ll cSum = 0;
        node *track = new node();
        
        while(1) {
            //printf("-----------------Search for %lld\n", cSum);
            // how to keep track of used values in this range??
            // use key -> count, and minus??
            Count = 0;
            ll val = query(persis[l-1], persis[r], track, 1, lim, cSum+1);     // finds val less than or equal to cSum
            // if val found, then cSum += val, then again search
            // else break
            
            //printf("Found %lld : %lld\n", val, Count);
            
            if(val == -1)
                break;

            cSum += (val*Count);
        }
        printf("%lld\n", cSum+1);
        
        ClearTree(track);
    }
    
    return 0;
}
    
