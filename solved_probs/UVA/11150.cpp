//UVa
// 11150 - Cola
#include <bits/stdc++.h>
using namespace std;
bool first;
int p;
int total(int x, int y, int z)
{
    if(x == 0 && y < 3)
    {
        p = y;
        return z;
    }
    if(first){
        first = false;
        y+= x;
        z += x;
        x = 0;
    }
    else{
        z += x;
        y += x;
        x = y/3;
        y -= x*3;
    }
    total(x, y, z);
}


int main()
{
    int n, y, a, a1, a2;
    while(scanf(" %d", &n) != EOF)
    {
        first = true;
        a = total(n, 0, 0);
        a1 = total(n, 1, 0);
        if(!(p >= 1))
            a1 = 0;
        printf("%d\n", max(a, a1));
    }
    return 0;
}
