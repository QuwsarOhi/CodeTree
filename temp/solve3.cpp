#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){


    int t;
    scanf("%d",&t);


    while(t--){

        ll n, m;
        scanf("%lld %lld",&n,&m);

        ll rr = max(n,m);
        m = min(n,m);
        
        n=rr;

        if(n%m == 0)
        {
            cout<<"Ari"<<endl;
        }
        else
        {
            vector<ll>v;
            bool sign = true;
            while(true)
            {
                if( n == 0 || m == 0 || n%m == 0){ v.push_back(1LL); break; }
                ll tt=n/m;

                if(tt != 1) sign = false;

                v.push_back(tt);
                n=n-(tt*m);
                ll t1 = max(n,m);
                m = min(n,m);
                n=t1;
            }
            if(sign)
            {
                if(int(v.size())%2 == 0) cout<<"Rich"<<endl;
                else cout<<"Ari"<<endl;
            }
            else
            {
                for(int i=0; i<int(v.size()); i++)
                {
                    if(v[i]>1LL)
                    {
                        ll r = i+1LL;
                        if(r%2 == 0) cout<<"Rich"<<endl;
                        else cout<<"Ari"<<endl;
                        break;
                    }
                }
            }
           // for(int i=0; i<v.size(); i++) cout<<"V  "<<v[i]<<endl;
        }
    }

    return 0;
}