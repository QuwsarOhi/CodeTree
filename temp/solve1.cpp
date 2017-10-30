// LightOJ
// 1032 - Fast Bit Calculations 
// Unsolved

#include <bits/stdc++.h>
#define isOn(x, i) (x & (1LL<<i))
#define On(x, i) (x | (1LL<<i))

using namespace std;

int N, lastBit;
long long dp[35][35][35];
bitset<5>B;


long long recur(int pos, long long mask, long long pairs, int lastOnSum) {
    if(mask > N || pos > lastBit)
        return pairs;
    
    long long ans = 0;

    ans += recur(pos+1, mask, pairs, 0);
    if(On(mask, pos) <= N)
        ans += recur(pos+1, mask|(1<<pos), pairs + (lastOnSum > 0), lastOnSum+1);
    
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &N);
        
        for(int i = 0; i <= 31; ++i)
            if(isOn(N, i))
                lastBit = i;
        
        memset(dp, -1, sizeof dp);
        printf("Case %d: %lld\n", Case, recur(0, 0, 0, 0));
    }
    return 0;
}
