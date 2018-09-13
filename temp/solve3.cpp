#include <bits/stdc++.h>
using namespace std;
#define MAX                 300000
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
    ll mod;
    
    void Resize(int n, ll mod) {
        sum.resize(5*n);
        propSum.resize(5*n);
        propMul.resize(5*n);
        mod = mod;
    }
    
    ll add(ll a, ll b) {
        a %= mod, b %= mod;
        a = (a + mod)%mod, b = (b + mod)%mod;
        return (a+b)%mod;
    }
    
    ll mul(ll a, ll b) {
        a = ((a%mod) + mod)%mod;
        b = ((b%mod) + mod)%mod;
        return (a*b)%mod;
    }
        
    void init(int pos, int l, int r, ll val[]) {
        sum[pos] = propSum[pos] = 0, propMul[pos] = 1;
        if(l == r) {
            sum[pos] = val[l]%mod;
            return;
        }
        int mid = (l+r)>>1;
        init(pos<<1, l, mid, val);
        init(pos<<1|1, mid+1, r, val);
        sum[pos] = add(sum[pos<<1], sum[pos<<1|1]);
    }

    void propagate(int pos, int l, int r) {
        if(propMul[pos] == 0) propMul[pos] = 1;
        if((propMul[pos] == 1 and propSum[pos] == 0) or l == r) return;
        int mid = (l+r)>>1;
        
        sum[pos<<1] = add(mul(sum[pos<<1], propMul[pos]), mul(propSum[pos], (mid-l+1)));
        sum[pos<<1|1] = add(mul(sum[pos<<1|1], propMul[pos]), mul(propSum[pos], (r-mid)));
        
        propSum[pos<<1] = add(propSum[pos<<1], propSum[pos]);
        propSum[pos<<1|1] = add(propSum[pos<<1|1], propSum[pos]);
        propSum[pos] = 0;
        
        propMul[pos<<1] = mul(propMul[pos<<1], propMul[pos]);
        propMul[pos<<1|1] = mul(propMul[pos<<1|1], propMul[pos]);
        propMul[pos] = 1;
    }

    void add(int pos, int l, int r, int L, int R, ll val) {
        if(r < L || R < l) return;
        propagate(pos, l, r);
        if(L <= l && r <= R) {
            sum[pos] = add(sum[pos], val*(r-l+1));
            propSum[pos] = add(propSum[pos], val);
            return;
        }

        int mid = (l+r)>>1;
        add(pos<<1, l, mid, L, R, val);
        add(pos<<1|1, mid+1, r, L, R, val);
        sum[pos] = add(sum[pos<<1], sum[pos<<1|1]);
    }
    
    void multiply(int pos, int l, int r, int L, int R, ll val) {
        if(r < L || R < l) return;
        propagate(pos, l, r);
        if(L <= l && r <= R) {
            sum[pos] = mul(sum[pos], val);
            propMul[pos] = mul(propMul[pos], val);
            return;
        }
        
        int mid = (l+r)>>1;
        multiply(pos<<1, l, mid, L, R, val);
        multiply(pos<<1|1, mid+1, r, L, R, val);
        sum[pos] = add(sum[pos<<1], sum[pos<<1|1]);
    }

    ll query(int pos, int l, int r, int L, int R) {
        if(r < L || R < l) return 0;
        propagate(pos, l, r);
        if(L <= l && r <= R)
            return sum[pos];
        int mid = (l+r)>>1;
        return add(query(pos<<1, l, mid, L, R), query(pos<<1|1, mid+1, r, L, R));
}};

struct DynamicHash {
    pair<HashTree, HashTree>H;
    tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexGen;
    const ll p1 = 31, modInvP1 = 838709685;
    const ll p2 = 51, modInvP2 = 1372550;
    const ll mod1 = 1e9+9, mod2 = 1e7+7;
    ll LIM;
    int len;
    vll Power;
    
    void init(string &str) {
        LIM = str.size() + 100;
        PowerGen(LIM+100);
        
        H.first.Resize(len+5, mod1);
        H.second.Resize(len+5, mod2);
        
        ll h1 = 0, h2 = 0;
        len = str.size();
        
        for(int i = 1; i < len; ++i) {        // assuming string starts from index 1
            h1 = ((str[i] - 'a' + 1) * Power[i].first)%mod1;
            h2 = ((str[i] - 'a' + 1) * Power[i].second)%mod2;
            
            H.first.add(1, 1, len, i, len, h1);
            H.second.add(1, 1, len, i, len, h2);
    }}
    
    int GetPos(int idx) {
        return indexGen.order_of_key(idx)+idx;
    }
    
    void ReplaceChar(int idx, char newChar, char prevChar) {
        idx = GetPos(idx);
        ll newVal1 = ((((newChar-'a'+1)*Power[idx].first)%mod1 - ((prevChar-'a'+1)*Power[idx].second)%mod1)%mod1 + mod1)%mod1;
        ll newVal2 = ((((newChar-'a'+1)*Power[idx].second)%mod2 - ((prevChar-'a'+1)*Power[idx].second)%mod2)%mod2 + mod2)%mod2;
        
        H.first.add(1, 1, len, idx, len, newVal1);
        H.second.add(1, 1, len, idx, len, newVal2);
    }
    
    void RemoveChar(int idx, char ch) {
        idx = GetPos(idx);
        ll val1 = ((ch-'a'+1)*Power[idx].first)%mod1;
        ll val2 = ((ch-'a'+1)*Power[idx].second)%mod2;
        
        H.first.add(1, 1, len, idx, len, -val1);
        H.second.add(1, 1, len, idx, len, -val2);
        
        H.first.multiply(1, 1, len, idx, len, modInvP1);
        H.second.multiply(1, 1, len, idx, len, modInvP2);
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
    
    

int main() {
    int n = 7;
    HashTree ht;
    ht.Resize(4, 1000);
    char ch;
    int x, y;
    
    while(1) {
        cin >> ch;

        if(ch == '+') {
            cin >> x >> y;
            ht.add(1, 1, n, x, x, y);
        }
        else {
            cin >> x >> y;
            ht.multiply(1, 1, n, x, x, y);
        }
        cerr << "TREE" << endl;
        for(int i = 1; i <= n; ++i)
            cout << ht.query(1, 1, n, i, i) << " ";
        cout << endl;
    }
    
    return 0;
}
