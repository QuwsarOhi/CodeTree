#include <bits/stdc++.h>
using namespace std;
#define MAX                 300000
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
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

/*const ll LIM = 20;
const ll p1 = 31;
const ll p2 = 51;
const ll mod1 = 1e9+9, mod2 = 1e7+7;

string str;

struct BIT {
    ll tree[MAX], mod;
    int MaxVal;
    void init(int sz, ll modVal) {
        memset(tree, 0, sizeof tree);
        MaxVal = sz;
        mod = modVal;
    }
    void reset() {
        memset(tree, 0, sizeof tree);
    }
    void update(int idx, ll val) {
        for( ;idx <= MaxVal; idx += (idx & -idx))
            tree[idx] = ((tree[idx] + val)%mod + mod)%mod;
    }
    void div(int idx, ll val) {
        for( ; idx <= MaxVal; idx += (idx & -idx))
            tree[idx] = (tree[idx] * modInverse(val, mod))%mod;
    }
    void update(int l, int r, ll val) {
        if(l > r) swap(l, r);
        update(l, val);
        update(r+1, -val);
    }
    ll read(int idx) {
        ll sum = 0;
        for( ;idx > 0; idx -= (idx & -idx))
            sum = ((sum + tree[idx])%mod + mod)%mod;
        return sum;
    }
    ll read(int l, int r) {
        ll ret = ((read(r) - read(l-1))%mod + mod)%mod;
        return ret;
    }
    ll readSingle(int idx) {             // Point read in log(n)
        ll sum = tree[idx];
        if(idx > 0) {
            int z = idx - (idx & -idx);
            --idx;
            while(idx != z) {
                sum = ((sum - tree[idx])%mod + mod)%mod;
                idx -= (idx & -idx);
        }}   
        return sum;
    }
    ll size() {
        return read(MaxVal);
}};


vll Power;
void PowerGen(int n) {
    Power.resize(n+1);
    Power[0] = {1, 1};
    for(int i = 1; i < n; ++i) {
        Power[i].first = (Power[i-1].first * p1)%mod1;
        Power[i].second = (Power[i-1].second * p2)%mod2;
}}


void HashGen(string &str, int len, BIT &b1, BIT &b2) {
    ll h1 = 0, h2 = 0;
    ll tmp = 0;
    for(int i = 1; i < len; ++i) {
        h1 = ((str[i] - 'a' + 1) * Power[i].first)%mod1;
        h2 = ((str[i] - 'a' + 1) * Power[i].second)%mod2;
        
        tmp += h1;
        tmp %= mod1;
        cerr << i << " : " << tmp << " (" << h1 << " " << str[i] << ")" << endl;
        
        b1.update(i, h1);
        b2.update(i, h2);
}}

void HashReplace(int idx, char c, BIT &b1, BIT &b2) {
    ll h1 = ((((c - 'a' + 1) * Power[idx].first)%mod1 - b1.readSingle(idx))%mod1 + mod1)%mod1;
    ll h2 = ((((c - 'a' + 1) * Power[idx].second)%mod2 - b2.readSingle(idx))%mod2 + mod2)%mod2;
    
    b1.update(idx, h1);
    b2.update(idx, h2);
    str[idx] = c;
}

void EraseChar(int idx, char c, BIT &b1, BIT &b2, BIT &lenModify) {
    lenModify.update(idx, 1);
    b1.update(idx, -((c-'a'+1)*Power[idx].first)%mod1);
    b2.update(idx, -((c-'a'+1)*Power[idx].second)%mod2);
    cerr << "BEFORE " << b1.readSingle(idx+1) << " MUL WITH " << modInverse(p1, mod1) << endl;
    b1.div(idx+1, p1);
    cerr << "AFTER " << b1.readSingle(idx+1) << endl;
    b2.div(idx+1, p2);
    str[idx] = '*';
}

int ActualPos(int pos, BIT &lenModify) {
    return pos+lenModify.read(pos);
}

ll GetSegHash(int l, int r, BIT &b, ll mod, bool first = 1) {
    ll h = b.read(r);
    //cerr << h << endl;
    
    h = ((h - (l-1 > 0 ? b.read(l-1):0))%mod + mod)%mod;
    if(first)
        h = (h * Power[LIM-l].first)%mod;
    else
        h = (h * Power[LIM-l].second)%mod;
    cerr << l << " - " << r << " : " << h << " :: " << LIM-l << endl;
    return h;
}*/

