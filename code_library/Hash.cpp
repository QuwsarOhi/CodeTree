// Hashing
// p = 31, 51
// MOD = 1e9+9, 1e7+7
const ll p = 31;
const ll mod1 = 1e9+9, mod2 = 1e7+7;

// Returns Single Hash Val
ll hash(char *s,  int len, ll mod = 1e9+9) {
    int p = 31;
    ll hashVal = 0;
    ll pPow = 1;
    for(int i = 0; i < len; ++i) {
        hashVal = (hashVal + (s[i] - 'a' + 1) * pPow)%mod;
        pPow = (pPow *p)%mod;
    }
    return hashVal;
}
vl Hash(char *s, int len) {
    ll hashVal = 0;
    vector<ll>v;
    for(int i = 0; i < len; ++i) {
        hashVal = (hashVal + (s[i] - 'a' + 1)* Power[i])%mod;
        v.push_back(hashVal);
    }
    return v;
}
bool MATCH(pll a, pll b) {
    while(a.fi <= a.se) {
        if(s1[a.fi] != s2[b.fi])
            return 0;
        a.fi++, b.fi++;
    }
    return 1;
}
void PowerGen(int n) {
    Power.resize(n+1);
    Power[0] = 1;
    for(int i = 1; i < n; ++i)
        Power[i] = (Power[i-1] * p)%mod;
}
ll SubHash(vl &Hash, ll l, ll r, ll LIM) {
    ll H;
    H = (Hash[r] - (l-1 >= 0 ? Hash[l-1]:0) + mod)%mod;
    H = (H * Power[LIM-l])%mod;
    return H;
}

// --------------- DOUBLE HASH GENERATORS ---------------
// Generates Hash of entire string without PowerGen func
vector<pair<ll, ll> > doubleHash(char *s, int len, ll mod1 = 1e9+7, ll mod2 = 1e9+9) {
    ll hashVal1 = 0, hashVal2 = 0, pPow1 = 1, pPow2 = 1;
    vector<pair<ll, ll> >v;
    for(int i = 0; i < len; ++i) {
        hashVal1 = (hashVal1 + (s[i] - 'a' + 1)* pPow1)%mod1;
        hashVal2 = (hashVal2 + (s[i] - 'a' + 1)* pPow2)%mod2;
        pPow1 = (pPow1 * p)%mod1;
        pPow2 = (pPow2 * p)%mod2;
        v.push_back({hashVal1, hashVal2});
    }
    return v;
}
void PowerGen(int n) {
    Power.resize(n+1);
    Power[0] = {1, 1};
    for(int i = 1; i < n; ++i) {
        Power[i].first = (Power[i-1].first * p)%mod1;
        Power[i].second = (Power[i-1].second * p)%mod2;
}}
vll doubleHash(char *s, int len) {      // Returns Double Hash vector for a full string
    ll hashVal1 = 0, hashVal2 = 0;
    vector<pll>v;
    for(int i = 0; i < len; ++i) {
        hashVal1 = (hashVal1 + (s[i] - 'a' + 1)* Power[i].fi)%mod1;
        hashVal2 = (hashVal2 + (s[i] - 'a' + 1)* Power[i].se)%mod2;
        v.push_back({hashVal1, hashVal2});
    }
    return v;
}
pll SubHash(vll &Hash, ll l, ll r, ll LIM) {    // Produce SubString Hash
    pll H;
    H.fi = (Hash[r].fi - (l-1 >= 0 ? Hash[l-1].fi:0) + mod1)%mod1;
    H.se = (Hash[r].se - (l-1 >= 0 ? Hash[l-1].se:0) + mod2)%mod2;
    H.fi = (H.fi * Power[LIM-l].fi)%mod1;
    H.se = (H.se * Power[LIM-l].se)%mod2;
    return H;
}
// Returns True if the Hashval of length len exists in subrange [l, r] of Hash vector
bool MatchSubStr(int l, int r, vector<pll>&Hash, pll HashVal, int len) {
    for(int Start = l, End = l+len-1; End <= r; ++End, ++Start) {
        pll pattHash, strHash;
        pattHash.first = (HashVal.first*Power[Start].first)%mod1;
        pattHash.second = (HashVal.second*Power[Start].second)%mod2;
        strHash.first = (Hash[End].first - (Start == 0 ? 0:Hash[Start-1].first) + mod1)%mod1;
        strHash.second = (Hash[End].second - (Start == 0 ? 0:Hash[Start-1].second) + mod2)%mod2;
        if(strHash == pattHash) return 1;
    }
    return 0;
}

