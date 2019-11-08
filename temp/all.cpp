String :
 *Aho Aho-Corasick
 *Suffix Array
 *Hash
 *KMP

DP:
 * Building Palindrome in minimum move and printing the answer palindrome
 * Matching two strings by insert, erase, and changing characters
 * String reduction                                     [AXDOODOO -> AX(DO^2)^2] 
 * Merging multiple strings into shortest string        [TAC + ACT + CTA = ACTAC]
 * Making balanced bracket sequqnce from imbalanced bracket sequence
 * Digit DP : Decimal DP, Bit DP, Double bonded Decimal DP
 * Memory Optimized Dp : Building two subsets of equal sum from a single set of values
 * Travelling Salesman

Data Structure:
 * DSU : Disjoint Set Union, Bipartite DSU, Weighted DSU
 * Trie : Dynamic Trie, Static Trie
 * 

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
    for(int i = 0; i < MAXS; ++i)
        out[i].reset();
    memset(f, -1, sizeof f);
    memset(g, -1, sizeof g);
    int states = 1;                                     // Initially, we just have the 0 state
    for(int i = 0; i < (int)words.size(); ++i) {
        const string &keyword = words[i];
        int currentState = 0;
        for(int j = 0; j < (int)keyword.size(); ++j) {
            int c = keyword[j] - lowestChar;
            if(g[currentState][c] == -1)                // Allocate a new node
                g[currentState][c] = states++;
            currentState = g[currentState][c];
        }
        out[currentState].set(i);       // There's a match of keywords[i] at node currentState.
    }
    for(int c = 0; c < MAXC; ++c)       // State 0 should have an outgoing edge for all chars.
        if(g[0][c] == -1)
            g[0][c] = 0;                // Now, let's build the failure function
    queue<int> q;
    for(int c = 0; c <= highestChar - lowestChar; ++c)     // Iterate over every possible input
        if(g[0][c] != -1 and g[0][c] != 0) {            // All nodes s of depth 1 have f[s] = 0
            f[g[0][c]] = 0;
            q.push(g[0][c]);
        }
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
            } } }
    return states;
}

int findNextState(int currentState, char nextInput, char lowestChar = 'a') {
    int answer = currentState;
    int c = nextInput - lowestChar;
    while(g[answer][c] == -1)
        answer = f[answer];
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
    int t, n;
    cin >> t;
    for(int Case = 1; Case <= t; ++Case) {
        cin >> n >> text;               // n: number of patterns, text: the main string
        while(n--) {
            cin >> str;                 // str: the patterns which are to be found in 'text'
            keywords.push_back(str);
        }
        build(keywords);
        cout << "Case " << Case << ":\n";
        Matcher(keywords, text);
        for(int i = 0; i < (int)keywords.size(); ++i)
            cout << cnt[i] << "\n";
        keywords.clear();
    }
    return 0;
}

