#include <bits/stdc++.h>
using namespace std;
#define MAX                 200100
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

set<int>Divisors[320][245], QuSet;
int Div[1000100], val[1000100], blockSize;


void sqrtDecompose(int n) {
    blockSize = sqrt(n);
    int idx, pos;
    
    for(int i = 0; i < n; ++i) {
        idx = i/blockSize;
        pos = i%blockSize;
    

        Divisors[idx][Div[val[i]]].insert(val[i]);
    }
}


int Query(int l, int r, int k) {
    while(l%blockSize != 0 && l < r) {
        if(Div[val[l]] == k)
            QuSet.insert(val[l]);
        ++l;
    }
    while(l+blockSize <= r) {
        QuSet.insert(Divisors[l/blockSize][k].begin(), Divisors[l/blockSize][k].end());         // TLE LINE
        l += blockSize;
    }
    while(l <= r) {
        if(Div[val[l]] == k)
            QuSet.insert(val[l]);
        ++l;
    }
    
    return QuSet.size();
}


void DivCal(int n) {
    for(int i = 1; i <= n; ++i)
        for(int j = i; j <= n; j+=i)
            Div[j]++;
}


int main() {
    int n, l, r, k, q;
    
    DivCal(1000000);
    //fr(i, 1, 1000001)
    //    ans = max(ans, Div[i]);
    
    //cout << ans << endl;
    
    
    int t;
    sf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        sf("%d", &n);
        
        for(int i = 0; i < n; ++i)
            sf("%d", &val[i]);
        
        //for(int i = 0; i < n; ++i)
        //    pf("%d ", Div[val[i]]);
        //pf("\n");
        
        sf("%d", &q);
        sqrtDecompose(n);
        pf("Case %d:\n", Case);
        
        while(q--) {
            sf("%d%d%d", &l, &r, &k);
            --l, --r;
            QuSet.clear();
            pf("%d\n", Query(l, r, k));
        }
        
        if(Case+1 <= t)
            for(int i = 0; i < n; ++i)
                Divisors[i/blockSize][Div[val[i]]].clear();
    }
    
    return 0;
}
