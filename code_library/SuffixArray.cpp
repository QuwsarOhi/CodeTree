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
// Adding a '~' after the string takes the longer lenth higher of the SA
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
    }
    for(int i = 0; i < len; ++i)
        idxToRank[suff[i].idx] = i;
}

// Suffix Array
// Complexity : N log(N)
int o[2][MAX], t[2][MAX];
int idxToRank[MAX], rankToIdx[MAX], A[MAX], B[MAX], C[MAX], D[MAX];
void SuffixArray(char str[], int len, int maxAscii = 256) {     // use ~ as a distinguishing charachter
    int x = 0;
    memset(A, 0, sizeof A);
    memset(C, 0, sizeof C);
    memset(D, 0, sizeof D);
    memset(o, 0, sizeof o);
    memset(t, 0, sizeof t);
    for(int i = 0; i < len; ++i) A[(str[i]-'a')] = 1;
    for(int i = 1; i < maxAscii; ++i) A[i] += A[i-1];
    for(int i = 0; i < len; ++i) o[0][i] = A[(int)(str[i]-'a')];
 
    for (int j = 0, jj = 1, k = 0; jj < len && k < len; ++j, jj <<= 1) {
        memset(A, 0, sizeof A);
        memset(B, 0, sizeof B);
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
        x^=1;
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

int lcp[MAX];
void Kasai(char str[], int len) {               // Matches Same charechters with i'th rank & (i+1)'th rank
    int match = 0;
    memset(lcp, 0, sizeof lcp);
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

int totUniqueSubstr(int len) {                  // Returns total number of unique substring
    int ans = 0;
    for(int rank = 0; rank < len; ++rank) {
        int idx = suff[rank].idx;
        ans += len-idx;
        if(rank != 0)
            ans -= lcp[idx];
    }
    return ans;
}

// Longest Common Prefix [Sparse Table after running Kasai]
int table[MAX][14], lg[MAX];
void buildSparseTableRMQ(int n) {                           //  O(n Log n)
    for(ll i = 0; 1LL << i < n; i++)
        lg[1LL << i] = i;
    for(ll i = 1; i < n; i++)
        lg[i] = max(lg[i], lg[i - 1]);
    for(int i = 0; i < n; ++i)
        table[i][0] = i;
    for(int j = 1; (1 << j) <= n; ++j)                      // 2^j
        for(int i = 0; i + (1 << j) - 1< n; ++i) {          // For every node
            if(lcp[rankToIdx[table[i][j-1]]] < lcp[rankToIdx[table[i + (1 << (j-1))][j-1]]])
                table[i][j] = table[i][j-1];
            else
                table[i][j] = table[i + (1 << (j-1))][j-1];
}}

int sparseQueryRMQ(int l, int r) {          // Gives LCP of index l, r in O(1)
    l = idxToRank[l], r = idxToRank[r];     // Remove this line if rankUp or rankDown is used
    if(l > r) swap(l, r);
    ++l;
    int k = lg[r - l + 1];                                // log(2);
    return min(lcp[rankToIdx[table[l][k]]], lcp[rankToIdx[table[r - (1 << k) + 1][k]]]);
}


// Gives Upper (lower index) for which the Range minimum LCP is tlen
// Call : 0, PosRank, strlen, totstring_len
int rankUP(int lo, int hi, int tlen, int len) {
    int mid, ret = hi, pos = hi;
    --hi;
    while(lo <= hi) {
        mid = (lo+hi)>>1;
        if(sparseQueryRMQ(mid, pos) >= tlen)
            hi = mid-1, ret = mid;
        else
            lo = mid+1;
    }
    return ret;
}

// Gives Lower (higher index) for which the Range minimum LCP is tlen
// Call : PosRank, len-1 strlen, totstring_len
int rankDown(int lo, int hi, int tlen, int len) {
    int mid, ret = lo, pos = lo;
    ++lo;
    while(lo <= hi) {
        mid = (lo+hi)>>1;
        if(sparseQueryRMQ(mid, pos) >= tlen)
            lo = mid+1, ret = mid;
        else
            hi = mid-1;
    }
    return ret;
}