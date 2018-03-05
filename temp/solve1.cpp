#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct BIT {
    vector<ll>tree;
    int MaxVal;
    
    void init(int sz=1e7) {
        tree.resize(sz+1, 0);
        MaxVal = sz;
    }

    void update(int idx, ll val) {
        while(idx <= MaxVal) {
            //tree[idx] = (tree[idx] + MOD) % MOD;
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }
    
    void update(int l, int r, ll val) {
        if(l > r) swap(l, r);
        update(l, val);
        update(r+1, -val);
    }

    ll read(int idx) {
        ll sum = 0;
        while(idx > 0) {
            //sum = (sum + tree[idx] + MOD) % MOD;
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
    
    ll read(int l, int r) {
        ll ret = read(r) - read(l-1);
        //return (ret + MOD)%MOD;
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

    int search(int cSum) {		        // Returns the greater index if value is present more than once
        int pos = -1, lo = 1, hi = MaxVal, mid;
        while(lo <= hi) {
            mid = (lo+hi)/2;
            if(read(mid) >= cSum) {     // read(mid) >= cSum : can be used to find the lowest index of cSum value
                pos = mid;              // read(mid) == cSum : can be used to find the greatest index of cSum value
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
    
    /*void scale(int idx = MaxVal) {                      // BIT supports scaling
        for(int i = 0; i < idx; ++i)
            tree[i] %= MOD;
    }*/
};

BIT bt;
vector<int>v;

int main() {
    int t, n;
    scanf("%d", &t);
    
    while(t--) {
        scanf("%d", &n);
        v.resize(n+1);
        
        bt.init(n);
        
        for(int i = 1; i <= n; ++i)
            bt.update(i, 1);
        
        int pstPos = 0;
        for(int i = 1; i <= n; ++i) {
            //cout << "I " << i << endl;
            int pos = pstPos + i + 1;
            
            //cout << "Pos " << pos << endl;
            
            if(pos > bt.size()) {
                //cout << "MOD " << endl;
                pos %= bt.size();
                if(pos == 0) pos = bt.size();
            }
            
            //for(int i = 1; i <= n; ++i)
            //    printf("%lld ", bt.read(i));
            //printf("\n");
            //cout << "SZ " << bt.size() << endl;
            //cout << "Pos " << pos << endl;
            int newPos = bt.search(pos);
            //cout << "NewPos " << newPos << endl;
            v[newPos] = i;
            bt.update(newPos, -1);
            
            pstPos = max(bt.read(newPos), 0LL);
            //cout << "pstPos " << pstPos << endl;
        }
        
        for(int i = 1; i < n; ++i)
            printf("%d ", v[i]);
        printf("%d\n", v[n]);
    }
    
    return 0;
}
