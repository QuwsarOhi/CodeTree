//UVa
//11926 - Multitasking
#include<bits/stdc++.h>
using namespace std;

bitset<1000010>bit;
int n, m, st, en, inV;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    while(scanf("%d %d", &n ,&m) && (n || m)) {
        bool ok = 1;
        bit.reset();
        while(n--) {
            scanf("%d %d", &st, &en);
            for(register int i = st; i < en && ok; i++) {
                if(!bit[i])
                    bit[i] = 1;
                else
                    ok = 0;
            }
        }
        while(m--) {
            scanf("%d %d %d", &st, &en, &inV);
            while((st < 1000000) && ok) {
                for(register int i = st; i < en && i < 1000000 && ok; i++) {
                    if(!bit[i])
                        bit[i] = 1;
                    else
                        ok = 0;
                }
                st += inV;
                en += inV;
            }
        }
        if(ok)
            printf("NO CONFLICT\n");
        else
            printf("CONFLICT\n");
    }
    return 0;
}
