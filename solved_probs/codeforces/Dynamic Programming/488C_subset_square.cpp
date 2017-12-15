// Codeforces
// C. Square Subsets
// Bitmask DP

#include <bits/stdc++.h>
using namespace std;
#define MAX                 1e6
#define EPS                 1e-9
#define INF                 1e9+10
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS)) 
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbug(vari)          cerr << #vari << " = " << (vari) <<endl
#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

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

const int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
const int primeSize = sizeof(prime)/sizeof(prime[0]);
int power2[100010],  cnt[71] = {0}, bit[71] = {0}, dp[71][(1<<(primeSize))+10];

int main() {
    power2[0] = 1;
    for(int i = 1; i <= 100000; ++i)            // Generating Powers of 2
        power2[i] = (power2[i-1] * 2)%MOD;       // 2^n = C(n, 0) + C(n, 1) + C(n, 2) + C(n, 3) + ... C(n, n-1) + C(n, n)
    
    int n, x;
    
    cin >> n;
    
    for(int i = 0; i < n; ++i) {
        cin >> x;
        cnt[x]++;
    }
    
    for(int i = 2; i <= 70; ++i) {          // if a value consists of even prime[j], the j'th pos is 0, else 1
        x = i;
        int tmp = 0;
        for(int j = 0; j < primeSize; ++j)
            while(x%prime[j] == 0) {
                tmp ^= (1<<j);
                x/=prime[j];
            }
        bit[i] = tmp;
    }
    
    dp[0][0] = 1;
    //cout << "psize " << primeSize << endl;
    for(int i = 1; i <= 70; ++i) {
        if(cnt[i] == 0) {                   // if value is not present in input, pass all value to the upper index
            for(int bits = 0; bits < (1<<primeSize); ++bits)
                dp[i][bits] = dp[i-1][bits];
        }
        else {                              // else calculate the combinations
            for(int bits = 0; bits < (1<<primeSize); ++bits) {                                  // 2^(n-1) = how many ways even or odd elements can be taken
                dp[i][bits^bit[i]] = ((ll)dp[i][bits^bit[i]] + (ll)power2[cnt[i]-1] * (ll)dp[i-1][bits])%MOD;   // Taking i'th value odd times (and all other bit combinations)
                dp[i][bits] = ((ll)dp[i][bits] + (ll)power2[cnt[i]-1] * (ll)dp[i-1][bits])%MOD;                 // Taking i'th value even times (and all other bit combinations)
            }
            
        }
    }
    
    pf("%d\n", dp[70][0] - 1);      // Substract 0 from case
    
    return 0;
}
    
    