#include <algorithm>
#include <iostream>
using namespace std;
int h,w,n,i,j,x,y,f[2005];
pair<int,int> a[2005];
long long xxx[200005],yyy[200005];
long long pw(long long a,int b)
{
	if(b==0) return 1LL;
	if(b&1) return (a*pw(a,b-1))%1000000007;
	long long x=pw(a,b/2);
	return (x*x)%1000000007;
}
long long check(int x,int y)
{
	return (((xxx[x]*yyy[y])%1000000007)*yyy[x-y])%1000000007;
}
int main()
{
	for (xxx[0]=yyy[0]=i=1;i<200005;i++)
	{
		xxx[i]=(xxx[i-1]*i)%1000000007;
    	yyy[i]=pw(xxx[i],1000000007-2);
	}
	cin>>h>>w>>n;
	for (i=0;i<n;i++) cin>>a[i].first>>a[i].second;
	sort(a,a+n);
	a[n]=make_pair(h,w);
	for (i=0;i<=n;i++)
	{
    	x=a[i].first;
    	y=a[i].second;
    	f[i]=check(x+y-2,x-1);
        cout << x << " " << y << " " << f[i] << endl;
    	for (j=0;j<i;j++)
		{
			if (a[j].first<=x&&a[j].second<=y)
			{
				f[i]=(f[i]+1000000007-(f[j]*check(x-a[j].first+y-a[j].second,x-a[j].first))%1000000007)%1000000007;
			}
		}
  	}
	cout<<f[n];
	return 0;
}
	  	     			  		 				 			  	 	
