#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct station { 
    int x, r, f; 
};


int n, k;
long long ans;

vector<station> a;
ordered_set st[11001];

bool cmp(station x, station y) {
    return x.r > y.r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    
	cin >> n >> k;
	
    for(int i = 0,x,r,f; i < n; i++) {
		cin >> x >> r >> f;
		a.push_back({x,r,f});
	}
	
    sort(a.begin(), a.end(), cmp);
	
    for(auto p: a) {
		for(int kk = max(p.f-k, 1); kk <= p.f+k; kk++) 
            ans += st[kk].order_of_key(p.x+p.r+1) - st[kk].order_of_key(p.x-p.r);
		st[p.f].insert(p.x);
	}
	
    cout << ans;
}
