<<<<<<< HEAD
#include <bits/stdc++.h>
#define MAXN 5
using namespace std;
typedef long long ll;

ll MOD;

struct MAT {
    MAT() { memset(m, 0, sizeof(m)); }
    long long m[MAXN][MAXN];
};

MAT mul(const MAT a, const MAT b, int p, int q, int r) {		// O(n^3) :: r1, c1, c2  [c1 = r2]
    MAT ans;
    for(int i = 0; i < p; ++i)
        for(int j = 0; j < r; ++j) {
            ans.m[i][j] = 0;
            for(int k = 0; k < q; ++k)
                ans.m[i][j] = (ans.m[i][j]%MOD + (a.m[i][k]%MOD * b.m[k][j]%MOD)%MOD)%MOD;
        }
    return ans;
}

MAT pow(const MAT xx, ll p, int sz) {                      // Power using loop
    if(p == 1) return xx;
    MAT ret, x = xx;
    for(int i = 0; i < sz; ++i) ret.m[i][i] = 1;    // Diagonal Matrix
    while(p > 0) {
        if(p&1) ret = mul(ret, x, sz, sz, sz);
        p = p >> 1, x = mul(x, x, sz, sz, sz);
    }
    return ret;
}

void printer(MAT x, int sz) {
	for(int i = 0; i < sz; ++i) {
		for(int j = 0; j < sz; ++j) {
			cout << x.m[i][j] << " ";
		}
		cout << endl;
	}
}

ll get(int q) {
	if(q <= 2)
		return 1;
	if(q%2 == 0)
		return 2*get(q-1) - get(q-2) + 2;
	return 3*get(q-2);
}

MAT f, To, Te, T;

MAT getEVEN(ll n) {
	n -= 2;
	MAT TT = pow(T, n/2, 4);
	TT = mul(TT, f, 4, 4, 4);
	return TT;
}

MAT getODD(ll n) {
	n -= 3;
	MAT TT = pow(T, n/2, 4);
	TT = mul(To, TT, 4, 4, 4);
	TT = mul(TT, f, 4, 4, 4);
	return TT;
}



ll CAL(ll L, ll R) {
	L -= 1;
	if(L == 0)
		L = 0;
	else if(L == 1)
		L = 1;
	else if(L == 2)
		L = 2;
	else {
		if(L%2 == 0)
			L = getEVEN(L).m[0][0];
		else
			L = getODD(L).m[0][0];
	}

	//cout << "T\n";
	//printer(T, 4);

	if(R == 1)
		R = 1;
	else if(R == 2)
		R = 2;
	else {
		if(R%2 == 0)
			R = getEVEN(R).m[0][0];
		else
			R = getODD(R).m[0][0];
	}

	//cout << L << ", " << R << endl;
	return ((((R-L)%MOD)+MOD)%MOD);
}

int main() {
	ll t, l, r;
	scanf("%lld%lld", &t, &MOD);

	//MAT f;
	f.m[0][0] = 2;
	f.m[1][0] = 1;
	f.m[2][0] = 1;
	f.m[3][0] = 2;
	//cout << "f\n"; printer(f, 4);

	//MAT Te;
	Te.m[0][0] = 1;
	Te.m[0][1] = 2;
	Te.m[0][2] = -1;
	Te.m[0][3] = 1;
	Te.m[1][1] = 2;
	Te.m[1][2] = -1;
	Te.m[1][3] = 1;
	Te.m[2][1] = 1;
	Te.m[3][3] = 1;
	//cout << "Te\n"; printer(Te, 4);

	//MAT To;
	To.m[0][0] = 1;
	To.m[0][2] = 3;
	To.m[1][2] = 3;
	To.m[2][1] = 1;
	To.m[3][3] = 1;
	//cout << "To\n"; printer(To, 4);

	T = mul(Te, To, 4, 4, 4);
	//cout << "T\n"; printer(T, 4);

	while(t--) {
		scanf("%lld%lld", &l, &r);
		printf("%lld\n", CAL(l, r));
	}

	return 0;
}
=======
>>>>>>> 70a5491588d00ec98f196356c1f76d863f3bdd71
