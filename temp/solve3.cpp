#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Digit DP
// Complexity : O(10*idx*sum*tight)
// Tight contains if there is any restriction to number

ll dp[100][100][2], Pow[20];

ll digitSum(int idx, int sum, int value, bool tight, int K, vector<int>&MaxDigit) {
    //
    if (idx == -1) {
        cout << "K " << K << endl;
        cout << idx << " " << sum << " " << value << endl;
        cout << "return " << ((value%K == 0) && (sum%K == 0)) << endl;
        return ((value%K == 0) && (sum%K == 0));
    }
    
    
    if (dp[idx][sum][tight] != -1 && tight != 1)
        return dp[idx][sum][tight];

    ll ret = 0;
    int lim = (tight)? MaxDigit[idx] : 9;
    
    //cout << "Range " << idx << " " << MinDigit[idx] << " " << lim << endl;
    for (int i = 0; i <= lim; i++) {
        bool newTight = (MaxDigit[idx] == i)? tight : 0;       // caclulating newTight value for next state
        int newValue = value ? value*10+i : i;
        cout << "new " <<idx << " " << sum+i << " " << newValue << endl;
        ret += digitSum(idx-1, (sum+i), newValue, newTight, K, MaxDigit);
        
    }

    if (!tight)
      dp[idx][sum][tight] = ret;

    return ret;
}


int main() {
    vector<int>mn, mx;
    int t, a, b, K;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d %d %d", &a, &b, &K);
        cout << K << endl;
        while(b) {
            mx.push_back(b%10);
            b /= 10;
        }
        //reverse(mx.begin(), mx.end());
        

        while(a) {
            mn.push_back(a%10);
            a/=10;
        }
        
        Pow[0] = 1;
        for(int i = 1; i <= 20; ++i)
            Pow[i] = Pow[i-1]*10;
        
        for(auto it : mn)
            cout << it << " ";
        cout << endl;
        
        for(auto it : mx)
            cout << it << " ";
        cout << endl;
        
        
        memset(dp, -1, sizeof dp);
        
        printf("Case %d: %lld\n", Case, digitSum((int)mx.size()-1, 0, 0, 1, K, mx));
    }
    
    return 0;
}
