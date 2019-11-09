String :
 * Aho Aho-Corasick
 * Suffix Array : Suffix Array, Longest Common Prefix
 * Hash : Pure Hash 
          2D Hash
          Dynamic Hash supports replacing and erasing characters
 * KMP

/* Aho-Corasick
Complexity : O(n+m+z)
Finds multiple patterns in a given string with positions and number of occrances of each
n : Length of text
m : total length of all keywords
z : total number of occurance of word in text 
*/
const int TOTKEY = 505;                 // Total number of keywords
const int KEYLEN = 505;                 // Size of maximum keyword
const int MAXS = TOTKEY*KEYLEN + 10;    // Max number of states in the matching machine.
                                        // Should be equal to the total length of all keywords.
const int MAXC = 26;                    // Number of characters in the alphabet.
bitset<TOTKEY> out[MAXS];               // Output for each state, as a bitwise mask.
int f[MAXS];                            // Failure function
int g[MAXS][MAXC];                      // Goto function, or -1 if fail.
int build(const vector<string> &words, char lowestChar = 'a', char highestChar = 'z') {
    for(int i = 0; i < MAXS; ++i)  out[i].reset();
    memset(f, -1, sizeof f), memset(g, -1, sizeof g);
    int states = 1;                                     // Initially, we just have the 0 state
    for(int i = 0; i < (int)words.size(); ++i) {
        const string &keyword = words[i];
        int currentState = 0;
        for(int j = 0; j < (int)keyword.size(); ++j) {
            int c = keyword[j] - lowestChar;
            if(g[currentState][c] == -1)                // Allocate a new node
                g[currentState][c] = states++;
            currentState = g[currentState][c];
        } out[currentState].set(i);     // There's a match of keywords[i] at node currentState.
    } for(int c = 0; c < MAXC; ++c)      // State 0 should have an outgoing edge for all chars.
        if(g[0][c] == -1)
            g[0][c] = 0;                               // Now, let's build the failure function
    queue<int> q;
    for(int c = 0; c <= highestChar - lowestChar; ++c)     // Iterate over every possible input
        if(g[0][c] != -1 and g[0][c] != 0)              // All nodes s of depth 1 have f[s] = 0
            f[g[0][c]] = 0, q.push(g[0][c]);
    while(q.size()) {
        int state = q.front();
        q.pop();
        for(int c = 0; c <= highestChar - lowestChar; ++c) {
            if(g[state][c] != -1) {
                int failure = f[state];
                while(g[failure][c] == -1)
                    failure = f[failure];
                failure = g[failure][c];
                f[g[state][c]] = failure;
                out[g[state][c]] |= out[failure];               // Merge out values
                q.push(g[state][c]);
    }}}
    return states;
} int findNextState(int currentState, char nextInput, char lowestChar = 'a') {
    int answer = currentState, c = nextInput - lowestChar;
    while(g[answer][c] == -1) answer = f[answer];
    return g[answer][c];
}
int cnt[TOTKEY];
void Matcher(const vector<string> &keywords, string &text) {
    int currentState = 0;
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < (int)text.size(); ++i) {
        currentState = findNextState(currentState, text[i]);
        if(out[currentState] == 0)         // Nothing new, let's move on to the next character.
            continue;
        for(int j = 0; j < (int)keywords.size(); ++j)
            if(out[currentState][j])                            // Matched keywords[j]
                ++cnt[j];
}}
string text, str;
vector<string>keywords;
int main() {
    int n;
    cin >> n >> text;               // n: number of patterns, text: the main string
    while(n--) {
        cin >> str;                 // str: the patterns which are to be found in 'text'
        keywords.push_back(str);
    } build(keywords);
    Matcher(keywords, text);
    cout << "Matches " << Case << ":\n";
    for(int i = 0; i < (int)keywords.size(); ++i)
        cout << cnt[i] << "\n";
    return 0; }

