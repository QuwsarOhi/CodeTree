// Suffix Array
// Complexity : N log^2(N)

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

int idxToRank[MAX];                                 // index to position mapping
suffix suff[MAX];

void SuffixArray(int len, char str[]) {             // First initial 1st and 2nd ranks for all suffix and sort once
    for(int i = 0, j = 1; i < len; ++i, ++j) {
        suff[i].idx = i;
        suff[i].rank.fi = order(str[i]);
        suff[i].rank.se = (j<len) ? order(str[j]):-1;   // if 2nd rank is out of range, assign -1
        idxToRank[i] = 0;
    }
    sort(suff, suff+len);                               
    for(ll k = 4; k < (2*len); k *= 2) {            // Assigning new first rank for all suffix
        int rank = 0;
        int prevRank = suff[0].rank.fi;             // prevRank contains previous suffix's first rank
        suff[0].rank.fi = 0;                        // first rank is always zero 
        idxToRank[suff[0].idx] = 0;
        for(int i = 1; i < len; ++i) {
            if(suff[i].rank == make_pair(prevRank, suff[i-1].rank.se)) {
                prevRank = suff[i].rank.fi;         // we'll manipulate this first rank, so saving it for later use
                suff[i].rank.fi = rank;             // assigning the new rank to this suffix first rank
            }
            else {
                prevRank = suff[i].rank.fi;         // saving this first rank as this will be manipulated
                suff[i].rank.fi = ++rank;           // as this is not as same as previous rank, increment rank by one
            }
            idxToRank[suff[i].idx] = i;
        }        
        for(int i = 0; i < len; ++i) {          // Assign the second rank
            int nxtIdx = suff[i].idx + k/2;     // finding index at where the substring is as same as this strings [idx, idx+k/2]
            suff[i].rank.se = (nxtIdx < len) ? suff[idxToRank[nxtIdx]].rank.fi:-1;  
        }                                       // the newIdx contains next segments second half's rank
        sort(suff, suff+len);
}}

char str[MAX];

// Longest Common Prefix: Kasai's Algorithm
// Complexity: O(n) ~ O(n logn)

int lcp[MAX];
void Kasai(int len, char str[]) {               // Matches Same charechters with i'th rank & (i+1)'th rank
    int match = 0;
    for(int idx = 0; idx < len; ++idx) {
        if(idxToRank[idx] == len-1) {
            match = 0;
            continue;
        }
        int nxtRankIdx = suff[idxToRank[idx]+1].idx;
        while(idx+match < len and nxtRankIdx+match < len and str[idx+match] == str[nxtRankIdx+match])
            ++match;
        lcp[nxtRankIdx] = match;                // the lcp match of i'th & (i+1)'th is stored in
        match -= match>0;                       // the index of (i+1)'th suffix's index
}}

int consecutiveMaxLCP(int idx, int len) {       // calculates max LCP of index idx
    int r = idxToRank[idx];                     // comparing with the next rank string of idx's string
    int ret = lcp[idx];
    if(r+1 < len)
        ret = max(ret, lcp[suff[r+1].idx]);
    return ret;
}

// Longest Common Prefix [Sparse Table after running Kasai]

int table[MAX][14];
void buildSparseTableRMQ(int n) {                           //  O(n Log n)
    for(int i = 0; i < n; ++i)
        table[i][0] = i;
    for(int j = 1; (1 << j) <= n; ++j)                      // 2^j
        for(int i = 0; i + (1 << j) - 1< n; ++i) {          // For every node
            if(lcp[suff[table[i][j-1]].idx] < lcp[suff[table[i + (1 << (j-1))][j-1]].idx])
                table[i][j] = table[i][j-1];
            else
                table[i][j] = table[i + (1 << (j-1))][j-1];
}}
int sparseQueryRMQ(int l, int r) {                          // Gives LCP of index l, r in O(1)
    int k = log2(r - l + 1);                                // log(2);
    return min(lcp[suff[table[l][k]].idx], lcp[suff[table[r - (1 << k) + 1][k]].idx]);
}