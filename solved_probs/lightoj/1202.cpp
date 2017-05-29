//LightOJ
//1202 - Bishops
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    long t, r1, r2, c1, c2, pos1, pos2;
    scanf("%ld", &t);
    for(long Case = 1; Case <= t; Case++) {
        scanf("%ld %ld %ld %ld", &r1, &c1, &r2, &c2);
        //pos1, pos2 detects the color of square in which the bishop can move
        //lets say, if pos1 is even then the bishops color is black, otherwise white
        pos1 = abs(r1-c1);
        pos2 = abs(r2-c2);
        //two bishops can only attack each other when they are in same color (as black bishop can't visit white square and vice-versa)
        if(((pos1 & 1) && (pos2 & 1)) || (!(pos1 & 1) & !(pos2 & 1))) {
            if(abs(r1-r2) == abs(c1-c2))                //the mathematical term if two bishops can attack each other (directly diagonal to each other)
                printf("Case %ld: 1\n", Case);
            else                                        //if not, then one bishop should first go to the same diagonal position then attack
                printf("Case %ld: 2\n", Case);
        }
        else
            printf("Case %ld: impossible\n", Case);
    }
    return 0;
}
