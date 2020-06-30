#include<bits/stdc++.h>

using namespace std;

int main()

{
    int  a,b,sum=0;
        //freopen("input_0.txt", "r", stdin); // redirects standard input
        //freopen("output_4.txt", "w", stdout); // redirects standard output


    cin>>a>>b;

    if(a%2==0)
    {
        printf("%d is even\n",a);
        sum+=a;
    }
    if(a%2!=0)
    {
        printf("%d is odd\n",a);
        sum-=a;
    }

    if(b > 0)
    {
        printf("%d is greater than zero\n",b);
        sum+=b;
    }
    if(b < 0)
    {
        printf("%d is less than zero\n",b);
        sum-=b;
    }
    if(b == 0)
    {
        printf("%d is equal to zero\n",b);
        sum*=b;
    }
    printf("after adding,a+b is equal to %d\n",a+b);

    if((a+b)%2==0)
    {
        sum+=(a+b);
        printf("after adding %d %d sum is equal to %d\n",a,b,sum);
    }
    if((a+b)%2==1)
    {
        sum-=(a+b);
        printf("after removing %d %d sum is equal to %d\n",a,b,sum);
    }
    if((a+b)==0)
    {
        sum*=10;
        printf("the result after multiplying sum = %d\n",sum);
    }
    sum*=5;
    printf("THE ULTIMATE RESULT = %d\n",sum);
    printf("I wanna be a national contestant and I can write long code\n");

}


