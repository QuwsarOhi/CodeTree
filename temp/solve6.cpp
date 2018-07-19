#include <bits/stdc++.h>
#define MAX 250090
using namespace std;
typedef long long ll;

struct STree {
    ll sum[4*MAX], prop[4*MAX], leftProp[4*MAX], rightProp[4*MAX];
    
    void init() {
        memset(sum, 0, sizeof sum);
        memset(prop, 0, sizeof prop);
        memset(leftProp, 0, sizeof leftProp);
        memset(rightProp, 0, sizeof rightProp);
    }
    
    ll getSeqSumLeft(ll a, ll len) {
        cerr << "LEFT " << a << " len " << len << " " << (len*(2*a + len-1))/2 << endl;
        return (len*(2*a + len-1))/2;
        
    }
    
    ll getSeqSumRight(ll a, ll len) {
        a = a-len+1;
        cerr << "RIGHT " << a << " len " << len << " " << (len*(2*a+len-1))/2 << endl;
        return (len*(2*a+len-1))/2;
        
    }
    
    //void checkOverlap(int pos, int l, int r) {
    //    if(prop[pos<<1] != 0 )
    
    void propagate0(int pos, int l, int r) {
        if(prop[pos] == 0) return;
        if(l == r) return;
        int mid = (l+r)>>1;
        
        sum[pos<<1] = prop[pos]*(mid-l+1);
        sum[pos<<1|1] = prop[pos]*(r-mid);
        prop[pos<<1] = prop[pos<<1|1] = prop[pos];
        leftProp[pos<<1] = leftProp[pos<<1|1] = rightProp[pos<<1] = rightProp[pos<<1|1] = 0;
        prop[pos] = 0;
    }
    
    void propagate1(int pos, int l, int r) {                    // propagate func for update1
        if(leftProp[pos] == 0) return;
        if(l == r) return;
        int mid = (l+r)>>1;
        
        //checkOverlap(pos, l, r);
        //propagate0(pos, l, r);
        
        sum[pos<<1] += getSeqSumLeft(l-leftProp[pos]+1, mid-l+1);
        sum[pos<<1|1] += getSeqSumLeft(mid+2-leftProp[pos], r-mid);
        leftProp[pos<<1] += leftProp[pos]; 
        leftProp[pos<<1|1] += leftProp[pos];
        leftProp[pos] = 0;
    }
    
    void propagate2(int pos, int l, int r) {
        if(rightProp[pos] == 0) return;
        if(l == r) return;
        int mid = (l+r)>>1;
        
        //checkOverlap(pos, l, r);
        //propagate0(pos, l, r);
        
        sum[pos<<1] += getSeqSumRight(rightProp[pos]-mid+1, mid-l+1);
        sum[pos<<1|1] += getSeqSumRight(rightProp[pos]-r+1, r-mid);
        rightProp[pos<<1] = rightProp[pos<<1|1] = rightProp[pos];
        rightProp[pos] = 0;
    }
    
    void update0(int pos, int l, int r, int L, int R, int val) {    // update val, val, val, ... at each index 
        if(r < L || R < l) return;
        //propagate1(pos, l, r), propagate2(pos, l, r), propagate0(pos, l, r);
        propagate0(pos, l, r);
        cerr << "AT " << pos << " [" << l << ", " << r << "] :" << sum[pos] << endl;
        if(L <= l && r <= R) {
            sum[pos] = val*(r-l+1);
            prop[pos] = val;
            leftProp[pos] = rightProp[pos] = 0;
            cerr << "NEWSUM " << sum[pos] << endl;
            return;
        }
        int mid = (l+r)>>1;
        update0(pos<<1, l, mid, L, R, val), update0(pos<<1|1, mid+1, r, L, R, val);
        sum[pos] = sum[pos<<1] + sum[pos<<1|1];
    }
    
    void update1(int pos, int l, int r, int L, int R) {         // update like 1, 2, 3, ... at each index i
        if(r < L || R < l) return;
        //propagate1(pos, l, r), propagate2(pos, l, r), propagate0(pos, l, r);
        propagate1(pos, l, r);
        cerr << "AT " << pos << " [" << l << ", " << r << "] :" << sum[pos] << endl;
        if(L <= l && r <= R) {
            sum[pos] += getSeqSumLeft(l-L+1, r-l+1);
            leftProp[pos] = L;
            cerr << "NEWSUM " << sum[pos] << endl;
            return;
        }
        int mid = (l+r)>>1;
        update1(pos<<1, l, mid, L, R), update1(pos<<1|1, mid+1, r, L, R);
        sum[pos] = sum[pos<<1] + sum[pos<<1|1];
    }
    
    void update2(int pos, int l, int r, int L, int R) {                       // update like 3, 2, 1 at each index i
        if(r < L || R < l) return;
        //propagate1(pos, l, r), propagate2(pos, l, r), propagate0(pos, l, r);
        propagate2(pos, l, r);
        cerr << "AT " << pos << " [" << l << ", " << r << "] :" << sum[pos] << endl;
        if(L <= l && r <= R) {
            sum[pos] += getSeqSumRight(R-l+1, r-l+1);
            rightProp[pos] = R;
            cerr << "NEWSUM " << sum[pos] << endl;
            return;
        }
        int mid = (l+r)>>1;
        update2(pos<<1, l, mid, L, R), update2(pos<<1|1, mid+1, r, L, R);
        sum[pos] = sum[pos<<1] + sum[pos<<1|1];;
    }
     
     
    ll query(int pos, int l, int r, int L, int R) {
        if(r < L || R < l) return 0;
        propagate1(pos, l, r), propagate2(pos, l, r), propagate0(pos, l, r);
        cerr << "AT " << pos << " [" << l << ", " << r << "] :" << sum[pos] << endl;
        if(L <= l && r <= R) {
            cerr << "RETSUM " << sum[pos] << endl;
            return sum[pos];
        }
        int mid = (l+r)>>1;
        ll ret = query(pos<<1, l, mid, L, R) + query(pos<<1|1, mid+1, r, L, R);
        
        return ret;
    }
};

STree ST;

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, q;
    ll a, b, c, LIM = 4;//250005;
    char typ;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &q);
        printf("Case %d:\n", Case);
        ST.init();
        
        while(q--) {
            scanf(" %c %lld%lld", &typ, &a, &b);
            if(typ == 'A')
                ST.update1(1, 1, LIM, a, b);
            else if(typ == 'B')
                ST.update2(1, 1, LIM, a, b);
            else if(typ == 'C') {
                scanf("%lld", &c);
                ST.update0(1, 1, LIM, a, b, c);
            }
            else
                printf("%lld\n", ST.query(1, 1, LIM, a, b));
            
            cerr << "TOT " << ST.sum[1] << endl;
        }
    }
    return 0;
}
        
