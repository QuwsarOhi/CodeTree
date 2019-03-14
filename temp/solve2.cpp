#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

long long nCr(int n, int k) { 
    if(n < k) return 0;
    if(n == k) return 1;
    long long c = 1;
    if(k > n - k)
        k = n-k;
    for(int i = 0; i < k; i++) {
        c *= (n-i);
        c /= (i+1);
    }
    return c;
}

ll a[100009];

int main()
{
    ll n;
    cin>>n;
    ll ev=0,od=0;
    for(ll i=0; i<n; i++){
        cin>>a[i];
        if(a[i]%2==0){
            ev++;
        }
        else{
            od++;
        }
    }

    ll ans1 = nCr(ev,3);
    ll ans2 = nCr(od,2)*ev;
    ll ans = ans1+ans2;
    cout<<ans<<endl;
    return 0;
}