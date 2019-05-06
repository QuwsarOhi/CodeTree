#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define mp make_pair
#define MAX 100010
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

struct SegTreeRSQ {
    ll carry[MAX*4], mn[MAX*4], mx[MAX*4];

    void init() {
        memset(carry, 0, sizeof carry);
        memset(mn, 0, sizeof mn);
        memset(mx, 0, sizeof mx);
    }

    void propagate(int pos, int l, int r) {
        if(carry[pos] == 0 || l == r) return;
        int mid = (l+r)>>1;
        
        carry[pos<<1] += carry[pos], carry[pos<<1|1] += carry[pos];
        mn[pos<<1] += carry[pos], mn[pos<<1|1] += carry[pos];
        mx[pos<<1] += carry[pos], mx[pos<<1|1] += carry[pos];
        carry[pos] = 0;
    }

    void update(int pos, int l, int r, int ql, int qr, int val) {
    	if(r < ql or qr < l) return;
    	//cerr << pos << " :: " << l << " - " << r << endl;
    	propagate(pos, l, r);
    	if(ql <= l and r <= qr) {
    		mn[pos] += val;
    		mx[pos] += val;
    		carry[pos] += val;
    		return;
    	}
    	int mid = (l+r)>>1;
    	update(pos<<1, l, mid, ql, qr, val);
    	update(pos<<1|1, mid+1, r, ql, qr, val);
    	mn[pos] = min(mn[pos<<1], mn[pos<<1|1]);
    	mx[pos] = max(mx[pos<<1], mx[pos<<1|1]);
    }

    ll query(int pos, int l, int r, int ql, int qr) {
    	if(r < ql or qr < l) return INF;
    	propagate(pos, l, r);
    	if(ql <= l and r <= qr)
    		return mn[pos];
    	int mid = (l+r)>>1;
    	return min(query(pos<<1, l, mid, ql, qr), query(pos<<1|1, mid+1, r, ql, qr));
    }

	void update(int n, int l, int r, int v) {
		//cerr << "UPDATE " << l << " - " << min(n, r) << " = " << v << endl;
		if(l > r) return;
		update(1, 1, n, l, min(n, r), v);
	}

	ll query(int l, int r) {
		return query(1, 1, r, l, r);
	}
};



SegTreeRSQ ST;
ll val[MAX];


void printer(int pos, int l, int r) {
	if(l == r) {
		cerr << l << " :: " << ST.mn[pos] << ", " << ST.carry[pos] << endl;
		return;
	}
	int mid = (l+r)>>1;
	printer(pos<<1, l, mid);
	printer(pos<<1|1, mid+1, r);
}

int main() {
    ll t, n, q, idx, x, typ, st;
    scanf("%lld", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lld%lld", &n, &q);

        ST.init(), ++n;
        printf("Case %d:\n", Case);
        for(int i = 1; i < n; ++i) {
        	scanf("%lld", &val[i]);
        	//cerr << "UPDATE " << i << " " << val[i] << endl;
        	ST.update(n, i+1, i+val[i], 1);
        }
        //cerr << "OKA" << endl;
        //printer(1, 1 , n);

        while(q--) {
        	scanf("%lld", &typ);

        	if(typ == 1) {
        		scanf("%lld%lld", &idx, &x);
        		ST.update(n, idx+1, idx+val[idx], -1);
        		ST.update(n, idx+1, idx+x, 1);
        		val[idx] = x;
        	}
        	else {
        		scanf("%lld", &x);
        		st = x;
        	}

        	if(typ == 2) {
        		if(st > 0 and ST.query(st+1, n) > 0)
        			printf("yes\n");
        		else
        			printf("no\n");

        		//cerr << "RANGE " << st+1 << " - " << n << endl;
        		//printer(1, 1, n);
        	}
        }
    }
}