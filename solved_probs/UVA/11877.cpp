//UVa
//11877 - The Coco-Cola Store
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
    //printf("%d %d %d\n", x, y, z);
    total(x, y, z);
}


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, y, a, a1, a2;
    while(scanf(" %d", &n) && n)
    {
        first = true;
        a = total(0, n, 0);
        //a2 = total(n, 2, 0);
        //if(y != 2)
            //a2 = 0;
        a1 = total(0, n+1, 0);
        if(!(p >= 1))
            a1 = 0;
        a2 = total(0, n+2, 0);
        if(!(p == 2))
            a2 = 0;
        printf("%d\n", max(max(a, a1), a2));
    }
    return 0;
}
