#include <bits/stdc++.h>
#define MAX 250090
using namespace std;
typedef long long ll;

struct STree {
    ll sum[4*MAX], SetVal[4*MAX], lftProp[4*MAX], rhtProp[4*MAX], lftd[4*MAX], rhtd[4*MAX];
    bool hasSet[4*MAX];
    
    void init() {
        memset(sum, 0, sizeof sum);
        memset(SetVal, 0, sizeof SetVal);
        memset(lftProp, 0, sizeof lftProp);
        memset(rhtProp, 0, sizeof rhtProp);
        memset(lftd, 0, sizeof lftd);
        memset(rhtd, 0, sizeof rhtd);
        memset(hasSet, 0, sizeof hasSet);
    }
    
    ll getSum(ll a, ll l, ll r, ll d) {
        ll n = r-l+1;
        cerr << "GS " << l << " " << r << " " << a << " " << d << " " << n << " : " << (n*(2*a + (n-1)*d))/2 << endl; 
        return (n*(2*a + (n-1)*d))/2;
    }
    
    ll getRevSum(ll a, ll l, ll r, ll d) {
        ll n = r-l+1;
        //cout << "PST a " << a << endl; 
        a = a-(n-1)*d;
        cerr << "GS " << l << " " << r << " " << a << " " << d << " " << n << " : " << (n*(2*a + (n-1)*d))/2 << endl;
        return (n*(2*a + (n-1)*d))/2;
    }
    
    
    void propagateSet(int pos, int l, int r) {
        if(l == r || hasSet[pos] == 0) return;
        int mid = (l+r)>>1;
        
        sum[pos<<1] = SetVal[pos]*(mid-l+1);
        sum[pos<<1|1] = SetVal[pos]*(r-mid);
        
        SetVal[pos<<1] = SetVal[pos<<1|1] = SetVal[pos];
        hasSet[pos<<1] = hasSet[pos<<1|1] = 1;
        hasSet[pos] = 0, SetVal[pos] = 0;
        
        // If there is a set value operation in propagation, then erase all previous works
        lftd[pos<<1] = lftProp[pos<<1] = rhtd[pos<<1] = rhtProp[pos<<1] = 0;
        lftd[pos<<1|1] = lftProp[pos<<1|1] = rhtd[pos<<1|1] = rhtProp[pos<<1|1] = 0;
    }
    
    void propagateSeq(int pos, int l, int r) {
        if(l == r) return;
        int mid = (l+r)>>1;
        
        // Overlapping Increment and SetValue propagation
        //propagateSet(pos<<1, l, mid);
        //propagateSet(pos<<1|1, mid+1, r);
        
        if(lftd[pos]) {             // sequence propagation exists
            sum[pos<<1] += getSum(lftProp[pos], l, mid, lftd[pos]);
            ll rhtVal = lftProp[pos] + (mid+1-l) * lftd[pos];
            sum[pos<<1|1] += getSum(rhtVal, mid+1, r, lftd[pos]);
            
            lftProp[pos<<1] += lftProp[pos], lftProp[pos<<1|1] += rhtVal;
            lftd[pos<<1]++, lftd[pos<<1|1]++;
            lftd[pos] = lftProp[pos] = 0;
        }
        
        if(rhtd[pos]) {             // reversed sequence exists
            //sum[pos<<1|1] += getRevSum(rhtProp[pos], mid+1, r, rhtd[pos]);
            //ll lftVal = rhtProp[pos] - (r-mid) * rhtd[pos];
            //sum[pos<<1] += getRevSum(lftVal, l, mid, rhtd[pos]);
            
            sum[pos<<1] += getRevSum(rhtProp[pos], l, mid, rhtd[pos]);
            ll rhtVal = rhtProp[pos] - (r-mid) * rhtd[pos];
            sum[pos<<1|1] += getRevSum(rhtVal, mid+1, r, rhtd[pos]);
            
            rhtProp[pos<<1] += rhtProp[pos], rhtProp[pos<<1|1] += rhtVal;
            rhtd[pos<<1]++, rhtd[pos<<1|1]++;
            rhtd[pos] = rhtProp[pos] = 0;
        }
    }
    
