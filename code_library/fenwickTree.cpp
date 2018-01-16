#include <bits/stdc++.h>
using namespace std;
#define MAX                 1e6
#define EPS                 1e-9
#define INF                 1e9+10
#define MOD                 1000000007
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
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<ll, ll>mll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<ll>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;
// ----------------------- 1D Fenwick Tree-----------------

long long tree[100010];
int MaxVal;

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

// Tested Version
// Complexity : LogN
int binarySearch(int cSum) {			// Binary search for the cumulative sum
	int idx = 0, tIdx;					// Returns the greater index if value is present more than once
	int bitmask = highBitMaxVal;		// Another way is to use hand made binary search with read() function (logN)^2 complexity
	
	while(bitmask != 0 && idx < MaxVal) {
		tIdx = idx + bitmask;
		if(cSum == tree[tIdx])
			return tIdx;
		if(cSum > tree[tIdx]) {
			idx = tIdx;
			cSum -= tree[tIdx];
		}
		bitmask >>= 1;
	}
	if(cSum != 0) 
		return -1;
	else
		return idx;
}

// Complexity : (logN)^2
int binarySearch(int lo, int hi, int cSum) {		// Returns the greater index if value is present more than once
	int pos = -1, mid;								// More trustworthy
	while(lo <= hi) {
		mid = (lo+hi)/2;
		if(read(mid) == cSum) {
			pos = mid;
			hi = mid-1;
		}
		else
			lo = mid+1;
	}
	return pos;
}

// --------------------------- 2D Fenwick Tree -------------------------

/*
    /\
 y  |
    |   (x1,y2) -------- (x2,y2)
    |          |       |
    |          |       |
    |          |       |
    |          ---------
    |   (x1,y1)			(x2, y1)
    |
    |___________________________
   (0, 0)                   x-->
*/

ull tree[2510][2510];
int xMax = 2505, yMax = 2505;

// Updates from min point to MAX LIMIT
void update(int x, int y, ll val) {
	int y1;
	while(x <= xMax) {
		y1 =  y;
		while(y1 <= yMax) {
			tree[x][y1] += val;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}

// Reads from (0, 0) to (x, y)
ll read(int x, int y) {
	ll sum = 0;
	int y1;
	while(x > 0) {
		y1 = y;
		while(y1 > 0) {
			sum += tree[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return sum;
}

ll readSingle(int x, int y) {
    return read(x, y) + read(x-1, y-1) - read(x-1, y) - read(x, y-1);
}

void updateSquare(pii p1, pii p2, ll val) {     // p1 : lower left point, p2 : upper right point
    update(p1.first, p1.second, val);
    update(p1.first, p2.second+1, -val);
    update(p2.first+1, p1.second, -val);
    update(p2.first+1, p2.second+1, val);
}


ll readSquare(pii p1, pii p2) {                // p1 : lower left point, p2 : upper right point
    ll ans = read(p2.first, p2.second);
    ans -= read(p1.first-1, p2.second);
    ans -= read(p2.first, p1.second-1);
    ans += read(p1.first-1, p1.second-1);
    return ans;
}

// // --------------------------- 3D Fenwick Tree -------------------------

ll tree[105][105][105];
ll xMax = 100, yMax = 100, zMax = 100;
void update(int x, int y, int z, ll val) {
    int y1, z1;
    while(x <= xMax) {
        y1 = y;
        while(y1 <= yMax) {
            z1 = z;
            while(z1 <= zMax) {
                tree[x][y1][z1] += val;
                z1 += (z1 & -z1);
            }
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}
 
ll read(int x, int y, int z) {
    ll sum = 0;
    int y1, z1;
    while(x > 0) {
        y1 = y;
        while(y1 > 0) {
            z1 = z;
            while(z1 > 0) {
                sum += tree[x][y1][z1];
                z1 -= (z1 & -z1);
            }
            y1 -= (y1 & -y1);
        }
        x -= (x & -x);
    }
    return sum;
}


ll readRange(ll x1, ll y1, ll z1, ll x2, ll y2, ll z2) {
    --x1, --y1, --z1;
    return  read(x2, y2, z2) 
    - read(x1, y2, z2)
    - read(x2, y1, z2)
    - read(x2, y2, z1)
    + read(x1, y1, z2) 
    + read(x1, y2, z1) 
    + read(x2, y1, z1)
    - read(x1, y1, z1);
}

// Not tested yet!!
void updateRange(int x1, int y1, int z1, int x2, int y2, int z2) {
    update(x1, y1, z1, val);
    update(x2+1, y1, z1, -val);
    update(x1, y2+1, z1, -val);
    update(x1, y1, z2+1, -val);
    update(x2+1, y2+1, z1, val);
    update(x1, y2+1, z2+1, val);
    update(x2+1, y1, z2+1, val);
    update(x2+1, y2+1, z2+1, -val);
}


// Pattens to built BIT update read:
// always starts with first(starting point), add val
// take (1 to n) elements from ending point with all combination add it to staring point, add (-1)^n * val

