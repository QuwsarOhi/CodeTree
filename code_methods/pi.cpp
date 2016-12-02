#include <stdio.h>
#include <math.h>

int main()
{
    double r, area, pi;

    scanf("%lf", &r);

    pi = acos(-1);
    printf("%lf", pi);
    area = pi * r * r;

    printf("%lf", area);
    return 0;

}
