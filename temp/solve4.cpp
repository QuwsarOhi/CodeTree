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
vector<tuple<char, int, int> >query;
vector<pair<int, char> >insertChar;
char ss[MAX];
int revPos[MAX];

ordered_set<int>StringPos, lenModify;

int main() {
    int l, r, q;
    char typ, ch;
    sf(" %s", ss);
    int len = strlen(ss);
    int ssLen = len;
    cerr << "STRING INPUT DONE\n";
    
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
        
    cerr << str << endl;
    
    cerr << "NEW Queries\n";
    for(int i = 0; i < SIZE(query); ++i) {
        typ = get<0>(query[i]);
        l = get<1>(query[i]);
        ch = get<2>(query[i]);
        cerr << typ << " " << l << " " << ch << endl;
    }
    
    // ALL OK UNTIL NOW <3
    
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