/* Suffix Array
Complexity : N log^2(N)
Sorts all suffixes in lexicographical order, finds their Longest Common Prefix using Kasai.
Approaches: 
1. Number of unique substrings: Sum of lengths of all suffixes - Sum of all LCP,
   Check totalUniqueSubstr() function
2. Minimum lexicographical rotation: Perform Kasai on input string 'S' as 'SS', the minimum 
   Suffix rank from index 0-|S| is the answer. rotation -> abcd -> bcda -> cdab -> dabc
3. LCP of two index i, j of string S is the minimum of subarray LCP[rank[i], ..., rank[j]]
4. Lontest Common Substring of multiple string: let S1, S2, S3 be strings. Build new string,
   S = S1+#+S2+$+S3. Perform a sliding window on the LCP array from lower to higher rank, such
   that the window contains suffixes of the three strings. Answer will be the minimum LCP of 
   the sliding window.
*/

struct suffix {
    int idx;
    pii rank;
    bool operator < (suffix x) {
        return rank < x.rank;
}};
int order(char x) {
    if(isdigit(x)) return x - '0';
    else if(isupper(x)) return x-'A'+10;
    else if(islower(x)) return x-'a'+36;
    else return 110;
}
int idxToRank[MAX];                        // Index to suffix rank/lexicographicalindex mapping
suffix suff[MAX];                          // Rank is the legicographical index of each suffix
// Adding a '~' after the string takes the longer lenth higher of the SA
void SuffixArray(int len, char str[]) {      
    for(int i = 0, j = 1; i < len; ++i, ++j) {
        suff[i].idx = i, idxToRank[i] = 0;              // Initialize value of index i, and i+1             
        suff[i].rank.fi = order(str[i]),    suff[i].rank.se = (j<len) ? order(str[j]):-1;  
    } sort(suff, suff+len);                             // Out of range position assigned as -1 
    for(ll k = 4; k < (2*len); k *= 2) {             // Assigning new first rank for all suffix
        int rank = 0, prevRank = suff[0].rank.fi;         // K is the size of each suffix block
        suff[0].rank.fi = 0, idxToRank[suff[0].idx] = 0;
        for(int i = 1; i < len; ++i) {
            if(suff[i].rank == make_pair(prevRank, suff[i-1].rank.se)) {
                prevRank = suff[i].rank.fi;
                suff[i].rank.fi = rank;
            } else {
                prevRank = suff[i].rank.fi;
                suff[i].rank.fi = ++rank;
            } idxToRank[suff[i].idx] = i;
        } for(int i = 0; i < len; ++i) {
            int nxtIdx = suff[i].idx + k/2;
            suff[i].rank.se = (nxtIdx < len) ? suff[idxToRank[nxtIdx]].rank.fi:-1;  
        } sort(suff, suff+len);
    } for(int i = 0; i < len; ++i) 
        idxToRank[suff[i].idx] = i;
}
// Optimized Suffix Array
// Complexity : N log(N)
int o[2][MAX], t[2][MAX];
int idxToRank[MAX], rankToIdx[MAX], A[MAX], B[MAX], C[MAX], D[MAX];
void SuffixArray(char str[], int len, int maxAscii = 256) {
    int x = 0;
    memset(A, 0, sizeof A), memset(C, 0, sizeof C), memset(D, 0, sizeof D);
    memset(o, 0, sizeof o), memset(t, 0, sizeof t);
    for(int i = 0; i < len; ++i) A[(str[i]-'a')] = 1;
    for(int i = 1; i < maxAscii; ++i) A[i] += A[i-1];
    for(int i = 0; i < len; ++i) o[0][i] = A[(int)(str[i]-'a')];
    for (int j = 0, jj = 1, k = 0; jj < len && k < len; ++j, jj <<= 1) {
        memset(A, 0, sizeof A), memset(B, 0, sizeof B);
        for(int i = 0; i < len; ++i) {
            ++A[ t[0][i] = o[x][i] ];
            ++B[ t[1][i] = (i+jj<len) ? o[x][i+jj] : 0 ];
        } for(int i = 1; i <= len; ++i) {
            A[i] += A[i-1];
            B[i] += B[i-1];
        }
        for(int i = len-1; i >= 0; --i)
            C[--B[t[1][i]]] = i;
        for(int i = len-1; i >= 0; --i)
            D[--A[t[0][C[i]]]] = C[i];
        x ^= 1, o[x][D[0]] = k = 1;
        for(int i = 1; i < len; ++i)
            o[x][D[i]]= (k += (t[0][D[i]] != t[0][D[i-1]] || t[1][D[i]] != t[1][D[i-1]]));
    } for(int i = 0; i < len; i++) {
        idxToRank[i] = o[x][i]-1;
        rankToIdx[o[x][i]-1] = i;
}}

