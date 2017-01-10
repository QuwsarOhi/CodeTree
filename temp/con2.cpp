//UVa
//10878 - Decode the tape

#include<bits/stdc++.h>
using namespace std;

char a[100000];

inline void printer(int n)
{
    int num = 0;
    register int i = 0;
    while(n) {
        num += n%10 * 1<<i++;
        n/=10;
    }
    printf("%c", num);
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    register int i = 0, bin;
    bool start = 0, lstart;
    while(scanf(" %[^\n]", a)) {
        if(a[0] == '_' && start) {
            //printf("worked");
            break;
        }
        if(a[0] == '_' && !start) {
            start = 1;
            continue;
        }
        lstart = 0;
        bin = 0;
        for(i = 0; ; i++) {
            if(a[i] == '|' && !lstart) {
                lstart = 1;
                bin = 0;
                continue;
            }
            if(a[i] == '|' && lstart) {
                printer(bin);
                break;
            }
            if(a[i] == ' ') bin *= 10;
            else if(a[i] == 'o') bin = bin*10 + 1;
        }
    }
    return 0;
}
