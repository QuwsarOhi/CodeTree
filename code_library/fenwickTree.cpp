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

long long tree[1010][1010];
int xMax = 1001, yMax = 1001;

// Updates from min point to maxpoint

void update(int x, int y, int val) {
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

long long read(int x, int y) {
	long long sum = 0;
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
