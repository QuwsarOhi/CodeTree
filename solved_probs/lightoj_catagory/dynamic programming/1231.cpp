// Dynamic Programming
// LightOJ : 1231 - Coin Change (I)
     
    #include <bits/stdc++.h>
    #define MOD 100000007
    using namespace std;
     
    int n, coinVal[55], coinNumber[55], total, dp[52][1010];
    //vector<int>v;
     
    int recur(int pos, int taken) { 
        if(taken == total) {
            //cout << "Coins : " << endl;
            //for(auto it : v)
                //cout << it << endl;
            //cout << endl;
            return 1;
        }
        if(taken > total || pos == n)
            return 0;
       
        if(dp[pos][taken] != -1)           
            return dp[pos][taken];
       
        int takenCoin = 0, ans = 0;
        for(int i = 0; i < coinNumber[pos]; ++i) {
            takenCoin += coinVal[pos];
            //v.push_back(coinVal[pos]);
            ans += recur(pos+1, taken+takenCoin);
            ans %= MOD;
        }
       
        //for(int i = 0; i < coinNumber[pos]; ++i)
            //v.pop_back();
       
        ans += recur(pos+1, taken);
        ans %= MOD;
       
        return dp[pos][taken] = ans;
    }
     
    int main() {
        //freopen("in", "r", stdin);
        //freopen("out", "w", stdout);
       
        int t;
        scanf("%d", &t);
       
        for(int Case = 1; Case <= t; ++Case) {
            scanf("%d %d", &n, &total);
            //cout << "Total " << total << endl;
            for(int i = 0; i < n; ++i)
                scanf("%d", &coinVal[i]);
           
            for(int i = 0; i < n; ++i)
                scanf("%d", &coinNumber[i]);
           
            memset(dp, -1, sizeof dp);
            printf("Case %d: %d\n", Case, recur(0, 0));
        }
       
        return 0;
    }
     
