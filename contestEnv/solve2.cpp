#include <bits/stdc++.h>
using namespace std;
#define MAX                 5010
#define MOD                 1000000007
typedef long long ll;


ll powerMOD(ll x, ll y) {                   // Can find modular inverse by a^(MOD-2),  a and MOD must be co-prime
    //if(MAP.find({x, y}) != MAP.end())
    //    return MAP[{x, y}];
        
    ll res = 1;

    while(y > 0) {
        if(y&1) {
            res = res*x;          // If y is odd, multiply x with result
            if(res > MOD) res %= MOD;
        }
        y = y >> 1;
        x = (x * x);
        if(x > MOD) x %= MOD;
    }
    
    //MAP[{x, y}] = res;
    return res;
}


// Building Pascle C(n, r)
ll p[MAX][MAX];
void buildPascle() {                                // This Contains values of nCr : p[n][r] 
    p[0][0] = 1;
    p[1][0] = p[1][1] = 1;
    for(int i = 2; i <= 5001; i++)
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i)
                p[i][j] = 1;
            else
                p[i][j] = (p[i-1][j-1] + p[i-1][j]) % (MOD-1);
}}

ll C(int n, int r) {
    if (r<0 || r>n || n<0) return 0;
    return p[n][r];
}

//------------------------------------------------------------------

ll NumOfSameValueInCombination(int n, int r) {          // Returns number of same value in a set of nCr combination
    if(n < r) return 0;
    n = r + abs(n-r);
    return C(n-1, r-1);
}


ll a[MAX];
ll Fsum[MAX];
ll CNT[MAX];

int main() {
    buildPascle();
    int t, n;
    ll m;
    scanf("%d", &t);
    
    while(t--) {
        scanf("%d%lld", &n, &m);
        
        a[0] = 1;
        for(int i = 1; i <= n; ++i)
            scanf("%lld", &a[i]);
        
        if(n < m) {
            printf("0\n");
            continue;
        }
        
        
        memset(Fsum, 0, sizeof Fsum);
        //for(int i = 0; i <= 5000; ++i)
        //    Fsum[i+1] = (F(m-2+i, m-2) + Fsum[i]) % (MOD - 1);
        
        for(int i = 1; i <= 5000; ++i)
            Fsum[i] = (F(i, m-2) + Fsum[i-1]) % (MOD - 1);
        
        //for(int j = 0; j <= n; ++j)
        //    cout << j << " : " << Fsum[j] << endl;
        //cout << endl;
        
        sort(a+1, a+n+1);
        memset(CNT, 0, sizeof CNT);
        for(int l = 1; l <= n-m+1; ++l) {
            int pos = l+1, KK = n-l-m+2;
            //cout << "L " << l << " " << KK << endl;
            
            for( ; pos <= l+m-2; ++pos) {
                ll rightPoints = n-(l+m-2);
                ll T = Fsum[rightPoints+m-3];
                //cout << pos << " : " << rightPoints << " " << T << endl; 
                CNT[pos] += T;
                CNT[pos] %= MOD-1;
            }
            
            //cout << "EXTRA\n";
            for( ; pos <= n-1; ++pos) {
                ll rightPoints = n-pos;
                ll minElem = pos - l;
                ll T = Fsum[rightPoints+minElem-1]-Fsum[minElem-1];
                //cout << pos << " : " << rightPoints+minElem-1 << " * " << T << " " << minElem-1 << endl;
                //cout << Fsum[rightPoints+minElem-1] << " - " << Fsum[minElem-1] << endl;
                CNT[pos] += T;
                CNT[pos] %= MOD-1;
            }
            cout << endl;
        }
        
        //cerr << "DONE\n";
        //for(int i = 1; i <= n; ++i)
        //    cout << i << " : " << CNT[i] << endl;
        
        ll ANS = 1;
        for(int i = 1; i <= n; ++i)
            ANS = (ANS * powerMOD(a[i], CNT[i]))%MOD;
            
        printf("%lld\n", ANS);
    }
    return 0;
}