/* Suffix Array
Complexity : N log^2(N)
Sorts all suffixes in lexicographical order, finds their Longest Common Prefix using Kasai.
Approaches: 
1. Number of unique substrings: Sum of lengths of all suffixes - Sum of all LCP,
   Check totalUniqueSubstr() function
2. Minimum lexicographical rotation: Perform Kasai on input string 'S' as 'SS', the minimum 
   Suffix rank from index 0-|S| is the answer. rotation -> abcd -> bcda -> cdab -> dabc
3. 
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
        suff[i].idx = i;                                // Initialize value of index i, and i+1             
        suff[i].rank.fi = order(str[i]);
        suff[i].rank.se = (j<len) ? order(str[j]):-1;   // Out of range position assigned as -1
        idxToRank[i] = 0;
    }
    sort(suff, suff+len);                               
    for(ll k = 4; k < (2*len); k *= 2) {      // Assigning new first rank for all suffix
        int rank = 0;                         // K is the size of each suffix block
        int prevRank = suff[0].rank.fi;       // prevRank contains previous suffix's first rank
        suff[0].rank.fi = 0;                  // first rank is always zero 
        idxToRank[suff[0].idx] = 0;
        for(int i = 1; i < len; ++i) {
            if(suff[i].rank == make_pair(prevRank, suff[i-1].rank.se)) {
                prevRank = suff[i].rank.fi;
                suff[i].rank.fi = rank;
            }
            else {
                prevRank = suff[i].rank.fi;
                suff[i].rank.fi = ++rank;
            }
            idxToRank[suff[i].idx] = i;
        }                                      // The first rank of all indexes are assigned
        for(int i = 0; i < len; ++i) {         // Assign the second rank
            int nxtIdx = suff[i].idx + k/2;    // The second rank of position i+k/2
            suff[i].rank.se = (nxtIdx < len) ? suff[idxToRank[nxtIdx]].rank.fi:-1;  
        }
        sort(suff, suff+len);
    }
    for(int i = 0; i < len; ++i) 
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
        }
        for(int i = 1; i <= len; ++i) {
            A[i] += A[i-1];
            B[i] += B[i-1];
        }
        for(int i = len-1; i >= 0; --i)
            C[--B[t[1][i]]] = i;
        for(int i = len-1; i >= 0; --i)
            D[--A[t[0][C[i]]]] = C[i];
        x ^= 1;
        o[x][D[0]] = k = 1;
        for(int i = 1; i < len; ++i)
            o[x][D[i]]= (k += (t[0][D[i]] != t[0][D[i-1]] || t[1][D[i]] != t[1][D[i-1]]));
    }
    for(int i = 0; i < len; i++) {
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
        }
        int nxtRankIdx = rankToIdx[idxToRank[idx]+1];
        while(idx+match < len and nxtRankIdx+match < len and str[idx+match] == str[nxtRankIdx+match])
            ++match;
        lcp[nxtRankIdx] = match;              // the lcp match of i'th & (i+1)'th is stored in
        match -= match>0;                     // the index of (i+1)'th suffix's index
}}

int consecutiveMaxLCP(int idx, int len) {    // Finds max LCP of index idx and the total string
    int r = idxToRank[idx];              // comparing with the next rank string of idx's string
    int ret = lcp[idx];
    if(r+1 < len) ret = max(ret, lcp[suff[r+1].idx]);
    return ret;
}

int totalUniqueSubstr(int len) {                  // Returns total number of unique substring
    int ans = 0;
    for(int rank = 0; rank < len; ++rank) {
        int idx = suff[rank].idx;
        ans += len-idx;
        if(rank != 0) ans -= lcp[idx];
    }
    return ans;
}

// Longest Common Prefix [Sparse Table after running Kasai]
int table[MAX][14], lg[MAX];
void buildSparseTableRMQ(int n) {                           //  O(n Log n)
    for(ll i = 0; 1LL << i < n; i++)                        // Logarithm Precal
        lg[1LL << i] = i;
    for(ll i = 1; i < n; i++)
        lg[i] = max(lg[i], lg[i - 1]);
    for(int i = 0; i < n; ++i)                              // Table Init
        table[i][0] = i;             
    for(int j = 1; (1 << j) <= n; ++j)                      // j is the power : 2^j
        for(int i = 0; i + (1 << j) - 1< n; ++i) {
            if(lcp[rankToIdx[table[i][j-1]]] < lcp[rankToIdx[table[i + (1 << (j-1))][j-1]]])
                table[i][j] = table[i][j-1];
            else
                table[i][j] = table[i + (1 << (j-1))][j-1];
}}

int sparseQueryRMQ(int l, int r) {          // Gives LCP of index l, r in O(1)
    l = idxToRank[l], r = idxToRank[r];     // Remove this line if rankUp or rankDown is used
    if(l > r) swap(l, r);
    ++l;
    int k = lg[r - l + 1];                  // log_2 segment;
    return min(lcp[rankToIdx[table[l][k]]], lcp[rankToIdx[table[r - (1 << k) + 1][k]]]); }

// Gives Upper (lower rank) for which the Range minimum LCP is tlen
// Call : 0, PosRank, strlen, totstring_len
int rankUP(int lo, int hi, int tlen, int len) {
    int mid, ret = hi, pos = hi;
    --hi;
    while(lo <= hi) {
        mid = (lo+hi)>>1;
        if(sparseQueryRMQ(mid, pos) >= tlen)    hi = mid-1, ret = mid;
        else                                    lo = mid+1;
    }
return ret; }

// Gives Lower (higher rank) for which the Range minimum LCP is tlen
// Call : PosRank, len-1 strlen, totstring_len
int rankDown(int lo, int hi, int tlen, int len) {
    int mid, ret = lo, pos = lo;
    ++lo;
    while(lo <= hi) {
        mid = (lo+hi)>>1;
        if(sparseQueryRMQ(mid, pos) >= tlen)    lo = mid+1, ret = mid;
        else                                    hi = mid-1;
    }
return ret; }


/* Hashing
Eqn : s[i] * p^i + s[i+1] * p^(i+1) ...
Hash powers starting from x and y, matched by multiplying with Power[MAX-x] and Power[MAX-y]
*/