    void propagate(int pos, int l, int r) {
        propagateSet(pos, l, r);
        propagateSeq(pos, l ,r);
    }
    
    void SetValue(int pos, int l, int r, int L, int R, ll x) {
        if(r < L || R < l) return;
        propagate(pos, l, r);
        if(L <= l && r <= R) {
            sum[pos] = x*(r-l+1);
            hasSet[pos] = 1, SetVal[pos] = x;
            return;
        }
        int mid = (l+r)>>1;
        SetValue(pos<<1, l, mid, L, R, x), SetValue(pos<<1|1, mid+1, r, L, R, x);
        sum[pos] = sum[pos<<1] + sum[pos<<1|1];
    }
    
    void AddSeq(int pos, int l, int r, int L, int R) {
        if(r < L || R < l) return;
        //cerr << "AT " << pos << " " << lftProp[pos] << " " << lftd[pos] << " " << rhtProp[pos] << " " << rhtd[pos] << " " << SetVal[pos] << endl;
        propagate(pos, l, r);
        cerr << "AT " << pos << " [" << l << ", " << r << "] :" << sum[pos] << endl;
        if(L <= l && r <= R) {
            sum[pos] += getSum(l-L+1, l, r, 1);
            lftd[pos] = 1, lftProp[pos] = l-L+1;
            cerr << "SUM " << sum[pos] << endl;
            return;
        }
        int mid = (l+r)>>1;
        AddSeq(pos<<1, l, mid, L, R), AddSeq(pos<<1|1, mid+1, r, L, R);
        sum[pos] = sum[pos<<1] + sum[pos<<1|1];
    }
    
    void AddRevSeq(int pos, int l, int r, int L, int R) {
        if(r < L || R < l) return;
        propagate(pos, l, r);
        cerr << "AT " << pos << " [" << l << ", " << r << "] :" << sum[pos] << endl;
        if(L <= l && r <= R) {
            sum[pos] += getRevSum(R-l+1, l, r, 1);
            rhtd[pos] = 1, rhtProp[pos] = R-l+1;
            cerr << "SUM " << sum[pos] << endl;
            return;
        }
        int mid = (l+r)>>1;
        AddRevSeq(pos<<1, l, mid, L, R), AddRevSeq(pos<<1|1, mid+1, r, L, R);
        sum[pos] = sum[pos<<1] + sum[pos<<1|1];
    }
    
    ll query(int pos, int l, int r, int L, int R) {
        if(r < L || R < l) return 0;
        cerr << "AT " << pos << " " << lftProp[pos] << " " << lftd[pos] << " " << rhtProp[pos] << " " << rhtd[pos] << " " << SetVal[pos] << endl;
        propagate(pos, l, r);
        cerr << "AT " << pos << " [" << l << ", " << r << "] :" << sum[pos] << endl;
        if(L <= l && r <= R) {
            cerr << "RETSUM " << sum[pos] << endl;
            return sum[pos];
        }
        int mid = (l+r)>>1;
        return query(pos<<1, l, mid, L, R) + query(pos<<1|1, mid+1, r, L, R);
    }
};
        

STree ST;

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    
    int t, q;
    ll a, b, c, LIM = 110;
    char typ;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &q);
        printf("Case %d:\n", Case);
        ST.init();
        
        while(q--) {
            scanf(" %c %lld%lld", &typ, &a, &b);
            if(typ == 'A')
                ST.AddSeq(1, 1, LIM, a, b);
            else if(typ == 'B')
                ST.AddRevSeq(1, 1, LIM, a, b);
            else if(typ == 'C') {
                scanf("%lld", &c);
                ST.SetValue(1, 1, LIM, a, b, c);
            }
            else
                printf("%lld\n", ST.query(1, 1, LIM, a, b));
            
            cerr << "TOT " << ST.sum[1] << endl;
        }
    }
    return 0;
}
        