// Dynamic Hash supports replacing and deletion of charachter

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
        PowerGen(LIM+100);+
        ll h1 = 0, h2 = 0;
        len = SIZE(str);
        indexGen.clear();
        H.first.init(len+5, mod1);
        H.second.init(len+5, mod2);
        indexGen.insert(0);
 
        for(int i = 1; i < len; ++i) {                  // assuming string starts from index 1
            h1 = ((str[i] - 'a' + 1) * Power[i].first)%mod1;
            h2 = ((str[i] - 'a' + 1) * Power[i].second)%mod2;
            
            H.first.add(i, i, h1);
            H.second.add(i, i, h2);
            indexGen.insert(i);
    }}
    int GetPos(int idx) {
        return *indexGen.at(idx);
    }
    void PlaceChar(int idx, char newChar) {             // Place/Replace charachter at idx
        int StrIdx = GetPos(idx);
        ll newVal1 = ((newChar-'a'+1)*Power[idx].first)%mod1;
        ll newVal2 = ((newChar-'a'+1)*Power[idx].second)%mod2;
        H.first.set(StrIdx, StrIdx, newVal1);
        H.second.set(StrIdx, StrIdx, newVal2);
        str[StrIdx] = newChar;
    }
    void RemoveChar(int pos) {                          // Remove charachter at pos
        int idx = GetPos(pos);
        H.first.set(idx, idx, 0);
        H.second.set(idx, idx, 0);
        H.first.mul(idx+1, len, modInvP1);
        H.second.mul(idx+1, len, modInvP2);
        indexGen.erase(indexGen.at(pos));
    }
    void PowerGen(int n) {
        Power.resize(n+1);
        Power[0] = {1, 1};
        for(int i = 1; i < n; ++i) {
            Power[i].first = (Power[i-1].first * p1)%mod1;
            Power[i].second = (Power[i-1].second * p2)%mod2;
    }}
    ll SubStrHash(int l, int strLen, bool first = 1) {
        int RR = GetPos(l+strLen-1);
        int LL = GetPos(l);
        ll hash = first ? H.first.query(LL, RR):H.second.query(LL, RR);
        hash = (hash * (first?Power[LIM-l].first:Power[LIM-l].second))%(first?mod1:mod2);
        return hash;
    }
    ll GetHash(int l, int r) {
        return H.first.query(GetPos(l), GetPos(r));
}};


// ---------------------------------------- 2D Hash ---------------------------------------- 

ll Minus(ll x, ll y, ll m) {
    return ((x-y)%m+m)%m;
}

