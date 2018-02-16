// LightOJ
// 1085 - All Possible Increasing Subsequences


#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long tree[100010], val[100010];
int MaxVal;
map<long long, int>Map;

void update(int idx, int val) {
	while(idx <= MaxVal) {
		tree[idx] = (val + tree[idx]) % MOD;
		idx += (idx & -idx);
	}
}

long long read(int idx) {
	long long sum = 0;
	while(idx > 0) {
		sum = (tree[idx] + sum) % MOD;
		idx -= (idx & -idx);
	}
	return sum%MOD;
}


long long findMax(long long x) {
    return (read(MaxVal) - read(x) + MOD)%MOD;
}

int main() {
    int t, n;
    
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &n);
        MaxVal = 0;
        memset(tree, 0, sizeof tree);
        
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", &val[i]);
            Map[val[i]];
        }
        
        map<long long, int> :: iterator it;
        MaxVal = 0;
        
        for(it = Map.begin(); it != Map.end(); ++it)
            it->second = ++MaxVal;
        
        for(int i = n; i >= 1; --i) {
            long long tmp = (findMax(Map[val[i]]) + 1)%MOD;
            update(Map[val[i]], tmp);
        }
        
        printf("Case %d: %lld\n", Case, read(MaxVal)%MOD);
        
        Map.clear();
    }
    
    return 0;
}
