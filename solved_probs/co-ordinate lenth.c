#include <stdio.h>
#include <math.h>

int main()
{
    int x_1, y_1, x_2, y_2, math_x, math_y;

    scanf("%d %d %d %d", &x_1, &y_1, &x_2, &y_2);

    math_x = pow(x_1 - x_2, 2);
    math_y = pow(y_1 - y_2, 2);

    printf("%lf", sqrt(math_x + math_y));

    return 0;
}