// Longest Common Prefix: Kasai's Algorithm
// Complexity: O(n)
int lcp[MAX];                        // LCP[i] contains LCP of index i and i-1
void Kasai(char str[], int len) {    // Matches Same charechters with i'th rank & (i+1)'th rank
    int match = 0;
    for(int idx = 0; idx < len; ++idx) {
        if(idxToRank[idx] == len-1) {
            match = 0;
            continue;
        } int nxtRankIdx = rankToIdx[idxToRank[idx]+1];
        int p = idx+match, q = nxtRankIdx+match;
        while(p < len and q < len and str[p] == str[q])
            ++p, ++q, ++match;
        lcp[nxtRankIdx] = match;               // the lcp match of i'th & (i+1)'th is stored in
        match -= (match > 0);                  // the index of (i+1)'th suffix's index
}}

int consecutiveMaxLCP(int idx, int len) {    // Finds max LCP of index idx and the total string
    int r = idxToRank[idx], ret = lcp[idx];                   //   comparing with the next rank
    if(r+1 < len) ret = max(ret, lcp[suff[r+1].idx]);         //         string of idx's string
    return ret;
}

int totalUniqueSubstr(int len) {                  // Returns total number of unique substring
    int ans = 0;
    for(int rank = 0; rank < len; ++rank) {
        int idx = suff[rank].idx;
        ans += len-idx;
        if(rank != 0) ans -= lcp[idx];
    } return ans;
}

// Longest Common Prefix [Sparse Table after running Kasai]
int table[MAX][14], lg[MAX];
void buildSparseTableRMQ(int n) {                           //  O(n Log n)
    for(ll i = 0; 1LL << i < n; i++)    lg[1LL << i] = i;
    for(ll i = 1; i < n; i++)           lg[i] = max(lg[i], lg[i - 1]);
    for(int i = 0; i < n; ++i)          table[i][0] = i;             
    for(int j = 1; (1 << j) <= n; ++j) {                     // j is the power : 2^j
        for(int i = 0; i + (1 << j) - 1< n; ++i) {
            if(lcp[rankToIdx[table[i][j-1]]] < lcp[rankToIdx[table[i + (1 << (j-1))][j-1]]])
                table[i][j] = table[i][j-1];
            else
                table[i][j] = table[i + (1 << (j-1))][j-1];
}}}
int sparseQueryRMQ(int l, int r) {          // Gives LCP of index l, r in O(1)
    l = idxToRank[l], r = idxToRank[r];     // Remove this line if rankUp or rankDown is used
    if(l > r) swap(l, r);
    ++l;
    int k = lg[r - l + 1];                  // log_2 segment;
    return min(lcp[rankToIdx[table[l][k]]], lcp[rankToIdx[table[r - (1 << k) + 1][k]]]); 
}
// Gives Upper (lower rank) for which the Range minimum LCP is tlen
// Call : 0, PosRank, strlen, totstring_len
int rankUP(int lo, int hi, int tlen, int len) {
    int mid, ret = hi, pos = hi;
    --hi;
    while(lo <= hi) {
        mid = (lo+hi)>>1;
        if(sparseQueryRMQ(mid, pos) >= tlen)    hi = mid-1, ret = mid;
        else                                    lo = mid+1;
    } return ret; 
}
// Gives Lower (higher rank) for which the Range minimum LCP is tlen
// Call : PosRank, len-1 strlen, totstring_len
int rankDown(int lo, int hi, int tlen, int len) {
    int mid, ret = lo, pos = lo;
    ++lo;
    while(lo <= hi) {
        mid = (lo+hi)>>1;
        if(sparseQueryRMQ(mid, pos) >= tlen)    lo = mid+1, ret = mid;
        else                                    hi = mid-1;
    } return ret;
}


