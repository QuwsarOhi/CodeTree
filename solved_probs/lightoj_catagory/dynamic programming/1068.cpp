// LightOJ
// 1068 - Investigation 

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Digit DP
// Complexity : O(10*idx*sum*tight)
// Tight contains if there is any restriction to number (Tight is initially 1)
// Initial Params: (MaxDigitSize-1, 0, 0, 1, modVal, digitvector)

ll dp[15][100][100][2];

ll digitSum(int idx, int sum, ll value, bool tight, int mod, vector<int>&MaxDigit) {
    if (idx == -1)
        return ((value == 0) && (sum == 0));
    
    if (dp[idx][sum][value][tight] != -1)
        return dp[idx][sum][value][tight];

    ll ret = 0;
    int lim = (tight)? MaxDigit[idx] : 9;                           // Numbers are genereated in reverse order
    
    for (int i = 0; i <= lim; i++) {
        bool newTight = (MaxDigit[idx] == i)? tight : 0;            // caclulating newTight value for next state
        ll newValue = value ? ((value*10) % mod)+i : i;
        ret += digitSum(idx-1, (sum+i)%mod, newValue%mod, newTight, mod, MaxDigit);
    }

    return dp[idx][sum][value][tight] = ret;
}


int main() {
    vector<int>mn, mx;
    int t, K;
    ll a, b;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lld %lld %d", &a, &b, &K);
        
        if(K > 85) {
            printf("Case %d: 0\n", Case);
            continue;
        }
        
        while(b) {
            mx.push_back(b%10);
            b /= 10;
        }
        
        memset(dp, -1, sizeof dp);
        ll ans = digitSum((int)mx.size()-1, 0, 0, 1, K, mx); 
        
        
        a = a-1;
        while(a) {
            mn.push_back(a%10);
            a/=10;
        }
        if(mn.empty())
            mn.push_back(0);
        memset(dp, -1, sizeof dp);
        ans -= digitSum((int)mn.size()-1, 0, 0, 1, K, mn);
        
        printf("Case %d: %lld\n", Case,  ans);
        mn.clear();
        mx.clear();
    }
    
    return 0;
}
