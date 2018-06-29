#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int M = 998244353;
const int N = 1000+7;

int a[N];
LL CC[N][N];

void build()
{
    for (int i=0; i<N; i++)
        CC[i][0] = 1;

    for (int i=1; i<N; i++)
        for (int j=1; j<N; j++)
            CC[i][j] = (CC[i-1][j-1] + CC[i-1][j])%M;
}

LL C(int n, int r)
{
    if (r<0 || r>n) return 0;
    return CC[n][r];
}

LL dp[N];

int main()
{
    build();
    int n;
    cin>>n;

    for (int i=0; i<n; i++)
        cin>>a[i];

    dp[n] = 1;
    for (int i=n-1; i>=0; i--) {
        if (a[i] == 0)      continue;

        for (int j=i+1; j<=n; j++) {
            
            int opt = j-i-1;
            //cout<<i<<" "<<j<<" "<<opt<<" "<<a[i] << endl;
            printf("( dp[%d] (%lld) + C(%d, %d) (%lld) )* dp[%d] (%lld) = ", i, dp[i], opt, a[i], C(opt, a[i]), j, dp[j]);
            dp[i] = (dp[i] + C(opt, a[i]) * dp[j])%M;
            printf("%lld\n", dp[i]);
        }
        cout << "\n";
    }

    LL ans = 0;
    for (int i=0; i<n; i++)
    {
        ans = (ans + dp[i])%M;
        //cout<<i<<" "<<dp[i]<<endl;
    }
    cout<<ans<<endl;
}
