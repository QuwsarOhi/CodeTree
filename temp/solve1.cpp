#include <bits/stdc++.h>
using namespace std;
#define SZ 65
typedef long long LL;
LL mem[SZ][SZ];

char s[SZ];

LL dp(int i,int j)
{
    if(i>j )return 0;

    if(i==j)return 1;

    LL &ret=mem[i][j];
    if(ret!=-1)return ret;

    if(s[i] == s[j] ) ret = dp(i+1,j) + dp(i,j-1) + 1 ;
    else           ret = -dp(i+1,j-1) + dp(i+1,j) + dp(i,j-1) ;

    return ret;
}

int main()
{
    int t,cs=1;
    scanf("%d", &t);
    while(t--)
    {
        memset(mem,-1,sizeof mem);
        cin>>s;
        printf("%lld\n", dp(0,strlen(s)-1));
    }
    return 0;
}
