// SPOJ BEADS
// Cycle Shifts, Ad-hoc, suffix array

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
char str[11000], txt[55000];

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


int main() {
    //freopen("in", "r", stdin);
    int t;
    
    scanf("%d", &t);
    
    while(t--) {
        memset(txt, 0, sizeof txt);
        memset(str, 0, sizeof str);
        scanf("%s", str);
        int len1 = strlen(str);
        strcat(txt, str);
        strcat(txt, str);                   // Critical Case: "aaaa", "aaabba"
        strcat(txt, "{");                   // "{" is lexicograpgically bigger than any other string
        int len2 = len1*2 + 1;              // we need strings sorted also according to size (bigger to lower + lexicographical), the "{" produces this
        SuffixArray(txt, len2);
        
        //for(int i = 0; i < len2; ++i)     // se all suffix sortings
        //    printf("%2d : %s\n", suff[i].idx, txt+suff[i].idx);
        
        for(int i = 0; i < len2; ++i)
            if(suff[i].idx < len1) {
                printf("%d\n", suff[i].idx+1);
                break;
            }
    }
    return 0;
}
