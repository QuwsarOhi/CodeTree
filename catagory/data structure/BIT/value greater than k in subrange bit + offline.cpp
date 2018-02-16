// SPOJ KQUERY 
// http://www.spoj.com/problems/KQUERY/

// BIT + OFFLINE
// TLE WITH SEG-TREE

// Find values strictly greater than k in range [l, r]
// Offline Process

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


struct node {
    ll l, r, id, val;
    
    node(ll l, ll r, ll val, ll id) {
        this->l = l;
        this->r = r;
        this->val = val;
        this->id = id;
    }
};

vector<node>v;
ll tree[31000], MaxVal = 30100;
int ans[200100];

inline void fastIn(ll &num) {          // Fast IO, with space and new line ignoring
    bool neg = false;
    register int c;
    num = 0;
    c = getchar_unlocked();
    for( ; c != '-' && (c < '0' || c > '9'); c = getchar_unlocked());
    if (c == '-') {
        neg = true;
        c = getchar_unlocked();
    }
    for(; (c>47 && c<58); c=getchar_unlocked())
        num = (num<<1) + (num<<3) + c - 48;
    if(neg)
        num *= -1;
}


void update(int idx, int val) {
	while(idx <= MaxVal) {
		tree[idx] = (val + tree[idx]);
		idx += (idx & -idx);
	}
}


long long read(int idx) {
	long long sum = 0;
	while(idx > 0) {
		sum = (tree[idx] + sum);
		idx -= (idx & -idx);
	}
	return sum;
}


bool cmp(node a, node b) {
    if(a.val != b.val)
        return a.val > b.val;           // Greater value goes first
    return a.id > b.id;                 // ID = -1 for input values, so if there is any query, it should go first
}

int main() {
    ll n, l, r, k, x, q;
    
    fastIn(n);
    
    for(ll i = 1; i <= n; ++i) {
        fastIn(x);
        v.push_back({i, -1, x, -1});
    }
    
    fastIn(q);
    
    for(ll i = 1; i <= q; ++i) {
        fastIn(l), fastIn(r), fastIn(k);
        v.push_back({l, r, k, i});
    }
    
    sort(v.begin(), v.end(), cmp);      // Sorting gurantees that every greater value contains 1 in their position
    
    
    for(auto it : v) {
        if(it.id == -1)
            update(it.l, 1);            // This value is greater than all other queries that comes next, so set 1 to this index
        else
            ans[it.id] = read(it.r) - read(it.l-1);     // Range Sum
    }
    
    for(ll i = 1; i <= q; ++i)
        printf("%d\n", ans[i]);
    
    return 0;
}
