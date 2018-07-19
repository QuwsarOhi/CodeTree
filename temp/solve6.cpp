#include <bits/stdc++.h>
#define MAX 100
using namespace std;
typedef long long ll;

struct STree {
    ll sum[4*MAX], prop[4*MAX], leftProp[4*MAX], rightProp[4*MAX];
    
    void propagate0(int pos, int l, int r) {
        if(prop[pos] == 0) return;
        if(l == r) return;
        int mid = (l+r)>>1;
        
        sum[pos<<1] += prop[pos]*(mid-l+1);
        sum[pos<<1|1] += prop[pos]*(r-mid);
        prop[pos<<1] = prop[pos<<1|1] = prop[pos];
        prop[pos] = 0;
    }
    
    void update0(int pos, int l, int r, int L, int R, int val) {    // update val, val, val, ... at each index 
        if(r < L || R < l) return;
        propagate0(pos, l, r);
        if(L <= l && r <= R) {
            sum[pos] += val*(r-l+1);
            prop[pos] += pos;
            return;
        }
        int mid = (l+r)>>1;
        update0(pos<<1, l, mid, L, R, val), update0(pos<<1|1, mid+1, r, L, R, val);
        sum[pos] = sum[pos<<1] + sum[pos<<1|1];
    }
    
    void propagate1(int pos, int l, int r) {                    // propagate func for update1
        if(leftProp[pos] == 0) return;
        if(l == r) return;
        int mid = (l+r)>>1;
        
        sum[pos<<1] += getSeqSumLeft(leftProp[pos], mid-l+1);
        sum[pos<<1|1] += getSeqSumLeft(mid+2-leftProp[pos], mid-r);
        leftProp[pos<<1] = leftProp[pos<<1|1] = leftProp[pos];
        leftProp[pos] = 0;
    }
    
    void update1(int pos, int l, int r, int L, int R) {         // update like 1, 2, 3, ... at each index i
        if(r < L || R < l) return;
        propagate1(pos, l, r);
        if(L <= l && r <= R) {
            sum[pos] += getSeqSumLeft(l-L+1, r-l+1);
            leftProp[pos] = L;
            return;
        }
        int mid = (l+r)>>1;
        update1(pos<<1, l, mid, L, R), update1(pos<<1|1, mid+1, L, R);
        sum[pos] = sum[pos<<1] + sum[pos<<1|1];
    }
    
    void propagate2(int pos, int l, int r) {
        if(rightProp[pos] == 0) return;
        if(l == r) return;
        int mid = (l+r)>>1;
        
        sum[pos<<1] += getSeqSumRight(mid-rightProp[pos]+1, mid-l+1);
        sum[pos<<1|1] += getSeqSumRight(r-rightProp[pos]+1, r-mid);
        rightProp[pos<<1] = rightProp[pos<<1|1] = rightProp[pos];
        rightProp[pos] = 0;
    }
    
    void update2(int pos, int l, int r, int L, int R) {                       // update like 3, 2, 1 at each index i
        if(r < L || R < l) return;
        propagate2(pos, l, r);
        if(L <= l && r <= R) {
            sum[pos] += getSeqSumRight(R-l+1, r-l+1);
            rightProp[pos] = R;
            return;
        }
        int mid = (l+r)>>1;
        update2(pos<<1, l, mid, L, R), update2(pos<<1|1, mid+1, r, L, R);
        sum[pos] = sum[pos<<1] + sum[pos<<1|1];
    }
     
     
    ll query(int pos, int l, int r, int L, int R) {
        propagate0(pos, l, r), propagate1(pos, l, r), propagate2(pos, l, r);
        if(L <= l && r <= R) return sum[pos];
        int mid = (l+r)>>1;
        return query(pos<<1, l, mid, L, R) + query(pos<<1|1, mid+1, r, L, R);
    }
};


int main() {
    return 0;
}
        
