#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j,x,y,a,b,sum,flag,t,z,p,q;


    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&n,&m,&a,&b);

        if((n/b==m&&n%b==0)||(n/b)<m)
        {
            printf("-1\n");
        }
        else
        {
            if(n/a==m&&n%a==0)
            {
                printf("%d\n",m-1);
            }
            else if((n/a)>m||(n/a)==m&&n%a!=0)
            {
                printf("%d\n",m);
            }
            else
            {
                flag = 0;
                    x = n/a;
                    y = m-x;
                    int qq = x;
                while(flag!=1)
                {
                    z = y*b;
                    p = n-z;
                  //  printf("%d %d\n",z,p);
                    if(p/a>m-y)
                    {
                        flag = 1;
                        printf("%d\n",qq);
                        break;
                    }
                    else if(p/a==m-y&&p%a!=0)
                    {
                        flag = 1;
                        printf("%d\n",qq);
                        break;
                    }
                     else if(p/a==m-y&&p%a==0)
                    {
                        flag = 1;
                        printf("%d\n",--qq);
                        break;
                    }
                    y++;
                    qq--;
                }
            }
        }
    }






    return 0;
}