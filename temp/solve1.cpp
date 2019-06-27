<<<<<<< HEAD
	#include <bits/stdc++.h>
	#define MAX 100009
	using namespace std;
	typedef long long ll;

	ll cnt[MAX];

	ll MOD(ll v, ll mod = 1000000007) {
	    if(v < mod) {
	        v %= mod;
	        v += mod;
	    }
	    return v%mod;
	}

	ll powerMOD(ll x, ll y) {
	    ll res = 1;
	    x = MOD(x);
	    while(y > 0) {
	        if(y&1) res = MOD(res*x);
	        y = y >> 1, x = MOD(x*x);
	    }
	    return MOD(res);
	}

	ll fa[MAX], fainv[MAX];
	ll C(ll n, ll r) {     
	    if(fa[0] == 0) {   
	        fa[0] = 1, fainv[0] = powerMOD(1, 1000000005);
	        for(int i = 1; i < MAX; ++i) {
	            fa[i] = MOD(fa[i-1]*i); 
	            fainv[i] = powerMOD(fa[i], 1000000005);
	    }}
	    if(n < 0 || r < 0 || n-r < 0) return 0;         // Exceptional Cases
	    return MOD(MOD(fa[n] * fainv[r]) * fainv[n-r]);
	}


	int main() {
	    ll t, n;
	    cin >> t;

	    while(t--) {
	        cin >> n;
	        ll tot = C(n, 4), greaterONE = 0, ans = 0;

	        memset(cnt, 0, sizeof cnt);
	        for(ll i = 2; n/i >= 4; ++i)
	            cnt[i] = C(n/i, 4);

	        for(int i = 2; i<=n; i++)
	        	for(int j = i+i; j <= n; j += i)
	        		cnt[i] -= cnt[j];

	        for(int i = 2; n/i >= 4; ++i) {
	        	tot -= cnt[i];
	        	//cout << i << " " << cnt[i] << endl;
	        	ans = MOD(ans + MOD(cnt[i] * MOD(i*MOD(i*MOD(i*i)))));
	        }

	        cout << MOD(ans+MOD(tot-greaterONE)) << endl;
	    }

	    return 0;
	}
=======
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    ++n;

    int cnt = 0;
    for(int i = 1; i <= 5; ++i) {
        int x = m+i;
        if(x > n) {
            if(x%n == 0)
                x = n;
            else
                x = x%n;
        }
        if(x != 1) 
            ++cnt;
    }
    cout << cnt << endl;
    return 0;
}
>>>>>>> 70a5491588d00ec98f196356c1f76d863f3bdd71
