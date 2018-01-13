#include <bits/stdc++.h>
using namespace std;
#define MAX                 100100
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000003
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS)) 
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbug(vari)          cerr << #vari << " = " << (vari) <<endl
#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<ll, ll>mll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<long long>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;

long long tree[101000], val[101000];

int MaxVal = 100100;

void update(int idx, int val) {
	while(idx <= MaxVal) {
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

long long read(int idx) {
	long long sum = 0;
	while(idx > 0) {
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}


long long readSingle(int idx) {
	long long sum = tree[idx];
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

int main() {
    //fileRead("in");
    //fileWrite("out");
    int t, n, m, q, x, y, l, r, Case = 1;
    
    FastRead;
    cin >> t;
    
    while(t--) {
        cin >> n >> m >> q;
        memset(tree, 0, sizeof tree);
        memset(val, 0, sizeof val);
        //dbug(n), dbug(m), dbug(q);
        for(int i = 1; i <= n; ++i) {
            cin >> x;
            update(i, x);
            update(i+1, -x);
        }
        
        val[0] = 0;
        for(int i = 1; i <= m; ++i) {
            cin >> x;
            val[i] = val[i-1]+x;
        }
        
        cout << "Case " << Case << ":\n";
        ++Case;
        while(q--) {
            cin >> x >> y >> l >> r;
            if(x > y)
                swap(x, y);
            if(l > r)
                swap(l, r);
            ll add = val[y]-val[x-1];
            //dbug(add);
            update(l, add);
            update(r+1, -add);
        }
        
        ll ans = read(1);
        cout << ans;
        for(int i = 2; i <= n; ++i) {
            ll tmp = read(i);
            cout << " " << tmp;
        }
        cout << "\n";
    }
    
    return 0;
}
