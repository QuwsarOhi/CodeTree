#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h1,h2,m1,m2;
    int r,d,sum,dif,sum1,sum2;
    char c;
    cin>>h1>>c>>m1;
    cin>>h2>>c>>m2;
    sum1=(h1*60)+m1;
    sum2=(h2*60)+m2;
    dif=(sum2-sum1)/2;
    sum=sum1+dif;
    d=sum/60;
    r=sum%60;
    if(d<10)
    {
        cout<<"0"<<d<<":"<<r<<endl;
    }
    else if(r<10){
        cout<<d<<":"<<"0"<<r<<endl;
    }
    else
    {
        cout<<d<<":"<<r<<endl;
    }
    return 0;
}