/* ----------------------------------------- Hashing -----------------------------------------
Eqn : s[i] * p^i + s[i+1] * p^(i+1) ...
Hash powers starting from x and y, matched by multiplying with Power[MAX-x] and Power[MAX-y]
*/
const ll p = 31;
const ll mod1 = 1e9+9, mod2 = 1e7+7;
// --------------- DOUBLE HASH GENERATORS ---------------
void PowerGen(int n) {
    Power.resize(n+1);
    Power[0] = {1, 1};
    for(int i = 1; i < n; ++i) {
        Power[i].first = (Power[i-1].first * p)%mod1;
        Power[i].second = (Power[i-1].second * p)%mod2;
}} vll doubleHash(char *s, int len) {              // Returns Double Hash vector for a full string
    ll hashVal1 = 0, hashVal2 = 0;
    vector<pll>v;
    for(int i = 0; i < len; ++i) {
        hashVal1 = (hashVal1 + (s[i] - 'a' + 1)* Power[i].fi)%mod1;
        hashVal2 = (hashVal2 + (s[i] - 'a' + 1)* Power[i].se)%mod2;
        v.push_back({hashVal1, hashVal2});
    } return v;
} pll SubHash(vll &Hash, ll l, ll r, ll LIM) {    // Produce SubString Hash
    pll H;
    H.fi = (Hash[r].fi - (l-1 >= 0 ? Hash[l-1].fi:0) + mod1)%mod1;
    H.se = (Hash[r].se - (l-1 >= 0 ? Hash[l-1].se:0) + mod2)%mod2;
    H.fi = (H.fi * Power[LIM-l].fi)%mod1;
    H.se = (H.se * Power[LIM-l].se)%mod2;
    return H;
}

