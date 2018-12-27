#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}
template<class T>T sqr(T a){
    return a*a;
}

const double pi = acos(-1.0);
const double eps = 1e-8;

int ar[100];
int flag[200010];

vector<int>vec;

int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int i,j,k,cnt,n,t,sum,sz,z;

    for(i=30;i>-1;i--)
        ar[i]=pow(2,i);


    while(2==scanf("%d%d",&n,&k))
    {
        vec.clear();
//        printf("naim\n");
        if(n<k)
        {
            printf("NO\n");
            continue;
        }


//        printf("naim\n");
        sum  = n;
        cnt = 0;
        if(n%2==1)
            sum--,cnt++,vec.pb(1);
        for(i=30;i>-1;i--)
        {
//            printf("i - > %d\n",i);
            while(ar[i]<=sum)
            {
                vec.pb(ar[i]);
                sum-=ar[i];
                cnt++;
//                cout<<cnt<<endl;
            }
        }
        sort(vec.rbegin(),vec.rend());
//        cout<<sum<<endl;
        if(cnt>k)
        {
            printf("NO\n");
            continue;
        }
        j = 0;
        while(cnt!=k)
        {
            z = vec[j];
            if(z>1)
            {
                vec.pb(z/2);
                vec.pb(z/2);
                vec.erase(vec.begin()+j);
                cnt++;
            }
            else
                j++;

        }
        t = 0;
        printf("YES\n");
        for(auto it:vec)
        {
            printf("%d ",it);
        }
        cout<<endl;
    }

    return 0;
}