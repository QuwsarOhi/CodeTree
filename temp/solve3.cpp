// YODANESS - Yodaness Level
// http://www.spoj.com/problems/YODANESS/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct BIT {
    vector<ll>tree;
    int MaxVal;
    
    void init(int sz=1e7) {
        tree.resize(sz+1, 0);
        MaxVal = sz+1;
    }

    void update(int idx, ll val) {
        for( ;idx <= MaxVal; idx += (idx & -idx))
            tree[idx] += val;
    }
    
    void update(int l, int r, ll val) {
        if(l > r) swap(l, r);
        update(l, val);
        update(r+1, -val);
    }

    ll read(int idx) {
        ll sum = 0;
        for( ;idx > 0; idx -= (idx & -idx))
            sum += tree[idx];
        return sum;
    }
    
    ll read(int l, int r) {
        ll ret = read(r) - read(l-1);
        return ret;
    }

    ll readSingle(int idx) {             // Point read in log(n)
        ll sum = tree[idx];
        if(idx > 0) {
            int z = idx - (idx & -idx);
            --idx;
            while(idx != z) {
                sum -= tree[idx];
                idx -= (idx & -idx);
            }
        }   
        return sum;
    }

    int search(int cSum) {
        int pos = -1, lo = 1, hi = MaxVal, mid;
        while(lo <= hi) {
            mid = (lo+hi)/2;
            if(read(mid) >= cSum) {     // read(mid) >= cSum : to find the lowest index of cSum value
                pos = mid;              // read(mid) == cSum : to find the greatest index of cSum value
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        return pos;
    }
    
    ll size() {
        return read(MaxVal);
    }
    
    int KthPos(int k) {
        if(read(MaxVal) > k)        // Position is greater than existing values in BIT
            return -1;
        return search(k);
    }
    
    void insert(int pos) {
        update(pos, 1);
    }
    
    void remove(int pos) {
        update(pos, -1);
    }
    
    // Modified BIT, this section can be used to add/remove/read 1 to all elements from 1 to pos
    // all of the inverse functions must be used, for any manipulation
    
    ll invRead(int idx) {           // gives summation from 1 to idx
        return read(MaxVal-idx);
    }
    
    void invInsert(int idx) {       // adds 1 to all index less than idx
        update(MaxVal-idx, 1);
    }
    
    void invRemove(int idx) {       // removes 1 from idx
        update(MaxVal-idx, -1);
    }
    
    void invUpdate(int idx, ll val) {
        update(MaxVal-idx, val);
    }
    
    /*void scale(int idx = MaxVal) {                    // BIT supports scaling
        for(int i = 0; i < idx; ++i)
            tree[i] %= MOD;                             // all mathematical operations supported
    }*/
};


unordered_map<string, int>Map;
char str[30000][30], tok[30];

int main() {
    int t, n;
    
    scanf("%d", &t);
    
    while(t--) {
        scanf("%d", &n);
        Map.clear();
        
        for(int i = 1; i <= n; ++i)
            scanf(" %s", str[i]);
        
        for(int i = 1; i <= n; ++i) {
            scanf(" %s", tok);
            Map[string(tok)] = i;
        }
        
        BIT bt;
        bt.init(n);
        ll ans = 0;
        
        for(int i = 1; i <= n; ++i) {
            int sortedIDX = Map[str[i]];
            
            ans += bt.invRead(sortedIDX);
            bt.invInsert(sortedIDX);
        }
        
        printf("%lld\n", ans);
    }
    return 0;
}
