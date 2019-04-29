#include<iostream>
#include<vector>
#include<cstdio>
#include<math.h>
#define MOD 1000000000
using namespace std;
typedef long long ll;

vector<ll>val;

ll n,dp[1000002];

void Tot()
{
    ll mul=1;
    while(mul<=n){
        val.push_back(mul);
        mul*=2;
    }
}


ll Dp()
{
    dp[0]=1LL;
    for(int i=0; i<(int)val.size(); i++)
        for(ll j=val[i]; j<=n; j++) {
            dp[j]= (dp[j]+dp[j-val[i]]);
            if(dp[j] >= MOD)
                dp[j] %= MOD;
        }
    return dp[n]%MOD;
}

int main()
{
    //cout<<5059487556%1000000000<<endl;
    scanf("%lld",&n);
    Tot();
    printf("%lld\n",Dp());
    return 0;
}