#include <stdio.h>
#include <string.h>


int main()
{
    char a[10], c[1000], s[1000], b;

    int d;

    printf("enter a string:\n");
    scanf("%s", a);//note that & is missing//

    printf("%s\n", a);

    a[3] = 0;//giving a null(0) in a3 for shoring the word//
    printf("%s\n", a);

    printf("%d\n\n", 'A');//prints the ascii value of A//

    gets(c);//dummy gets()//

    printf("enter a string:\n")
    gets(s);

    d = strlen(s);

    printf("the lenth of the string is %d\n", d);

    strcpy(s, "this is a copied line\n\n");

    printf("%s", s);

    memset(s, '*', 7);

    printf("%s", s);



    return 0;
}