const ll p = 31;
const ll mod1 = 1e9+9, mod2 = 1e7+7;
void PowerGen(int n) {
    Power.resize(n+1);
    Power[0] = 1;
    for(int i = 1; i < n; ++i)
        Power[i] = (Power[i-1] * p)%mod;
}

vl Hash(char s[], int len) {
    ll hashVal = 0;
    vector<ll>v;
    for(int i = 0; i < len; ++i) {
        hashVal = (hashVal + (s[i] - 'a' + 1)* Power[i])%mod;
        v.push_back(hashVal);
    }
return v; }

ll SubHash(vl &Hash, ll l, ll r) {      // Generate hash of substring s[l..r]
    ll H;                               // Power is auto increased for matching
    H = (Hash[r] - (l-1 >= 0 ? Hash[l-1]:0) + mod)%mod;
    H = (H * Power[MAX-l-1])%mod;
return H; }

// --------------- DOUBLE HASH GENERATORS ---------------
void PowerGen(int n) {
    Power.resize(n+1);
    Power[0] = {1, 1};
    for(int i = 1; i < n; ++i) {
        Power[i].first = (Power[i-1].first * p)%mod1;
        Power[i].second = (Power[i-1].second * p)%mod2;
}}

vll doubleHash(char *s, int len) {              // Returns Double Hash vector for a full string
    ll hashVal1 = 0, hashVal2 = 0;
    vector<pll>v;
    for(int i = 0; i < len; ++i) {
        hashVal1 = (hashVal1 + (s[i] - 'a' + 1)* Power[i].fi)%mod1;
        hashVal2 = (hashVal2 + (s[i] - 'a' + 1)* Power[i].se)%mod2;
        v.push_back({hashVal1, hashVal2});
    }
return v;}

pll SubHash(vll &Hash, ll l, ll r, ll LIM) {    // Produce SubString Hash
    pll H;
    H.fi = (Hash[r].fi - (l-1 >= 0 ? Hash[l-1].fi:0) + mod1)%mod1;
    H.se = (Hash[r].se - (l-1 >= 0 ? Hash[l-1].se:0) + mod2)%mod2;
    H.fi = (H.fi * Power[LIM-l].fi)%mod1;
    H.se = (H.se * Power[LIM-l].se)%mod2;
    return H;
}

// Dynamic Hash supports replacing and deletion of charachter
struct DynamicHash {
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
    }}
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            if(i > 0) {
                hash[i][j].first = (hash[i][j].first + hash[i-1][j].first)%mod1;
                hash[i][j].second = (hash[i][j].second + hash[i-1][j].second)%mod2; }
            if(j > 0) {
                hash[i][j].first = (hash[i][j].first + hash[i][j-1].first)%mod1;
                hash[i][j].second = (hash[i][j].second + hash[i][j-1].second)%mod2; }
            if(i > 0 and j > 0) {
                hash[i][j].first = (hash[i][j].first - hash[i-1][j-1].first + mod1)%mod1;
                hash[i][j].second = (hash[i][j].second - hash[i-1][j-1].second + mod2)%mod2; }
            hash[i][j].first = (hash[i][j].first)%mod1;
            hash[i][j].second = (hash[i][j].second)%mod2;
    }}
return hash; }

