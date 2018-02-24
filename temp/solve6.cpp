// SUFFIX ARRAY NEW

#include <bits/stdc++.h>
using namespace std;
#define MAX                 10000000
#define EPS                 1e-9
#define INF                 1e9
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
    int r[2], idx;
};

suffix suff[MAX];
int P[MAX][22];                    // Sparse Table Like    
char str[MAX];

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

bool cmp(suffix a, suffix b) {
    if(a.r[0] != b.r[0])
        return a.r[0] < b.r[0];
    return a.r[1] < b.r[1];
}


void SuffixArray(char str[], int len) {
    for(int i = 0; i < len; ++i)
        P[i][0] = order(str[i]);

    for(int stp = 1, cnt = 1; cnt >> 1 < len; stp++, cnt <<= 1) {
        for(int i = 0; i < len; ++i) {
            suff[i].r[0] = P[i][stp-1];
            suff[i].r[1] = i + cnt < len ? P[i+cnt][stp-1]:-1;
            suff[i].idx = i;
        }
        sort(suff, suff+len, cmp);
        
        P[suff[0].idx][stp] = 0;
        for(int i = 1; i < len; ++i)
            P[suff[i].idx][stp] = suff[i].r[0] == suff[i-1].r[0] && suff[i].r[1] == suff[i-1].r[1] ? P[suff[i-1].idx][stp] : i;
    }
}


int main() {
    scanf("%s", str);
    int len = strlen(str);
    SuffixArray(str, len);
    
    for(int i = 0; i < len; ++i)
        printf("%d\n", suff[i].idx);
    
    /*for(int i = 0; i < len; ++i) {
        printf("P[%d][0] : %d %s\n", i, P[i][0], str+i);
        for(int k = 1; (1 << k)+i <= len; k <<= 1)
            printf("P[%d][%d] : %d %s\n", i, k, P[i][k], str+i);
    }*/
    
    return 0;
}
