// SPOJ LCS
// Verdict : TLE
// Longest Common Substring

#include <bits/stdc++.h>
using namespace std;
#define MAX                 200100
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define All(S)              S.begin(), S.end()              
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())
#define error(args...)      { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

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

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {                                                  // Debugger error(a, b, ....)
	cerr << *it << " = " << a << "\n";
	err(++it, args...);
}

//const int dx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};                                                      // Four side 
//const int dxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};                     // Eight side
//----------------------------------------------------------------------------------------------------------


struct suffix {
    int idx;
    pair<int, int>rank;
};

suffix suff[700100];
char str1[350000], str2[350000], str[700100];
int len1, len2, len, suffArr[700100];


bool cmp(suffix a, suffix b) {
    return a.rank < b.rank;
}

int order(char x) {                 // Ordering : Number < Capital Letter < Small Letter
    if(ispunct(x))
        return 110;
    else if(isdigit(x))
        return x-'0';
    else if(isupper(x))
        return x-'A'+10;
    else
        return x-'a'+36;
}

void SuffixArray(char str[], int n) {
    for(int i = 0, j = 1; i < n; ++i, ++j) {
        suff[i].idx = i;
        suff[i].rank.fi = order(str[i]);
        suff[i].rank.se = (j<n) ? order(str[j]):-1;
    }
    
    sort(suff, suff+n, cmp);
    int Rank[n];
    
    for(ll k = 4; k < (n<<1); k <<= 1) {
        int rank = 0;
        int prevRank = suff[0].rank.fi;
        suff[0].rank.fi = 0;
        Rank[suff[0].idx] = 0;
        
        for(int i = 1; i < n; ++i) {
            if(suff[i].rank == mp(prevRank, suff[i-1].rank.se)) {
                prevRank = suff[i].rank.fi;
                suff[i].rank.fi = rank;
            }
            else {
                prevRank = suff[i].rank.fi;
                suff[i].rank.fi = ++rank;
            }
            Rank[suff[i].idx] = i;
        }
        
        for(int i = 0; i < n; ++i) {
            int nxtIdx = suff[i].idx + k/2;
            suff[i].rank.se = (nxtIdx<n) ? suff[Rank[nxtIdx]].rank.fi:-1;
        }
        
        sort(suff, suff+n, cmp);
    }
}

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
    
    return lcp;
}



int fastIn(char str[]) {
    register int c, i = 0;
    while(1) {
        c = getchar_unlocked();
        if(c == '\n' || c == ' ') {
            str[i++] = '\0';
            return i;
        }
        str[i++] = c;
    }
    return 0;
}

int main() {
    len1 = fastIn(str1);
    len2 = fastIn(str2);
    
    len = len1+len2+1;
    
    strcat(str, str1);
    strcat(str, "#");               // Two strings won't be compared for this terminator
    strcat(str, str2);
    
    SuffixArray(str, len);
    
    for(int i = 0; i < len; ++i) {
        //printf("%2d: %s\n", suff[i].idx, str+suff[i].idx);
        suffArr[i] = suff[i].idx;
    }
    //printf("\n");
    
    vi lcp = LCP(str, suffArr, len);
    int ans = 0;
    
    for(int i = 0; i < len-1; ++i) {                                        // Critical Case : asdasd xas
        if(!(suff[i].idx < len1 && suff[i+1].idx < len1)) {                 // if one of the string is not the str1
            //printf("%2d: %s %s\n", lcp[i], str+suff[i].idx, str+suff[i+1].idx);
            ans = max(ans, lcp[i]);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