const ll LIM = 1025000; 
pll SubHash2D(vector<vll> &H, int x, int y, int r, int c) {      // Generates hash which's 
    int xx = x+r-1, yy = y+c-1;                                  // upper-left point = (x, y)
    pll ret = H[xx][yy];                                  // lower right point = (x+r-1, y-c-1)
    if(x > 0) {
        ret.first = (ret.first - H[x-1][yy].first + mod1)%mod1;
        ret.second = (ret.second - H[x-1][yy].second + mod2)%mod2; }
    if(y > 0) {
        ret.first = (ret.first - H[xx][y-1].first + mod1)%mod1;
        ret.second = (ret.second - H[xx][y-1].second + mod2)%mod2; }
    if(x > 0 and y > 0)
        ret.first += H[x-1][y-1].first, ret.second += H[x-1][y-1].second;
    ret.first = ret.first%mod1;
    ret.second = ret.second%mod2;
    ret.first = (ret.first*Power[LIM-(x*lineOffset+y)].first)%mod1;
    ret.second = (ret.second*Power[LIM-(x*lineOffset+y)].second)%mod2;
return ret; }


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
        }
        else if(i < strLen && str[i] != pat[j]) {            // Match not found
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

/* ----------------------- Dynamic Programming ----------------------- */

// String DP
int Palindrome(int l, int r) {                          // Building Palindrome in minimum move
    if(dp[l][r] != INF) return dp[l][r];
    if(l >= r)          return dp[l][r] = 0;
    if(l+1 == r)        return dp[l][r] = (s[l] != s[r]);
    if(s[l] == s[r])    return dp[l][r] = Palindrome(l+1, r-1);
    return dp[l][r] =   min(Palindrome(l+1, r), Palindrome(l, r-1))+1;  // Adding a alphabet 
}                                                                       // on left and right

// String Printer function of above DP
void dfs(int l, int r) {                // Palindrome printing, for above DP function
    if(l > r) return;
    if(s[l] == s[r]) {
        Palin.push_back(s[l]);
        dfs(l+1, r-1);
        if(l != r) Palin.push_back(s[l]);
        return;
    }
    int P = min(make_pair(dp[l+1][r], 1), make_pair(dp[l][r-1], 2)).second;
    if(P == 1) {
        Palin.push_back(s[l]);
        dfs(l+1, r);
        Palin.push_back(s[l]);
    }
    else {
        Palin.push_back(s[r]);
        dfs(l, r-1);
        Palin.push_back(s[r]);
}}

bool isPalindrome(int l, int r) {       // Checks if substring l-r is palindrome
    if(l == r || l > r)     return 1;
    if(dp[l][r] != -1)      return dp[l][r];
    if(s[l] == s[r])        return dp[l][r] = isPalindrome(l+1, r-1);
    return 0;
}

// Given two string s1 and s2, match the two strings by performing the following operations:
// delete chars, insert chars, and change chars at any position on any string
int recur(int p1, int p2) {         // make string s1 like s2, in minimum move
    if(dp[p1][p2] != INF)
        return dp[p1][p2];
    if(p1 == l1 or p2 == l2) {      // reached end of string s1 or s2
        if(p1 < l1) return dp[p1][p2] = recur(p1+1, p2)+1;
        if(p2 < l2) return dp[p1][p2] = recur(p1, p2+1)+1;
        return dp[p1][p2] = 0;
    }
    if(s1[p1] == s2[p2])            // match found
        return dp[p1][p2] = recur(p1+1, p2+1);
    // change at position p1, delete position p1, insert at position p1
    return dp[p1][p2] = min(recur(p1+1, p2+1), min(recur(p1+1, p2), recur(p1, p2+1)))+1;    
}

// Printing the string of above dp function
void dfs(int p1, int p2) {          // printing function for above dp
    if(dp[p1][p2] == 0)             // end point (value depends on topdown/bottomup)
        return;
    if(s1[p1] == s2[p2]) {          // match found, no operation
        dfs(p1+1, p2+1);
        return;
    }
    int P = min(mp(dp[p1+1][p2], 1), min(mp(dp[p1][p2+1], 2), mp(dp[p1+1][p2+1], 3))).second;
    if(P == 1)      dfs(p1+1, p2);               // delete s1[p1] from position p2 of s1 string
    else if(P == 2) dfs(p1, p2+1);                 // insert s2[p2] on position p2 of s1 string
    else            dfs(p1+1, p2+1);     // change s1[p2] to s2[p2] on position p2 of string s1       
}

// Reduce string AXDOODOO (len : 8) to AX(DO^2)^2 (len : 4)
int reduce(int l, int r) {              
    if(l > r)           return INF;
    if(l == r)          return 1;
    if(dp[l][r] != -1)  return dp[l][r];
    int ret = r-l+1;
    int len = ret;
    for(int i = l; i < r; ++i)          // A B D O O D O O   remove A X substring
        ret = min(ret, reduce(l, i)+reduce(i+1, r));
    for(int d = 1; d < len; ++d) {      // D O O D O O  to check all divisable length substring
        if(len%d != 0)  continue;
        for(int i = l+d; i <= r; i += d)
            for(int k = 0; k < d; ++k)
                if(s[l+k] != s[i+k])
                    goto pass;
        ret = min(ret, reduce(l, l+d-1));
        pass:;
    }
    return dp[l][r] = ret;
}

// Light OJ 1073 - DNA Sequence
// FIND and PRINT shortest string after merging multiple string together
// TAC + ACT + CTA = ACTAC
int matchDP[20][20];                    
int TryMatch(int x, int y) {            // Finds overlap of two strings if placed as x + y
    if(matchDP[x][y] != -1)             // ABAAB + AAB : Match at index 2
        return matchDP[x][y];
    for(size_t i = 0; i < v[x].size(); ++i) {
        for(size_t j = i, k = 0; j < v[x].size() && k < v[y].size(); ++j, ++k)
            if(v[x][j] != v[y][k])
                goto pass;
        return matchDP[x][y] = i;
        pass:;
    }
return matchDP[x][y] = v[x].size(); }

int dp[16][(1<<15)+100];
int recur(int mask, int last) {                 // Final match patterns of strings
    if(dp[last][mask] != -1)             return dp[last][mask];
    if(mask == (1<<n)-1)                 return dp[last][mask] = v[last].size();
    int ret = INF, cost;
    for(int i = 0; i < n; ++i) {
        if(isOn(mask, i))
            continue;
        int mPos = TryMatch(last, i);
        if(mPos < (int)v[last].size())
            cost = (int)v[last].size() - ((int)v[last].size() - mPos);
        else
            cost = v[last].size();
        ret = min(ret, recur(mask | (1 << i), i) + cost);
    }
return dp[last][mask] = ret; }

string ans;
void dfs(int mask, int last, string ret) {      // Printing the final string
    if(!ret.empty() && ans < ret) return;
    if(mask == (1<<n)-1) {
        ret += v[last];
        if(ret < ans)
            ans = ret;
        return; }
    for(int i = 0; i < n; ++i) {
        if(isOn(mask, i))
            continue;
        int mPos = TryMatch(last, i), cost;
        if(mPos < (int)v[last].size())
            cost = (int)v[last].size() - ((int)v[last].size() - mPos);
        else
            cost = v[last].size();
        if(dp[last][mask] - cost == dp[i][mask | (1<<i)])
            dfs(mask | (1<<i), i, ret + v[last].substr(0, cost));
}}

// FileName : 1141 - Brackets Sequence
// Given a bracket sequence of () and [] which can be non-accurate have to make it accurate 
// such as the accurate sequence length is minimum and lexicographically smallest
int recur(int l, int r) {
    int &ret = dp[l][r];
    if(l > r)                    return ret = 0;
    if(l == r)                   return ret = 2;           // We need to place an extra bracket
    if(ret != INF)               return ret;
    ret = min(recur(l+1, r), recur(l, r-1))+2;     // First we assume that we
    char lft = s[l];                              // need to place brackets on first or on last
    if(lft == '(' or lft == '[') {               // If this segment starts with opening bracket
      for(int i = l+1; i <= r; ++i) {        // Then we try to slice the segment into two parts
        if((lft == '(' and s[i] == ')') or (lft == '[' and s[i] == ']'))
          ret = min(ret, recur(l+1, i-1)+recur(i+1, r)+2);      // +2 is the lenght of () or []
return ret; }

/* -----------------------Digit DP-----------------------
Complexity : O(10*idx*sum*tight)     : LightOJ 1068
Tight contains if there is any restriction to number (Tight is initially 1)
Initial Params: (MaxDigitSize-1, 0, 0, 1, modVal, allowed_digit_vector)
MaxDigit contains values in reverse order, (123 will be stored as {3, 2, 1}) */
ll dp[15][100][100][2];
ll digitSum(int idx, int sum, ll value, bool tight, int mod, vector<int>&MaxDigit) {
    if (idx == -1)                              return ((value == 0) && (sum == 0));
    if (dp[idx][sum][value][tight] != -1)       return dp[idx][sum][value][tight];
    ll ret = 0;
    int lim = (tight)? MaxDigit[idx] : 9;
    for(int i = 0; i <= lim; i++) {
        bool newTight = (MaxDigit[idx] == i)? tight:0;                  // caclulating newTight  
        ll newValue = value ? ((value*10) % mod)+i : i;                 // value for next state
        ret += digitSum(idx-1, (sum+i)%mod, newValue%mod, newTight, mod, MaxDigit);
    }
return dp[idx][sum][value][tight] = ret; }

/* Bit DP (Almost same as Digit DP)    : LighOJ 1032
Complexity O(2*pos*total_bits*tights*number_of_bits)
Initial Params : (MostSignificantOnBitPos, N, 0, 0, 1)
Call as : bitDP(SigOnBitPos, N, 0, 0, 1)   N is the Max Value, calculating in range [0 - N]
pairs are number of paired bits, prevOn shows if previous bit was on (it is for this problem)*/

ll dp[33][33][2][2], N, lastBit;
ll bitDP(int pos, int mask, int pairs, bool prevOn, bool tight) {
    if(pos < 0)                                 return pairs;
    if(dp[pos][pairs][prevOn][tight] != -1)     return dp[pos][pairs][prevOn][tight];
    bool newTight = tight & !isOn(mask, pos);
    ll ans = bitDP(pos-1, Off(mask, pos), pairs, 0, newTight);
    if(On(mask, pos) <= N)
        ans += bitDP(pos-1, On(mask, pos), pairs + prevOn, 1, tight && isOn(mask, pos)); 
return dp[pos][pairs][prevOn][tight] = ans; }

/* ----------------------- Double Bounded Digit Dp Technique -----------------------
mn, mx contains the digits from MSB to LSB and both of them must be of same length */
vector<int>tt, mn = {0, 5, 4}, mx = {1, 3, 0};              // mn = 54, mx = 130, mn is resized
void recur(int pos = 0, bool lower = 1, bool higher = 1) {                  // A dummy function
    if(pos == LEN) {
        for(auto it : tt) cout << it;
        cout << endl;
        return;
    }
    int lo = lower ? mn[pos]:0;
    int hi = higher ? mx[pos]:9;
    for(int d = lo; d <= hi; ++d) {
        bool newLower = (d == mn[pos]) ? lower:0;
        bool newHigher = (d == mx[pos]) ? higher:0;
        tt.push_back(d);
        recur(pos+1, newLower, newHigher);
        tt.pop_back();
}}

/* Memory Optimized DP + Bottom Up solution (LOJ : 1126 - Building Twin Towers)
 Given array v of n elements, make two value x1 and x2 where x1 == x2, output maximum of it */
int dp[2][500010], n;                                   // present dp table and past dp table
int BottomUp(int TOT) {                                 // TOT = (Cumulative Sum of v)/2
    memset(dp, -1, sizeof dp);             // DP[iteration_state][sum_difference] = maximum sum
    dp[0][0] = 0;
    bool present = 0, past = 1;
    for(int i = 0; i < n; ++i) {
      present ^= 1, past ^= 1;                        // Swapping present and past dp table
      for(int diff = 0; diff <= TOT; ++diff) {
        if(dp[past][diff] != -1) {
          int moreDiff = diff + v[i], lessDiff = abs(diff - v[i]);
          dp[present][diff] = max(dp[present][diff], dp[past][diff]);
          dp[present][lessDiff] = max(dp[present][lessDiff], 
                                            max(dp[past][lessDiff], dp[past][diff] + v[i]));
          dp[present][moreDiff] = max(dp[present][moreDiff], 
                                            max(dp[past][moreDiff], dp[past][diff] + v[i]));
    }}}
    return (max(dp[0][0], dp[1][0]))/2;                 // Returns the maximum possible answer
}

/* Travelling Salesman
 dist[u][v] = distance from u to v
 dp[u][bitmask] = dp[node][set_of_taken_nodes]  (saves the best(min/max) path) */
int n, x[11], y[11], dist[11][11], memo[11][1 << 11], dp[11][1 << 11];
int TSP(int u, int bitmask) {               // TSP(startin_node, bitmask_of_visited_node)
    if(bitmask == ((1 << (n)) - 1))         return dist[u][0];
    if(dp[u][bitmask] != -1)                return dp[u][bitmask];             
    int ans = INF;
    for(int v = 0; v <= n; v++)                 // Traverse all nodes from u
        if(u != v && !(bitmask & (1 << v)))     
            ans = min(ans, dist[u][v] + tsp(v, bitmask | (1 << v)));
return dp[u][bitmask] = ans; }


/* ------------------------------ DSU with Path Compression ------------------------------ */
struct DSU {
    vector<int>u_list, u_set;                       // u_list[x] : the size of a set x
    DSU() {}                                        // u_set[x]  : the root of x
    DSU(int SZ) { init(SZ); }
    int unionRoot(int n) {                          // Root of node n
        if(u_set[n] == n) return n;
        return u_set[n] = unionRoot(u_set[n]); }
    int makeUnion(int a, int b) {                   // Union making with compression
        int x = unionRoot(a), y = unionRoot(b);
        if(x == y) return x;                        // If both are in same set
        else if(u_list[x] > u_list[y]) {            // Makes x root (y -> x)
            u_set[y] = x;
            u_list[x] += u_list[y];                 // Root's size is increased
            return x; }
        else {                                      // Makes y root (x -> y)
            u_set[x] = y;
            u_list[y] += u_list[x];                 // Root's size is increased
            return y;
    }}
    void init(int len) {                            // Initializer
        u_list.resize(len+5), u_set.resize(len+5);
        for(int i = 0; i <= len+3; i++)
            u_set[i] = i, u_list[i] = 1;
    }
    bool isRoot(int x)              { return u_set[x] == x; }
    bool isRootContainsMany(int x)  { return (isRoot(x) && (u_list[x] > 1)); }
    bool isSameSet(int a, int b)    { return (unionRoot(a) == unionRoot(b));
}};

// Bipartite DSU (Tested)

struct BipartiteDSU {
    vector<int>u_list, u_set, u_color;                      // u_color : color of nodes
    vector<bool>missmatch;                                  // Bicolor missmatch
    BipartiteDSU() {}
    BipartiteDSU(int SZ) { init(SZ); }
    pll unionRoot(int n) {                                  // Finds root of node n
        if(u_set[n] == n) return {n, u_color[n]};           // returns : {root_node, color}
        pll root = unionRoot(u_set[n]);
        if(missmatch[u_set[n]] or missmatch[n])
            missmatch[n] = missmatch[u_set[n]] = 1;
        u_color[n] = (u_color[n] + root.second)&1;
        u_set[n] = root.first;
        return {u_set[n], u_color[n]};
    }
    int makeUnion(int a, int b) {
        int x = unionRoot(a).first, y = unionRoot(b).first;
        if(x == y) {
            if(u_color[a] == u_color[b]) missmatch[x] = 1;
            return x;
        }
        if(missmatch[x] or missmatch[y])                // Checks if Bipartite missmatch exists
            missmatch[x] = missmatch[y] = 1;
        if(u_list[x] < u_list[y]) {                     // Makes y root
            u_set[x] = y, u_list[x] += u_list[y];
            u_color[x] = (u_color[a]+u_color[b]+1)&1;      // Setting color of component
            return y;                                      // y according to the color of a & b
        }
        else {                                          // Makes x root
            u_set[y] = x, u_list[y] += u_list[x];
            u_color[y] = (u_color[a]+u_color[b]+1)&1;
            return x;
    }}
    void init(int len) {                // Initializer
        u_list.resize(len+5), u_set.resize(len+5);
        u_color.resize(len+5), missmatch.resize(len+5);
        for(int i = 0; i <= len+3; i++)
            u_set[i] = i, u_list[i] = 1, u_color[i] = 0, missmatch[i] = 0;
}};

// Dynamic Weighted DSU  ------ Not Tested !!!!!!!!!!!!
struct WeightedDSU {
    vector<int>u_list, u_set, u_weight, weight;
    WeightedDSU() {}
    WeightedDSU(int SZ) { init(SZ); }
    int unionRoot(int n) {
        if(u_set[n] == n) return n;
        return u_set[n] = unionRoot(u_set[n]);
    }
    void changeWeight(int u, int w, bool first = 1) {          // Change any component's weight
        if(first) w = w - weight[u];
        u_weight[u] += w;
        if(u_set[u] != u)
            changeWeight(u_set[u], w, 0);
    }
    int makeUnion(int a, int b) {                              // Union making with compression
        int x = unionRoot(a), y = unionRoot(b);
        if(x == y) return x;
        if(u_list[x] > u_list[y]) {                        
            u_set[y] = x, u_list[x] += u_list[y];                        
            u_weight[x] += u_weight[y];                
            return x;
        }
        else {                                             
            u_set[x] = y, u_list[y] += u_list[x];                         
            u_weight[y] += u_weight[x];                     
            return y;
    }}
    void init(int len) {                                    // Initializer
        u_list.resize(len+5), u_set.resize(len+5);
        u_weight.resize(len+5), weight.resize(len+5);
        for(int i = 0; i <= len+3; i++)
            u_set[i] = i, u_list[i] = 1, u_weight[i] = weight[i] = 0;
}};


/* -------------------------------------- Trie --------------------------------------
 Complexity : making a trie : O(S), searching : O(S)

    Trie of a string abca, abcb:  
                                               (b)    {isEnd = 1}
                                            |---------> node5
   [start] ----> node1 ----> node2 ----> node3 ----->  node4
           (a)         (b)         (c)         (a)   {isEnd = 1}
    Edges are the next[x] pointers, that direct to the next node of the trie */

// Dynamic Trie (with pointers)
struct dynamicTrie {
    struct node {
        bool isEnd;
        node *next[CHARS];                                      // CHARS: number of charachters
        node() {
            isEnd = false;
            for(int i = 0; i < 10; i++) next[i] = NULL;
    }};
    bool create(char str[], int len, node *current) {
        for(int i = 0; i < len; i++) {
            int pos = str[i] - '0';
            if(current->next[pos] == NULL)      current->next[pos] = new node();
            current = current->next[pos];
            if(current->isEnd)                  return true;
        }
        current->isEnd = true;
        return false; 
    }
    void del(node *current) {
        for(int i = 0; i < CHARS; i++)
            if(current->next[i] != NULL)
                del(current->next[i]);
        delete current; 
    }
    void check(node *current) {
        for(int i = 0; i < CHARS; i++)
            if(current->next[i] != NULL)
                check(current->next[i]);
        if(found) return;
        if(current->isEnd && !found) {
            for(int i = 0; i < CHARS && !found; i++)
                if(current->next[i] != NULL) {
                    found = 1;
}}}};

// Non-Dynamic implementation
// root node is at 0 index of tree
// root node counter contains total number of string insertion
// each inserted char counter is on the child node of the edges
struct Trie {
    struct node {
        int cnt;                    // number of edges, or number of times this node is visited
        int nxt[CHARS];                // if nxt[x] == -1, there is no edge from this node to x
    };
    int nodes;
    node tree[MAX];
    void newNode() {
        tree[nodes].cnt = 0;
        memset(tree[nodes].nxt, -1, sizeof tree[nodes].nxt);
        ++nodes; 
    }
    void init() { nodes = 0; newNode(); }
    int getId(char x) {
        if(x >= 'A' and  x <= 'Z')
            return (x - 'A' + 27);
        return (x - 'a' + 1);
    }
    void insert(string &str, int len = 0, int idx = 0) {
        tree[idx].cnt++;
        if(len == str.size()) return;
        int id = getId(str[len]);
        if(tree[idx].nxt[id] == -1) {
            tree[idx].nxt[id] = nodes;
            newNode();
        }
        insert(str, len+1, tree[idx].nxt[id]);
    }
    int search(string &str, int len = 0, int idx = 0) {
        if(len == str.size())       return -2;
        int id = getId(str[len]);
        if(tree[idx].nxt[id] == -1) return -1;
        if(tree[idx].cnt == 1)      return len;
        return search(str, len+1, tree[idx].nxt[id]);
}};
