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
    }
    return ret;
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
    }
    return ret;
}
