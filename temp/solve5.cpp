// SPOJ - ORDERSET - Order statistic set
// http://www.spoj.com/problems/ORDERSET/

#include <bits/stdc++.h>
using namespace std;
#define MAX                 210000
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define All(S)              S.begin(), S.end()              
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())
#define error(args...)      { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)

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

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {                                                  // Debugger error(a, b, ....)
	cerr << *it << " = " << a << "\n";
	err(++it, args...);
}

//const int dx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};                                                      // Four side 
//const int dxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};                     // Eight side
//----------------------------------------------------------------------------------------------------------

unordered_map<int, int>Map;
unordered_map<int, int>ReMap;
int MaxVal = 0, tree[MAX];
set<int>Set;
set<int>Compress;
vector<pair<char, int> > Query;

void update(int idx, int val) {
	while(idx <= MaxVal) {
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

ll read(int idx) {
	ll sum = 0;
	while(idx > 0) {
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

ll readSingle(int idx) {
	ll sum = tree[idx];
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

int getIDX(ll val) {
    if(Map.find(val) ==  Map.end())
        return 0;
    return Map[val];
}

void Insert(int val) {
    if(readSingle(val))
        return;
    update(val, 1);
}

void Delete(int val) {
    if(!readSingle(val))
        return;
    update(val, -1);
}

int Smaller(int val) {
    return read(val-1);
}

ll Kth(int k) {
    int low = 1, hi = MaxVal, pos = -1;
    if(k > read(MaxVal))
        return -1;
    
    while(low <= hi) {
        int mid = (low+hi)>>1;
		if(read(mid) >= k) {
			pos = mid;
			hi = mid-1;
		}
		else
			low = mid+1;
    }
    
    return pos;
}

int main() {
    int t, x;
    char q;
    
    scanf("%d", &t);
    
    for(int i = 0; i < t; ++i) {
        scanf(" %c %d", &q, &x);
        if(q != 'K')
            Compress.insert(x);
        Query.push_back({q, x});
    }
    
    for(auto it = Compress.begin(); it != Compress.end(); ++it) {
        Map[*it] = ++MaxVal;
        ReMap[MaxVal] = *it;
    }
    
    for(int i = 0; i < t; ++i) {
        if(Query[i].first == 'I')
            Insert(Map[Query[i].second]);
        else if(Query[i].first == 'D')
            Delete(Map[Query[i].second]);
        else if(Query[i].first == 'C')
            printf("%d\n", Smaller(Map[Query[i].second]));
        else {
            int ans = Kth(Query[i].second);
            if(ans == -1)
                printf("invalid\n");
            else
                printf("%d\n", ReMap[ans]);
        }
    }
    
    return 0;
}
