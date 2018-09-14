#include <bits/stdc++.h>
using namespace std;
#define MAX                 100100
#define EPS                 1e-9
#define INF                 1e7
#define pb                  push_back
#define mp                  make_pair
#define xx                  first
#define yy                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define All(S)              S.begin(), S.end()
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

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

#include <ext/pb_ds/assoc_container.hpp>    // rb_tree_tag
#include <ext/pb_ds/tree_policy.hpp>        // tree_order_statistics_node_update
#define at(X)          find_by_order(X)
#define lessThan(X)    order_of_key(X)
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------


struct HashTree {
    vector<ll>sum, propSum, propMul;
    ll mod, len;
    void init(int n, ll _mod) {
        sum.resize(4*n);
        propSum.resize(4*n);
        propMul.resize(4*n);
        mod = _mod, len = n;
        init(1, 1, len);
    }
    inline ll add(ll a, ll b) {
        //a = ((a%mod) + mod)%mod, b = ((b%mod) + mod)%mod;         // Can Cause TLE
        return (a+b)%mod;
    }
    inline ll mul(ll a, ll b) {
        //a = ((a%mod) + mod)%mod, b = ((b%mod) + mod)%mod;         // Can Cause TLE
        return (a*b)%mod;
    }
    void pushDown(int child, int par) {                             // just push down the values
        propSum[child] = mul(propSum[child], propMul[par]);
        propSum[child] = add(propSum[child], propSum[par]);
        propMul[child] = mul(propMul[child], propMul[par]);
    }
    void init(int pos, int l, int r) {                              // NOTE: init must be called!!
        sum[pos] = propSum[pos] = 0, propMul[pos] = 1;
        if(l == r) return;
        int mid = (l+r)>>1;
        init(pos<<1, l, mid);
        init(pos<<1|1, mid+1, r);
        sum[pos] = add(sum[pos<<1], sum[pos<<1|1]);
    }
    void propagate(int pos, int l, int r) {                         // sets and pushes values to child
        if(propMul[pos] == 1 and propSum[pos] == 0) return;
        sum[pos] = add(mul(sum[pos], propMul[pos]), mul(r-l+1, propSum[pos]));
        if(l == r) {
            propMul[pos] = 1, propSum[pos] = 0;
            return;
        }
        pushDown(pos<<1, pos), pushDown(pos<<1|1, pos);
        propMul[pos] = 1, propSum[pos] = 0;
    }
    void update(int pos, int l, int r, int L, int R, ll val, int type) {
        propagate(pos, l, r);
        if(r < L or R < l) return;
        if(L <= l and r <= R) {
            if(type == 0)                               // add val in [L, R]
                propSum[pos] = add(propSum[pos], val);
            else if(type == 1) {                        // multiply val in [L, R]
                propSum[pos] = mul(propSum[pos], val);
                propMul[pos] = mul(propMul[pos], val);
            }
            else if(type == 2)                          // set all value = val
                propSum[pos] = val, propMul[pos] = 0;
            propagate(pos, l, r);
            return;
        }
        int mid = (l+r)>>1;
        update(pos<<1, l, mid, L, R, val, type);
        update(pos<<1|1, mid+1, r, L, R, val, type);
        sum[pos] = add(sum[pos<<1], sum[pos<<1|1]);
    }
    ll query(int pos, int l, int r, int L, int R) {
        propagate(pos, l, r);
        if(r < L || R < l) return 0;
        if(L <= l && r <= R) return sum[pos];
        int mid = (l+r)>>1;
        return add(query(pos<<1, l, mid, L, R), query(pos<<1|1, mid+1, r, L, R));
    }
    
    ll query(int l, int r)              { return query(1, 1, len, l, r); }
    void add(int l, int r, ll val)      { update(1, 1, len, l, r, val, 0); }
    void mul(int l, int r, ll val)      { update(1, 1, len, l, r, val, 1); }
    void set(int l, int r, ll val)      { update(1, 1, len, l, r, val, 2); }   
};

struct DynamicHash {
    pair<HashTree, HashTree>H;
    ordered_set<int> indexGen;
    const ll p1 = 31, modInvP1 = 838709685;
    const ll p2 = 51, modInvP2 = 1372550;
    const ll mod1 = 1e9+9, mod2 = 1e7+7;
    ll LIM;
    int len;
    vll Power;
    
