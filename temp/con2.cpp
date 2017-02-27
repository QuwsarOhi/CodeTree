    #include <iostream>
    #include <cstdio>
    using namespace std;
    #define pi 3.14159265359
    int main()
    {
        int i,j,r1,r2,h,p;
        double r,v;
        scanf("%d",&j);
        for(i=1;i<=j;i++)
        {
                  scanf("%d%d%d%d",&r1,&r2,&h,&p);
                  r=r2+(r1-r2)*p/h;
                  printf("%f\n", r);
                  v = 1/3.0 * pi * p *( r*r + r*r2 + r2*r2 );
                  printf("Case %d: %lf\n",i,v);
        }
        return 0;
    }

