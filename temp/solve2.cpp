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

const ll LIM = 20;
const ll p1 = 31;
const ll p2 = 51;
const ll mod1 = 1e9+9, mod2 = 1e7+7;

string str;

ll gcdExtended(ll a, ll b, ll *x, ll *y) {          // C function for extended Euclidean Algorithm
    if (a == 0) {                                   // Base Case
        *x = 0, *y = 1;
        return b;
    }
    ll x1, y1;                                     // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
 
ll modInverse(ll a, ll mod) {
    ll x, y;
    ll g = gcdExtended(a, mod, &x, &y);
    if(g != 1) return -1;                   // ModInverse doesnt exist
    ll res = (x%mod + mod) % mod;           // m is added to handle negative x
    return res;
}

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
}
    
vector<tuple<char, int, int> >query;
vector<pair<int, char> >insertChar;
char ss[MAX];
int revPos[MAX];

BIT b1, b2, lenModify;
ordered_set<int>StringPos;

int main() {
    int l, r, q;
    char typ, ch;
    sf(" %s", ss);
    int len = strlen(ss);
    
    
    for(int i = 0; i < len; ++i)
        insertChar.pb({i+1, ss[i]});
    
    cerr << "STRING INPUT DONE\n";
    
    sf("%d", &q);
    for(int i = 0; i < q; ++i) {
        sf(" %c", &typ);
        cerr << " AT " << i << " " << typ << endl;
        
        if(typ == 'Q') {
            sf(" %d %d", &l, &r);
            query.pb(make_tuple(typ, l, r));
        }
        else {
            sf(" %d %c", &l, &ch);
            query.pb(make_tuple(typ, l, ch));
        }
        if(typ == 'I')
            ++len;
    }
    
    cerr << "QUERY INPUT DONE\n";
    
    StringPos.clear();
    for(int i = 1; i <= len; ++i)
        StringPos.insert(i);
    
    // convert all index to 1 base-------------------------
    
    ++len;
    str.resize(len);
    fill(All(str), '*');
    lenModify.init(len+2, mod1);
    
    for(int i = query.size(); i >= 0; --i) {
        typ = get<0>(query[i]);
        if(typ == 'Q') continue;
        int idx = get<1>(query[i]);
        ch = get<2>(query[i]);
        
        if(typ == 'I') {
            auto it2 = StringPos.at(idx-1);
            if(str[*it2] != '*') {
                get<2>(query[revPos[idx]]) = ch;
                continue;
            }
            str[*it2] = ch;
            cerr << "idx " << idx << " " << *it2 << " = " << ch << endl;
            StringPos.erase(it2);
            lenModify.update(*it2, 1);
        }
        else {
            idx = lenModify.read(idx)+idx;
            if(str[idx] == '*') {
                str[idx] = ch;
                revPos[idx] = i;
            }
            else {
                get<2>(query[revPos[idx]]) = ch;
                revPos[idx] = i;
            }
        }
    }
    
    for(int i = SIZE(insertChar)-1; i >= 0; --i) {
        int idx = insertChar[i].first;
        ch = insertChar[i].second;
        auto it = StringPos.at(idx-1);
        if(str[*it] == '*')
            str[*it] = ch;
        else
            get<2>(query[revPos[idx]]) = ch;
    }
    
    cerr << str << endl;
    
    PowerGen(LIM+10);
    b1.init(len+2, mod1);
    b2.init(len+2, mod2);
    lenModify.reset();
    HashGen(str, len, b1, b2);
    
    cerr << "HASH GEN DONE\n";
    
    for(int i = 1; i < len; ++i)
        cerr << i << " : " << b1.read(i) << endl;
    
    for(int i = SIZE(query)-1; i >= 0; --i) {
        typ = get<0>(query[i]);
        if(typ == 'Q') {
            int p1 = get<1>(query[i]), p2 = get<2>(query[i]);
            p1 = ActualPos(p1, lenModify);
            p2 = ActualPos(p2, lenModify);
            
            cerr << "TOTLEN " << len-lenModify.size() << endl;
            
            int hi = len-lenModify.size()-max(p1, p2), lo = 1, mid, ans = 0;
            
            cerr << "AT " << i << " Query " << p1 << " " << p2 << " LIM " << hi << endl;
            
            while(lo <= hi) {
                mid = (lo+hi)>>1;
                
                int pp1 = ActualPos(p1+mid-1, lenModify);
                int pp2 = ActualPos(p2+mid-1, lenModify);
                
                cerr << mid << " " << p1 << " - " << pp1 << " : " << p2 << " - " << pp2 << endl;
                
                if((GetSegHash(p1, pp1, b1, mod1) != GetSegHash(p2, pp2, b1, mod1)) || (GetSegHash(p1, pp1, b2, mod2, 0) != GetSegHash(p2, pp2, b2, mod2, 0)))
                    hi = mid-1;
                else {
                    cerr << "MATCH" << endl;
                    lo = mid+1;
                    ans = max(ans, mid);
                }
                
            }
            pf("%d\n", ans);
        }
        else if(typ == 'R') {
            int idx = get<1>(query[i]);
            ch = get<2>(query[i]);
            cerr << "AT " << i << " Replace " << idx << " " << ch << endl;
            HashReplace(idx, ch, b1, b2);
        }
        else {
            int idx = get<1>(query[i]);
            ch = get<2>(query[i]);
            cerr << "AT " << i << " Delete " << idx << " " << ch << endl;
            EraseChar(idx+1, ch, b1, b2, lenModify);
            for(int i = 1; i < len; ++i)
                cerr << i << " : " << b1.read(i) << endl;
        }
        cerr << str << endl;
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

madamimadam
7
Q 1 7
Q 4 8
Q 10 11
R 3 a
Q 1 7
I 10 a
Q 2 11

*/