    void init(string &str) {
        LIM = str.size() + 100;
        PowerGen(LIM+100);
        
        H.first.init(len+5, mod1);
        H.second.init(len+5, mod2);
        
        ll h1 = 0, h2 = 0;
        len = str.size();
        
        cerr << "GENERATED HASH :\n";
        ll TMP = 0;
        
        for(int i = 1; i < len; ++i) {        // assuming string starts from index 1
            h1 = ((str[i] - 'a' + 1) * Power[i].first)%mod1;
            h2 = ((str[i] - 'a' + 1) * Power[i].second)%mod2;
            
            H.first.add(i, len, h1);
            H.second.add(i, len, h2);
            
            TMP += h1;
            TMP %= mod1;
            cerr << i << " : " << h1 << " (" << TMP << ", " << str[i] << ")\n"; 
    }}
    
    int GetPos(int idx) {
        return indexGen.lessThan(idx)+idx;
    }
    
    void ReplaceChar(int idx, char newChar, char prevChar) {
        idx = GetPos(idx);
        ll newVal1 = ((((newChar-'a'+1)*Power[idx].first)%mod1 - ((prevChar-'a'+1)*Power[idx].second)%mod1)%mod1 + mod1)%mod1;
        ll newVal2 = ((((newChar-'a'+1)*Power[idx].second)%mod2 - ((prevChar-'a'+1)*Power[idx].second)%mod2)%mod2 + mod2)%mod2;
        
        H.first.add(idx, len, newVal1);
        H.second.add(idx, len, newVal2);
    }
    
    void RemoveChar(int idx, char ch) {
        idx = GetPos(idx);
        ll val1 = ((ch-'a'+1)*Power[idx].first)%mod1;
        ll val2 = ((ch-'a'+1)*Power[idx].second)%mod2;
        
        H.first.add(idx, len, (-val1+mod1)%mod1);
        H.second.add(idx, len, (-val2+mod2)%mod2);
        
        H.first.mul(idx, len, modInvP1);
        H.second.mul(idx, len, modInvP2);
        indexGen.insert(idx);
    }
    
    void PowerGen(int n) {
        Power.resize(n+1);
        Power[0] = {1, 1};
        for(int i = 1; i < n; ++i) {
            Power[i].first = (Power[i-1].first * p1)%mod1;
            Power[i].second = (Power[i-1].second * p2)%mod2;
    }}
    
    ll SubStrHash(int l, int strLen, bool first = 1) {
        l = GetPos(l);
        int r = GetPos(l+strLen-1);
        ll hash = 0;
        
        if(first) {
            hash = H.first.query(1, 1, len, l, r);
            if(l-1 > 0) hash = (hash - (H.first.query(1, 1, len, 1, l-1)%mod1) + mod1)%mod1;
        }
        else {
            hash = H.second.query(1, 1, len, l, r);
            if(l-1 > 0) hash = (hash - (H.second.query(1, 1, len, 1, l-1)%mod2) + mod2)%mod2;
        }
        return hash;
}};
    
HashTree HT;    
ll arr[3*MAX];

int main() {
    ll n, q, x, y, v, typ;
    cin >> n >> q;
    
    //HT.init(n, 1e9+7);
    
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
        //cerr << "DONE\n";
    }
    
    HT.init(n, 1e9+7, arr);
    
    /*for(int i = 1; i <= n; ++i)
        cerr << HT.query(i, i) << " ";
    cerr << endl;
    cerr << HT.query(1, n) << endl;*/
    
    while(q--) {
        cin >> typ;
        //cerr << "TYP " << typ << endl;
        if(typ == 1) {
            cin >> x >> y >> v;
            //cerr << "ADD " << x << " " << y << " " << v << endl;
            HT.add(x, y, v);
        }
        else if(typ == 2) {
            cin >> x >> y >> v;
            //cerr << "MUL " << x << " " << y << " " << v << endl;
            HT.mul(x, y, v);
        }
        else if(typ == 3) {
            cin >> x >> y >> v;
            //cerr << "SET " << x << " " << y << " " << v << endl;
            HT.set(x, y, v);
        }
        else {
            cin >> x >> y;
            //cerr << "Query " << x << " " << y << endl;
            cout << HT.query(x, y) << "\n";
        }
    }
    return 0;
}
