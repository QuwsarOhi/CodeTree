#include <stdio.h>

int main()
{
    char a, b, c[500];
    int x[500];

    printf("enter a sentence\n");
    gets(c);
    printf("%s\n", c);

    puts(c);

    c[4]=0;
    printf("%s", c);


    return 0;
}
