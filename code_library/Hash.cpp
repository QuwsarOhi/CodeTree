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