const int lineOffset = 1010;                                    // use the 2DLim to distinguish between rows
vector<vll> Gen2DHash(int r, int c, char str[][1010]) {         // row, column, string
    vector<vll> hash(r);
    for(int i = 0, offset = 0; i < r; ++i, offset += lineOffset) {          // Powers of every row r starts from r*offset
        pll h = {0, 0};
        for(int j = 0; j < c; ++j) {
            h.first = ((str[i][j] - 'a' + 1)*Power[j+offset].first)%mod1;
            h.second = ((str[i][j] - 'a' + 1)*Power[j+offset].second)%mod2;
            hash[i].push_back(h);
    }}

    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            if(i > 0) {
                hash[i][j].first = (hash[i][j].first + hash[i-1][j].first)%mod1;
                hash[i][j].second = (hash[i][j].second + hash[i-1][j].second)%mod2;
            }
            if(j > 0) {
                hash[i][j].first = (hash[i][j].first + hash[i][j-1].first)%mod1;
                hash[i][j].second = (hash[i][j].second + hash[i][j-1].second)%mod2;
            }
            if(i > 0 and j > 0) {
                hash[i][j].first = (hash[i][j].first - hash[i-1][j-1].first + mod1)%mod1;
                hash[i][j].second = (hash[i][j].second - hash[i-1][j-1].second + mod2)%mod2;
            }
            hash[i][j].first = (hash[i][j].first)%mod1;
            hash[i][j].second = (hash[i][j].second)%mod2;
    }}
    return hash;
}

const ll LIM = 1025000;
pll SubHash2D(vector<vll> &H, int x, int y, int r, int c) {       // generates hash which's upper left point is x, y
    int xx = x+r-1, yy = y+c-1;
    pll ret = H[xx][yy];
    if(x > 0) {
        ret.first = (ret.first - H[x-1][yy].first + mod1)%mod1;
        ret.second = (ret.second - H[x-1][yy].second + mod2)%mod2;
    }
    if(y > 0) {
        ret.first = (ret.first - H[xx][y-1].first + mod1)%mod1;
        ret.second = (ret.second - H[xx][y-1].second + mod2)%mod2;
    }
    if(x > 0 and y > 0)
        ret.first += H[x-1][y-1].first, ret.second += H[x-1][y-1].second;
    ret.first = ret.first%mod1;
    ret.second = ret.second%mod2;
    ret.first = (ret.first*Power[LIM-(x*lineOffset+y)].first)%mod1;
    ret.second = (ret.second*Power[LIM-(x*lineOffset+y)].second)%mod2;
    return ret;
}

// ------------ HASH ON TREE -------------

/*
up[u]   : hash from u to root node
down[u] : hash from root node to u (according to level) 
**hash power starts from 1
*/

void dfs(int u, int par = 0) {
    int h = str[u-1]-'a'+1;

    lvl[u] = lvl[par]+1;
    up[u] = (h*p1 + (up[par] * p1)%mod1)%mod1;
    down[u] = (down[par] + (h*Power[lvl[u]])%mod1)%mod1;
    
    for(auto v : G[u]) if(v != par) dfs(v, u);
}

// NOT TESTED
// returns path hash of a tree from u to v [power starts with 1]
ll getPathHash(int u, int v, int lca, int k) {
    if(k == 1)
        return str[u-1];
    if(v == lca) {
        v = getKthNode(u, v, k, lca);
        return (up[u] - (up[par[v][0]] * Power[lvl[u]-lvl[par[v][0]]])%mod1 + mod1)%mod1;
    }
    if(u == lca) {
        v = getKthNode(u, v, k, lca);
        ll h = (down[v] - down[lvl[lca]-1] + mod1)%mod1;
        h = (h * rPower[par[lca][0]])%mod1;
        return h;
    }
    int d = lvl[u] - lvl[lca] + 1;
    if(d >= k) {
        v = getKthNode(u, v, k, lca);
        return (up[u] - (up[par[v][0]] * Power[lvl[u]-lvl[par[v][0]]])%mod1 + mod1)%mod1;
    }
    // v is on right side
    v = getKthNode(u, v, k, lca);
    ll lft = (up[u] - (up[par[lca][0]] * Power[lvl[u]-lvl[par[lca][0]]])%mod1 + mod1)%mod1;
    ll rht = (down[v] - down[lca] + mod1)%mod1;
    int l = lvl[lca]+1;
    if(l > d+1)
        rht = (rht * rPower[l-d-1])%mod1;
    else if(l < d+1)
        rht = (rht * Power[d-l+1])%mod1;
    return (lft + rht)%mod1;
}