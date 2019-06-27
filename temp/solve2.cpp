<<<<<<< HEAD
#include <bits/stdc++.h>
#define MAX 100009
using namespace std;
typedef long long ll;

struct BIT {
    ll tree[MAX], v[MAX];
    int MaxVal;
    void init(int sz) {
        for(int i = 1; i <= sz; ++i)
            tree[i] = 1;
        MaxVal = sz;
    }
    void MUL(int idx, ll val) {
        for( ;idx <= MaxVal; idx += (idx & -idx)) {
            tree[idx] *= val;
            cout << idx << " -> " << tree[idx] << ", ";
        }
        cout << endl;
    }
    void DIV(int idx, ll val) {
        for( ;idx <= MaxVal; idx += (idx & -idx))
            tree[idx] /= val;
    }
    void update(int idx, ll val) {
        DIV(idx, v[idx]);
        MUL(idx, val);
        v[idx] = val;
    }
    ll read(int idx) {
        ll m = 1;
        for( ;idx > 0; idx -= (idx & -idx))
            m *= tree[idx];
        return m;
    }
    ll read(int l, int r) {
        ll m = read(r);
        return m / read(l-1);
    }
    ll tot() {
        return read(MaxVal);
    }
};

BIT v;

int main() {
    int n, q;
    scanf("%d%d", &n, &q);

    v.init(n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &v.v[i]);
        v.MUL(i, v.v[i]);
    }

    for(int i = 1; i <= n; ++i)
        cout << i << " :: " << v.read(i) << endl;

    return 0;
}

/*

4 6 3 50
3 4 2 5

*/
=======
// LightOJ
// 1369 - Answering Queries

#include <bits/stdc++.h>
#define MAX 100009
using namespace std;
typedef long long ll;

ll v[MAX];

int main() {
	int q, t, n, m, idx;
	ll val;
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i)
			scanf("%lld", &v[i]);

		ll ans = 0;
		for(int i = 1; i <= n; ++i)
			ans += v[i]*(n-i);
		for(int i = 1; i <= n; ++i)
			ans -= v[i]*(i-1);

		printf("Case %d:\n", Case);
		while(m--) {
			scanf("%d", &q);
			
			if(q == 0) {
				scanf("%d%lld", &idx, &val);
				++idx;
				
				ans -= v[idx]*(n-idx);
				ans += val*(n-idx);

				ans += v[idx]*(idx-1);
				ans -= val*(idx-1);

				v[idx] = val;
			}
			else {
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}
>>>>>>> 70a5491588d00ec98f196356c1f76d863f3bdd71