string str;

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
            //cerr << "AT " << l << " " << r << " " << pos << " : ";
            if(type == 0)                               // add val in [L, R]
                propSum[pos] = add(propSum[pos], val);
            else if(type == 1) {                        // multiply val in [L, R]
                propSum[pos] = mul(propSum[pos], val);
                propMul[pos] = mul(propMul[pos], val);
            }
            else if(type == 2)                          // set all value = val
                propSum[pos] = val, propMul[pos] = 0;
            propagate(pos, l, r);
            //cerr << sum[pos] << endl;
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
        
        ll h1 = 0, h2 = 0;
        len = SIZE(str);
        
        indexGen.clear();
        H.first.init(len+5, mod1);
        H.second.init(len+5, mod2);
        
        //cerr << "GENERATED HASH :\n";
        //ll TMP = 0;
        
        for(int i = 1; i < len; ++i) {        // assuming string starts from index 1
            h1 = ((str[i] - 'a' + 1) * Power[i].first)%mod1;
            h2 = ((str[i] - 'a' + 1) * Power[i].second)%mod2;
            
            H.first.add(i, i, h1);
            H.second.add(i, i, h2);
            
            indexGen.insert(i);
            //TMP += h1;
            //TMP %= mod1;
            //cerr << i << " : " << h1 << " (" << TMP << ", " << str[i] << ") " << endl;; 
    }}
    
    int GetPos(int idx) {
        //return indexGen.lessThan(idx)+idx;
        return *indexGen.at(idx-1);
    }
    
    void PlaceChar(int idx, char newChar) {        // MODIFIED
        idx = GetPos(idx);
        //ll newVal1 = ((((newChar-'a'+1)*Power[idx].first)%mod1 - ((prevChar-'a'+1)*Power[idx].second)%mod1)%mod1 + mod1)%mod1;
        //ll newVal2 = ((((newChar-'a'+1)*Power[idx].second)%mod2 - ((prevChar-'a'+1)*Power[idx].second)%mod2)%mod2 + mod2)%mod2;
        
        ll newVal1 = ((newChar-'a'+1)*Power[idx].first)%mod1;
        ll newVal2 = ((newChar-'a'+1)*Power[idx].second)%mod2;
        
        //H.first.add(idx, len, newVal1);
        //H.second.add(idx, len, newVal2);
        
        H.first.set(idx, idx, newVal1);
        H.second.set(idx, idx, newVal2);
    }
    
    void RemoveChar(int idx) {
        idx = GetPos(idx);
        //ll val1 = ((ch-'a'+1)*Power[idx].first)%mod1;
        //ll val2 = ((ch-'a'+1)*Power[idx].second)%mod2;
        
        //H.first.add(idx, len, (-val1+mod1)%mod1);
        //H.second.add(idx, len, (-val2+mod2)%mod2);
        H.first.set(idx, idx, 0);
        H.second.set(idx, idx, 0);
        
        H.first.mul(idx+1, len, modInvP1);
        H.second.mul(idx+1, len, modInvP2);
        indexGen.erase(indexGen.at(idx-1));
    }
    
    void PowerGen(int n) {
        Power.resize(n+1);
        Power[0] = {1, 1};
        for(int i = 1; i < n; ++i) {
            Power[i].first = (Power[i-1].first * p1)%mod1;
            Power[i].second = (Power[i-1].second * p2)%mod2;
    }}
    
    ll SubStrHash(int l, int strLen, bool first = 1) {
        int r = GetPos(l+strLen-1);
        l = GetPos(l);
        
        ll hash = first ? H.first.query(l, r):H.second.query(l, r);
        
        cerr << "L " << l << "(" << str[l] << ") " << " R " << r << " : " << hash << " :: ";
        
        int pw = l-indexGen.lessThan(l);
        cerr << " PW " << pw;
        hash = (hash * (first?Power[LIM-l+pw].first:Power[LIM-l+pw].second))%(first?mod1:mod2);
        cerr << hash << " mul pow " << LIM-l << endl;
        return hash;
    }
    ll GetHash(int l, int r) {
        return H.first.query(l, r);
    }
};



vector<tuple<char, int, int> >query;
vector<pair<int, char> >insertChar;
char ss[MAX];
int revPos[MAX];
vi ANS;
ordered_set<int>StringPos, lenModify;

DynamicHash DH;

void GETHASH() {
    for(int i = 1; i < SIZE(str); ++i) {
        cerr << i << " : " << DH.GetHash(i, i) << ", " << DH.GetHash(1, i) << endl;
    }
}

