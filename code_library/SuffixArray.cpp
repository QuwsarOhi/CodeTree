// Suffix Array
// Complexity : N log^2(N)

#include <bits/stdc++.h>
#define fi      first
#define se      second
typedef long long   ll;
using namespace std;



struct suffix{
    int idx;                        // Start index of suffix
    pair<int, int> rank;            // Sorting Ranks
};

suffix suff[200000];

bool cmp(suffix a, suffix b) {
    return a.rank < b.rank;
}

int order(char x) {                 // Ordering : Number < Capital Letter < Small Letter
    if(isdigit(x))
        return x-'0';
    else if(isupper(x))
        return x-'A'+10;
    else if(islower(x))
        return x-'a'+36;
    else
        return 110;                 // Adding a big constant : {, }, #..
}

void SuffixArray(char str[], int n) {
    // First initial 1st and 2nd ranks for all suffix and sort once
    for(int i = 0, j = 1; i < n; ++i, ++j) {
        suff[i].idx = i;
        suff[i].rank.fi = order(str[i]);
        suff[i].rank.se = (j<n) ? order(str[j]):-1;                 // if 2nd rank is out of range, assign -1
    }
    
    sort(suff, suff+n, cmp);
    int Rank[n];                                    // index to position mapping
    
    for(ll k = 4; k < (2*n); k *= 2) {
        // Assigning new first rank for all suffix
        int rank = 0;
        int prevRank = suff[0].rank.fi;             // prevRank contains previous suffix's first rank
        suff[0].rank.fi = 0;                        // first rank is always zero 
        Rank[suff[0].idx] = 0;

        for(int i = 1; i < n; ++i) {
            if(suff[i].rank == make_pair(prevRank, suff[i-1].rank.se)) {
                prevRank = suff[i].rank.fi;         // we'll manipulate this first rank, so saving it for later use
                suff[i].rank.fi = rank;             // assigning the new rank to this suffix first rank
            }
            else {
                prevRank = suff[i].rank.fi;         // saving this first rank as this will be manipulated
                suff[i].rank.fi = ++rank;           // as this is not as same as previous rank, increment rank by one
            }
            Rank[suff[i].idx] = i;
        }
        
        // Assign the second rank
        for(int i = 0; i < n; ++i) {
            int nxtIdx = suff[i].idx + k/2;         // finding index at where the substring is as same as this strings [idx, idx+k/2]
            suff[i].rank.se = (nxtIdx < n) ? suff[Rank[nxtIdx]].rank.fi:-1;     // the newIdx contains next segments second half's rank
        }
        sort(suff, suff+n, cmp);
    }
}


// Longest Common Prefix: Kasai's Algorithm
// Complexity: O(n) ~ O(n logn)

vector<int> LCP(char str[], int suffArr[], int n) {
    vector<int>Rank(n), lcp(n);
    
    for(int i = 0; i < n; ++i)              // suffArr : {key:rank, value:index}
        Rank[suffArr[i]] = i;               // rank    : {key:index, value:rank}
    
    int k = 0;
    for(int i = 0; i < n; ++i) {            // loop runs from string index 0 to n
        if(Rank[i] == n-1) {                // if the rank of i'th index is last, there is no consicutive same suffix
            k = 0;
            continue;
        }
        
        int j = suffArr[Rank[i]+1];         // Starting index of the next rank suffix
        
        while(i+k < n && j+k < n && str[i+k] == str[j+k])
            ++k;
        
        lcp[Rank[i]] = k;                   // k is the lcp size of that rank
        
        //printf("comparing %s & %s ::: k = %d\n", str+i, str+j, k);
        if(k>0) --k;
    }
    
    return lcp;                              // contains rank-wise lcp length
}


int main() {
    char str[200000];
    scanf("%s", str);
    int len = strlen(str);
    
    SuffixArray(str, len);
    
    for(int i = 0; i < len; ++i)                // i : rank
        printf("%d\n", suff[i].idx);            // idx: starting index of suffix
    
    return 0;
}