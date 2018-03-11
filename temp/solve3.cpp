/*
struct SegTreeRSQ {
    vector<ll>sum;
    vector<bool>prop;
    
    void propagate(int pos, int l, int r) {
        if(!prop[pos] || l == r)
            return;
        
        int mid = (l+r)>>1;
        
        
    void init(int pos, int l, int r) {
        if(l == r) {
            sum[pos] = val[l];
            return;
        }
        
        int mid = (l+r)>>1;
        init(pos<<1, l, mid);
        init(pos<<1|1, mid+1, r);
        sum[pos] = (sum[pos<<1] + sum[pos<<1|1])%MOD;
    }
    
    void update(int pos, int l, int r, int L, int R, ll val) {
        if(r < L || R < l)
            return;
        
        // prop
        if(L <= l && r <= R) {
            sum[pos] += val;
            prop[pos] = 1;
            return;
        }
        
        int mid = (l+r)>>1;
        update(pos<<1, l, mid, L, R, val);
        update(pos<<1|1, mid+1, r, L, R, val);
        
        sum[pos] = (sum[pos<<1] + sum[pos<<1|1])%MOD;
    }
    
    ll query(int pos, int l, int r, int L, int R) {
        if(r < L || R < l)
            return;
        
        // prop
        if(L <= l && r <= R)
            return sum[pos];
        
        int mid = (l+r)>>1;
        return (query(pos<<1, l, mid, L, R) + query(pos<<1|1, mid+1, r, L, R))%MOD;
    }
};*/