// Dynamic Hash supports replacing and deletion of charachter
struct DynamicHash {
    struct HashTree {                               // Data Structure of dynamix hash
        vector<ll>sum, propSum, propMul;
        ll mod, len;
        inline ll add(ll a, ll b) { return (a+b)%mod; }
        inline ll mul(ll a, ll b) { return (a*b)%mod; }
        void resize(int n, ll _mod, ll arr[]) {
            sum.resize(4*n), propSum.resize(4*n);
            propMul.resize(4*n), mod = _mod, len = n;
        } void pushDown(int child, int par) {                      // just push down the values
            propSum[child] = mul(propSum[child], propMul[par]);
            propSum[child] = add(propSum[child], propSum[par]);
            propMul[child] = mul(propMul[child], propMul[par]);
        } void init(int pos, int l, int r, ll arr[]) {                  // Call resize first!!!
            sum[pos] = propSum[pos] = 0, propMul[pos] = 1;
            if(l == r) { sum[pos] = arr[l]; return; }
            int mid = (l+r)>>1;
            init(pos<<1, l, mid, arr), init(pos<<1|1, mid+1, r, arr);
            sum[pos] = add(sum[pos<<1], sum[pos<<1|1]);
        } void propagate(int pos, int l, int r) {            // sets and pushes values to child
            if(propMul[pos] == 1 and propSum[pos] == 0) return;
            sum[pos] = add(mul(sum[pos], propMul[pos]), mul(r-l+1, propSum[pos]));
            if(l == r) { propMul[pos] = 1, propSum[pos] = 0; return; }
            pushDown(pos<<1, pos), pushDown(pos<<1|1, pos);
            propMul[pos] = 1, propSum[pos] = 0;
        } void update(int pos, int l, int r, int L, int R, ll val, int type) {
            propagate(pos, l, r);
            if(r < L or R < l) return;
            if(L <= l and r <= R) {
                if(type == 0)                               // add val in [L, R]
                    propSum[pos] = add(propSum[pos], val);
                else if(type == 1) {                        // multiply val in [L, R]
                    propSum[pos] = mul(propSum[pos], val);
                    propMul[pos] = mul(propMul[pos], val);
                } else if(type == 2)                          // set all value = val
                    propSum[pos] = val, propMul[pos] = 0;
                propagate(pos, l, r);
                return;
            } int mid = (l+r)>>1;
            update(pos<<1, l, mid, L, R, val, type), update(pos<<1|1, mid+1, r, L, R, val, type);
            sum[pos] = add(sum[pos<<1], sum[pos<<1|1]);
        } ll query(int pos, int l, int r, int L, int R) {
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

    pair<HashTree, HashTree>H;
    ordered_set<int> indexGen;
    const ll p1 = 31, modInvP1 = 838709685;
    const ll p2 = 51, modInvP2 = 1372550;
    const ll mod1 = 1e9+9, mod2 = 1e7+7;
    ll LIM, len;
    vll Power;
    void init(string &str) {
        LIM = str.size() + 100;
        PowerGen(LIM+100);
        ll h1 = 0, h2 = 0;
        len = SIZE(str);
        indexGen.clear();
        H.first.init(len+5, mod1), H.second.init(len+5, mod2);
        indexGen.insert(0);
        for(int i = 1; i < len; ++i) {                  // assuming string starts from index 1
            h1 = ((str[i] - 'a' + 1) * Power[i].first)%mod1;
            h2 = ((str[i] - 'a' + 1) * Power[i].second)%mod2;
            H.first.add(i, i, h1),  H.second.add(i, i, h2);
            indexGen.insert(i);
    }} 
    int GetPos(int idx) { return *indexGen.at(idx); }
    void PlaceChar(int idx, char newChar) {             // Place/Replace charachter at idx
        int StrIdx = GetPos(idx);
        ll newVal1 = ((newChar-'a'+1)*Power[idx].first)%mod1;
        ll newVal2 = ((newChar-'a'+1)*Power[idx].second)%mod2;
        H.first.set(StrIdx, StrIdx, newVal1),   H.second.set(StrIdx, StrIdx, newVal2);
        str[StrIdx] = newChar;
    } void RemoveChar(int pos) {                          // Remove charachter at pos
        int idx = GetPos(pos);
        H.first.set(idx, idx, 0),           H.second.set(idx, idx, 0);
        H.first.mul(idx+1, len, modInvP1),  H.second.mul(idx+1, len, modInvP2);
        indexGen.erase(indexGen.at(pos));
    } void PowerGen(int n) {
        Power.resize(n+1);
        Power[0] = {1, 1};
        for(int i = 1; i < n; ++i) {
            Power[i].first = (Power[i-1].first * p1)%mod1;
            Power[i].second = (Power[i-1].second * p2)%mod2;
    }} ll SubStrHash(int l, int strLen, bool first = 1) {
        int LL = GetPos(l), RR = GetPos(l+strLen-1);
        ll hash = first ? H.first.query(LL, RR):H.second.query(LL, RR);
        return (hash * (first?Power[LIM-l].first:Power[LIM-l].second))%(first?mod1:mod2);
    } ll GetHash(int l, int r) {
        return H.first.query(GetPos(l), GetPos(r));
}};

// ---------------------------------------- 2D Hash ---------------------------------------- 

// For row, column (i,j) prime power is somthing like p^(ij)
const int lineOffset = 1010;                       // use the 2DLim to distinguish between rows
vector<vll> Gen2DHash(int r, int c, char str[][1010]) {                  // row, column, string
    vector<vll> hash(r);                          
    for(int i = 0, offset = 0; i < r; ++i, offset += lineOffset) {          
        pll h = {0, 0};                           // Powers of every row r starts from r*offset
        for(int j = 0; j < c; ++j) {
            h.first = ((str[i][j] - 'a' + 1)*Power[j+offset].first)%mod1;
            h.second = ((str[i][j] - 'a' + 1)*Power[j+offset].second)%mod2;
            hash[i].push_back(h);
    }} for(int i = 0; i < r; ++i) {
         for(int j = 0; j < c; ++j) {
            if(i > 0) {
                hash[i][j].first = (hash[i][j].first + hash[i-1][j].first)%mod1;
                hash[i][j].second = (hash[i][j].second + hash[i-1][j].second)%mod2; 
            } if(j > 0) {
                hash[i][j].first = (hash[i][j].first + hash[i][j-1].first)%mod1;
                hash[i][j].second = (hash[i][j].second + hash[i][j-1].second)%mod2; 
            } if(i > 0 and j > 0) {
                hash[i][j].first = (hash[i][j].first - hash[i-1][j-1].first + mod1)%mod1;
                hash[i][j].second = (hash[i][j].second - hash[i-1][j-1].second + mod2)%mod2; }
            hash[i][j].first = (hash[i][j].first)%mod1;
            hash[i][j].second = (hash[i][j].second)%mod2;
    }} return hash; 
}
const ll LIM = 1025000; 
pll SubHash2D(vector<vll> &H, int x, int y, int r, int c) {           // Generates hash which's 
    int xx = x+r-1, yy = y+c-1;                                    // upper-left point = (x, y)
    pll ret = H[xx][yy];                                  // lower right point = (x+r-1, y-c-1)
    if(x > 0) {
        ret.first = (ret.first - H[x-1][yy].first + mod1)%mod1;
        ret.second = (ret.second - H[x-1][yy].second + mod2)%mod2; 
    } if(y > 0) {
        ret.first = (ret.first - H[xx][y-1].first + mod1)%mod1;
        ret.second = (ret.second - H[xx][y-1].second + mod2)%mod2; 
    } if(x > 0 and y > 0)
        ret.first += H[x-1][y-1].first, ret.second += H[x-1][y-1].second;
    ret.first = ret.first%mod1, ret.second = ret.second%mod2;
    ret.first = (ret.first*Power[LIM-(x*lineOffset+y)].first)%mod1;
    ret.second = (ret.second*Power[LIM-(x*lineOffset+y)].second)%mod2;
    return ret; 
}

/* Knuth Morris Pratt - KMP
 Complexity : O(String + Token)
 Some Tricky Cases:   aaaaaa   : 0 1 2 3 4 5        
                      aaaabaa  : 0 1 2 3 0 1 2
                      abcdabcd : 0 0 0 0 1 2 3 4 */

void prefixTable(int n, char pat[], int table[]) {
    int len = 0, i = 1;                     // Length of the previous longest prefix suffix
    table[0] = 0;                           // table[0] is always 0
    while (i < n) {
        if (pat[i] == pat[len])
            table[i++] = ++len;
        else {                                                  // pat[i] != pat[len]
            if(len != 0)    len = table[len-1];                 // find previous match
            else            table[i] = 0, i++;                  // if (len == 0) and mismatch
}}}                                                  // set table[i] = 0, and go to next index

void KMP(int strLen, int patLen, char str[], char pat[], int table[]) { 
    int i = 0, j = 0;                                                   // i : string index
    while (i < strLen) {                                                // j : pattern index
        if(str[i] == pat[j]) i++, j++;
        if(j == patLen) {
            printf("Found pattern at index %d n", i-j);
            j = table[j-1];                                  // Match found, try for next match
        } else if(i < strLen && str[i] != pat[j]) {          // Match not found
            if(j != 0)  j = table[j-1];           // if j != 0, then go to the prev match index
            else        i = i+1;          // if j == 0, then we need to go to next index of str
}}}
// p is the pattern where table[] is the previously made prefix-table of pattern
// For any index idx the nxt[idx][j] returns the new index idx where the index
// should point next, this optimizes the kmp in linear time
void getState(string &p, int table[], int nxt[][27]) {
    for(int i = 0; i < p.size(); ++i) {
        for(int j = 0; j < 26; ++j) {
            if(p[i]-'a' == j)   nxt[i][j] = i+1;
            else                nxt[i][j] = i == 0 ? 0 : nxt[table[i-1]][j];
}}}
// check function using nxt[idx][j]
// idx is the index from which the string should start matching with the pattern
// by default idx = 0, also it refers the last index of the pattern to which
// the string matched
int match(string &s, int table[], int nxt[][27], int &idx) {
    int ans = 0;
    for(char c : s) {
        idx = nxt[idx][c-'a'];
        if(idx == p.size())
            ++ans, idx = table[idx-1];
    }
return ans; }
