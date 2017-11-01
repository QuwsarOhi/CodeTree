// LightOJ
// 1032 - Fast Bit Calculations

#include <bits/stdc++.h>
#define isOn(x, i) (x & (1LL<<i))
#define On(x, i) (x | (1LL<<i))
#define Off(x, i) (x & ~(1LL<<i))

using namespace std;
typedef long long ll;

int N, lastBit;
long long dp[33][33][2][2];
bitset<5>B;

// Bit DP (Almost same as Digit DP)
// Complexity O(2*pos*total_bits*tights*number_of_bits)
// Initial Params : (MostSignificantOnBitPos, N, 0, 0, 1)
// Tight is initially on
// pairs are number of paired bits, prevOn shows if previous bit was on (it is for this problem)

ll bitDP(int pos, int mask, int pairs, bool prevOn, bool tight) {
    if(pos < 0)
        return pairs;

    if(dp[pos][pairs][prevOn][tight] != -1)
        return dp[pos][pairs][prevOn][tight];
    
    bool newTight = tight & !isOn(mask, pos);               // Turn off tight when we are turning off a bit which was initially on
    ll ans = bitDP(pos-1, Off(mask, pos), pairs, 0, newTight);

    if(On(mask, pos) <= N)
        ans += bitDP(pos-1, On(mask, pos), pairs + prevOn, 1, tight && isOn(mask, pos));
        
    return dp[pos][pairs][prevOn][tight] = ans;
}


int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &N);
        
        for(int i = 0; i <= 31; ++i)
            if(isOn(N, i))
                lastBit = i;
        
        memset(dp, -1, sizeof dp);
        
        printf("Case %d: %lld\n", Case, bitDP(lastBit, N, 0, 0, 1));
    }
    return 0;
}
