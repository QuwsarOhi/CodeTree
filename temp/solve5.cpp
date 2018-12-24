#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define maxi 100000000
using namespace std;
 
bitset<maxi+2>b;
unsigned int prime[5761499],cum[5761499];
 
unsigned int k=0;
 
void Prime()
{
    b[0]=true;
    for(int i=3; i*i<=maxi; i+=2) if(!b[i]) for(int j=i*i; j<=maxi; j=j+i )b[j]=true;
    k=1;
    prime[0]=2;
    cum[0]=2;
    for(int i=3; i<=maxi; i+=2)if(!b[i] ) prime[k++]=i;
    for(int i=1; i<k; i++) cum[i] = (cum[i-1]*prime[i]);
}
 
unsigned int Bigmod(unsigned int base, ll power)
{
    if( power == 0) return 1;
    unsigned  int x = Bigmod(base,power/2);
    x= (x*x);
    if(power%2 == 1) x = (x*base);
 
    return x;
}
 
ll Power(unsigned int n, unsigned int p)
{
    ll cnt=0;
    for(ll i= (ll)p; i<=(ll)n; i = i*p) cnt++;
    return cnt;
}
int main()
{
    int t,cas=1;
    Prime();
    scanf("%d",&t);
    while(t--)
    {
        unsigned int n;
        scanf("%u",&n);
 
        unsigned int ans=1;
        for(int i=0; prime[i]*prime[i] <= n && i<k; i++)
        {
 
            ll power = Power(n,prime[i])-1;
            if(power > 0) ans= (ans*Bigmod(prime[i],power));
        }
 
        int ind = (upper_bound(prime,prime+k,n)-prime)-1;
        cerr << prime[ind] << endl;
        ans = ans*cum[ind];
        printf("Case %d: %u\n",cas++, ans);
    }
    return 0;
}