int main() {
    int t;
    sf("%d", &t);
    
    while(t--) {
        int l, r, q;
        char typ, ch;
        sf(" %s", ss);
        int len = strlen(ss);
        int ssLen = len;
        //cerr << "STRING INPUT DONE\n";
    
        sf("%d", &q);
        for(int i = 0; i < q; ++i) {
            sf(" %c", &typ);
            if(typ == 'Q') {
                sf(" %d %d", &l, &r);
                query.pb(make_tuple(typ, l, r));
            }
            else {
                sf(" %d %c", &l, &ch);
                query.pb(make_tuple(typ, l, ch));
            }
            len += (typ == 'I');
        }
    
        ++len;
        str.resize(len);
        fill(All(str), '*');
        for(int i = 1; i <= len; ++i) StringPos.insert(i);          // Contains available pos
    
        for(int i = SIZE(query)-1; i >= 0; --i) {
            typ = get<0>(query[i]);
            l = get<1>(query[i]);
            ch = get<2>(query[i]);
        
            if(typ == 'Q') continue;
        
            if(typ == 'I') {
                auto it = StringPos.at(l);                          // insertion at l+1'th pos
                if(str[*it] == '*')                                 // if slot is empty, put it
                    str[*it] = ch;
                else                                                // if slot was used earlier
                    get<2>(query[revPos[*it]]) = ch;                  // put the current val in previous char
                StringPos.erase(it);
            }
            else {
                auto it = StringPos.at(l-1);                        // replacement at l'th pos
                if(str[*it] == '*')
                    str[*it] = ch;
                else
                    get<2>(query[revPos[*it]]) = ch;
                revPos[*it] = i;
        }}
    
        for(int i = ssLen-1; i >= 0; --i) {
            auto it = StringPos.at(i);                              // insert charechters at i'th position
            if(str[*it] == '*')
                str[*it] = ss[i];
            else
                get<2>(query[revPos[*it]]) = ss[i];
            StringPos.erase(it);
        }
        
        //cerr << str << endl;
    
        //cerr << "NEW Queries\n";
        for(int i = 0; i < SIZE(query); ++i) {
            typ = get<0>(query[i]);
            l = get<1>(query[i]);
            ch = get<2>(query[i]);
            //cerr << typ << " " << l << " " << ch << endl;
        }
    
        // ALL OK UNTIL NOW <3
        //str.clear();
        //str = "*madamimadam";
    
        DH.init(str);
        //cerr << "HASH GEN DONE\n";
        //GETHASH();
        int erased = 0;
        for(int i = SIZE(query)-1; i >= 0; --i) {
            typ = get<0>(query[i]);
        
        
            if(typ == 'Q') {
                int l = get<1>(query[i]), r = get<2>(query[i]);
                int lo = 1, hi = len-max(l, r)-erased, mid, ans = 0;
            
                cerr << "QUERY " << l << " " << r << " len " << hi << " erased " << erased << " :: " << str <<  endl;
            
                while(lo <= hi) {
                    mid = (lo+hi)>>1;
                
                    cerr << "BS LEN " << mid << " (" << lo << ", " << hi << ")" << endl; 
                
                    if(DH.SubStrHash(l, mid, 0) == DH.SubStrHash(r, mid, 0) and DH.SubStrHash(l, mid, 1) == DH.SubStrHash(r, mid, 1)) {
                        ans = max(ans, mid);
                        lo = mid+1;
                        cerr << "MATCHED!\n";
                    }
                    else
                        hi = mid-1;
                }
                pf("ANSWER :::::::: %d\n", ans);
                ANS.pb(ans);
            }
            else if(typ == 'I') {
                erased++;
                int idx = get<1>(query[i]);
                ch = get<2>(query[i]);
                //cerr << "ERASE " << idx << " " << str[idx] << endl;
                DH.RemoveChar(idx+1);
                str[idx+1] = '*';
                //cerr << "New Str " << str << endl;
                //GETHASH();
            }
            else {
                int idx = get<1>(query[i]);
                ch = get<2>(query[i]);
                cerr << "Replace " << idx << " " << str[idx] << " to " << ch << endl;
                DH.PlaceChar(idx, ch);
                str[idx] = ch;
                //cerr << "New Str " << str << endl;
                //GETHASH();
            }
        }
        
        for(auto it = ANS.rbegin(); it != ANS.rend(); ++it)
            pf("%d\n", *it);
        
        ANS.clear();
        query.clear();
        insertChar.clear();
        StringPos.clear();
        lenModify.clear();
    }
    return 0;
}
    
/*
abcdefg
5
I 3 x
I 1 p
I 4 q
I 3 y
I 6 z

*/

/*

4
madamimadam
7
Q 1 7
Q 4 8
Q 10 11
R 3 a
Q 1 7
I 10 a
Q 2 11

abcdef
19
Q 1 1
I 3 a
R 5 b
Q 1 4
I 5 c
I 6 a
I 7 b
Q 1 4
R 9 c
Q 1 4
Q 4 7
R 10 a
Q 1 10
Q 1 4
Q 1 1
R 10 x
Q 1 4
R 10 a
Q 1 4 

abcdef
9
Q 1 1
I 3 a
R 2 d
Q 1 4
R 6 c
R 7 a
Q 2 5
Q 1 4
Q 1 7

a
16
Q 1 1
I 1 a
I 1 a
I 1 a
I 1 a
I 1 a
Q 1 2
Q 4 2
Q 3 4
R 2 x
Q 1 3
R 4 x
Q 1 3
I 2 a
Q 2 5
Q 1 4

*/

/*

abcdef
7
R 5 r
R 3 x
I 3 y
R 3 p
R 4 z
I 1 q
R 8 k


aqbpzdek
*/ 
