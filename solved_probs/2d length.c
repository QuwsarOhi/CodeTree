#include <stdio.h>
#include <math.h>


int main()
{
    int x1, x2, y1, y2, an;
    float sum1, sum2, p1, p2, total, ans;
    
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    
    sum1 = x1 - x2;
    sum2 = y1 - y2;
    
    p1 = sum1 * sum1;
    p2 = sum2 * sum2;
    
    total = fabs(p1 + p2);
    an = fabs(total);
    
    ans = sqrt(an);
    
    printf("%f", ans);
    
    return(0);
}
